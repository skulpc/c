#include <stdio.h>

int main()
{
    float x;
    printf("x: ");
    scanf("%f", &x);

    unsigned stupen;
    printf("stupen: ");
    scanf("%d", &stupen);

    int koef[20];

    for (size_t i = 0; i < stupen + 1; i++)
    {
        size_t ii = stupen - i;
        printf("□x^%d: □ = ", ii);
        scanf("%d", &koef[ii]);
    }

    float out;
    for (size_t i = 0; i < stupen + 1; i++)
    {
        size_t ii = stupen - i;
        
        if (i == 0) {
            out = koef[ii];
            printf("opsano %d\n", out);
            continue;
        }
        else {
            out = x * out + koef[ii];
        }
    }
    printf("out: %d", out);
}

// stupen | n_koef
// 2    | 3
// 3    | 4
