#include <stdio.h>
#include <math.h>

double enax(float x, float pr)
{
  if (x == 0)
    return 1;

  double out = 1;
  size_t i = 1;
  double Sp;
  double Sn = 1;
  size_t Fp = 1;
  do
  {
    Sp = Sn;

    size_t Fn = Fp * i;
    Fp = Fn;

    Sn = (pow(x, i) / (double)Fn);
    printf("Sn = pow(%f,%d) / %f\n", x, i, (double)Fn);
    out += Sn;

    printf("%f - %f\n", Sn, Sp);

    i++;
  } while (pr > Sn - Sp);

  return out;
}

int main()
{
  double arr[11] = {1, 2.718282, 7.389056, 20.085537, 54.59815, 148.41316, 403.4288, 1096.6332, 2980.958, 8103.084, 22026.466};
  for (size_t i = 0; i < 11; i++)
  {
    printf("%3d %f (%f)\n", i, enax(i, 0.1), arr[i]);
  }
}