#include<stdio.h>

int main(){ 
    int sayi, ters=0, temp, rem; 
    printf("Bir sayi giriniz : ");
    scanf("%d", &sayi);
    
    temp = sayi;
    while(temp>0)
    {
        rem = temp%10;
        ters = (ters*10)+rem;
        temp = temp/10;
    }
    if(ters == sayi)
        printf("Palindromdur");
    else
        printf("Palindrom degildir.");
}