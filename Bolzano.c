#include <stdio.h>
#include <math.h>

double F(double x)
{
  return exp(x) - 3 * x;
}

void checkRoot(double a, double b)
{
  double Fa = F(a);
  double Fb = F(b);
  double epsilon = 1e-6;

  if (Fa * Fb < 0)
  {
    printf("[%.2f, %.2f] araliginda bir kok bulunmaktadir.\n", a, b);
  }
  else
  {
    printf("[%.2f, %.2f] araliginda bir kok bulunmamaktadir.\n", a, b);
  }
}

int main()
{
  double a, b;

  printf("Araligin baslangic degeri (a): ");
  scanf("%lf", &a);

  printf("Araligin bitis degeri (b): ");
  scanf("%lf", &b);

  checkRoot(a, b);
  return 0;
}