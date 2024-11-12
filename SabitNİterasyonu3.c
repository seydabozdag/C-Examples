#include<stdio.h>
#include<math.h>

double F(double x) {
  return cos(x);
}

int main() {

  #define PI 3.14159265358979323846

  double  x0 = 45 * PI / 180, x1; //Başlangıç değeri olarak kendisi 𝜋/4 vermiş.
  int i = 0;

  x1 = F(x0);

  for(i = 1; i < 7; i++) {
    x0 = x1;
    x1 = F(x0);

    printf("Iterasyon %d: x = %.6lf\n", i, x1);
  }

  printf("\nSonuc kok yaklasik olarak: %.6lf\n", x1);

  return 0;
}