#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 41
void * wczytaj(char * st, int n);

int main(void)
{
    char tablica[SIZE];

    printf("Podaj tekst o długości %d znaków\n", SIZE-1);
    wczytaj(tablica, SIZE);
    puts(tablica);
    return 0;
}
void * wczytaj(char * st, int n)
{
    int i = 0;
    bool flag = false;
    char x;

    for (i = 0; i < n; i++)
    {
        x = getchar();
        if (isalpha(x))
        {
            flag = true;
            st[i] = x;
        }
        // else if (flag == true && isalpha(x))
        //     st[i] = x;
        else if (flag == true && isspace(x))
        {
            st[i] ='\0';
            while (getchar() != '\n')
                continue;
            break;
        }
        else                //(flag == false && isspace(x))
            i=0;

    }
    //printf("i= %d", i+1);


}