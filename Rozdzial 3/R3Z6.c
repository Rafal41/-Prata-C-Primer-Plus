
#include <stdio.h>
int main(void)                     
{
       float woda ; 
       printf("Podaj ilość wody w litrach \n");
       scanf("%f", &woda);
       printf("W %.3f litrach wody jest %le cząsteczek wody", woda, woda*(1000/3.0E-23));
       return 0;
}
