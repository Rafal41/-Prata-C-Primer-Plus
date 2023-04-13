//program podaje reszte z dzielenia liczb calkowitych
#include <stdio.h>

int main(void)                     
{
       int dzielnik, dzielna, reszta;
       printf("Program obliczajacy reszte z dzielenia.\n");
       printf("Podaj dzielnik (liczba calkowita): ");
       scanf("%d", &dzielnik);
       printf("Podaj dzielna (liczba calkowita): ");
       scanf("%d", &dzielna);

       while (dzielna >0)
       {
              reszta = dzielna % dzielnik;
              printf("%d %% %d wynosi %d\n", dzielna, dzielnik, reszta);
              printf("Podaj dzielna (<= 0, aby zakonczyc): ");
              scanf("%d", &dzielna);
       }
       printf("Koniec");

       return 0;
}
