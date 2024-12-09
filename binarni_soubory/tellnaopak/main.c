#include <stdio.h>

int main()
{
    FILE *f, *g;

    f = fopen("input.txt", "rb");
    if (f == NULL)
        return 1;

    g = fopen("output.txt", "wb");
    if (g == NULL)
        return 1;

    fseek(f, 0, SEEK_END);
    unsigned size = ftell(f);

    for (size_t i = 0; i < size; i++)
    {
        char c;
        fseek(f, size - i - 1, SEEK_SET);
        fread(&c, sizeof(char), 1, f);

        fwrite(&c, sizeof(char), 1, g);
    }
    fclose(f);
    fclose(g);
}