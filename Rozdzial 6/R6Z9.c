#include <stdio.h>
#include <string.h>
double dzialanie (double a, double b);
int main(void)
{
    
    double a, b ;
    int x, y ; 
    
    do   
    {
        printf("Podaj pierwsza liczbe\n");
        x = scanf("%lf", &a);
        printf("Podaj drugą liczbe\n");
        y = scanf("%lf", &b);
        dzialanie (a, b);
        printf("%lf\n", dzialanie (a, b));
    } while (x == 1, y == 1);
    return 0;
}
double dzialanie (double a, double b)
{
    double wynik;
    wynik = (a - b)/(a * b);
    return wynik;
}