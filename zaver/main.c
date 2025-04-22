#include <stdio.h>
#include <string.h>

typedef char Name[10];

typedef struct Competitor
{
    Name name;
    int score;
} Competitor;

int main()
{
    Competitor ppl[5];

    FILE *f;

    if ((f = fopen("desetiboj.txt", "r")) == NULL)
    {
        printf("soubor IN se nepodařilo otevřít");
        return 1;
    }

    char line[100];
    int count = 0;
    while (fgets(line, 100, f) != NULL)
    {
        if (strlen(line) > 1)
        {
            printf("%d %s", count, line);

            strncpy(ppl[count].name, line, 10);
            char *spacepos = strstr(ppl[count].name, " ");
            if (spacepos == NULL)
            {
                printf("error");
                return 1;
            }

            ppl[count].score = 0;
            int scores[10];
            sscanf(spacepos, "%d%d%d%d%d%d%d%d%d%d", &scores[0], &scores[1], &scores[2], &scores[3], &scores[4], &scores[5], &scores[6], &scores[7], &scores[8], &scores[9]);
            for (size_t i = 0; i < 10; i++)
            {
                ppl[count].score += scores[i];
            }
            
            // char *start = strstr(line, " ");
            // while (start != NULL)
            // {
            //     char *end = strstr(start + 1, " ");
            //     if (end != NULL) {
            //         end = '\0';
            //     }
            //     else {
            //         printf("endnull");
            //     }
            //     ppl[count].score += atoi(start);
            //     printf("(%d)", atoi(start));
            //     start = end;
            // }

            count++;
        }
    }

    for (size_t i = 0; i < count; i++)
    {
        printf("%s %d\n", ppl[i].name, ppl[i].score);
    }
}