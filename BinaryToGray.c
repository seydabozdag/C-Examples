#include<stdio.h>
#include<stdlib.h>

// Binary'den Gray'e dönüştürme fonksiyonu
unsigned int binaryToGray(unsigned int n) {
    
    if (!n)
      return 0;
    int a = n % 10;
    int b = (n / 10) % 10;
    if ((a && !b) || (!a && b))
      return (1 + 10 * binaryToGray(n / 10));
    return (10 * binaryToGray(n / 10));

}

int main() {
    unsigned int binary, gray;

    printf("Binary sayi giriniz: ");
    scanf("%u", &binary);

    gray = binaryToGray(binary);
    printf("Gray kodu: %u\n", gray);

    return 0;

}

