#include <stdio.h>
int main(void)
{
    
    int dolna, gorna, rozmiar, i ;
    int lista[rozmiar];

    printf("Podaj dolna granice\n");
    scanf("%d", &dolna);
    printf("Podaj gorna granice\n");
    scanf("%d", &gorna);

    rozmiar = 3*(gorna - dolna + 1);
    
    //printf("%d", rozmiar);

    for (i = 0; dolna <= gorna; dolna++, i+3)
    {       
        lista[i] = dolna;
        lista[i+1] = dolna*dolna;
        lista[i+2] = dolna*dolna*dolna;
        printf("%5d %5d %5d \n", lista[i], lista[i+1], lista[i+2]);
    }
    return 0;
}