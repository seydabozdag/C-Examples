#include<stdio.h>
#include<math.h>

double F(double x) {
  return 2 * exp(x) - log(x) + x - 13.31;
}

double FT(double x) {
  return 2 * exp(x) - (1/x) + 1;
}

double FTT(double x) {
  return 2 * exp(x) + (1/pow(x, 2));
}

int main() {
  double a1, b1, a0 = 1.5, b0 = 2, epsilon = 0.0001;
  int i = 0;

  if((F(a0) * F(b0) >= 0)) {
    printf("%.4lf ve %.4lf arasinda kok yoktur.  ", a0, b0);
    return 0;
  }

  do {
    printf("-----------------------------\n");

    printf("F(%.4lf) = %.4lf\n", a0, F(a0));
    printf("F(%.4lf) = %.4lf\n", b0, F(b0));
  
    printf("F'(%.4lf) = %.4lf\n", a0, FT(a0));
    printf("F'(%.4lf) = %.4lf\n", b0, FT(b0));

    printf("F''(%.4lf) = %.4lf\n", a0, FTT(a0));
    printf("F''(%.4lf) = %.4lf\n", b0, FTT(b0));

    if((F(a0) * FTT(a0)) > 0) {
      a1 = a0 - (F(a0) / FT(a0));
      b1 = ((b0 * F(a0)) - (a0 * F(b0))) / (F(a0) - F(b0));
      printf("Teget(%.4lf, F(%.4lf)) noktasindan cizilmistir.\n\n", a0, a0);
    }

    if((F(b0) * FTT(b0)) > 0) {
      b1 = b0 - (F(b0) / FT(b0));
      a1 = ((a0 * F(b0)) - (b0 * F(a0))) / (F(b0) - F(a0));
      printf("Teget(%.4lf, F(%.4lf)) noktasindan cizilmistir.\n\n", b0, b0);
    }

    a0 = a1;
    b0 = b1;
    i++;

    printf("%d. iterasyonda yeni aralik = (%.4lf, %.4lf)\n", i, a1, b1);
    printf("-----------------------------\n");

  } while(fabs(a1 - b1) > epsilon);

  printf("Yaklasik kok %d. iterasyonda hesaplanmistir.\n", i);
  printf("Yaklasik kok = %.4lf\n", a1);
  printf("F(%.4lf) = %.4lf\n", a1, F(a1));
  
  return 0;
}