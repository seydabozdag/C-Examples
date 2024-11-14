#include<stdio.h>
#include<math.h>


double determinant(double M[3][3]) {
  return  M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]) 
        - M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0]) 
        + M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);
}

void matrisYaz(double N[3][3]) {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%.3lf ", N[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
  double A[3][3], B[3], tempA[3][3], detA, x[3];
  int i, j, t, s;

  A[0][0] = 2; A[0][1] = -1; A[0][2] = -1; B[0] = 2;
  A[1][0] = 4; A[1][1] = 1;  A[1][2] = -1; B[1] = -5;
  A[2][0] = 6; A[2][1] = -2; A[2][2] = 2;  B[2] = 17;

  printf("Katsayilar matrisi: ");
  matrisYaz(A);
  printf("B sonuc matrisi:\n");
  for(i = 0; i < 3; i++) {
    printf("%.3lf\n", B[i]);
  }

  printf("-------------------------\n");

  detA = determinant(A);
  printf("A matrisinin determinanti: %.3lf\n", detA);

  if(detA == 0) {
    printf("Matrisin determinanti sifir, cozum yoktur.\n");
    return 0;
  }


  for (i = 0; i < 3; i++) {

    for (t = 0; t < 3; t++) {

      for (s = 0; s < 3; s++) {

        tempA[t][s] = A[t][s];

      }

    }

    for (j = 0; j < 3; j++) {
      tempA[j][i] = B[j];
    }

    x[i] = determinant(tempA) / detA;
    printf("%d. sutun elemanlari ile B matrisinin elemanlari yer degistirdi: ", i+1);
    matrisYaz(tempA);
      
  }

  printf("Sonuclar:\n");
  for(i = 0; i < 3; i++) {

    printf("x[%d] = %.3lf\n", i+1, x[i]);

  }

  return 0;

}


