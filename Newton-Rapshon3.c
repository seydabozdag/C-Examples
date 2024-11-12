#include<stdio.h>
#include<math.h>

double F(double x) {
  return pow(x, 3) + 7 * pow(x, 2) - 5 * x - 20;
}

double FT(double x) {
  return 3 * pow(x, 2) + 14 * x -5;
}

int main() {
  double x0 = 8, x, epsilon = 0.000001;
  int i = 0;

  printf("Yonteme basladigimiz nokta: %.7lf\n", x0);
  
  do {
    x = x0;
    x0 = x - F(x) / FT(x);
    
    printf("%d. Iterasyon: x = %.7lf\n", i, x0);

    i++;

  } while (fabs(x0 - x) > epsilon);

  printf("\nBulunan kok yaklasik olarak: %.7lf\n", x0);
  printf("Toplam iterasyon sayisi: %d\n", i);

  return 0;

}