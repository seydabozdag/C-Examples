#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

void sifrele(char metin[], int anahtar); 
void coz(char metin[], int anahtar);

int main() {
    char metin[MAX_LENGTH];
    int anahtar, secim;

    printf("Lutfen bir metin giriniz: ");
    fgets(metin, MAX_LENGTH, stdin);

    printf("Lutfen bir anahtar giriniz: ");
    scanf("%d", &anahtar);

    printf("1. sifreleme\n2. coz\nseciminizi yapiniz: ");
    scanf("%d", &secim);

    switch(secim) {
        case 1:
            sifrele(metin, anahtar);
            break;
        case 2:
            coz(metin, anahtar);
            break;
        default:
            printf("Gecersiz secim yaptiniz. ");
    }

    return 0;
}

void sifrele(char metin[], int anahtar) {
    int i;
    for(i=0; i<strlen(metin); i++) {
        if(metin[i] >= 'a' && metin[i] <= 'z') {
            metin[i]=((metin[i] - 'a') + anahtar) % 26 + 'a';
        } else if(metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = ((metin[i] - 'A') + anahtar) % 26 + 'A';
        } 
    }
    printf("Sifrelenmis metin: %s\n", metin);
}

void coz(char metin[], int anahtar) {
    sifrele(metin, -anahtar);
}