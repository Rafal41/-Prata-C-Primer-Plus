#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define ROZMIAR 16


char * wczytaj(char * st, int n); // funkcja wczytująca łańcuchy
int konwdoint(char * st);
int odrzlan (char *st);
int potega(int podstawa, int potega);

int main(void)
{
    char lancuch[ROZMIAR];
    

    int dlg;
    int liczba;

    //pobieranie liczby
    puts("Wprowadz liczbę całkowitą");
    while (wczytaj(lancuch, ROZMIAR) != NULL)
    {
        puts(lancuch);

        if (odrzlan(lancuch)) //odrzucanie złych łańcuchów
        {
            liczba = konwdoint(lancuch);
            printf("liczba to %d\n", liczba);
        }
        else    
            puts("podano złą wartość");

        puts("Wprowadz następną liczbę całkowitą. CTRL+Z kończy");
    }
   
    return 0;
}


int odrzlan (char *st)
{
    int i;

    if (!isdigit(st[0]) && st[0] != '-')
        return 0;
    for (i = 1; i < strlen(st); i++)
    {
        if(!isdigit(st[i]))        
            return 0;
    }
  
    return 1;
}

int konwdoint(char * st)
{
    int dlg;
    int i,j;
    int wynik = 0;

    dlg = strlen(st);
    if (st[0] == '-')
    {
        for (i = 1, j = dlg - 2; i < dlg; i++, j--)
        {
            //wynik = wynik + pow(10,j)*(st[i]-'0');
            wynik = wynik + potega(10,j)*(st[i]-'0');
        }
        wynik = wynik * (-1);
    }

    else // isdigit(st[0])
    {
        for (i = 0, j = dlg - 1; i < dlg; i++, j--)
            //wynik = wynik + pow(10,j)*(st[i]-'0');
            wynik = wynik + potega(10,j)*(st[i]-'0');
    }
    
    return wynik;


}

int potega(int podstawa, int potega)
{
    int licznik;
    int wynik = 1;

    for (licznik = 0 ; licznik < potega; licznik++)
        wynik = wynik*podstawa;
    
    return wynik;

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