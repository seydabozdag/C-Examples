#include<stdio.h>
#include<math.h>

double F(double x) {
  return pow(x, 3) - 20;
}

int main() {
  double x0 = 2.5, x1 = 3, x2;
  int i = 0;

  printf("Iterasyonlar:\n");

  for (i = 0; i < 2; i++) {
    x2 = x1 - ((F(x1) * (x0 - x1)) / (F(x0) - F(x1)));

    printf("Iterasyon %d: x2 = %.4lf\n", i+1, x2);

    x0 = x1;
    x1 = x2;

  }

  printf("Yaklasik kok: %.4lf\n", x2);
  printf("F(%.4lf) = %.4lf\n", x2, F(x2));

  return 0;
}