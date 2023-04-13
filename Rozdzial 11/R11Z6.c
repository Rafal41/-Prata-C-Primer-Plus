#include <stdio.h>
#define ROZMIAR 40
int znajduje_sie_w(char *lan, char znak); //funkcja szukająca czy dany znak znajduje się w podanym tekscie
int iloscwyst(char *lan, char znak);    //funkcja licząca ilość wystąpień danego znaku w podanym tekscie
int strl(const char *lan);          //funkcja licząca długość łańcucha

int main(void)
{
    
    char lancuch[ROZMIAR];
    char ch;
    int ilosc = 0;

    printf("Podaj lancuch.\n");
    while ((fgets(lancuch, ROZMIAR, stdin)) != NULL)
    {
        //printf("Podaj lancuch.\n");
        //fgets(lancuch, ROZMIAR, stdin);
        printf("Podaj znak jaki chcesz znalezc w tym łańcuchu.\n");
        ch = getchar();
        getchar(); //odrzuca enter
        ilosc = znajduje_sie_w(lancuch,ch);
        printf("Czy dany znak znajduję się w podanym tekscie?  0 - nie, 1 - tak: %d\n", ilosc);
        printf("Podany znak występuje %d razy w podanym tekscie\n",iloscwyst(lancuch, ch));
        printf("Podaj nastepny lancuch. CTRL+Z kończy\n");
        
    }
    
    return 0;
}

int znajduje_sie_w(char *lan, char znak)
{
    int licznik = 0;

    while (*lan != '\0' && *lan != znak)
        lan++;
    if (*lan == '\0')
        licznik = 0; 
    else    // *lan == znak
        licznik = 1;
    
    return licznik;
}

int iloscwyst(char *lan, char znak)
{
    int licznik = 0;
    int i, dlugosclan;

    dlugosclan = strl(lan);

    for (i = 0; i < dlugosclan; i++)
    {
        if (*lan++ == znak)
            licznik++;
    }
    return licznik; 
}

int strl(const char *lan)
{
    int i=0;

    while (*lan++ != '\0')
        i++;
    printf("%d\n",i);

    return i;
}