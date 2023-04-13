#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROZMIAR 20
#define ROZMIARDRZ 18


struct zawodnik {
    int num;
    char imie[ROZMIAR];
    char nazwisko[ROZMIAR];
    int rzu2pkt;
    int traf2pkt;
    int asysty;
    int faule;
    float skutecznosc;
};

int main(void)
{ 
    struct zawodnik person[ROZMIARDRZ];
    FILE *wp;
    char nazwa[ROZMIAR]; // nazwa pliku
    //char temp[sizeof(struct zawodnik)+1];        // tablica tymczasowa przechowywujaca jeden wiersz z pliku
    char ch = '0';
    bool flag = false;

    int tempnum;
    char tempimie[ROZMIAR];
    char tempnazwisko[ROZMIAR];
    int temprzu2pkt;
    int temptraf2pkt;
    int tempasysty;
    int tempfaule;

    char tempdata[ROZMIAR];

    int pobranewiersze = 0;
    int count = 0;
    int odjpoz = 0;

    float sumaskt;
    float sktdrz;


    //////////////////////inicjalizacja tablicy//////////////////////////
    for (int i = 0; i < ROZMIARDRZ; i++)
    {
        person[i].num = 0;
        person[i].imie[0] = '0';
        person[i].nazwisko[0] = '0';
        person[i].rzu2pkt = 0;
        person[i].traf2pkt = 0;
        person[i].asysty = 0;
        person[i].faule = 0;
        person[i].skutecznosc = 0;
    }

    //////////////////////otwarcie pliku//////////////////////////
    puts("Podaj nazwe pliku tekstowego zawierajacego wyniki");
    scanf("%s", nazwa);
    if ((wp = fopen(nazwa, "r")) == NULL)
    {
        printf("Ne mozna otworzyc %s\n", nazwa);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (ch != EOF)
    {
        int j = 0;         //reset j

        fscanf(wp, "%s", &tempdata);
        tempnum = atoi(tempdata);

        fscanf(wp, "%s", &tempdata);
        for (j = 0; j < strlen(tempdata); j++)
            tempimie[j] = tempdata[j];
        tempimie[j] = '\0';

        fscanf(wp, "%s", &tempdata);
        for (j = 0; j < strlen(tempdata); j++)
            tempnazwisko[j] = tempdata[j];
        tempnazwisko[j] = '\0';

        fscanf(wp, "%s", &tempdata);
        temprzu2pkt = atoi(tempdata);
        
        fscanf(wp, "%s", &tempdata);
        temptraf2pkt = atoi(tempdata);

        fscanf(wp, "%s", &tempdata);
        tempasysty = atoi(tempdata);

        fscanf(wp, "%s", &tempdata);
        tempfaule = atoi(tempdata);

        pobranewiersze++;

        while ((ch = getc(wp)) != '\n' && ch != EOF)
            continue; 

        //printf("%d %s %s %d %d %d %d\n", tempnum,tempimie, tempnazwisko, temprzu2pkt, temptraf2pkt, tempasysty, tempfaule);
        
        //////////////////////wczytanie zawartosci do struktury//////////////////////////

            if (i == 0)
        {
            person[i].num = tempnum;
            for (j = 0; j < strlen(tempimie); j++)
                person[i].imie[j] = tempimie[j];
            person[i].imie[j] = '\0';
                //strncpy(person[i].imie,tempimie,strlen(tempimie));
            for (j = 0; j < strlen(tempnazwisko); j++)
                person[i].nazwisko[j] = tempnazwisko[j];
            person[i].nazwisko[j] = '\0';
                //strncpy(person[i].nazwisko,tempnazwisko,strlen(tempnazwisko));
            person[i].rzu2pkt = temprzu2pkt;
            person[i].traf2pkt = temptraf2pkt;
            person[i].asysty = tempasysty;
            person[i].faule = tempfaule;  
        }
        else //i > 0
        {
            for (j = 0; j < i; j++)
            {
                if (tempnum == person[j].num)
                {
                        flag = true;
                        count += 1;
                        odjpoz++;
                        break;
                }
            }
            //printf("tempnum = %d, flag = %d\n", tempnum, flag);
            if (flag == false)       //brak danych zawodnika na liscie
            {
                if (count != 0)
                {
                    i -= 1;
                    count = 0;
                }

                person[i].num = tempnum;
                for (j = 0; j < strlen(tempimie); j++)
                    person[i].imie[j] = tempimie[j];
                person[i].imie[j] = '\0';
                for (j = 0; j < strlen(tempnazwisko); j++)
                    person[i].nazwisko[j] = tempnazwisko[j];
                person[i].nazwisko[j] = '\0';
                person[i].rzu2pkt = temprzu2pkt;
                person[i].traf2pkt = temptraf2pkt;
                person[i].asysty = tempasysty;
                person[i].faule = tempfaule; 
            }
            else                    //zawodnik juz jest na liscie, dopisujemy
            {
                person[j].rzu2pkt += temprzu2pkt;
                person[j].traf2pkt += temptraf2pkt;
                person[j].asysty += tempasysty;
                person[j].faule += tempfaule;   
                flag = false;
            }
        }
        //printf("%d %s %s %d %d %d %d\n", person[i].num, person[i].imie, person[i].nazwisko, person[i].rzu2pkt, person[i].traf2pkt, person[i].asysty, person[i].faule);
        i++;

    }
    //printf("pobranewiersze = %d, odjpoz = %d\n",pobranewiersze, odjpoz); 

    ////////////////////obliczanie skutecznosci//////////////////////////
    for (int i = 0; i < pobranewiersze - odjpoz ; i++)
    {
        person[i].skutecznosc = (float) person[i].traf2pkt/(float) person[i].rzu2pkt;
        sumaskt += person[i].skutecznosc;
    }
        sktdrz = sumaskt/ (pobranewiersze - odjpoz);
    

    ////////////////////wyswietlanie wynikow//////////////////////////
    for (int i = 0; i < pobranewiersze - odjpoz ; i++)
    {
        printf("%d %s %s %d %d %d %d %.2f\n", person[i].num, person[i].imie, person[i].nazwisko, person[i].rzu2pkt, person[i].traf2pkt, person[i].asysty, person[i].faule, person[i].skutecznosc);
    }
    printf("Skutecznosc druzyny wynosi %.2f\n",sktdrz);

    fclose(wp);
    return 0;   
}
