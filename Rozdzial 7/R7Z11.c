wier#include <stdio.h>
#include <ctype.h>
#define ARBUZY 1.25
#define BURAKI 0.65
#define CEBULA 0.89

#define RABAT   0.05
#define RABATKW 100.0

#define KP1 3.5
#define KP2 10.0
#define KP3A 8.0
#define KP3B 0.1
#define PROGW1 5.0
#define PROGW2 20.0

#define WYBOR1 "A) ARBUZY"
#define WYBOR2 "B) BURAKI"
#define WYBOR3 "C) CEBULA"
#define WYBOR4 "K) KONIEC"


int main(void)
{
    
    char wybor;

    float cena, ilosc, sumaa, sumab, sumac, sumatot, koszta, kosztb, kosztc, koszttot, kosztprz, kosztcalk;
    int licznikm;


     wybor = 'A';
     sumaa = 0.0;
     sumab = 0.0;
     sumac = 0.0;


     while (wybor != 'K')
     {
          //menu
          for (licznikm = 1; licznikm <80; licznikm++)
               printf("*");
          printf("\n");  
          printf("Podaj literę odpowiadającą zamawianemu produktowi:\n");
          printf("%-20s %-20s\n", WYBOR1, WYBOR2);
          printf("%-20s %-20s\n", WYBOR3, WYBOR4);
          for (licznikm = 1; licznikm <80; licznikm++)
               printf("*");
          printf("\n");
          
          //instrukcja switch
          wybor = getchar();
          if (isspace(wybor))
               wybor = getchar();
          wybor = toupper(wybor);
 
          switch (wybor)
          {
               case 'A' :
                    cena = ARBUZY; 
                    break;
               case 'B' :
                    cena = BURAKI;
                    break;
               case 'C' :
                    cena = CEBULA;
                    break;
               case 'K' :
                    break;
               default :
                    printf("Podaj właściwą literę odpowiadającą pozycjom w menu\n");
          }
          
          // obliczenia ilosci zamawianych produktów
          if (wybor >= 'A' && wybor <= 'C')
          {
               printf("Podaj ilość produktu w kg\n");
               scanf("%f", &ilosc);  

               if (wybor == 'A')
                    sumaa += ilosc;
               else if (wybor == 'B')
                    sumab += ilosc;
               else
                    sumac += ilosc;
          }

     }

     sumatot = sumaa + sumab + sumac;
     koszta = sumaa * ARBUZY;
     kosztb = sumab * BURAKI;
     kosztc = sumac * CEBULA;

     koszttot= koszta + kosztb + kosztc; 

     //naliczenie rabatu
     if (koszttot > RABATKW)
          koszttot = koszttot - koszttot*RABAT;

     //obliczenie kosztów przesyłki
     if (sumatot < PROGW1)
          kosztprz = KP1;
     else if (sumatot < PROGW2)
          kosztprz = KP2;
     else
          kosztprz = KP3A + sumatot*KP3B;

     // obliczenie kosztu całkowitego zamowienia
     kosztcalk = koszttot + kosztprz;

     //wyświetlenie informacji końcowych

     if (sumaa != 0)
     {
          printf("Twoje zamowienie to %.1f kg arbuzów\n", sumaa);
          printf("Cena za 1kg wynosi %.2f zł\n", ARBUZY);
          printf("Kwota do zapłaty za ten produkt wynosi %.2f zł\n", koszta);
     }
     if (sumab != 0)
     {
          printf("Twoje zamowienie to %.1f kg buraków\n", sumab);
          printf("Cena za 1kg wynosi %.2f zł\n", BURAKI);
          printf("Kwota do zapłaty za ten produkt wynosi %.2f zł\n", kosztb);
     }
     if (sumac != 0)
     {
          printf("Twoje zamowienie to %.1f kg cebuli\n", sumac);
          printf("Cena za 1kg wynosi %.2f zł\n", CEBULA);
          printf("Kwota do zapłaty za ten produkt wynosi %.2f zł\n", kosztc);
     }

     if (sumatot != 0)
     {
          printf("Łączna kwota do zapłaty za produkty to %.2f zł\n",koszttot);
          if (koszttot > RABATKW)
               printf("Łączna kwota do zapłaty za produkty to %.2f zł\n",koszttot);
          printf("Koszt przesyłki wynosi %.2f zł\n ", kosztprz);
          printf("Kwota całkowita do zapłaty to %.2f zł\n", kosztcalk);
     }
     else 
          printf("Twój koszyk jest pusty");
     
    return 0;
}