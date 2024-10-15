#include <stdio.h>

int main()
{
    FILE *f, *g;

    if ((f = fopen("vypoved.txt", "r")) == NULL)
    {
        printf("soubor IN se nepodařilo otevřít");
        return 1;
    }

    if ((g = fopen("priznani.txt", "w")) == NULL)
    {
        printf("soubor OUT se nepodařilo otevřít");
        return 1;
    }

#define RADEK_SIZE 300
    char radek[RADEK_SIZE];

    while (fgets(radek, RADEK_SIZE, f) != NULL)
    {
        int start = 0;

        printf("%s", radek);

        for (size_t i = 0; i < RADEK_SIZE; i++)
        {
            if ((radek[i] == ' ' || i == 0) && radek[i + 1] != ' ')
            {
                for (size_t u = start; u < i; u++)
                {
                    fputc(radek[u], g);
                    printf("%d ", u);
                }
                printf("\n");

                if (i < RADEK_SIZE - 2 && radek[i + ((i == 0) ? 0 : 1)] == 'n' && radek[i + ((i == 0) ? 1 : 2)] == 'e')
                {
                    start = i + ((i == 0) ? 2 : 3);
                    if (i != 0)
                    {
                        fputc(' ', g);
                    }
                }
                else
                {
                    start = i;
                }
            }
            else if (radek[i] == '\0')
            {
                if (i != 0)
                {
                    // konec radku
                    for (size_t u = start; u < i; u++)
                    {
                        fputc(radek[u], g);
                    }
                }
                else
                {
                    fputc('\n', g);
                }
                printf("trig: [%d] %d\n", i, radek[i]);
                break;
            }
        }
    }
}

// ZBYVA ZAOKROUHLIT