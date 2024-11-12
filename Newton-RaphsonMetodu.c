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
  double x0, x1;
  double epsilon = 0.00001;
  int i = 0;

  x0 = 0;

  do
  {

    x0 = x1;
    x1 = x0 - F(x0) / FT(x0);
    printf("Iterasyon %d: x = %.6lf\n", i + 1, x1);

    i++;

  } while (fabs(x1 - x0) > epsilon);

  printf("\nBulunan kok yaklasik olarak: %.6lf\n", x1);
  printf("Toplam iterasyon sayisi: %d\n", i);

  return 0;
}