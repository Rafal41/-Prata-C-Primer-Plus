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
#define WYBOR1 "A) 35zł/godz;"
#define WYBOR2 "B) 37zł/godz;"
#define WYBOR3 "C) 40zł/godz;"
#define WYBOR4 "D) 45zł/godz;"
#define WYBOR5 "Q) wyjście"

char pobierz_wybor(void);
char pobierz_pierwszy(void); 

int main(void)
{
    float godz, wyplatab, wyplatan, podatek;
    int podst;
    int wybor;
   
     podst = 0;

     while ((wybor = pobierz_wybor()) != 'Q')
     {
     
          switch (wybor)
          {
               case 'A' :
                    podst = 35; 
                    break;
               case 'B' :
                    podst = 37;
                    break;
               case 'C' :
                    podst = 40;
                    break;
               case 'D' :
                    podst = 45;
                    break;
               case 'Q' :
                    break;
               default :
                    printf("Podaj właściwą literę odpowiadającą stawkom w menu\n");
          }

          // obliczenia głowne
          if (wybor >='A' && wybor <= 'D')
          {
               printf("Podaj liczbę przepracowanych godzin w tygodniu\n");
               scanf("%f", &godz);  
               // while (getchar() != '\n')
               //      continue;

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

char pobierz_wybor(void)
{
     int ch;
     int licznikm;
   

     //menu
     for (licznikm = 1; licznikm <80; licznikm++)
          printf("*");
     printf("\n");  
     printf("Podaj literę odpowiadającą stawce jaką otrzymujesz:\n");
     printf("%-20s %-20s\n", WYBOR1, WYBOR2);
     printf("%-20s %-20s\n", WYBOR3, WYBOR4);
     printf("%-20s \n", WYBOR5);
     for (licznikm = 1; licznikm <80; licznikm++)
          printf("*");
     printf("\n");

    ch = pobierz_pierwszy();

    while ( (ch < 'A' || ch > 'D') && ch != 'Q')
    {
      printf("Wpisz A, B, C, D lub Q.\n");
      ch = pobierz_pierwszy();
    }
    return ch;
}

char pobierz_pierwszy(void)
{
    int ch;

    ch = getchar();
    ch = toupper(ch);
    if (ch == '\n')  // wypierdziela enter który zostaje po podaniu godzin w obliczeniach glownych
    {
          ch = getchar();
          ch = toupper(ch);
    }


    while (getchar() != '\n')
        continue;

    return ch;
}

