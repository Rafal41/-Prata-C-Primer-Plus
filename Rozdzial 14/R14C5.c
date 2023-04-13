#include <stdio.h>
#include "R14Z5.h"

extern struct dane rok[];
int wyswietldane(int numermsc)
{
    int wynik = 0;

    // if (numermsc = 1)
    //     wynik = 31;
    // else if (numermsc = 2)
    //     wynik = 28;
    // //etc.

    // switch (numermsc)
    // {
    //     case 1 :
    //         wynik = 31;
    //     case 2 :
    //         wynik = 31 + 28; 
    //     //etc.  
    // }

    for (int i = 0; i < numermsc; i++)
        wynik += rok[i].dni;
    return wynik;
}