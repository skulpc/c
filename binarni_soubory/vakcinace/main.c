#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Osoba
{
    char jmeno[20];
    int cis_poj;
    int vek;
    int vakc;
} TOsoba;
typedef char TNazev[36];

FILE *new_file(TNazev filename)
{
    printf("novy soubor?:");
    char c;
    scanf("%c", &c);

    if (c == 'y')
    {
        FILE *f;
        if ((f = fopen(filename, "wb")) != NULL)
        {
            return f;
        }
        else
        {
            printf("nemozne otevrit soubor %s", filename);
            exit(1);
        }
    }
}

void write_struct(TOsoba input, FILE *f)
{
    fwrite(&input.jmeno, sizeof(input.jmeno), 1, f);
    fwrite(&input.cis_poj, sizeof(input.cis_poj), 1, f);
    fwrite(&input.vek, sizeof(input.vek), 1, f);
    fwrite(&input.vakc, sizeof(input.vakc), 1, f);
}

void registrace(TNazev filename)
{
    TOsoba new;
    printf("jmeno:");
    scanf("%20s", new.jmeno);
    printf("cis_poj:");
    scanf("%d", &new.cis_poj);
    printf("vek:");
    scanf("%d", &new.vek);
    new.vakc = 0;

    FILE *f;
    if ((f = fopen(filename, "ab")) == NULL)
    {
        printf("nemozne otevrit soubor %s", filename);
        exit(1);
    }

    write_struct(new, f);
    fclose(f);
}

TOsoba read_struct(FILE *f)
{
    TOsoba output;
    fread(&output.jmeno, sizeof(output.jmeno), 1, f);
    fread(&output.cis_poj, sizeof(output.cis_poj), 1, f);
    fread(&output.vek, sizeof(output.vek), 1, f);
    fread(&output.vakc, sizeof(output.vakc), 1, f);
    return output;
}

void vypis(TNazev filename)
{
    int v;
    printf("jaky stav vas zajima (0, 1, 2; 3-all):");
    scanf("%d", &v);

    FILE *f;
    if ((f = fopen(filename, "rb")) == NULL)
    {
        printf("nemozne otevrit soubor %s", filename);
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    fseek(f, 0, SEEK_SET);

    printf("ftell:%d, size %d, sizeof: %d\n", ftell(f), size, sizeof(TOsoba));
    while (ftell(f) <= size - sizeof(TOsoba))
    {
        TOsoba read = read_struct(f);
        // printf("ftell:%d, size %d, sizeof: %d  --  ", ftell(f), size, sizeof(TOsoba));
        if (read.vakc == v || v == 3)
        {
            printf("jmeno:%s; ", read.jmeno);
            printf("cis_poj:%d; ", read.cis_poj);
            printf("vek:%d; ", read.vek);
            printf("vakc:%d\n", read.vakc);
        }
    }
}

void vakcinace(TNazev filename) {
    printf("pass\n");
}

int main()
{
    printf("nazev souboru:");
    TNazev filename;
    scanf("%s", filename);
    if (strcmp(filename, "xx") == 0)
        strcpy(filename, "data.dat");
    printf("filename:%s\n", filename);

    // fseek(stdin, 0, SEEK_END);

    int akce = 0;
    while (akce != 5)
    {
        printf("jakou akci chcete provest?\n");
        printf("1) Registrace\n2) vypis\n3) novy soubor\n4) vakcinace\n5) exit\nakce: ");
        scanf("%d", akce);

        switch (akce)
        {
        case 1:
            registrace(filename);
            break;
        case 2:
            vypis(filename);
            break;
        case 3:
            new_file(filename);
            break;
        case 4:
            vakcinace(filename);
            break;

        default:
            break;
        }
    }
}