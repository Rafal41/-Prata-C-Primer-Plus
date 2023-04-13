#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned int zamiana(char *);
void do_binar(unsigned int n);

int main (int argc, char * argv[])
{
    unsigned int liczba1, liczba2;  

    if (argc != 3)
    {
        puts("Podano niepoprawna liczbe argumentow. Sposób użycia - Nazwa Lancuch_Binarny1 Lancuch_Binarny2");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] != '0' && argv[1][i] != '1')
        {
            puts("niepoprawnie podane dane - ciag wejsciowy ma sie skladac wylacznie ze znakow 0 i 1");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < strlen(argv[2]); i++)
    {
        if (argv[2][i] != '0' && argv[2][i] != '1')
        {
            puts("niepoprawnie podane dane - ciag wejsciowy ma sie skladac wylacznie ze znakow 0 i 1");
            exit(EXIT_FAILURE);
        }
    }

    liczba1 = zamiana(argv[1]);
    liczba2 = zamiana(argv[2]);

    printf("liczba1 = %u, liczba2 = %u\n", liczba1, liczba2);
    printf("~liczba1 = %u, ~liczba2 = %u\n", ~liczba1, ~liczba2);
    
    printf("liczba1 & liczba2 = %u; liczba1 | liczba2 = %u; liczba1 ^ liczba2 = %u;\n", liczba1 & liczba2, liczba1 | liczba2, liczba1 ^ liczba2);
    printf("liczba1 & liczba2 binarnie = ");
    do_binar(liczba1 & liczba2);
    printf("\nliczba1 | liczba2 binarnie = ");
    do_binar(liczba1 | liczba2);
    printf("\nliczba1 ^ liczba2 binarnie = ");
    do_binar(liczba1 ^ liczba2);


    return 0;
}

unsigned int  zamiana(char * wsk)
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

    return suma;
}

void do_binar(unsigned int n)
{
    int r;

    r = n % 2;
    if (n >= 2)
        do_binar(n/2);
    putchar(r == 0 ? '0': '1');

    return;

}