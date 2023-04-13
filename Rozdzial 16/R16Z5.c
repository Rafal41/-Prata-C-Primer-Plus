#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define ROZMIAR 20

void totolotto(int tab[], int rozmiar, int num);

int main(void)
{
    int liczby[ROZMIAR];
    int wybor;

    for (int i = 0; i < ROZMIAR; i++)
        liczby[i] = i + 100;

    puts("ile liczb chcesz wylosować?");
    while (scanf("%d", &wybor) && wybor > ROZMIAR)
        puts("ile liczb chcesz wylosować?");

    totolotto(liczby, ROZMIAR, wybor);

    return 0;
}

void totolotto(int tab[], int rozmiar, int num)
{
    int licznik = 0; 
    int wylosowanapoz, wylosowanal;   
    int tabtemp[num];
    int flag = 0;

    for (int i = 0; i < num; i++)
        tabtemp[i] = 0;

    srand ((unsigned int) time(0));
    
    while (licznik < num)
    {
        flag = 0;
        wylosowanapoz = rand() % ROZMIAR;
        //printf("licznik= %d, wylosowana = %d\n", licznik, wylosowanapoz);

        for (int j = 0; j < num; j++)
            if (tabtemp[j] != 0 && wylosowanapoz == tabtemp[j])
            {
                flag = 1;
                break;
            }

        if (!flag)
        {
            tabtemp[licznik] = wylosowanapoz;
            wylosowanal = tab[wylosowanapoz];
            printf("wylosowana liczba to %d\n", wylosowanal);
            licznik++;
            
        }
    }
}