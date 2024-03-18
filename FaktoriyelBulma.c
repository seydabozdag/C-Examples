#include <stdio.h>
int main() {
    int n, i;
    unsigned long long fact = 1;
    printf("Sayi : ");
    scanf("%d", &n);
 
    // shows error if the user enters a negative integer
    if (n < 0)
        printf("Hata! Negatif sayilarda faktoriyel hesaplanamaz.");
    else {
        for (i = 1; i <= n; ++i) {
            fact *= i;
        }
        printf("%d sayisinin faktoriyeli  = %llu", n, fact);
    }
 
    return 0;
}