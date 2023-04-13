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
    int i,j,k;
    double temp;
    double tabl[3];
    tabl[0] = *x;
    tabl[1] = *y;
    tabl[2] = *z;

    //printf("n = %lf m = %lf o = %lf\n",tabl[0],tabl[1],tabl[2]);
    for (i=1; i <= 2 ; i++)
    {
        temp = tabl[i];
        j = i-1;
        while (j >= 0)
        {
            if (tabl[j] > temp)
            {
                tabl[j+1] = tabl[j];
                tabl[j] = temp;
                
            }
            
            j--;

        }

    }
    *x = tabl[0];
    *y = tabl[1];
    *z = tabl[2];
}