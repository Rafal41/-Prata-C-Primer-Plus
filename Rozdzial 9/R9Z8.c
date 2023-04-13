// ten program zwraca wartość liczby podniesionej do potegi calkwitej
#include <stdio.h>
double potega (double a, int b);

int main(void)
{
    double x, xpot;
    int n;

    printf("Podaj liczbe oraz potege całkowitą, do ktorej podniesiona zostanie liczba\n");
    printf("Wpisz q zeby zakonczyc program\n");
    while (scanf("%lf %d",&x, &n) == 2)
    {
        xpot = potega(x,n);
        printf("%.3g do potegi %d to %.5g\n", x, n, xpot);
        printf("Podaj kolejną parę liczb lub wpisz q zeby zakonczyc program\n");
    }
    printf("Zycze milego dnia\n");
    return 0;
}

double potega (double a, int b)
{
    double pot = 1;
    int i;
    int wykl;
    
    if (a != 0)
    {
        if (b > 0)
        {
            for (i = 1; i <= b; i++)
                pot *=a;
        }
        else if (b < 0)
        {
            for (i = 1, wykl = -b; i <= wykl; i++)
                pot *=1/a;
        }
        else
            pot = 1;
    }
    else 
    {
        if (b != 0)
            pot = 0;
        else
        {
            printf("0 do potegi 0 to symbol nieoznaczony - nie da się tego wyliczyc. zamiast tego funkcja uzyje wartosci 1\n");
            pot = 1;
        }
    }


    return pot;
}