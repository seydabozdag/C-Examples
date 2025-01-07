#include<stdio.h>
#include<stdlib.h>
#include<math.h>


float f(float a) {
  return 1/a;
}

int main() {
  float *x, *y, p, c, xt;
  char cevap;
  int i, j, n;
  printf("Lagrange Interpolasyonu\n");
  printf("Kac nokta gireceksiniz?: ");
  scanf("%d", &n);

  x = (float*)malloc(n*sizeof(float));
  y = (float*)malloc(n*sizeof(float));

  for (i = 0; i < n; i++) {
    printf("%d. noktanin x degeri: ", i+1);
    scanf("%f", &x[i]);
    printf("%d. noktanin y degeri: ", i+1);
    scanf("%f", &y[i]);
  }

  do {
    printf("Hangi noktadaki degeri bulmak istiyorsunuz?:");
    scanf("%f", &xt);
    p = 0;
    for(i = 0; i < n; i++) {
      c = 1;
      for(j = 0; j < n; j++) {
        if(i != j) {
          c = c * (xt - x[j]) / (x[i] - x[j]);
        }
        p = p + c * y[i];
      }
      
    }

    printf("\nTahmini deger: %f\n", p);
    printf("Gercek deger: %f\n", f(xt));
    printf("Hata: %f\n", fabs(f(xt) - p));

  } while (0); 
  
  free(x);
  free(y);

  return 0;

}