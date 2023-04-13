// program pobiera liczbe float i podnosi ja do trzeciej potegi
#include <stdio.h>
void potegowanie(float x);
int main(void)                     
{
       float liczba;
       
       printf("Podaj liczbe ktora chcesz podniesc do 3 potegi\n");
       scanf("%f", &liczba);
       potegowanie(liczba);
      
       return 0;
}

void potegowanie(float x)
{
       float potega;
       potega = x*x*x;  
       printf("liczba %.3f podniesiona do 3 potegi wynosi %.3f \n", x, potega);    
}