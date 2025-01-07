#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double Fonksiyon(double z) {
  if (z == 0) {
    printf("Hata: Sifira bolme yapilamaz.\n");
    exit(EXIT_FAILURE);
  }
  return 1 / z;
}

double Fonk_Int(double z) {
  if (z <= 0) {
    printf("Hata: Logaritma negatif veya sifir degeri alamaz.\n");
    exit(EXIT_FAILURE);
  }
  return log(z);
}

double alt(double B[], double hh, int x) {
  int j; 
  double IA = 0;
  for (j = 0; j <= x - 2; j++) {
    IA += B[j];
  }
  IA *= hh;
  return IA;
}

double ust(double B[], double hh, int x) {
  int j; 
  double IU = 0;
  for (j = 1; j <= x - 1; j++) {
    IU += B[j];
  }
  IU *= hh;
  return IU;
}

double yamuk(double B[], double hh, int x) {
  int j;
  double IY = 0;
  for (j = 1; j <= x - 2; j++) {
    IY += 2 * B[j];
  }
  IY += B[0] + B[x - 1];
  IY *= (hh / 2);
  return IY;
}

int main() {
  double a = 1, b = 2, h, i, gercek_deger, mutlak_hata1, mutlak_hata2, mutlak_hata3, Y[11];
  int n = 10, j = 0;

  h = (b - a) / n;

  for (i = a, j = 0; j <= n; i += h, j++) {
    Y[j] = Fonksiyon(i);
    printf("F(%.2lf) = %lf\n", i, Y[j]);
  }

  gercek_deger = Fonk_Int(b) - Fonk_Int(a);
  printf("\nGercek Deger = %lf\n", gercek_deger);

  double IDA = alt(Y, h, n + 1);
  printf("Alt dikdortgenler toplami = %lf\n", IDA);

  double IDU = ust(Y, h, n + 1);
  printf("Ust dikdortgenler toplami = %lf\n", IDU);

  double IDY = yamuk(Y, h, n + 1);
  printf("Yamuklar toplami = %lf\n", IDY);

  mutlak_hata1 = fabs(gercek_deger - IDA);
  mutlak_hata2 = fabs(gercek_deger - IDU);
  mutlak_hata3 = fabs(gercek_deger - IDY);

  printf("\nMutlak Hata (Alt) = %lf\n", mutlak_hata1);
  printf("Mutlak Hata (Ust) = %lf\n", mutlak_hata2);
  printf("Mutlak Hata (Yamuk) = %lf\n", mutlak_hata3);

  if (fabs(gercek_deger) < 1e-9) {
    printf("\nGercek Deger sifira yakin oldugu icin yuzde bagil hata hesaplanamaz.\n");
  } else {
    printf("\nYuzde Bagil Hata (Alt) = %lf\n", (mutlak_hata1 / fabs(gercek_deger)) * 100);
    printf("Yuzde Bagil Hata (Ust) = %lf\n", (mutlak_hata2 / fabs(gercek_deger)) * 100);
    printf("Yuzde Bagil Hata (Yamuk) = %lf\n", (mutlak_hata3 / fabs(gercek_deger)) * 100);
  }

  return 0;
}
