//manuet.c - - techniki realizacji menu
#include <stdio.h>


char pobierz_wybor(void);       //obsluga menu
char pobierz_pierwszy(void);    //sprawdza poprawnosc danych wejsciowych do menu
int pobierz_int(void);          //sprawdza poprawnosc danych wejsciowych do funkcji liczącej
void liczenie(void);            //procedura licząca

int main(void)
{
    int wybor;

    while ((wybor = pobierz_wybor()) != 'q')
    {
         switch (wybor) 
         {
            case 'a': 
                printf("Kup po niskiej cenie, sprzedaj po wysokiej. \n");
                break;
            case 'b': 
                putchar('\a');
                break;
            case 'c': 
                liczenie();
                break;
            default:
                printf("Błąd programu! \n");
                break;
         }  
    }
    printf("Koniec.\n");
    return 0;
}          

char pobierz_wybor(void)
{
    int ch;

    printf("Wpisz wybraną literę: \n");
    printf("a. porada           b. alarm \n");
    printf("c. liczenie         q. koniec \n");

    ch = pobierz_pierwszy();

    while ( (ch < 'a' || ch > 'c') && ch != 'q')
    {
      printf("Wpisz a, b, c lub q.\n");
      ch = pobierz_pierwszy();
    }
    return ch;
}

char pobierz_pierwszy(void)
{
    int ch;

    ch = getchar();

    while (getchar() != '\n')
        continue;

    return ch;
}

void liczenie(void)
{
    int n, i;

    printf("Jak długo liczyć? Podaj liczbę całkwitą:\n");
    n = pobierz_int();

    for (i=1; i <= n; i++)
        printf("%d\n", i);
    
    while (getchar() != '\n')
        continue;
}

int pobierz_int(void)
{
    int we;
    char ch;

    while (scanf("%d", &we) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);  //pomija błędne dane wejściowe
        printf(" nie jest liczbą całkowitą. \nProszę podać wartość całkowitą: ");
    }
    return we;
}

