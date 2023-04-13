#include <stdio.h>
void raz_trzy(void);
void dwa(void);

int main(void)                     
{
       
       printf("zaczynamy:\n");
       raz_trzy();
       printf("koniec!\n");
       return 0;
}
void raz_trzy(void)       //funkcja wyswietlająca pierwszy wiersz
{
       printf("raz \n");
       dwa();
       printf("trzy \n");
}
void dwa(void)       //funkcja wyswietlająca ostatni wiersz
{
       printf("dwa \n");
}