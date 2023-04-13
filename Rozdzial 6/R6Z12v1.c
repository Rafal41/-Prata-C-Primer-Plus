#include <stdio.h>

int main(void)
{

    int limit, licznik, x;
    float i;
    double suma, sumad, sumau;

    printf("Dany jest ciąg + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...\n");
    printf("Podaj limit wyrazow\n");
    scanf("%d", &limit);

    while (limit > 0)
    {
            for (suma = 0, licznik = 1, i = 2.0; licznik <= limit; licznik++, i = i + 1.0)
            {
                suma = suma + 1.0/i;
                
            }
        printf("Suma składników ciągu jest równa %.10lf\n", suma);

        printf("Podaj limit wyrazow [liczba ujemna żeby zakończyć]\n");
        scanf("%d", &limit);
    }

//---------------------------------------------------------------------------

    printf("Dany jest ciąg - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...\n");
    printf("Podaj limit wyrazow\n");
    scanf("%d", &limit);

    while (limit > 0)
    {
            for (sumad = 0, licznik = 1, i = 3.0; licznik <= limit/2; licznik++, i = i + 2.0)                //sumuje liczby dodanie
            {
                sumad = sumad + 1.0/i;
                //printf("Suma składników ciągu jest równa %.10lf\n", sumad);
            }

            licznik = 1; // restart licznika

            while (limit % 2 == 1 && licznik <= ((limit/2) + 1))
            {
                for (sumau=0, licznik = 1, i = 2.0; licznik <= ((limit/2) + 1); licznik++, i = i + 2.0)                //sumuje liczby ujemne jezeli liczba wyrazow jest nieparzysta
                {
                    sumau = sumau - 1.0/i;
                    //printf("Suma składników ciągu jest równa %.10lf\n", sumau);
                }
            }

            licznik = 1; // restart licznika

            while (limit % 2 == 0 && licznik <= limit/2)
            {
                for (sumau=0, licznik = 1, i = 2.0; licznik <= limit/2; licznik++, i = i + 2.0)                //sumuje liczby ujemne jezeli liczba wyrazow jest parzysta
                {
                    sumau = sumau - 1.0/i;
                    //printf("Suma składników ciągu jest równa %.10lf\n", sumau);
                }
            }
            
        suma = sumad + sumau; 
        printf("Suma składników ciągu jest równa %.10lf\n", suma);

        printf("Podaj limit wyrazow [liczba ujemna żeby zakończyć]\n");
        scanf("%d", &limit);
    }
    return 0;
}