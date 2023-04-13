
#include <stdio.h>
int main(void)                     
{
       float wzrost ; 
       printf("Podaj swój wzrost w cm \n");
       scanf("%f", &wzrost);
       printf("Masz %.1f cm wzrostu, co jest równe %.2f calom", wzrost, wzrost/2.54);
       return 0;
}
