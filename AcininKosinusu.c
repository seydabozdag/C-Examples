#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

double cosinus(double);
int main() {
    double derece, radyan;
    printf("Dereceyi giriniz(0-360 arasinda)=\n");
    scanf("%lf", &derece);
    radyan=derece/180*3,14;
    printf("cosinus %g = %.9f\n", derece, cosinus(radyan));
    system("pause");
    getch();
    return 0;
}

double cosinus(double radyan) {
    double k=1.0, i, sonuc=1.0, fakt=1, us=1.0;
    for(i=2.0;i<40;i+=2.0) {
        k=k*-1;
        fakt=fakt*i*(i-1);
        us*=radyan*radyan;

        sonuc+=k*us/fakt;
    }

    return sonuc;
}