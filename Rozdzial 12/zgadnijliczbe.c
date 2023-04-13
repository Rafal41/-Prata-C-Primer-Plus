#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void)
{
    unsigned int wynik;
    unsigned int wybor;

    srand ((unsigned int) time(0));
    printf("Zgadnij liczbę z przedziału od 1 do 10. Podanie liczby spoza zakresu zakończy program.\n");
    scanf("%u", &wybor);
    while (wybor > 0 && wybor < 11)
    {
        wynik = rand() % 10 + 1;
        if (wybor == wynik)
        {
            printf("Brawo! Zgadłeś poprawną liczbę. Ta liczba to %u %u\n", wybor, wynik);
            break;
        }
            
        printf("Niestety to nie ta liczba, zgaduj jeszcze raz. Podanie liczby spoza zakresu zakończy program.\n");
        while (getchar() != '\n')
            continue;
        scanf("%u", &wybor);
    }

    return 0;
}

