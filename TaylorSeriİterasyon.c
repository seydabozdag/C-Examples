#include<stdio.h>
#include<math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float f(float a) {
  return cos(a);
}

int main () {
  double toplam, x, y;
  int i, n, k, is, c, j, aci;
  printf("Polinomun derecesini giriniz: ");
  scanf("%u", &n);
  printf("Yaklasik degeri hesaplanacak aciyi giriniz: ");
  scanf("%d", &aci);

  x = aci * M_PI / 180;
  toplam = 1; is = -1;
  for (i = 2; i <= n; i += 2) {
    c = 1;
    for (j = 1; j <= i; j++) {
      c *= j;
    }

    y = (pow(x, i) / c) * is;
    toplam += y;
    is *= -1;
  }

  printf("Yaklasik deger: cos(%d) = %f\n", aci, toplam);
  printf("Gercek deger: cos(%d) = %f\n", aci, f(x));
  printf("Hata: %f\n", fabs(toplam - f(x)));

  return 0;
}