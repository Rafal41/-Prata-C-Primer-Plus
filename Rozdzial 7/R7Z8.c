#include <stdio.h>
#include <ctype.h>
#define NADGODZ 1.5
#define TYDZPRACY   40
#define POD1   0.15
#define POD2   0.2
#define POD3   0.25
#define PROG1 1200
#define PROG2 1800
#define STAWKA1 POD1*PROG1
#define STAWKA2 STAWKA1 + POD2*(PROG2 - PROG1)
#define WYBOR1 "1) 35zł/godz;"
#define WYBOR2 "2) 37zł/godz;"
#define WYBOR3 "3) 40zł/godz;"
#define WYBOR4 "4) 45zł/godz;"
#define WYBOR5 "5) wyjście"

int main(void)
{
    float godz, wyplatab, wyplatan, podatek;
    int licznikz, wybor, licznikm, podst;
    char chtemp;
    licznikz = 0;
     wybor = 0;
     podst = 0;

     while (wybor !=5)
{
     //menu
     for (licznikm = 1; licznikm <80; licznikm++)
          printf("*");
     printf("\n");  
     printf("Podaj liczbę odpowiadającą stawce jaką otrzymujesz:\n");
     printf("%-20s %-20s\n", WYBOR1, WYBOR2);
     printf("%-20s %-20s\n", WYBOR3, WYBOR4);
     printf("%-20s \n", WYBOR5);
     for (licznikm = 1; licznikm <80; licznikm++)
          printf("*");
     printf("\n");
     
     //instrukcja switch
     wybor = 0; //restart konieczny do odrzucania literek
     scanf("%d", &wybor);
   
     if (wybor == 0) //postępowanie w przypadku podania literki
     {
          chtemp = getchar();
          wybor = 6; //ustawienie dowolnej liczny z przedzialu default
     }
     switch (wybor)
     {
          case 1 :
               podst = 35; 
               break;
          case 2 :
               podst = 37;
               break;
          case 3 :
               podst = 40;
               break;
          case 4 :
               podst = 45;
               break;
          case 5 :
               break;
          default :
               printf("Podaj właściwą liczbę odpowiadającą stawkom w menu\n");
     }

     // obliczenia głowne
     if (wybor >=1 && wybor <=4)
     {
          printf("Podaj liczbę przepracowanych godzin w tygodniu\n");
          scanf("%f", &godz);  

          if (godz <= TYDZPRACY)
               wyplatab = godz * podst;
          else 
               wyplatab = TYDZPRACY * podst + (godz - TYDZPRACY) * NADGODZ*podst;
     
          printf("W tym tygodniu przepracowałeś %.1f godzin. Twoja wypłata brutto to %.2f \n", godz, wyplatab);
     
          if (wyplatab <= PROG1)
               podatek = POD1*wyplatab;
          else if (wyplatab <= PROG2)
               podatek = STAWKA1 + POD2*(wyplatab - PROG1);
          else 
               podatek = STAWKA2 + POD3*(wyplatab - PROG2);
          
          wyplatan = wyplatab - podatek;

          printf("Twój podatek wyniósł %.2f\n", podatek );
          printf("Twoja wypłata netto to %.2f\n", wyplatan);
     }
}
    return 0;
}