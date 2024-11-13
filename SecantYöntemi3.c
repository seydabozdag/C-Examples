#include<stdio.h>
#include<math.h>

double F(double x) {
  return log(x) - cos(x);
}

int main() {
  double x0 = 2.5, x1 = 3, x2, epsilon = 0.001;
  int i = 0;

  printf("Yonteme basladigimiz noktalar: x0 = %.4lf ve x1 =  %.4lf\n", x0, x1);

  do {
    x2 = x1 - ((F(x1) * (x0 - x1)) / (F(x0) - F(x1)));

    x0 = x1;
    x1 = x2;
    i++;

    printf("%d. iterasyonda yaklasik deger: %.4lf\n", i, x2);

  } while(fabs(x0 - x1) > epsilon);

  printf("Yaklasik kok %d. iterasyonda hesaplanmistir.\n", i);
  printf("Yaklasik kok: %.4lf\n", x2, F(x2));
  printf("F(%.4lf) = %.4lf\n", x2, F(x2));

  return 0;
}