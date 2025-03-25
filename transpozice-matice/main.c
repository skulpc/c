#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int TPole[100][100];

void print_mat(TPole mat, int y_size, int x_size)
{
    for (size_t i = 0; i < y_size; i++)
    {
        printf("[");
        for (size_t u = 0; u < x_size; u++)
        {
            printf("%3d,", mat[i][u]);
        }
        printf("]\n");
    }
}

int main()
{
    srand(time(NULL));

    int y_size, x_size;

    printf("y:");
    scanf("%d", &y_size);

    printf("x:");
    scanf("%d", &x_size);

    TPole A;
    for (size_t i = 0; i < y_size; i++)
    {
        for (size_t u = 0; u < x_size; u++)
        {
            A[i][u] = rand() % 100 + 1;
        }
    }

    print_mat(A, y_size, x_size);
    printf("\n");

    TPole B;
    for (size_t i = 0; i < y_size; i++)
    {
        for (size_t u = 0; u < x_size; u++)
        {
            B[u][i] = A[i][u];
        }
    }

    print_mat(B, x_size, y_size);
}