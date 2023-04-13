#include <stdio.h>
#include <string.h>
#define MILANAKM 1.609
#define GALONNALITR 3.785
int main()                     
{
       
       float dystans;
       float paliwo;
       float zuzycie;
       float zuzycieeur;
       printf("Ile mil przejechales?\n");
       scanf("%f", &dystans);
       printf("Ile galonow paliwa spaliles?\n");
       scanf("%f", &paliwo);

       zuzycie= dystans/paliwo;
       zuzycieeur= (1/zuzycie)*(GALONNALITR/MILANAKM)*100 ;
       printf("Zuzycie paliwa wynosi %.1f mile/galon. \n", zuzycie);

       printf("Zuzycie paliwa wynosi %.1f litrów/100km. \n", zuzycieeur);
       return 0;
}
