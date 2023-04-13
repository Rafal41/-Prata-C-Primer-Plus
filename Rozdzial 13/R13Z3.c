#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main (void)
{
    int ch;
    FILE *pz;
    FILE *pd;
    char nazwa[40];
    unsigned long licznik = 0;

    printf("Podaj nazwe pliku tekstowego zrodlowego, który chcesz otworzyć\n");
    scanf("%s", nazwa);

    if ((pz = fopen(nazwa, "r")) == NULL)
    {
        printf("Ne mozna otworzyc %s\n", nazwa);
        exit(EXIT_FAILURE);
    }

    printf("Podaj nazwe pliku tekstowego docelowego, który chcesz otworzyć\n");
    scanf("%s", nazwa);

    if ((pd = fopen(nazwa, "w+")) == NULL)
    {
        printf("Ne mozna otworzyc %s\n", nazwa);
        exit(EXIT_FAILURE);
    }

    //kopiowanie zawartosci jednego pliku do drugiego
    while ((ch = getc(pz)) != EOF)
    {
        ch = toupper(ch);
        putc(ch,pd);
    }

    rewind(pd);
    //wyswietlanie zawartosci
    while ((ch = getc(pd)) != EOF)
    {
        putc(ch,stdout);
    }


    fclose(pz);
    fclose(pd);
    return 0;
}