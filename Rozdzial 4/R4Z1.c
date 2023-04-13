// talkback.c -- ciekawski program
#include <stdio.h>
int main()                     
{
       char imie[20];
       char nazwisko[20]; 
       printf("Podaj swoje imie\n");
       scanf("%s", imie);
       printf("Podaj swoje nazwisko\n");
       scanf("%s", nazwisko);
       printf("%s %s", nazwisko, imie);
       return 0;
}
