#include <stdio.h>
#include <string.h>
#include <float.h>
int main()                     
{
       double z1 = 1.0/3.0;
       float z2 = 1.0/3.0;
       
       printf("%20.*f \n", 4-1, z1);
       printf("%20.*f \n", 12-1,z1);
       printf("%20.*f \n", 16-1, z1);

       printf("%20.*f \n", 4-1, z2);
       printf("%20.*f \n", 12-1,z2);
       printf("%20.*f \n", 16-1, z2);

       printf("%d \n", DBL_DIG);
       printf("%d \n", FLT_DIG);
       return 0;
}
