#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *f, *g;

    if ((f = fopen("activity_318109582.tcx", "r")) == NULL)
    {
        printf("soubor IN se nepodařilo otevřít");
        return 1;
    }

    int kcal = 0;
    double seconds = 0;
    double meters = 0;
    char *kal, *konkal;
    char radek[200];
    int lap = 0;

    while (fgets(radek, 200, f) != NULL)
    {
        if ((kal = strstr(radek, "<Calories>")) != NULL) {
            printf("%s", radek);
            kal += 10;
            konkal = strstr(kal, "<");
            *konkal = '\0';
            kcal += atoi(kal);
        }
        else if ((kal = strstr(radek, "<TotalTimeSeconds>")) != NULL) {
            printf("%s", radek);
            kal += 18;
            konkal = strstr(kal, "<");
            *konkal = '\0';
            seconds += atof(kal);
        }
        if (strstr(radek, "<Lap") != NULL) {
            lap = 1;
        }
        if (lap == 1 && (kal = strstr(radek, "<DistanceMeters>")) != NULL) {
            printf("%s", radek);
            kal += 16;
            konkal = strstr(kal, "<");
            *konkal = '\0';
            meters += atof(kal);
            lap = 0;
        }
    }
    printf("kcal %d\n", kcal);
    printf("BigMac: %f\n", (float)kcal / 510.f);
    printf("time %d:%d:%d\n", (int)seconds / 60 / 60, ((int)seconds / 60) % 60, ((int)seconds % 60));
    printf("kilometers %.2f\n", meters / 1000);
    printf("rychlost %f km/h\n", (meters / 1000) / (seconds / 60 / 60));
    printf("tempo %f min/km\n", (seconds / 60) / (meters / 1000));
}