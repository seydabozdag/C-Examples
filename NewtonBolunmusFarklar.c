#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  int n, i, j;
  printf("Kac adet nokta oldugunu giriniz: ");
  scanf("%d", &n);

  float *X = (float*)malloc(n*sizeof(float));
  float **Y = (float**)malloc(n*sizeof(float*));
  for (i = 0; i < n; i++) {
    Y[i] = (float*)malloc(n*sizeof(float));
  }

  float bx, s;
  printf("Yaklasik degeri bulunacak x degerini giriniz: ");
  scanf("%f", &bx);

  for (i = 0; i < n; i++) {
    printf("%d. noktadaki x degerini giriniz: ", i + 1);
    scanf("%f", &X[i]);
    printf("%d. noktadaki y degerini giriniz: ", i + 1);
    scanf("%f", &Y[i][0]);
  }

  for (i = 1; i < n; i++) {
    for (j = 0; j < n - i; j++) {
      Y[j][i] = (Y[j + 1][i - 1] - Y[j][i - 1]) / (X[j + i] - X[j]);
    }
  }

  printf("\nNewton Bolunmus Farklar Tablosu\n");
  for (i = 0; i < n; i++) {
    printf("%5.2f ", X[i]);
    for (j = 0; j < n - i; j++) {
      printf("%10.6f ", Y[i][j]);
    }
    printf("\n");
  }

  printf("\nP(x) = ");
  for (i = 0; i < n; i++) {
    if (i > 0)
      printf(" + ");
    printf("(%.6f)", Y[0][i]);
    for (j = 0; j < i; j++) {
      printf(" * (x - %.2f)", X[j]);
    }
  }

  s = Y[0][0];
  for (i = 1; i < n; i++) {
    float carp = 1.0;
    for (j = 0; j < i; j++) {
      carp *= (bx - X[j]);
    }
    s += Y[0][i] * carp;
  }
  
  printf("\n\nSonuc: P(%.6f) = %.6f\n", bx, s);

  for (i = 0; i < n; i++) {
    free(Y[i]);
  }

  free(Y);
  free(X);

  return 0;
}
