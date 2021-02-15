/*
    Dieses Programm gibt dir die Tage des Eingegebenen Jahres aus!
    Autor: Tim Bücker
    Datum: 25.01.2021
*/

//Implementieren der Standartbibliotheken
#include <stdio.h>
#include <stdlib.h>
#include "time.h"


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
