#include <stdio.h>
// funkcja sortuje wartosci od najmniejszej do najwiekszej
void wieksze_od(double * x, double * y, double *z); 

int main(void)
{
    double n, m, o;
    printf("Podaj trzy wartości liczbowe zmiennoprzecinowe (q kończy)\n");
    while (scanf("%lf %lf %lf", &n, &m, &o) == 3)
    {
        printf("Najpierw n = %lf m = %lf o = %lf \n", n, m, o);
        wieksze_od(&n, &m, &o);
        printf("Teraz n = %lf m = %lf o = %lf \n", n, m, o);
        printf("Podaj trzy wartości liczbowe zmiennoprzecinowe (q kończy)\n");
    }
    return 0;
}
void wieksze_od(double * x, double * y, double * z)
{
    double temp;

    temp = *y;
    if (*x > temp)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
    if (temp > *z)
    {
        *y = *z;
        *z = temp;
    }
    temp = *y;
    if (*x > temp)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
    
}