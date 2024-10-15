#include <stdio.h>

int main()
{
    printf("cislo: ");

    long long unsigned cislo;
    scanf("%d", &cislo);

    printf("\nprvocinitele: ");
    long long unsigned delene = cislo;
    for (long long unsigned i = 2; i <= cislo; i++)
    {
        while (delene % i == 0)
        {
            printf("%d, ", i);
            delene /= i;
        }
        if (delene == 1)
        {
            break;
        }
    }
}