// program oblicza sume liczb całkowitych z danego przedziału
#include <stdio.h>
int main(void)                     
{
       int start, koniec, suma;

       printf("Podaj liczbe oznaczajaca poczatek przedzialu\n");
       scanf("%d", &start);
       printf("Podaj liczbe oznaczajaca koniec przedzialu\n");
       scanf("%d", &koniec);
       suma = 0;

       while (start <= koniec)
       {
       suma = suma + start;
       start++;
       }

       printf("suma liczb z przedziału wynosi %d \n", suma );

       return 0;
}
