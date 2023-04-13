#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    
    FILE *wp;
    double liczba;
    double suma = 0.0;
    int ilosc = 0;
    size_t bajty;

    //printf("rozmiar double %zd",sizeof(double));
    // tworzenie pliku binarnego
    wp = fopen("mds", "ab+");
    printf("Podaj liczbę zmiennoprzecinkową do zapisania q konczy\n");
            while (scanf("%lf", &liczba) == 1)
                fwrite(&liczba, sizeof(double), 1, wp);
    rewind(wp);
    while (fread(&liczba, sizeof(double), 1, wp) > 0)  
            printf("liczba= %lf\n", liczba);
   
    fclose(wp);

    
    return 0;
}
