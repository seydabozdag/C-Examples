#include<stdio.h>
#include<math.h>

double f(double x, double y) {
  return pow(x, 2) - 2 * x - y + 0.5;
}

double g(double x, double y) {
  return pow(x, 2) + (4 * pow(y, 2)) - 4;
}

double F(double x, double y) {
  return ((pow(x, 2) - y + 0.5) / 2);
}

double G(double x, double y) {
  return ((-1 * (pow(x, 2)) + (-4 * pow(y, 2)) + 8 * y + 4) / 8);
}

int main() {
  double x0 = 0, y0 = 1, x1, y1, epsilon = 0.0001;
  int i = 0;

  printf("Yonteme basladigimiz nokta = (%.4lf, %.4lf)\n", x0, y0);

  do {
    x1 = x0;
    y1 = y0;
    x0 = F(x1, y1);
    y0 = G(x1, y1);
    i++;

    printf("%d. iterasyonda yaklasik deger = (%.4lf, %.4lf)\n", i, x0, y0);

  } while((fabs(x1-x0) > epsilon) || (fabs(y1-y0) > epsilon));

  printf("Yaklasik kok x = %.4lf\n", x0);
  printf("Yaklasik kok y = %.4lf\n", y0);
  printf("f(%.4lf, %.4lf) = %.4lf\n", x0, y0, f(x0, y0));
  printf("g(%.4lf, %.4lf) = %.4lf\n", x0, y0, g(x0, y0));

  return 0;

}