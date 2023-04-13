#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define ROZMIAR 81
#define GRAN 10


char * wczytaj(char * st, int n); // funkcja wczytująca łańcuchy

char pobierz_wybor(void);       //obsluga menu
char pobierz_pierwszy(void);    //sprawdza poprawnosc danych wejsciowych do menu

void pierwlist(char lancuchy[][ROZMIAR], int rozmiar);  // funkcja wyswietla listę łańcuchów w kolejnosci pierwotnej
void strlan(char *lancuchy[], int num); //funkcja sortująca łańcuchy i wyswietlajaca posortowaną listę
void sortlen(char *lancuchy[], int num); //funkcja sortująca łańcuchy wedlug dlugosci (rosnąco)
void sortwordlen(char *lancuchy[], int num); //funkcja sortująca łańcuchy wedlug dlugosci pierwszego wyrazu (rosnąco)
int strl(const char *lan); // funkcja licząca dlugosc pierwszego wyrazu
void sort2str(char *lancuchy[], int dol, int szuk); // funckja sortująca dwa łańcuchy alfabetycznie

int main(void)
{
    char lancuch[GRAN][ROZMIAR];
    char * wsk[GRAN];
    int licz = 0; //licznik danych wejsciowych
    int k;      // licznik danych wyjsciowych

    int wybor; 

    //pobieranie łańcuchów
    printf("Wprowadz do %d wierszy. Aby zakończyć wciśnij ENTER na początku wiersza\n", GRAN);
    while (licz < GRAN && wczytaj(lancuch[licz], ROZMIAR) != NULL && lancuch[licz][0] != '\0')
    {
        wsk[licz] = lancuch[licz];
        licz++;
    }

    // wyswietlanie menu
    while ((wybor = pobierz_wybor()) != '5')
    {
         switch (wybor) 
         {
            case '1': 
                pierwlist(lancuch, licz);
                break;
            case '2': 
                strlan(wsk, licz);
                break;
            case '3': 
                sortlen(wsk, licz);
                break;
            case '4': 
                sortwordlen(wsk, licz);
                break;
            default:
                printf("Błąd programu! \n");
                break;
         }  
    }
    
    
    return 0;
}

void pierwlist(char lancuchy[][ROZMIAR], int rozmiar)
{
    int k;

    puts("Oto pierwotna lista:");
    for (k = 0; k < rozmiar; k++)
        puts(lancuchy[k]);
        putchar('\n');
}

void strlan(char *lancuchy[], int num)
{
    char *temp;
    int dol, szuk;
    int k;

    for (dol = 0; dol < num - 1; dol++)
        for (szuk = dol + 1; szuk < num; szuk++)
            if (strcmp(lancuchy[dol], lancuchy[szuk]) > 0)
            {
                temp = lancuchy[dol];
                lancuchy[dol] = lancuchy[szuk];
                lancuchy[szuk] = temp;
            }

    puts("Oto uporządkowana lista:\n");
    for (k = 0; k < num; k++)
        puts(lancuchy[k]);
    putchar('\n');
}

void sort2str(char *lancuchy[], int dol, int szuk)
{
    char *temp;

        if (strcmp(lancuchy[dol], lancuchy[szuk]) > 0)
        {
            temp = lancuchy[dol];
            lancuchy[dol] = lancuchy[szuk];
            lancuchy[szuk] = temp;
        }

}

void sortlen(char *lancuchy[], int num)
{
    char *temp;
    int dol, szuk;
    int k;

    for (dol = 0; dol < num - 1; dol++)
        for (szuk = dol + 1; szuk < num; szuk++)
            if (strlen(lancuchy[dol]) > strlen(lancuchy[szuk]))
            {
                temp = lancuchy[dol];
                lancuchy[dol] = lancuchy[szuk];
                lancuchy[szuk] = temp;
            }
            else if (strlen(lancuchy[dol]) == strlen(lancuchy[szuk]))
            {
                sort2str(lancuchy, dol, szuk);
                // if (strcmp(lancuchy[dol], lancuchy[szuk]) > 0)
                // {
                //     temp = lancuchy[dol];
                //     lancuchy[dol] = lancuchy[szuk];
                //     lancuchy[szuk] = temp;
                // }
            }
    puts("Oto uporządkowana lista:\n");
    for (k = 0; k < num; k++)
        puts(lancuchy[k]);
    putchar('\n');
}

void sortwordlen(char *lancuchy[], int num)
{
    char *temp;
    int dol, szuk;
    int k;

    for (dol = 0; dol < num - 1; dol++)
        for (szuk = dol + 1; szuk < num; szuk++)
        {
            if (strl(lancuchy[dol]) > strl(lancuchy[szuk]))
            {
                temp = lancuchy[dol];
                lancuchy[dol] = lancuchy[szuk];
                lancuchy[szuk] = temp;
            }
            else if (strl(lancuchy[dol]) == strl(lancuchy[szuk]))
            {
                sort2str(lancuchy, dol, szuk);
                // if (strcmp(lancuchy[dol], lancuchy[szuk]) > 0)
                // {
                //     temp = lancuchy[dol];
                //     lancuchy[dol] = lancuchy[szuk];
                //     lancuchy[szuk] = temp;
                // }
            }
        }
    puts("Oto uporządkowana lista:\n");
    for (k = 0; k < num; k++)
        puts(lancuchy[k]);
    putchar('\n');
}

int strl(const char *lan)
{
    int i=0;

    while (*lan != ' ' && *lan != '\0' )
    {
        i++;
        lan++;
    }
    //printf("%d",i);

    return i;
}

char * wczytaj(char * st, int n)
{
    char * wynik;
    int i = 0;

    wynik = fgets(st, n, stdin);
    if (wynik)
    { 
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] ='\0';
        else 
            while (getchar() != '\n')
                continue;
    }
    return wynik;
}
char pobierz_wybor(void)
{
    int ch;

    printf("Wpisz wybraną literę: \n");
    puts("1. Wyswietlanie pierwotnej listy łańcuchów");
    puts("2. Wyswietlanie łańcuchów w porządku ASCII");
    puts("3. Wyswietlanie łańcuchów według długości (rosnąco)");
    puts("4. Wyswietlanie łańcuchów według długości pierwszego słowa (rosnąco)");
    puts("5. koniec");

    ch = pobierz_pierwszy();

    while ( (ch < '1' || ch > '4') && ch != '5')
    {
      printf("Wpisz właściwą liczbę\n");
      ch = pobierz_pierwszy();
    }
    return ch;
}

char pobierz_pierwszy(void)
{
    int ch;

    ch = getchar();

    // while (isspace(ch))
    //     ch = getchar();

    while (getchar() != '\n')
        continue;

    return ch;
}



