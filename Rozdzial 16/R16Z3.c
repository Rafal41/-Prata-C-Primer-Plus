#include <stdio.h>
#include <math.h>
#define RADNAST 180/4 * atan(1)
#define STNARAD 4 * atan(1)/180


typedef struct biegun {
    double dlugosc;
    double kat;
} Biegun;
typedef struct kartez {
    double x;
    double y;
} Kartez;

Kartez bieg_na_kart(Biegun);


int main(void)
{
    Biegun wejscie;
    Kartez wyjscie;

    puts("podaj wspólrzedne biegunowe - najpierw dlugosc potem kat, q konczy");
    while (scanf("%lf %lf", &wejscie.dlugosc, &wejscie.kat ) == 2)
    {
        wyjscie = bieg_na_kart(wejscie);
        printf("x = %.2lf, y = %.2lf\n", wyjscie.x, wyjscie.y);
        puts("podaj wspólrzedne biegunowe - najpierw dlugosc potem kat, q konczy");
    }
    
    return 0;
}


Kartez bieg_na_kart(Biegun data)
{
    Kartez wynik;

    if (data.dlugosc != 0)
    {
        wynik.x = data.dlugosc * cos(data.kat * STNARAD);
        wynik.y = data.dlugosc * sin(data.kat * STNARAD);
    }
    else 
    {
        wynik.x = 0;
        wynik.y = 0;
    }
    return wynik;
}