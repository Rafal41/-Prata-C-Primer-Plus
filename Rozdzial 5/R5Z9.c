//program przeliczajacy temperatury
#include <stdio.h>
#include <string.h>
void Temperatura(double n);
int main(void)                     
{
       double tF;
       int x;
       printf("Podaj temperature w stopniach Fahrenheita ");
       //scanf("%lf", &tF);
       x = scanf("%lf", &tF);
       //printf("%d", x);


       while (x == 1)
       {
              
              Temperatura(tF);
              printf("Podaj temperature w stopniach Fahrenheita ");
              x = scanf("%lf", &tF);
       }
       printf("Koniec");

       return 0;
}
void Temperatura(double n)
{
       double tC, tK;
       char lenF, lenC, lenK;

       const double CONSTC1 = 5.0/9.0 ;
       const double CONSTC2 = 32.0 ;
       const double CONSTK = 273.16 ;


       tC = CONSTC1 * (n - CONSTC2);
       tK = tC + CONSTK;

       lenF = strlen("Temperatura w stopniach Farenheita");
       lenC = strlen("Temperatura w stopniach Cejsusza");
       lenK = strlen("Temperatura w stopniach Kelwina");
       printf("Temperatura w stopniach Farenheita Temperatura w stopniach Cejsusza Temperatura w stopniach Kelwina\n");
       printf("%*.2f %*.2f %*.2f\n", lenF, n, lenC, tC, lenK, tK);

}