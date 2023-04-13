#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int num, sump, sumn;
    int licznikp, licznikn;
    sump = 0;
    sumn = 0;
    licznikp = 0;
    licznikn = 0;
    printf("Wpisuj cyfry - cyfra 0 kończy działanie progamu\n");
    while (scanf("%d", &num) != 0 && num != 0)
    {
       if (num%2 == 0)
       {
          licznikp++;
          sump= sump + num;
       }
       else
       {
          licznikn++;
          sumn= sumn + num;
       }

    }
    if(licznikp > 0 && licznikn> 0)
    {
    printf("Wczytano łącznie %d liczb parzystych - ich średnia arytmetyczna jest równa %.2f \n", licznikp, (float)sump/(float)licznikp);
    printf("Wczytano łącznie %d liczb nieparzystych - ich średnia arytmetyczna jest równa %.2f \n", licznikn, (float)sumn/(float)licznikn);
    }
    else
    {
    printf("Wczytano łącznie %d liczb parzystych - ich średnia arytmetyczna jest równa %.2f \n", licznikp, 0);
    printf("Wczytano łącznie %d liczb nieparzystych - ich średnia arytmetyczna jest równa %.2f \n", licznikn, 0);
    }
    return 0;
}