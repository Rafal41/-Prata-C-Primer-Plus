#include <stdio.h>
int main(void)
{
    char lista[26];
    char j;
    int i;
    int suma;

    for (i = 0, j = 96; i < 26; i++)
    {       
        j += 1;
        lista[i] = j;
        printf("%c ", lista[i]);
    }
    printf("\n", lista[i]);

    for (i = 0, suma = 0; i < 26; i++)
    {       
        suma += 1;
        printf("%d ", suma);
    }
    return 0;
}