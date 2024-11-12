#include<stdio.h>
#include<math.h>

double g(double x) {
  return (pow(x,3) + 1) / 2;
}

int main() {
  double x0, x1, epsilon = 0.002;
  int i = 0;

  printf("Baslangic degeri (x0) giriniz: ");
  scanf("%lf", &x0);

  x1 = g(x0);

  while (fabs(x1 - x0) >= epsilon) {

    x0 = x1;
    x1 = g(x0);

    i++;

    printf("Iterasyon %d:  x = %.4lf\n", i,x1);
  }

  printf("\nBulunan kok yaklasik olarak: %.4lf\n", x1);
  printf("Toplam iterasyon sayisi: %d\n", i);

  return 0;

}


