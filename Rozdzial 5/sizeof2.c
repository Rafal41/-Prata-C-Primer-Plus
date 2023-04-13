//sizeof.c -- uzycie operatora sizeof
#include <stdio.h>
int main(void)                     
{
       char new[] = "Rafal";
       size_t intsize;

       intsize = sizeof (char);

       printf("n= %s, n ma %zd bajty; wszystkie liczby calkowite maja %zd bajty.\n", new, sizeof new, intsize);
       return 0;
}
