#include <stdio.h>
#define  LITERY 'h'  
int main(void)            
{
       char n = 'a';
       printf("%5c", n);
       n = (int) n - 1;
       while (n++ < LITERY)
              printf("%5c", n);
       printf("\n");
       return 0;
}
