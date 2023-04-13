#include <stdio.h>
void br(void);
void ic(void);

int main(void)                     
{
       br();
       ic();
       printf("\n");
       ic();
       printf("\n");
       br();
       return 0;
}
void br(void)       //funkcja wyswietlająca pierwszy wiersz
{
       printf("Brazylia, Rosja, ");
}
void ic(void)       //funkcja wyswietlająca ostatni wiersz
{
       printf("Indie, Chiny");
}