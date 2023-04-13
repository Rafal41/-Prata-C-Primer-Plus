#include <stdio.h>
#include <string.h>
int main(void)
{
    
    double a, b, wynik ;
    int x, y ; 
    
    do   
    {
        printf("Podaj pierwsza liczbe\n");
        x = scanf("%lf", &a);
        printf("Podaj drugą liczbe\n");
        y = scanf("%lf", &b);
        wynik = (a - b)/(a * b);
        printf("%lf\n", wynik);
    } while (x == 1, y == 1);
    return 0;
}