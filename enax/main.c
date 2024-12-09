#include <stdio.h>
#include <math.h>

// #define PRINT (a){
//   #if DEBUG == 1
    
// }

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

    printf("fn = fp:%d * i:%d", Fp, i);
    size_t Fn = Fp * i;
    Fp = Fn;

    printf("Fn = %d\n", Fn);
    Sn = (pow(x, i) / ((double)Fn));
    printf("Sn = pow(%f,%d) / %f\n", x, i, (double)Fn);
    out += Sn;

    printf("Sn:%f - Sp:%f === %f\n", Sn, Sp, fabs(Sn - Sp));
    printf("out:%f\n\n", out);

    i++;
  } while (pr < fabs(Sn - Sp) || fabs(Sn - Sp) == 0);

  return out;
}

int main()
{
  double arr[11] = {1, 2.718282, 7.389056, 20.085537, 54.59815, 148.41316, 403.4288, 1096.6332, 2980.958, 8103.084, 22026.466};
  for (size_t i = 0; i < 8; i++)
  {
    printf("\n%3d %f (%f)\n\n\n\n", i, enax((float)i, 0.01), arr[i]);
  }
}