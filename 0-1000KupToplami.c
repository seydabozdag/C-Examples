#include<stdio.h>
#include<stdlib.h>
int main() {
    int x,a,b,c,d;
    for (x=0;x<=999;x++){
        a=x/100;
        b=(x/10)%10;
        c=(x%10)%10;
        d=(a*a*a)+(b*b*b)+(c*c*c);	
            if (x==d) {	
            printf("%d\n",x);	
        } 
    }		
    return 0;
}
