// talkback.c -- ciekawski program
#include <stdio.h>
#include <string.h>
int main()                     
{
       float liczba = 21.29 ;
       printf("Wpisano liczbe %.1f lub %.1e.\n", liczba, liczba);
       printf("Wpisano liczbe %+.3f lub %.3E. \n", liczba, liczba);  
      
       return 0;
}
