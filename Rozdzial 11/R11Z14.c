#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int licznik;
    double podstawa = atof(argv[1]);
    int potega = atoi(argv[2]);
    double wynik = 1;
    
    if (podstawa == 0 && potega == 0)
         puts("symbol nieoznaczony");
    for (licznik = 0 ; licznik < potega; licznik++)
        wynik = wynik*podstawa;

    printf("%.3lf", wynik);
    return 0;
}
