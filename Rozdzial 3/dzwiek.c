
#include <stdio.h>
int main(void)                     
{
       char dzwiek = 7 ; 
       char syg = '\a';
       char sygn = '\007';
       printf("%c", dzwiek);
       printf("wcisnij enter");
       scanf("%c");
       printf("%c", syg);
       printf("wcisnij enter");
       scanf("%c");
       printf("%c", sygn);
       return 0;
}
