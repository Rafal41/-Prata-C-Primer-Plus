#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    
    unsigned long liczba, dzielnik;
    bool pierwsza;
   
    printf("Podaj dowolną liczbę naturalną [q żeby zakończyć]\n");

    while ( scanf("%ld", &liczba) == 1)
    {
        for (dzielnik = 2, pierwsza = true; (dzielnik*dzielnik) <= liczba; dzielnik++)
            {
                if ( liczba % dzielnik == 0 )
                {   
                    pierwsza = false;
                    if ( (liczba/dzielnik) != dzielnik)
                        printf("Liczba %ld ma nastepujace dzielniki %ld i %ld \n", liczba, dzielnik, liczba/dzielnik);
                    else   
                        printf("Liczba %ld ma nastepujacy dzielnik %ld \n", liczba, dzielnik);
                }
            }
    if (pierwsza)
        printf("liczba %ld jest liczbą pierwszą\n", liczba);

    printf("Podaj następną liczbę naturalną [q żeby zakończyć]\n");
    }
    
    return 0;
}