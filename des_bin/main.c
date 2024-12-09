#include <stdio.h>
#include <string.h>

void des_bin(unsigned in, char out[17])
{
    out[16] = '\0';
    for (size_t i = 0; i < 16; i++)
    {
        printf("%d %d\n", in, in % 2);
        out[15 - i] = (in % 2) + '0';
        in = in / 2;
        // if (in == 0)
        // {
        //     // out = strstr(out, "1");
        //     break;
        // }
    }
}

int main()
{
    char out[17];
    des_bin(24, out);
    printf("0b%s", out);
}