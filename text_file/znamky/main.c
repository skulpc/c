#include <stdio.h>
#include <stdbool.h>

int main()
{
    FILE *f, *g;

    if ((f = fopen("znamky.txt", "r")) == NULL)
    {
        printf("soubor IN se nepodařilo otevřít");
        return 1;
    }

    if ((g = fopen("vysledky.txt", "w")) == NULL)
    {
        printf("soubor OUT se nepodařilo otevřít");
        return 1;
    }

    char jmeno[17];
    int znamky[4];

    while (fscanf(f, "%s %d %d %d %d", jmeno, &znamky[0], &znamky[1], &znamky[2], &znamky[3]) != EOF)
    {
        float prumer = (znamky[0] + znamky[1] + znamky[2] + znamky[3]) / 4.f;
        fprintf(g, "%16s %d %d %d %d %.2f ", jmeno, znamky[0], znamky[1], znamky[2], znamky[3], prumer);

        bool neprospel = 0;
        bool nevyznamenal = 0;

        for (size_t i = 0; i < sizeof(znamky) / sizeof(znamky[0]); i++)
        {
            if (znamky[i] == 5) neprospel = 1;
            if (znamky[i] > 2) nevyznamenal = 1;
        }

        if (neprospel) {
            fprintf(g, "neporspel\n");
        }
        else if (nevyznamenal || prumer > 1.5) {
            fprintf(g, "prospel\n");
        }
        else {
            fprintf(g, "prospel s vyznamenanim\n");
        }
        
    }
}
