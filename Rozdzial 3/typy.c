//wyswietla rozmiary typow
#include <stdio.h>
int main(void)                     
{
       // w C99 zdefiniowano format %zd dla rozmiarow
       printf("Typ int ma rozmiar %zd bajtow. \n", sizeof(int));
       printf("Typ char ma rozmiar %zd bajtow. \n", sizeof(char));
       printf("Typ long ma rozmiar %zd bajtow. \n", sizeof(long));
       printf("Typ long long ma rozmiar %zd bajtow. \n", sizeof(long long));
       printf("Typ short ma rozmiar %zd bajtow. \n", sizeof(short));
       printf("Typ double ma rozmiar %zd bajtow. \n", sizeof(double));
       printf("Typ float ma rozmiar %zd bajtow. \n", sizeof(float));
       printf("Typ long double ma rozmiar %zd bajtow. \n", sizeof(long double));
       return 0;
}
