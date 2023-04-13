
#ifndef _STOS_H_
#define _STOS_H_

#include <stdbool.h>
#define MAXSTOS 40

typedef char Item;

typedef struct stos
{
    Item item[MAXSTOS];
    int polozenie;
}Stos;

/* dzialanie : inicjalizuje stos                                        */
/* warunek wstepny : wsk wskazuje na stos                               */
/* warunek koncowy : zwraca stos zainicjowany jako pusty                */
void InicjujStos(Stos *wsk);

/* dzialanie : sprawdza czy stos jest pełny                             */
/* warunek wstepny : wsk wskazuje na zainicjowany stos                  */
/* warunek koncowy : zwraca true jezeli stos jest pełny                 */
bool PelnyStos(Stos *wsk);

/* dzialanie : sprawdza czy stos jest pusty                             */
/* warunek wstepny : wsk wskazuje na zainicjowany stos                  */
/* warunek koncowy : zwraca true jezeli stos jest pusty                 */
bool PustyStos(Stos *wsk);

/* dzialanie : określa liczbę pozycji na stosie                         */
/* warunek wstepny : wsk wskazuje na zainicjowany stos                  */
/* warunek koncowy : zwraca liczbe pozycji                              */
int LiczbaPozycji(Stos *wsk);

/* dzialanie : dodaje element na wierzch stosu                          */
/* warunek wstepny : wsk wskazuje na zainicjowany stos, item zawiera    */
/* pozycje dodawaną na wierzch stosu                                    */
/* warunek koncowy : jezeli stos nie jest pusty to dodaje element       */
/* na wierzch stosu,a funkcja zwraca true, w przeciwnym wypadku stos    */   
/* pozostaje niezmieniony, a funkcja zwraca false                       */          
bool PoloznaStos(Stos *wsk, Item item);

/* dzialanie : pobiera pozycje ze stosu                                 */
/* warunek wstepny : wsk wskazuje na zainicjowany stos, a *iitem        */
/* wskazuje na pozycje docelową                                         */
/* warunek koncowy : jezeli stos nie jest pusty to pobiera element z    */
/* wierzchu stosu i przenosi do pozycji docolwej, a funkcja zwraca true */
/* w przeciwnym wypadku stos jest zerowany, a funkcja zwraca false      */      
/* Jezeli stos byl pusty juz wczesniej, to pozostaje niezmieniony,      */
/* a funkcja zwraca false                                               */
bool Pobierz(Stos *wsk, Item *iitem);

/* dzialanie : czysci stos                                              */
/* warunek wstepny : wsk wskazuje na zainicjowany stos                  */
/* warunek koncowy : stos jest pusty                                    */
void WyczyscStos(Stos *wsk);

#endif