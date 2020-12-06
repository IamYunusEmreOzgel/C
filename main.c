#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"TURKISH");
    float a , b , c , x ;
    printf("a degerini giriniz.\a\n");
    scanf("%f" , &a);
    printf("b degerini giriniz.\a\n");
    scanf("%f" , &b);
    printf("c degerini giriniz.\a\n");
    scanf("%f" , &c);
    printf("x degerini giriniz.\a\n");
    scanf("%f" , &x);
    float sonuc = a*x*x + b*x + c;
    printf("Denklemin sonucu= %f ",sonuc );
    return 0;
}


