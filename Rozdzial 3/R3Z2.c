
#include <stdio.h>
int main(void)                     
{
       char kod; 
       printf("Podaj kod ASCII z klawiatury\n");
       scanf("%d", &kod);
       printf("Podany kod %d oznacza znak \'%c\' w ASCII \n",kod,kod);
      
       return 0;
}
