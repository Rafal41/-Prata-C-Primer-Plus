#include <stdio.h>
#include <string.h>
//#define PCTPR 10/100 ;
//#define PCTZL 5/100 ;
int main(void)
{
    const float WKLAD = 100.00; 
    const float PCTPR = (10.00/100.00);
    const float PCTZL = (5.00/100.00);
    int i;
    float sumaE, sumaK; 

    for (sumaE=WKLAD, sumaK=WKLAD, i =1 ; sumaE >= sumaK; i++)
    {
        sumaE = sumaE + WKLAD*PCTPR;
        sumaK = sumaK + sumaK*PCTZL;
        printf("EWA   KASIA \n");
        printf("%5.2f %5.2f \n", sumaE, sumaK);

    }
    printf("%d", i-1);

    return 0;
}
