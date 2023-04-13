//kompilowac z plikiem rzutkosc.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rzutkosc.h"

int main(void)
{
    int rzuty, scianki;
    int wynik;
    int status;

    srand ((unsigned int) time(0));
    printf("Podaj ilosc scian kostki. 0 oznacza koniec\n");
    while (scanf("%d", &scianki) == 1 && scianki > 0)
    {
        if (scianki < 2)
        {
            printf("wymagane są co najmniej 2 scianki\n");
            continue;
        }

        printf("Podaj ilosc rzutów\n");
        while ((status = scanf("%d", &rzuty)) != 1 || rzuty < 1)
        {
            if (rzuty < 1)
            {
                printf("wymagany jest co najmniej 1 rzut\n");
                continue;
            }
            if (status == EOF)
                break;
            else
            {
                printf("Nalezy podac liczbe calkowitą\n");
                while (getchar() != '\n')  
                    continue;
                printf("Podaj ilosc scian kostki. 0 oznacza koniec\n");
                continue;
            }
          

        }
        
        wynik = rzucaj_n_razy(rzuty, scianki);
        printf("Rzucono %d razy kostką która miała %d scianek. Łaczny wynik z kostek to %d\n", rzuty, scianki, wynik);
        printf("Podaj ilosc scian kostki. 0 oznacza koniec\n");  
    }
    printf("Funkcja rzucaj() została wywołana %d razy\n", liczba_rzutow);
    return 0;
}

