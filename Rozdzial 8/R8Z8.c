//manuet.c - - techniki realizacji menu
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char pobierz_wybor(void);       //obsluga menu
char pobierz_pierwszy(void);    //sprawdza poprawnosc danych wejsciowych do menu
float pobierz_float(void);          //sprawdza poprawnosc danych wejsciowych do funkcji liczącej
void dodawanie(void);            //procedura licząca
void odejmowanie(void);    
void mnozenie(void);    
void dzielenie(void);    

int main(void)
{
    int wybor;

    while ((wybor = pobierz_wybor()) != 'k')
    {
         switch (wybor) 
         {
            case 'a': 
                dodawanie();
                break;
            case 'b': 
                odejmowanie();
                break;
            case 'c': 
                mnozenie();
                break;
            case 'd': 
                dzielenie();
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
    printf("a. dodawanie        b. odejmowanie \n");
    printf("c. mnozenie         d. dzielenie\n");
    printf("k. koniec\n");

    ch = pobierz_pierwszy();

    while ( (ch < 'a' || ch > 'd') && ch != 'k')
    {
      printf("Wpisz właściwą literę\n");
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

void dodawanie(void)
{
    float n1, n2, wynik;

    printf("Podaj pierwszą liczbę: ");
    n1 = pobierz_float();
    printf("Podaj drugą liczbę: ");
    n2 = pobierz_float();
   
    wynik = n1 + n2;
    printf("%.3f + %.3f = %.3f\n\n", n1, n2, wynik);
    
    while (getchar() != '\n')
        continue;
}


void odejmowanie(void)
{
    float n1, n2, wynik;

    printf("Podaj pierwszą liczbę: ");
    n1 = pobierz_float();
    printf("Podaj drugą liczbę: ");
    n2 = pobierz_float();
    
    wynik = n1 - n2;
    printf("%.3f - %.3f = %.3f\n\n", n1, n2, wynik);

    while (getchar() != '\n')
        continue;
}

void mnozenie(void)
{
    float n1, n2, wynik;

    printf("Podaj pierwszą liczbę: ");
    n1 = pobierz_float();
    printf("Podaj drugą liczbę: ");
    n2 = pobierz_float();
    
    wynik = n1*n2;
    printf("%.3f * %.3f = %.3f\n\n", n1, n2, wynik);

    while (getchar() != '\n')
        continue;
}

void dzielenie(void)
{
    float n1, n2, wynik;

    printf("Podaj pierwszą liczbę: ");
    n1 = pobierz_float();
    printf("Podaj drugą liczbę: ");
    n2 = pobierz_float();
    while (n2 == 0)
        {
            printf("Podaj liczbę inną niż 0: ");
            n2 = pobierz_float();
        }
    
    wynik = n1/n2;
    printf("%.3f / %.3f = %.3f\n\n", n1, n2, wynik);

    while (getchar() != '\n')
        continue;
}

// float pobierz_float(void)
// {
//     float we;
//     char ch;

//     while (scanf("%f", &we) != 1)
//     {
//         while ((ch = getchar()) != '\n')
//             putchar(ch);  //pomija błędne dane wejściowe
//         printf(" nie jest liczbą. \nProszę podać liczbę: ");
//     }

//     return we;
// }


float pobierz_float(void)
{

    // Zabieg ze stringiem został zrealizowany po to aby wyeliminować wpisy typu liczba - tekst np. 23aed, 23..00 albo 23ead.00ed
    // funkcja atof zwraca wartość numeryczną łańcucha w zapisie zmiennoprzecinkowym.



    char we[20];
    char ch;
    int licznikz = 1; //licznik znakow
    int licznikk = 0; // licznik kropek
    int i;
    float num;

    scanf("%s", we);
   
    while (licznikz > 0)
    {
        for (i = 0, licznikz = 0, licznikk = 0; i < strlen(we); i++)
        {
            if (!isdigit(we[i]) && we[i] != '\n')
            {
                if (we[i] != '.')
                    licznikz++;
                else
                    licznikk++;
            }
        }
        if (licznikz != 0)
        {
            printf("Proszę podać liczbę: ");
            scanf("%s", we);
        }
        else
        {
            if(licznikk > 1)
            {
                printf("Proszę podać liczbę: ");
                scanf("%s", we); 
                licznikz = 1;
            }

            else 
            {
            num = atof(we);
            }
        }

        // while ((ch = getchar()) != '\n')
        //     putchar(ch);  //pomija błędne dane wejściowe
        // printf(" nie jest liczbą. \nProszę podać liczbę: ");
    }

    return num;
}

