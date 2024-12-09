#include <stdio.h>

int je_prvocislo_basic(size_t x) {
    for (size_t i = 2; i < x / 2 + 1; i++)
    {
        if (x % i == 0) {
            return 0; 
        }
    }

    return 1;
}

void print_lower_ps_basic(size_t n){
    for (size_t i = 0; i < n; i++)
    {
        if (je_prvocislo_basic(i)) {
            printf("%d,", i);
        }
    }
}

int main() {
    for (size_t i = 0; i < 200; i++)
    {
        printf("%d %d - [", i, je_prvocislo_basic(i));
        print_lower_ps_basic(i);
        printf("\b]\n");
    }

    return 0;
}