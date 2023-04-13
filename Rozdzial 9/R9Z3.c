#include <stdio.h>
// funkcja wyswietlajaca znaki 
void wysw_znaki(char ch, int row, int col); 
// funkcja pobierająca liczby całkowite
int pobierz_int(void);
// funkcja pobierająca znak
char pobierz_znak(void);

int main(void)
{
    char znak;
    int wiersz, kolumna;

    printf("Podaj znak i dwie liczby z przedziału od 1 do 10\n");
    printf("Najpierw podaj znak: \n");
    znak = pobierz_znak();
    printf("Teraz podaj pierwszą liczbę z przedziału od 1 do 10: \n");
    wiersz = pobierz_int();
    while (wiersz < 1 || wiersz > 10)
    {
        printf("Błędnie podana wartość. Podaj poprawną wartość\n");
            wiersz = pobierz_int();
    }
    printf("Teraz podaj drugą liczbę z przedziału od 1 do 10: \n");
    kolumna = pobierz_int();
    while (kolumna < 1 || kolumna > 10)
    {
        printf("Błędnie podana wartość. Podaj poprawną wartość\n");
            kolumna = pobierz_int();
    }


    wysw_znaki(znak, wiersz, kolumna);
    return 0;
}
void wysw_znaki(char ch, int row, int col)
{
    int i,j;

    for (i=1; i <= row; i++)
    {
        for (j=1; j <= col; j++)
            putchar(ch);
        putchar('\n');
    }
}

char pobierz_znak(void)
{
    int ch;

    ch = getchar();
    while (ch < 32 || ch > 176)
    {
        printf("Podaj poprawny znak\n");
        ch = getchar();
    }
    while (getchar() != '\n')
        continue;
   
    return ch;
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