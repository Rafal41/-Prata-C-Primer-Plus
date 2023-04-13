#include <stdio.h>
// funkcja zwracająca minimum z dwóch wartosci
void wieksze_od(double * x, double * y); 

int main(void)
{
    double n, m;
    printf("Podaj dwie wartości liczbowe zmiennoprzecinowe (q kończy)\n");
    while (scanf("%lf %lf", &n, &m) == 2)
    {
        printf("Najpierw n = %lf m = %lf  \n", n,m);
        wieksze_od(&n,&m);
        printf("Teraz n = %lf m = %lf  \n", n,m);
        printf("Podaj dwie wartości liczbowe zmiennoprzecinowe (q kończy)\n");
    }
    return 0;
}
void wieksze_od(double * x, double * y)
{
    if (*x > *y)
        *y = *x ;
    else
        *x = *y;

}