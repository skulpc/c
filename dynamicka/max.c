#include <stdio.h>

int main()
{
    int pocet = 0;
    int *pa, *pmax;
    pa = (int *)malloc(sizeof(int));
    if (pa == NULL)
    {
        printf("fuck\n");
        return 1;
    }
    pmax = (int *)malloc(sizeof(int));
    if (pmax == NULL)
    {
        printf("fuck\n");
        return 1;
    }
    while (1)
    {
        printf("hodnota:", pocet);
        scanf("%d", pa);
        if (*pa == 0) break;
        if (*pa > *pmax)
        {
            *pmax = *pa;
        }
    };
    printf("max:%d", *pmax);

    free((void *) pa);
    pa = NULL;
    free((void *) pmax);
    pmax = NULL;
}