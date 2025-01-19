#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int faktoriyel(int a) {
    int i, faktoriyel = 1;
    for (i = 1; i <= a; i++) {
        faktoriyel *= i;
    }
    return faktoriyel;
}

int main() {
    int n, i, j;
    printf("Kac adet nokta oldugunu giriniz: ");
    scanf("%d", &n);

    float X[n], Y[n][n], bx, h, s;

    printf("Yaklasik degerini bulmak istediginiz x degerini giriniz: ");
    scanf("%f", &bx);

    for (i = 0; i < n; i++) {
        printf("%d. noktadaki x degerini giriniz: ", i + 1);
        scanf("%f", &X[i]);
        printf("%d. noktadaki y degerini giriniz: ", i + 1);
        scanf("%f", &Y[i][0]);
    }

    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            Y[j][i] = Y[j][i - 1] - Y[j - 1][i - 1];
        }
    }

    printf("\nGeri Farklar Tablosu\n");
    printf("          xi          yi = f(xi)");
    for (i = 1; i < n; i++) {
        printf("      %d. Geri Fark", i);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("    %10.1f", X[i]);
        for (j = 0; j <= i; j++) {
            printf("%15.5f", Y[i][j]);
        }
        printf("\n");
    }

    s = Y[n - 1][0]; 
    h = X[1] - X[0]; 

    for (i = 1; i < n; i++) {
        float carp = 1.0;
        for (j = 0; j < i; j++) {
            carp *= (bx - X[n - 1 - j]);
        }
        s += (carp * (Y[n - 1][i] / (pow(h, i) * faktoriyel(i))));
    }

    printf("\nSonuc: P(%.2f) = %f\n", bx, s);

    return 0;
}
