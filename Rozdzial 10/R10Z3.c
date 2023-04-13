#include <stdio.h>

//prototyp funkcji zwracajacej najwieksza wartosc przechowywana w tablicy 
int maks_wart(int tab1[], int n);


int main(void)
{
    int wartmaks = 0;
    int zrodlo[5] = {2, 3, 2, 45, 41};
    
    wartmaks = maks_wart(zrodlo, 5);
    printf("Wartość maksymalna wynosi %d\n", wartmaks);
  
    return 0;
}
int maks_wart(int tab1[], int n)
{
    int i;
    int maks = tab1[0];

    for (i = 1; i < n ; i++)
    {
        if (maks > tab1[i])
            continue;
        else
            maks = tab1[i];
 
    }
 
    return maks;
}
// int maks_wart(int tab1[], int n)
// {
//     int i;
//     int *maks = tab1;
    
//     for (i = 1; i < n ; i++)
//     {
//         if (*maks > *(tab1 + i))
//             continue;
//         else
//             *maks = *(tab1 + i);
//     }
   
//     return *maks;
// }