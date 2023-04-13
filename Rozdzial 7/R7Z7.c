#include <stdio.h>
#define PODST 40
#define NADGODZ 1.5*PODST
#define TYDZPRACY   40
#define POD1   0.15
#define POD2   0.2
#define POD3   0.25
#define PROG1 1200
#define PROG2 1800
#define STAWKA1 POD1*PROG1
#define STAWKA2 STAWKA1 + POD2*(PROG2 - PROG1)

int main(void)
{
    float godz, wyplatab, wyplatan, podatek;
    int licznikz;
    licznikz = 0;

    printf("Podaj liczbę przepracowanych godzin w tygodniu\n");
    scanf("%f", &godz);
    if (godz <= TYDZPRACY)
          wyplatab = godz * PODST;
    else 
          wyplatab = TYDZPRACY * PODST + (godz - TYDZPRACY) * NADGODZ;
     
     printf("W tym tygodniu przepracowałeś %.1f godzin. Twoja wypłata brutto to %.2f \n", godz, wyplatab);
     
     if (wyplatab <= PROG1)
          podatek = POD1*wyplatab;
     else if (wyplatab <= PROG2)
          podatek = STAWKA1 + POD2*(wyplatab - PROG1);
     else 
          podatek = STAWKA2 + POD3*(wyplatab-PROG2);
     
     wyplatan = wyplatab - podatek;

     printf("Twój podatek wyniósł %.2f\n", podatek );
     printf("Twoja wypłata netto to %.2f\n", wyplatan);

    return 0;
}