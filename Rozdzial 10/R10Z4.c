#include <stdio.h>

//prototyp funkcji zwracajacej indeks najwiekszej wartosci przechowywanej w tablicy 
int maks_wartind(int tab1[], int n);


int main(void)
{
    int wartmaks = 0;
    int zrodlo[5] = {2, 3, 2, 45, 41};
    
    wartmaks = maks_wartind(zrodlo, 5);
    printf("Wartość maksymalna jest elementem o indeksie %d w tablicy\n", wartmaks);
  
    return 0;
}
int maks_wartind(int tab1[], int n)
{
    int i;
    int maks = tab1[0];
    int indx;

    for (i = 1, indx = 0; i < n ; i++)
    {
        if (maks > tab1[i])
            continue;
        else
        {
            maks = tab1[i];
            indx = i;
        }
 
    }
 
    return indx;
}
