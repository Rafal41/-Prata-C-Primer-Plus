#include <stdio.h>
// funkcja wyswietlajaca znaki 
void rzad_zn(char ch, int column_i, int column_j); 
// funkcja pobierająca liczby całkowite
int pobierz_int(void);
// funkcja pobierająca znak
char pobierz_znak(void);

int main(void)
{
    char znak;
    int kolumna_i, kolumna_j;

    printf("Podaj znak i dwie liczby z przedziału od 1 do 10\n");
    printf("Najpierw podaj znak: \n");
    znak = pobierz_znak();
    printf("Teraz podaj pierwszą liczbę z przedziału od 1 do 10: \n");
    kolumna_i = pobierz_int();
    while (kolumna_i < 1 || kolumna_i > 10)
    {
        printf("Błędnie podana wartość. Podaj poprawną wartość\n");
            kolumna_i = pobierz_int();
    }
    printf("Teraz podaj drugą liczbę z przedziału od 1 do 10: \n");
    kolumna_j = pobierz_int();
    while (kolumna_j < 1 || kolumna_j > 10)
    {
        printf("Błędnie podana wartość. Podaj poprawną wartość\n");
            kolumna_j = pobierz_int();
    }


    rzad_zn(znak, kolumna_i, kolumna_j);
    return 0;
}
void rzad_zn(char ch, int column_i, int column_j)
{
    int i;

    for (i = 1; i < column_i; i++)
    {
        putchar(' ');
    }

    for (i = column_i; i <= column_j; i++)
    {
        putchar(ch);
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