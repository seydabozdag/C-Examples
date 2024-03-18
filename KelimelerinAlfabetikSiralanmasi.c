#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int aMetin;
    printf("Lutfen kelime sayisini belirtiniz :\n");
    scanf("%d" , &aMetin);

    char Kelimeler[aMetin][100], k[100];
    int x,y;
    printf("\nLutfen keliemeleri giriniz: \n");
    for(x=0; x<aMetin; x++){
        scanf("%s", Kelimeler[x]);
    }
    
    printf("\nMetindeki kelimeler: ");
    for(x=0; x<aMetin; x++) {
        printf("\n%s" , Kelimeler[x]);
    }
    for(x=1; x<aMetin; x++) {
        for(y=1; y<aMetin; y++) {
            if (strcmp(Kelimeler[y-1], Kelimeler[y]) > 0) {
                strcpy(k, Kelimeler[y-1]);
                strcpy(Kelimeler[y-1], Kelimeler[y]);
                strcpy(Kelimeler[y], k);
            }
        }
    }

    printf("\n-------------------------------\n");
    printf("\nMetindeki Kelimelerin Alfabetik Olarak Siralanmis Hali: ");
    for(x=0; x<aMetin; x++) {
        printf("\n%s", Kelimeler[x]);
    }
    return 0;
}
