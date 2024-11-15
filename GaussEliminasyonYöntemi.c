#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10

void gaussEliminasyon(float a[MAX][MAX], int n) {
  int i, j, k;

  float oran;

  for(i = 0; i < n - 1; i++) {
    for(j = i + 1; j < n; j++) {
      if(a[i][i] == 0.0) {
        printf("Sifira bolme hatasi\n");
        exit(0);
      }

      oran = a[j][i] / a[i][i];

      for(k = 0; k <= n; k++) {
        a[j][k] -= oran * a[i][k];
      }
    }
  }

  float x[MAX];
  x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

  for(i = n - 2; i >= 0; i--) {

    x[i] = a[i][n];

    for(j = i + 1; j < n; j++) {

      x[i] -= a[i][j] * x[j];

    }

    x[i] /= a[i][i];
  }

  printf("Cozumler:\n");
  
  for(i = 0; i < n; i++) {
    printf("x[%d] = %.2f\n", i + 1, x[i]);
  }

}

int main() {
  float a[MAX][MAX];

  int n, i, j;

  printf("Denklem sisteminin boyutunu giriniz:\n");
  scanf("%d", &n);

  printf("Katsayilar matrisini giriniz (Ax = B formunda):\n");

  for(i = 0; i < n; i++) {
    for(j = 0; j <= n; j++) {
      printf("a[%d][%d] = ", i, j);
      scanf("%f", &a[i][j]);
    }
  }

  gaussEliminasyon(a, n);

  return 0;
}
