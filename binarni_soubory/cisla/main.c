#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *f;
    int x;

    f = fopen("cisla.dat", "wb");
    if (f == NULL)
        return 1;

    srand(time(NULL));

    for (size_t i = 0; i < 0x0F; i++)
    {
        x = rand() % 100;
        if (fwrite(&x, sizeof(x), 1, f) != 1)
        {
            printf("shit");
        }
    }
    fclose(f);

    f = fopen("cisla.dat", "rb");
    if (f == NULL)
        return 1;

    srand(time(NULL));

    for (size_t i = 0; i < 0x0F; i++)
    {
        if (fread(&x, sizeof(x), 1, f) != 0)
        {
            printf("%d ", x);
        }
    }
    fclose(f);

    f = fopen("cisla.dat", "r");
    if (f == NULL)
        return 1;

    srand(time(NULL));

    while (fscanf(f, "%c", &x) != EOF)
    {
        printf("%c ", x);
    }

    fclose(f);

    f = fopen("cisla.txt", "rb+");

    while (fread(&x, sizeof(int), 1, f) != 0)
    {
        x*=2;
        fseek(f, -(int)sizeof(int), SEEK_CUR);
        fwrite(&x, sizeof(int), 1, f);
        fseek(f, 0, SEEK_CUR);
    }
    fclose(f);

    printf("succ");
}