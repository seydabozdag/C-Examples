#include<stdio.h>
#include<math.h>

double F(double x) {
  return x + log(x) - 5;
}

double FT(double x) {
  return 1 + (1 / x);
}

int main() {
  double x0 = 3.2, x, epsilon = 0.001;
  int i = 0;

  printf("Yonteme basladigimiz nokta: %.4lf\n", x0);
  
  do {
    x = x0;
    x0 = x - F(x) / FT(x);
    
    printf("%d. Iterasyon: x = %.4lf\n", i+1, x0);

    i++;

  } while (fabs(x0 - x) > epsilon);

  printf("\nBulunan kok yaklasik olarak: %.4lf\n", x0);
  printf("Toplam iterasyon sayisi: %d\n", i);

  return 0;

}