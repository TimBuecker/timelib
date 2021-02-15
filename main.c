/*
    Dieses Programm gibt dir die Tage des Eingegebenen Jahres aus!
    Autor: Tim Bücker
    Datum: 25.01.2021
*/

//Implementieren der Standartbibliotheken
#include <stdio.h>
#include <stdlib.h>

int day_of_the_year(int tag, int monat, int jahr, int tageDerMonate[])
{
    int alleTage = 0;

    //Abfrage ob der Monat überhaupt existiert
    if(monat < 0 || monat > 12) {
        printf("Der Monat existiert nicht!\n");
    }

    //Abfrage ob der Monat den Tag überhaupt besitzt
    if(tag > tageDerMonate[monat-1])
    {
        tag = tageDerMonate[monat-1];
        printf("Der Monat besitzt diesen Tag nicht!\n");
        //Abbruch des Programms
        return -1;
    }

    //Alle Tage des Jahres berechnen
    for(int i = monat - 2; i >= 0; i--)
    {
        alleTage += tageDerMonate[i];
    }
    //Initalisierung der Tage des Monats
    alleTage += tag;

    return alleTage;
}

int is_leapyear(int jahr)
{
    if (jahr % 4 == 0)
    {
        return 1;
    }
    else if (jahr % 4 != 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }

    return -1;
}

int get_days_for_month(int month, int year, int tageDerMonate[])
{
    //????

    return tageDerMonate[-1];
}

int exists_date(int tag, int monat, int jahr)
{
    //Abfrage ob tag kleiner als 1 oder größer als 31
    if(tag < 1 || tag > 31)
    {
        return -1;
    }
    //Abfrage ob monat kleiner als 1 oder größer als 12
    if(monat < 1 || monat > 12)
    {
        return -1;
    }
    //Abfrage ob jahr kleiner als 1582 oder größer als 2400
    if(jahr < 1582 || jahr > 2400)
    {
        return -1;
    }

    return 1;
}

void input_date(int *zeigerJahr, int *zeigerMonat, int *zeigerTag){
    do{
        int tag = 0;
        int monat = 0;
        int jahr = 0;
        printf("Bitte geben Sie das Jahr an: ");
        scanf("%i", &jahr);
        *zeigerJahr = jahr;
        fflush(stdin);

        printf("Bitte geben Sie den Monat ein: ");
        scanf("%i", &monat);
        *zeigerMonat = monat;
        fflush(stdin);

        printf("Bitte geben Sie den Tag ein: ");
        scanf("%i", &tag);
        *zeigerTag = tag;
        fflush(stdin);
    }
    while(exists_date(*zeigerTag, *zeigerMonat, *zeigerJahr) != 1);

}

//Startfunktion des Programms
int main()
{
    //Daklarierung und Initialisierung der Varibalen
    int jahr = 0;
    int monat = 0;
    int tag = 0;
    int tageDesFebruars = 28;

    //Aufruf der Funktion für die Eingabe der Daten
    input_date(&jahr, &monat, &tag);

    //Abfrage ob das Jahr ein Schaltjahr ist
    if(is_leapyear == 1)
    {
        //Initialisierung der Tage vom Februar, wenn Schaltjahr
        tageDesFebruars = 29;
    }

    //Daklarierung und Initialiserung der Varibale für die Max. Tage der Monate
    int tageDerMonate[12] = {31,tageDesFebruars,31,30,31,30,31,31,30,31,30,31};

    //Abfrage ob Daten inordnung sind
    if (exists_date == -1)
    {
        printf("Nur Daten vom  01.01.1582 bis zum 31.12.2400 sind gueltig!\n");
        //Abbruch des Programms
        return -1;
    }

    int alleTage = day_of_the_year(tag, monat, jahr, tageDerMonate);

    //Konsolenausgabe für die Tage des Jahres
    printf("Das Jahr %i hat bis zum %i.%i insgesamt %i Tage", jahr, tag, monat, alleTage);

    return 0;
}
