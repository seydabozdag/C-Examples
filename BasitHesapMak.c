#include<stdio.h>
#include<conio.h>

int main() {
    double sayi1, sayi2;
    char islem;

    printf("Bu basit bir hesap makinesidir. \n");
    printf("Lutfen ilk sayiyi giriniz: \n");
    scanf("%lf", &sayi1);

    printf("Islemi seciniz : toplama(+), cikarma(-), carpma(*), bolme(/)\n");
    printf("Isleminiz=");
    scanf(" %c", &islem);
    printf("Ikinci sayiyi giriniz:");
    scanf("%lf", &sayi2);

    switch(islem) {
        case '+':
            printf("Sonuc=%.2f", sayi1+sayi2);
            break;

        case '-':
            printf("Sonuc=%.2f", sayi1-sayi2);
            break;

        case '*':
            printf("Sonuc=%.2f", sayi1*sayi2);
            break;

        case '/':
                if(sayi2==0) {
                printf("Sayi 0'a bolunemez");
                break;
                }
            printf("Sonuc=%.2f", sayi1/sayi2);
            break;

        default:
            printf("Yanlis karakter girdiniz.");
    }

    getch();
    return 0;
}
