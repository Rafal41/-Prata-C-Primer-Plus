#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DLW 255
int main(int argc, char *argv[])
{
    
    FILE *wp; 
    char wiersz[DLW];
  

    if (argc != 3)
    {
        printf("Podano złą liczbę argumentów.\n");
        printf("Sposób uzycia %s lancuch nazwa_pliku \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if ((wp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Nie mozna otworzyc pliku %s",argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((fgets(wiersz, DLW, wp)) != NULL) 
    {
        //fputs(wiersz,stdout);
        if (strstr(wiersz, argv[1]) != NULL)
            fputs(wiersz, stdout);
    }

    if (ferror(wp) != 0)
    {
        puts("Błąd odczytu pliku");
    }
    fclose(wp);
    return 0;
}
