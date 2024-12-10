#include <stdio.h>

#define SIZE 5

int main()
{
    int *p;

    p = (int *)malloc(SIZE * sizeof(int));

    if (p == NULL)
    {
        printf("FAIL - not enough ram");
        return 1;
    }

    for (size_t i = 0; i < SIZE; i++)
    {
        p[i] = i;
    }

    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d, ", *(p + i));
    }

    printf("\n");

    p = (int *)realloc(p, (SIZE + 1) * sizeof(int));

    if (p == NULL)
    {
        printf("FAIL - not enough ram");
        return 1;
    }
    p[SIZE] = SIZE;

    for (size_t i = 0; i < SIZE + 1; i++)
    {
        printf("%d, ", p[i]);
    }

    free((void *) p);
    p = NULL;

    return 0;
}