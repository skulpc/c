#include <stdio.h>
typedef int TPole[256];
typedef char TRet[40];


// nadefinuj fci co zjisti cetnost pismen v retezci
void fce(TPole *cetnost, TRet r) {
    for (size_t i = 0; i < sizeof(cetnost) / sizeof(cetnost[0]); i++)
    {
        cetnost[i] = 0;
    }
    
    for (size_t i = 0; i < sizeof(r) / sizeof(r[0]); i++)
    {
        if (r[i] == '\0') {
            return;
        }
        cetnost[r[i]] += 1;
    }
    return;
}

int main () {
    TPole pole;
    fce(pole, "jhtegbciazbp til");
    for (size_t i = 0; i < sizeof(pole) / sizeof(pole[0]); i++)
    {
        if (pole[i] != 0) {

        printf("%c: %d", i, pole[i]);
        }
    }
    
}
