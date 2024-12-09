#include <stdio.h>
#include <string.h>

char to_lowercase(char i)
{
    if (i >= 'A' && i <= 'Z')
    {
        i += ('a' - 'A');
    }
    return i;
}

int is_palindrome(char *input, int len)
{
    for (size_t i = 0; i < (len + 1) / 2; i++)
    {
        if (to_lowercase(input[i]) != to_lowercase(input[len - i - 1]))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    FILE *f, *g;

    if ((f = fopen("palindrom_zdroj.txt", "r")) == NULL)
    {
        printf("soubor se nepodařilo otevřít");
        return 1;
    }

    if ((g = fopen("palindromy.txt", "w")) == NULL)
    {
        printf("soubor OUT se nepodařilo otevřít");
        return 1;
    }

#define RADEK_SIZE 300
    char radek[RADEK_SIZE];

    size_t pocet_celkem = 0;
    size_t pocet_palindromu = 0;

    while (fgets(radek, RADEK_SIZE, f) != NULL)
    {
        int len = strlen(radek);
        if (radek[len - 1] == '\n'){
            radek[len - 1] = '\0';
            len -= 1;
        }
        // printf("len:%d", len);

        int is = is_palindrome(radek, len);
        if (is == 0)
        {
            // printf("neni\n");
        }
        else if (is == 1)
        {
            // printf("je\n");
            fprintf(g, "%s\n", radek);
            pocet_palindromu++;
        }
        else
        {
            printf("wtf:%d\n", is);
        }
        pocet_celkem++;
    }

    fprintf(g, "Pocet palindromu: %d\nProcent z celkoveho poctu: %d%%\n", pocet_palindromu, (pocet_palindromu * 100 / pocet_celkem));
    return 0;
}