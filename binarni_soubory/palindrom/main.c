#include <stdio.h>

int main()
{
    FILE *f;
    f = fopen("slovo.txt", "rb");
    if (f == NULL)
    {
        printf("gr\n");
        return 1;
    }
    fseek(f, 0, SEEK_END);
    unsigned size = ftell(f);

    for (size_t i = 0; i < size / 2; i++)
    {
        char c;
        fseek(f, i, SEEK_SET);
        fread(&c, sizeof(char), 1, f);
        char d;
        fseek(f, size-i-1, SEEK_SET);
        fread(&d, sizeof(char), 1, f);

        if (c != d)
        {
            printf("neni palindrom\n");
            printf("%c != %c\n", c, d);
            fclose(f);
            return 0;
        }
    }
    printf("je palindrom\n");
    fclose(f);
}