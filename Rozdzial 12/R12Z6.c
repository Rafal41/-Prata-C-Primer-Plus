//kompilowac z plikiem rzutkosc.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rzucaj(void);
int liczba_rzutow = 0;

int main(void)
{
    int wynik;
    int suma;
    int licznik1 = 0, licznik2 = 0, licznik3 = 0, licznik4 = 0, licznik5 = 0, licznik6 = 0, licznik7 = 0, licznik8 = 0, licznik9 = 0, licznik10 = 0;
    
    for (int i = 0; i < 10; i++)
    {
        
        srand ((unsigned int) time(0));
        for (int rzuty = 0; rzuty < 100; rzuty++)
        {
            wynik = rzucaj();
            if (wynik == 1)
                licznik1++;
            else if (wynik == 2)
                licznik2++;
            else if (wynik == 3)
                licznik3++;
            else if (wynik == 4)
                licznik4++;
            else if (wynik == 5)
                licznik5++;
            else if (wynik == 6)
                licznik6++;
            else if (wynik == 7)
                licznik7++;
            else if (wynik == 8)
                licznik8++;
            else if (wynik == 9)
                licznik9++;
            else    
                licznik10++;
        }
    }   
    suma = licznik1 + licznik2 + licznik3 + licznik4 + licznik5 + licznik6 + licznik7 + licznik8 + licznik9 + licznik10;
    printf("Funkcja rzucaj() została wywołana %d razy\n", liczba_rzutow);
    printf("Ilosc rzutow = %d \n", suma);
    printf("liczba 1 - wylosowano %d razy \n", licznik1);
    printf("liczba 2 - wylosowano %d razy \n", licznik2);
    printf("liczba 3 - wylosowano %d razy \n", licznik3);
    printf("liczba 4 - wylosowano %d razy \n", licznik4);
    printf("liczba 5 - wylosowano %d razy \n", licznik5);
    printf("liczba 6 - wylosowano %d razy \n", licznik6);
    printf("liczba 7 - wylosowano %d razy \n", licznik7);
    printf("liczba 8 - wylosowano %d razy \n", licznik8);
    printf("liczba 9 - wylosowano %d razy \n", licznik9);
    printf("liczba 10 - wylosowano %d razy \n", licznik10);
    
    return 0;
}

int rzucaj(void)
{
        ++liczba_rzutow;
        return rand() % 10 + 1;
}


