
#include <stdio.h>
#include <string.h>
int main(void)
{
    const int ILOSC = 8;
    int i, j;
    int liczba[ILOSC]; 

    for ( i=0, j = 1 ; i < ILOSC; i++, j++)
    {
        liczba[i] = j*2;
    }

    i = 0; // zerowanie

    do {
        printf("%d ", liczba[i]);
        i++;
    } while(i < ILOSC);

    return 0;
}