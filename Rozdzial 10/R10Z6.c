#include <stdio.h>

//prototyp funkcji zmienia kolejnosc elementow tablicy
void zamien_kol(double tab1[], int n);


int main(void)
{
    int wartmaks = 0;
    double zrodlo[5] = {2.2, 33.1, 2.0, 45.123, 41.33};
    int i;

    zamien_kol(zrodlo, 5);
    for (i = 0; i < 5; i++)
        printf("%10.3f", zrodlo[i]);
  
    return 0;
}
void zamien_kol(double tab1[], int n)
{
    int i;
    double temp;

    for (i = 0; i < n/2 + n%2 ; i++)
    {
       temp = tab1[i];
       tab1[i] = tab1[n-1-i];
       tab1[n-1-i] = temp;
    }

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