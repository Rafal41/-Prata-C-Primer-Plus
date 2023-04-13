#include <stdio.h>
#include <string.h>
int main(void)
{
    
    double a, b, wynik ;
    int dolna, gorna, dolnakw, gornakw, suma; 
    

        printf("Podaj dolną i górna granice przedzialu liczb całkowitych: ");
        scanf("%d", &dolna);
        scanf("%d", &gorna);
        printf("\n");

    while (dolna != gorna , dolna < gorna)
    {
        dolnakw = dolna*dolna;
        gornakw = gorna*gorna;

        for(suma = 0; dolna <= gorna; dolna++)
        {
            suma = suma + dolna * dolna;
        }

        printf("Suma kwadratow od %d do %d wnosi %d", dolnakw, gornakw, suma);
        printf("\n");
        printf("Podaj nastepny przedział: ");
        scanf("%d", &dolna);
        scanf("%d", &gorna);
        printf("\n");
    } 
    return 0;
}