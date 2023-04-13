#include <stdio.h>
#include <ctype.h>

#define POD1   0.15
#define POD2   0.28
#define WYBOR1 "1) Stan wolny"
#define WYBOR2 "2) Głowa rodziny"
#define WYBOR3 "3) Małżeństwo, rozliczenie wspólne"
#define WYBOR4 "4) Małżeństwo, rozliczenie osobne"
#define WYBOR5 "5) Wyjście"

int main(void)
{
    float prog, wyplatab, wyplatan, podatek;
    int  wybor, licznikm ;
    char chtemp;
     wybor = 0;
     prog = 0;

     while (wybor !=5)
{
     //menu
     for (licznikm = 1; licznikm <80; licznikm++)
          printf("*");
     printf("\n");  
     printf("Podaj liczbę odpowiadającą właściwej dla Ciebie kategorii:\n");
     printf("%-40s %-40s\n", WYBOR1, WYBOR2);
     printf("%-40s %-40s\n", WYBOR3, WYBOR4);
     printf("%-40s \n", WYBOR5);
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
               prog = 17850; 
               break;
          case 2 :
               prog = 23900;
               break;
          case 3 :
               prog = 29750;
               break;
          case 4 :
               prog = 14875;
               break;
          case 5 :
               break;
          default :
               printf("Podaj właściwą liczbę odpowiadającą opcjom w menu\n");
     }

     // obliczenia głowne
     if (wybor >=1 && wybor <=4)
     {
          printf("Podaj dochód roczny podlegający opodatkowaniu\n");
          scanf("%f", &wyplatab);  
     
          if (wyplatab <= prog)
               podatek = POD1*wyplatab;
          else
               podatek = POD1*prog + POD2*(wyplatab - prog);
          
          wyplatan = wyplatab - podatek;

          printf("Twoja wypłata brutto to %.2f\n", wyplatab);
          printf("Twój podatek wyniósł %.2f\n", podatek );
          printf("Twoja wypłata netto to %.2f\n", wyplatan);
     }
}
    return 0;
}