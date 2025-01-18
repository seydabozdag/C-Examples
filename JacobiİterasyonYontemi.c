#include<stdio.h>
#include<math.h>

#define hata 0.0001

float f1(float a, float b, float c) {
  return (30 - (2 * b + 3 * c)) / 8;
}

float f2(float a, float b, float c) {
  return (1 - (a + 2 * c)) / -9;
}

float f3(float a, float b, float c) {
  return (31 - (2 * a + 3 * b)) / 6;
}

int main() {
  float x1 = 0, x2 = 0, x3 = 0, x1_new, x2_new, x3_new; 
  int i = 0;
  printf("Yonteme basladigimiz nokta: (%.4f, %.4f, %.4f)\n", x1, x2, x3);

  do
  {
    x1_new = x1;
    x2_new = x2;
    x3_new = x3;

    x1 = f1(x1_new, x2_new, x3_new);
    x2 = f2(x1_new, x2_new, x3_new);
    x3 = f3(x1_new, x2_new, x3_new);

    i++;
    printf("%d. iterasyon: (%.4f, %.4f, %.4f)\n", i, x1, x2, x3);
  } while ((fabs(x1_new - x1) > hata || fabs(x2_new - x2) > hata || fabs(x3_new - x3) > hata));
  
  printf("Yaklasik kok x1: %.4f\n", x1);
  printf("Yaklasik kok x2: %.4f\n", x2);
  printf("Yaklasik kok x3: %.4f\n", x3);

  return 0;
  
}
