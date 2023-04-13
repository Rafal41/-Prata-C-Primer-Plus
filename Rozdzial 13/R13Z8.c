#include <stdio.h>
#include <stdlib.h>
void liczbawyst(FILE *wskplik, char *nazwapliku, char *znak);
int main(int argc, char *argv[])
{
    
    char ch1 = '1';
    char ch2 = '1';
    FILE *wp; 
    char nazwa[40];
  

    if (argc == 1)
    {
        printf("Podano złą liczbę argumentów.\n");
        printf("Sposób uzycia %s znak nazwa_pliku (nazwa_pliku) ... \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else if (argc == 2)
    {
        printf("Wybrano interaktywny sposób podawania nazw plików \n");
        printf("Proszę podać nazwę pliku, który chcesz otworzyć.\n");
        while (scanf("%s",nazwa) != EOF)
        {
            if ((wp = fopen(nazwa, "r")) == NULL)
            {
                fprintf(stderr, "Nie mozna otworzyc pliku %s",nazwa);
                printf("Proszę podać nazwę kolejnego pliku, który chcesz otworzyć. CTRL+Z żeby zakończyć\n");
                continue;
            }

            liczbawyst(wp, nazwa, argv[1]);

            fclose(wp);

            printf("Proszę podać nazwę pliku, który chcesz otworzyć. CTRL+Z żeby zakończyć\n");
        }
    }
    else // argc > 2
    {
        for (int i = 2; i < argc; i++)
        {
            if ((wp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Nie mozna otworzyc pliku %s",argv[i]);
                printf("Przechodzę do następnego pliku\n");
                continue;
            }

            liczbawyst(wp, argv[i], argv[1]);

            fclose(wp);

        }
    }
    return 0;
}

void liczbawyst(FILE *wskplik, char *nazwapliku, char *znak)
{
    char ch;
    int licznikznk = 0;

    while ((ch = getc(wskplik)) != EOF)
        if (ch == *znak)
            licznikznk++;
    
    printf("Szukany znak %c występuje %d razy w pliku %s \n", *znak, licznikznk, nazwapliku );
}
