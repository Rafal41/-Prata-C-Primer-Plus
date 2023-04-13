#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void zamiana(char *);
int main (void)
{
    char liczba[sizeof(long)*8];

    puts("Podaj liczbe w postaci binarnej (sekwencja 0 i 1)");
    scanf("%s", liczba);

    for (int i = 0; i < strlen(liczba); i++)
    {
        if (liczba[i] != '0' && liczba[i] != '1')
        {
            puts("niepoprawnie podane dane - ciag wejsciowy ma sie skladac wylacznie ze znakow 0 i 1");
            puts("Podaj liczbe w postaci binarnej (sekwencja 0 i 1)");
            scanf("%s", liczba);
            i = 0;
        }
    }

    zamiana(liczba);
    return 0;
}
void zamiana(char * wsk)
{
    unsigned int dlugosc;
    unsigned int suma = 0;
    
    dlugosc = strlen(wsk) - 1;
    //printf("dlugosc  = %u\n", dlugosc);

    for (int i = 0; i <= dlugosc; i++)
    {
        if (wsk[i] == '1')
            suma += pow(2, dlugosc - i);
    }
    printf("Wartosc binarna = %s, wartosc liczbowa = %u\n", wsk, suma);
}