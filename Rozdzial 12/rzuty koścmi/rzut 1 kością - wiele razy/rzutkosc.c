// kompilowac z plikiem wielerzut.c
#include <stdio.h>
#include <stdlib.h>
#include "rzutkosc.h"

int liczba_rzutow = 0; //zmienna statyczna z łącznoscią zewnetrzną (static with external linkage)

int rzucaj_n_razy(int rzuty, int scianki);
static int rzucaj(int scianki);


int rzucaj_n_razy(int rzuty, int scianki)
{
    int suma = 0;

    // if (scianki < 2)
    // {
    //     printf("wymagane są co najmniej 2 scianki\n");
    //     return -2;
    // }

    // if (rzuty < 1)
    // {
    //    printf("wymagany jest co najmniej 1 rzut\n"); 
    //    return -1; 
    // }


    for (int i = 0; i < rzuty; i++)
        suma += rzucaj(scianki);

    return suma;
}

int rzucaj(int scianki)
{
        ++liczba_rzutow;
        return rand() % scianki + 1;
}