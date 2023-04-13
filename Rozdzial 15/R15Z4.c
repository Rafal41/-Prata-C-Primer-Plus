#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void bit(int n, int bitnr);
int main (void)
{
    int liczba;
    int iloscbitow = 0;
    int stopien;
    int nrbitu;

    puts("Podaj dowolną liczbe całkowitą");
    scanf("%d", &liczba);
    
    stopien = liczba;
    while (stopien >= 1)
    {
        stopien /= 2;
        iloscbitow++;
        //printf("stopien = %d, iloscbitow = %d\n", stopien, iloscbitow);
    }
    puts("A teraz kolej na numer bitu (numeracja od prawej do lewej, bit najbardziej z prawej to bit zerowy)");
    printf("Podaj dowolną liczbe całkowitą z przedziału od 0 do %d\n", iloscbitow - 1);
    scanf("%d", &nrbitu);
    
    while (nrbitu < 0 && nrbitu > iloscbitow)
        {
            puts("niepoprawnie podany numer bitu");
            printf("Podaj dowolną liczbe całkowitą z przedziału od 0 do %d\n", iloscbitow - 1);
            scanf("%d", &nrbitu);
        }

    bit(liczba, nrbitu);
    return 0;
}
void bit(int n, int bitnr)
{
    int wynik = 0;
    int wartosc;



    n >>= bitnr;
    wynik = 0x1 & n;
        if (wynik == 1)
            putchar('1');
        else 
            putchar('0');

    wartosc = wynik * pow(2,bitnr);

    printf("\nA wartosc przechowywana pod tym bitem to %d", wartosc);
}