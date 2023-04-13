#include <stdio.h>
int main(void)
{
    int licznikr, licznikk, liczniko;
    char x;
    char ch;

    printf("Podaj dowolną wielka litere alfabetu\n");
    scanf("%c", &x);

    for (licznikr = 'A'; licznikr <= x; licznikr++)
    {
        for (liczniko = licznikr ; liczniko < x ; liczniko++)                           // petla wyswietlajaca odstepy
            printf(" ");
        
            
        for (licznikk = 'A', ch = 'A'; licznikk < licznikr + 1; licznikk++, ch++)       // petla wyswietlajaca litery rosnaco
            printf("%c", ch);

        licznikk -=1;
        ch -= 1;

        for ( --licznikk, --ch ; licznikk >= 'A'; licznikk--, ch--)                     //petla wyswietlajaca litery malejąco
            printf("%c", ch);

        printf("\n");
    }
    return 0;

}