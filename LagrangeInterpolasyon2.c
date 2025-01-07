#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  float *x, *y, p, c, xt;
  int i, j, n;

  printf("Lagrange Interpolasyonu\n");
  printf("Kac nokta gireceksiniz?: ");
  scanf("%d", &n);

  x = (float *)malloc(n * sizeof(float));
  y = (float *)malloc(n * sizeof(float));

  for (i = 0; i < n; i++)
  {
    printf("%d. noktanin x degeri: ", i + 1);
    scanf("%f", &x[i]);
    printf("%d. noktanin y deger: ", i + 1);
    scanf("%f", &y[i]);
  }

  printf("Hangi noktadaki degeri bulmak istiyorsunuz?: ");
  scanf("%f", &xt);

  p = 0;
  for (i = 0; i < n; i++)
  {
    c = 1;
    for (j = 0; j < n; j++)
    {
      if (i != j)
      {
        c = c * (xt - x[j]) / (x[i] - x[j]);
      }
    }
    p = p + c * y[i];
  }

  printf("\nTahmini deger: %f\n", p);

  free(x);
  free(y);

  return 0;
}