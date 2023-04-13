#include <stdio.h>
#define GODZNAMIN 60 
int main(void)                     
{
       int min, godz, resztamin;

       printf("Podaj liczbe minut (liczba minut <=0 przerywa program\n");
       scanf("%d", &min);
       while (min > 0)
       {
       godz = min / GODZNAMIN;
       resztamin = min % GODZNAMIN;
       printf("%d min to %d godz i %d min\n", min, godz, resztamin);
       printf("Podaj nastepną liczbe minut\n");
       scanf("%d", &min);
       }
       return 0;
}
