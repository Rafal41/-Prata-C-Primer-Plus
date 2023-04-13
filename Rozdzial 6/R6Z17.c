#include <stdio.h>
#include <string.h>
int main(void)
{
    const float WKLAD = 1000000.00;
    const float WYCIAG = 100000.00;
    const float PCTZL = (8.00/100.00);
    int i;
    float sumaZL; 

    for (sumaZL = WKLAD, i =1 ; sumaZL >= 0; i++)
    {
        sumaZL = (sumaZL + sumaZL*PCTZL) - WYCIAG;
        printf("Stan konta \n");
        printf("%5.2f \n", sumaZL);

    }
    printf("%d", i-1);

    return 0;
}
