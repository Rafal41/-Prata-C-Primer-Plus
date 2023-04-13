#include <stdio.h>
#include <string.h>
int main(void)
{
    const int WKLAD = 5;
    const int LIMIT = 150;
    int tydzien, suma;
    
    for (suma = WKLAD, tydzien = 1 ; suma <= LIMIT; tydzien++)
    {
        suma = (suma - tydzien)*2;
        printf("Tydzien Liczba znajomych \n");
        printf("%7d %10d\n", tydzien, suma);

    }
    printf("%d", tydzien-1);

    return 0;
}
