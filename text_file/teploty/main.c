#include <stdio.h>

int main()
{
    FILE *f, *g;

    if ((f = fopen("namerene_teploty.txt", "r")) == NULL)
    {
        printf("soubor IN se nepodařilo otevřít");
        return 1;
    }

    if ((g = fopen("out.txt", "w")) == NULL)
    {
        printf("soubor OUT se nepodařilo otevřít");
        return 1;
    }

    char nazev[17];
    int teploty[3];

    while (fscanf(f, "%s %d %d %d", nazev, &teploty[0], &teploty[1], &teploty[2]) != EOF)
    {
        float prumer = (teploty[0] + teploty[1] + teploty[2] + teploty[2]) / 4;
        fprintf(g, "%16s %d %d %d %.2f\n", nazev, teploty[0], teploty[1], teploty[2], prumer);
    }
}
