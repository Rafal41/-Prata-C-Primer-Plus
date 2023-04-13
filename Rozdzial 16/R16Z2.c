#include <stdio.h>
#define SRHARM(X,Y) (1/(1/(X) + 1/(Y)))
int main(void)
{
    float a = 5.0;
    float b = 10.0 ;
    float wynik = 0.0;


    wynik = 1/(1/a + 1/b);
    printf("wynik = %.2f\n", wynik);
    printf("wynik makro = %.2f\n", SRHARM(a,b));

    return 0;
}