#include <stdio.h>
#include <string.h>
struct dane_s {
    char imie[20];
    char nazwisko[20];
};
struct bard {
    struct dane_s dane;
    int data_ur;
    int data_sm;
};

int main(void)
{
    struct bard willie;
    struct bard *wsk = &willie;

    printf("Podaj dzień urodzenia\n");
    scanf("%d", &willie.data_ur);
    printf("Podaj dzień smierci\n");
    scanf("%d", &wsk->data_sm);
    printf("Podaj nazwisko\n");
    scanf("%s", willie.dane.nazwisko);
    printf("Podaj imie\n");
    scanf("%s", wsk->dane.imie);


    printf("imie %s, nazwisko %s, dzien urodzenia %d, dzien smierci %d\n", willie.dane.imie, willie.dane.nazwisko, willie.data_ur, willie.data_sm);
    printf("litera %c, litera %c, dlugosc %d, \n", willie.dane.imie[2], wsk->dane.imie[2], strlen(wsk->dane.imie) + strlen(wsk->dane.nazwisko));
    
    return 0;

}