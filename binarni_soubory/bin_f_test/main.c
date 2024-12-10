#include <stdio.h>

void jedna()
{
    FILE *f;

    f = fopen("text.txt", "rb");
    if (f == NULL)
    {
        printf("soubor se nepodarilo otevrit\n");
        return;
    }

    char c;
    while (fread(&c, sizeof(c), 1, f))
    {
        putchar(c);
    }
}

void dva()
{
    FILE *f, *g;

    f = fopen("text.txt", "rb");
    if (f == NULL)
    {
        printf("soubor in se nepodarilo otevrit\n");
        return;
    }
    g = fopen("encoded.txt", "wb");
    if (g == NULL)
    {
        printf("soubor out se nepodarilo otevrit\n");
        return;
    }

    char c;
    while (fread(&c, sizeof(c), 1, f))
    {
        putc((c > 32) ? c + 1 : c, g);
    }
    printf("succesfully wrote encoded.txt");
}

void tri()
{
    FILE *f;

    f = fopen("text.txt", "r");
    if (f == NULL)
    {
        printf("soubor se nepodarilo otevrit\n");
        return;
    }

    char c;
    while ((c = fgetc(f)) != EOF)
    {
        putchar(c);
    }
    
}

int main()
{
    printf("\n__jedna__\n");
    jedna();
    printf("\n__dva__\n");
    dva();
    printf("\n__tri__\n");
    tri();
}