#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    char ch1 = '1';
    char ch2 = '1';
    FILE *wp1, *wp2; 
  

    if (argc != 3)
    {
        printf("Podano złą liczbę argumentów.\n");
        printf("Sposób uzycia %s nazwa_pliku nazwa_pliku\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    //otwieramy dwa pliki
    if ((wp1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Nie mozna otworzyc pliku %s",argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((wp2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Nie mozna otworzyc pliku %s",argv[2]);
        exit(EXIT_FAILURE);
    }

    while (ch1 != EOF || ch2 != EOF)
    {
        while ((ch1 = getc(wp1)) != '\n' && ch1 != EOF)
            putchar(ch1);
        while ((ch2 = getc(wp2)) != '\n' && ch2 != EOF)
            putchar(ch2);
        putchar('\n');
    }

    fclose(wp1);
    fclose(wp2);
    
    return 0;
}
