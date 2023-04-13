#include <stdio.h>
#include <string.h>
int main()                     
{
       char imie[20];
       float wzrost ;
       printf("Podaj swoje imie\n");
       scanf("%s", imie);
       printf("Podaj swoj wzrost w centymetrach\n");
       scanf("%f", &wzrost);

       printf("%s, masz %.2f metra wzrostu. \n", imie , wzrost/100);
      
       return 0;
}
