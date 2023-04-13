#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DLWIERSZ 256
int main(int argc, char *argv[])
{
    
    double liczba;
    FILE *fz; // plik zrodlowy
    FILE *fd; // plik docelowy
    FILE *ft; // plik testowy
    FILE *wp; //tworzymy plik binarny
  

    if (argc != 3)
    {
        printf("Podano złą liczbę argumentów.\n");
        printf("Sposób uzycia %s znak nazwa_pliku\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    //najpierw stworzymy plik binarny
    if ((wp = fopen("mds", "wb")) == NULL)
    {
        printf("Nie mozna otworzyc mds");
        exit(EXIT_FAILURE);
    }
    printf("Podaj liczbę zmiennoprzecinkową do zapisania q konczy\n");
            while (scanf("%lf", &liczba) == 1)
                fwrite(&liczba, sizeof(double), 1, wp);

    fclose(wp);

    //tera go otworzymy 
    if ((fz = fopen(argv[1], "rb")) == NULL)
    {
        printf("Nie mozna otworzyc %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    // if (setvbuff(wp, NULL, _IOFBF, DLWIERSZ) != 0)
    // {
    //     fputs("Nie mozna utworzyc bufora wejsciowego\n", stderr);
    //     exit (EXIT_FAILURE);
    // }     

    if ((fd = fopen(argv[2], "wb")) == NULL)
    {
        printf("Nie mozna otworzyc %s", argv[2]);
        exit(EXIT_FAILURE);
    } 

    // a tera pokopiujemy
    while (fread(&liczba, sizeof(double), 1, fz) > 0)
        fwrite(&liczba, sizeof(double), 1, fd);

    fclose(fz);
    fclose(fd);


    //sprawdzenie czy sie skopiowalo
    if ((ft = fopen(argv[2], "rb")) == NULL)
    {
        printf("Nie mozna otworzyc %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fread(&liczba, sizeof(double), 1, ft) > 0)  
            printf("liczba= %lf\n", liczba);
   
    fclose(ft);     
   
    
    return 0;
}
