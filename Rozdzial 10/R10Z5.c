#include <stdio.h>

//prototyp funkcji zwracajacej roznice pomiedzy najwieksza i najmniejsza wartoscią w tablicy
int roznicamaksmin(int tab1[], int n);


int main(void)
{
    int roznica = 0;
    int zrodlo[5] = {2, 3, 2, 45, 41};
    
    roznica = roznicamaksmin(zrodlo, 5);
    printf("Różnica pomiedzy wartoscia maksymalna i minimalną wynosi %d\n", roznica);
  
    return 0;
}
int roznicamaksmin(int tab1[], int n)
{
    int i;
    int maks = tab1[0];
    int min = tab1[0] ;

    for (i = 1; i < n ; i++)
    {
        if (maks > tab1[i]) // znajdowanie wart maksymalnej
            continue;
        else
            maks = tab1[i];
        
        if (min < tab1[i])  // znajdowanie wart minimalnej 
            continue;
        else
            min = tab1[i];
    
    }

    return maks - min;
}
