// talkback.c -- ciekawski program
#include <stdio.h>
#include <string.h> 
#define GESTOSC 62.4 // gestosc ludzkiego ciala w funtach na stopy szczescienne
int main()                     
{
       float waga, objetosc;
       int rozmiar, litery;
       char nazwa[40]; // nazwa jest tablica 40 znakow\

       printf("Witam. Podaj swoje imie.\n");
       scanf("%s", nazwa);
       printf("%s, ile funtow wazysz? \n",nazwa);
       scanf("%f", &waga);
       rozmiar = sizeof nazwa;
       litery = strlen (nazwa);
       objetosc = waga / GESTOSC;
       printf("Zatem, %s, twoja objetosc wynosi %2.2f stopy szescienne. \n", nazwa, objetosc);
       printf("Ponadto Twoje imie zawiera %d liter(y), \n", litery);
       printf("a na jego przechowanie przeznaczylismy %d bajtow. \n", rozmiar);
       return 0;
}
