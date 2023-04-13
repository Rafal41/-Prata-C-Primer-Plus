// talkback.c -- ciekawski program
#include <stdio.h>
#include <string.h>
int main()                     
{
       char imie[20];
       int szerokosc ;
       printf("Podaj swoje imie\n");
       scanf("%s", imie);
       printf("\"%s\" \n", imie);
       printf("\"%20s\"\n", imie);
       printf("\"%-20s\"\n", imie);

       szerokosc = strlen(imie) + 3;
       printf("\"%*s\"\n", szerokosc ,imie);
      
       return 0;
}
