#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 41
void * wczytaj(char * st);

int main(void)
{
    char tablica[SIZE];

    printf("Podaj tekst\n");
    wczytaj(tablica);
    puts(tablica);
    return 0;
}
void * wczytaj(char * st)
{
    int i = 0;
    bool flag = false;
    char x;

    
    while ((x = getchar()) != EOF)
    {
        if (isalpha(x))
        {
            flag = true;
            st[i] = x;
            i++;
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
       


}