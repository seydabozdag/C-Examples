#include<stdio.h>
#include<math.h>

double F(double x) {
  return x + log(x) - 5;
}

int main() {
  double a=3.2, b=4, x, x0, x1, epsilon = 0.0001;
  int i = 0;

  if(F(a) * F(b) >= 0) {
    printf("%.4lf ve %.4lf arasinda kok yoktur  ", a, b);
    return 0;
  }  

  x0 = (a * F(b) - b * F(a)) / (F(b) - F(a));

  do {
    i++;
    printf("%d. adimda yaklasik kok: %.4lf\n", i, x0);
    x1 = x0;

    if(F(x0) * F(a) < 0) {
      b = x0;
    } else {
      a = x0;
    }

    printf("Yeni aralik: [%.4lf, %.4lf]\n", a,b);

    x0 = (a * F(b) - b * F(a)) / (F(b) - F(a));
  } while(fabs(x0 - x1) > epsilon);

  printf("Yaklasik kok %d. adimda hesaplanmistir.\n", ++i);
  printf("Yaklasik kok: %.4lf\n", x0);
  printf("F(%.4lf) = %.4lf\n", x0, F(x0));
  
  return 0;

}

