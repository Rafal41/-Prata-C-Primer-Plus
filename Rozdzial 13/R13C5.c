#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DLWIERSZ 256
int main(int argc, char *argv[])
{
    
    char lancuch[DLWIERSZ];
    FILE *wp;
  

    if (argc != 3)
    {
        printf("Podano złą liczbę argumentów.\n");
        printf("Sposób uzycia %s znak nazwa_pliku\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strlen(argv[1]) != 1)
    {
        printf("Podano nieprawidlowy znak w pierwszym argumencie");
        exit(EXIT_FAILURE);
    }      
    if ((wp = fopen(argv[2], "r")) == NULL)
    {
        printf("Nie mozna otworzyc %s", argv[2]);
        exit(EXIT_FAILURE);
    } 

    // if (setvbuff(wp, NULL, _IOFBF, DLWIERSZ) != 0)
    // {
    //     fputs("Nie mozna utworzyc bufora wejsciowego\n", stderr);
    //     exit (EXIT_FAILURE);
    // }      
            
    while (fgets(lancuch, DLWIERSZ, wp) != NULL) 
    {
        if (strchr(lancuch, *argv[1]) != NULL)
            fputs(lancuch, stdout);
    }      
      
    fclose(wp);
    return 0;
}
