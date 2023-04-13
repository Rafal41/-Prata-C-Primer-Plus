// program przelicza wzrost na inne jednostki
#include <stdio.h>
#define CMST 1/30.48
#define CMCA  1/2.54
int main(void)                     
{
       float wzrost, stopy, cale;

       printf("Podaj swoj wzrost (wzrost <=0 przerywa program)\n");
       scanf("%f", &wzrost);
       while (wzrost > 0)
       {
       stopy = wzrost / CMST;
       cale = wzrost / CMCA;
       printf("%.1f cm to %.2f stopy lub %.2f cale\n", wzrost, stopy, cale);
       printf("Podaj nastepną wartosc\n");
       scanf("%f", &wzrost);
       }
       return 0;
}
