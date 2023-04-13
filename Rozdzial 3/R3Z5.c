
#include <stdio.h>
int main(void)                     
{
       int wiek ; 
       printf("Podaj swój wiek \n");
       scanf("%d", &wiek);
       printf("Masz %d lat, co jest równe %.f sekundom", wiek, wiek *3.156E7);
       return 0;
}
