// program zamienia liczbe dni na liczbe tygodni i dni
#include <stdio.h>
#define TYDZIEN 7 
int main(void)                     
{
       int dni, tyg, resztadni;

       printf("Podaj liczbe dni (liczba dni <=0 przerywa program)\n");
       scanf("%d", &dni);
       while (dni > 0)
       {
       tyg = dni / TYDZIEN;
       resztadni = dni % TYDZIEN;
       printf("%d dni to %d tygodni i %d dni\n", dni, tyg, resztadni);
       printf("Podaj nastepną liczbe dni\n");
       scanf("%d", &dni);
       }
       return 0;
}
