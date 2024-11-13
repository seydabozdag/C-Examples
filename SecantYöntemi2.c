#include<stdio.h>
#include<math.h>

double F(double x) {
  return exp(-x) - x;
}

int main() {

  double x0 = 0, x1 = 1, x2, epsilon = 0.0001;
  int i = 0;

  printf("Yonteme basladigimiz noktalar: x0 = %.4lf x1 = %.4lf\n", x0, x1);

  do {
    x2 = x1 - ((F(x1) * (x0 - x1)) / (F(x0) - F(x1)));

    x0 = x1;
    x1 = x2;
    i++;
    
    printf("%d. adimda yaklasik deger: %.4lf\n", i, x2);

  } while(fabs(x0 - x1) > epsilon);

  printf("Yaklasik kok %d. adimda hesaplanmistir.\n", i);
  printf("Yaklasik kok: %.4lf\n", x2);
  printf("F(%.4lf) = %.4lf\n", x2, F(x2));

  return 0;

}