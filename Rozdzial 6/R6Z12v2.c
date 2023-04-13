#include <stdio.h>

int main(void)
{

    int limit, licznik, x, liczniknowy, liczniknowy2;
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
            for (suma = 0, licznik = 1, i = 2.0; licznik <= limit; licznik++, i++)                //sumuje liczby dodanie
            {

                for ( liczniknowy = 1; licznik%2 == 0 && liczniknowy <=1; liczniknowy++ )
                    suma = suma + 1.0/i;
                
                for ( liczniknowy2 = 1; licznik%2 == 1 && liczniknowy2 <=1; liczniknowy2++ )
                    suma = suma - 1.0/i;

            }

        printf("Suma składników ciągu jest równa %.10lf\n", suma);
        printf("Podaj limit wyrazow [liczba ujemna żeby zakończyć]\n");
        scanf("%d", &limit);
    }
    return 0;
}