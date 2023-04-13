#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void iloscbit(int n);
int main (void)
{
    int liczba;

    puts("Podaj dowolną liczbe całkowitą");
    scanf("%d", &liczba);
    iloscbit(liczba);
    return 0;
}
void iloscbit(int n)
{
    int stopien = n;
    int k = 0;
    int wynik = 0;
    int licznik = 0;

    while (stopien >= 1)
    {
        stopien /= 2;
        k++;
    }

    for (int i = 0; i < k; i++, n >>= 1)
        {
            wynik = 0x1 & n;
                if (wynik)
                    licznik++;
        }

    printf("ilosc wystąpien 1 w cyfrze = %d", licznik);
}