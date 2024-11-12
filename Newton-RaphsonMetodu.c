#include <stdio.h>
#include <math.h>

double F(double x)
{
  return exp(x) - 3 * x;
}

double FT(double x)
{
  return exp(x) - 3;
}

int main()
{
  double x0, x;
  double epsilon = 0.00001;
  int i = 0;

  x0 = 0;

  do
  {

    x = x0;
    x0 = x - F(x) / FT(x);
    printf("Iterasyon %d: x = %.6lf\n", i + 1, x);

    i++;

  } while (fabs(x - x0) > epsilon);

  printf("\nBulunan kok yaklasik olarak: %.6lf\n", x);
  printf("Toplam iterasyon sayisi: %d\n", i);

  return 0;
}
