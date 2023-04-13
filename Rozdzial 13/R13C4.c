#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    
    FILE *wp;
    double liczba;
    double suma = 0.0;
    int ilosc = 0;

    if (argc > 2)
    {
        printf("Podano złą liczbę argumentów.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        if (argc == 2)
        {
            wp = fopen(argv[1], "rb");
            while (fread(&liczba, sizeof(double), 1, wp) > 0)
            {
                suma += liczba;
                ilosc++;
            }
            if (ferror(wp) != 0)
                fprintf(stderr, "Błąd odczytu pliku.\n");
            printf("Suma arytmetyczna podanych liczb wynosi %lf\n", suma/(double)ilosc);
        }
        else 
        {
            printf("Podaj liczbę zmiennoprzecinkową, z której program obliczy srednią arytmetyczną. q konczy\n");
            while (scanf("%lf", &liczba) == 1)
            {
                suma += liczba;
                ilosc++;
            }
            printf("Suma arytmetyczna podanych liczb wynosi %lf\n", suma/(double)ilosc);
        }
    }
    printf("Koniec \n");
    fclose(wp);
    return 0;
}
