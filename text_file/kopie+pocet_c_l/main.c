#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *f, *g;

    if ((f = fopen("data.txt", "r")) == NULL)
    {
        printf("soubor IN se nepodařilo otevřít");
        return 1;
    }
    if ((g = fopen("kopie.txt", "w")) == NULL)
    {
        printf("soubor OUT se nepodařilo otevřít");
        return 1;
    }

    int lines = 0;
    int chars = 0;
    int c;

    while ((c = fgetc(f)) != EOF)
    {
        if (c == '\n')
            lines++;
        else
            chars++;
        fputc(c, g);
    }

    printf("chars: %d, lines: %d\n", chars, lines);
}