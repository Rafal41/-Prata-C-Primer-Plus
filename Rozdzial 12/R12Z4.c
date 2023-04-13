#include <stdio.h>

int * zwrot(int * licznik);
int main(void)
{
    int liczbawyw;
    int * wynik;
    int wsk = 0;

    puts("podaj liczbe wywolań: ");
    scanf("%d", &liczbawyw);
    for (int i = 0; i < liczbawyw; i++)
        wynik = zwrot(&wsk);   
    printf("Funkcja zwrot() została wywołana %d razy\n", *wynik);
    printf("wsk  = %d\n", wsk);
    return 0;
}

int * zwrot(int * licznik)
{
    *licznik += 1;
    return licznik;
}


