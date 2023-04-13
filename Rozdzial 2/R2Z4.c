#include <stdio.h>
void fun1(void);
void fun2(void);

int main(void)                     
{
       fun1();
       printf("Panie Janie!\n");
       fun2();
       return 0;
}
void fun1(void)       //funkcja wyswietlająca pierwszy wiersz
{
       printf("Panie Janie!\n");
}
void fun2(void)       //funkcja wyswietlająca ostatni wiersz
{
       printf("Rano wstań!");
}