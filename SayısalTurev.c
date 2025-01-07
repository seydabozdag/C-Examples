#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double Fonksiyon(double z) {
  return exp(2*z);
}

double FT(double z) {
  return 2*exp(2*z);
}

int main() {
  double x, h, gercek_deger, mutlak_hata1, mutlak_hata2, mutlak_hata3, i;
  printf("h degerini giriniz: ");
  scanf("%lf", &h);
  printf("Birinci Turevi alinacak istediginiz x degerini giriniz: ");
  scanf("%lf", &x);

  for (i = x - h; i <= x + h + 1e-9; i = i + h)
  printf("f(%.3lf) = %.3lf\n", i, Fonksiyon(i));
  gercek_deger = FT(x);
  
  double birinciTurev_ileri = (Fonksiyon(x+h) - Fonksiyon(x)) / (h);
  double birinciTurev_geri = (Fonksiyon(x) - Fonksiyon(x-h)) / (h);
  double birinciTurev_merkezi = (Fonksiyon(x+h) - Fonksiyon(x-h)) / (2*h);

  mutlak_hata1 = fabs(gercek_deger - birinciTurev_ileri);
  mutlak_hata2 = fabs(gercek_deger - birinciTurev_geri);
  mutlak_hata3 = fabs(gercek_deger - birinciTurev_merkezi);

  printf("Gercek Deger = %.3lf\n", gercek_deger);
  printf("Birinci Turev (Ileri) = %.3lf\n", birinciTurev_ileri);
  printf("Birinci Turev (Geri) = %.3lf\n", birinciTurev_geri);
  printf("Birinci Turev (Merkezi) = %.3lf\n", birinciTurev_merkezi);

  printf("Mutlak Hata (Ileri) = %.3lf\n", mutlak_hata1);
  printf("Mutlak Hata (Geri) = %.3lf\n", mutlak_hata2);
  printf("Mutlak Hata (Merkezi) = %.3lf\n", mutlak_hata3);

  return 0;
}