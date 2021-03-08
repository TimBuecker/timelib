/*
    Dieses Programm gibt dir die Tage des Eingegebenen Jahres aus!
    Autor: Tim B�cker
    Datum: 25.01.2021
*/

//Implementieren der Standartbibliotheken
#include <stdio.h>
#include <stdlib.h>
#include "time.h"


//Startfunktion des Programms
int main()
{
    //Deklarierung und Initialisierung der Variablen
    int tag = 0;
    int monat = 0;
    int jahr = 0;
    int alleTage = 0;

    struct datum datum;

    //Initialisierung des Structs Datum mit dem Eingabedatum
    datum = input_date();

    //Initialisierung der Variable mit den gesamten Tagen, des eingegebenen Datums
    alleTage = day_of_the_year(datum);

    //Konsolenausgabe f�r die Tage des Jahres
    printf("\n\nDas Jahr %i hat bis zum %i.%i insgesamt %i Tage \n", datum.jahr, datum.tag, datum.monat, alleTage);

    //Erfolgreiche R�ckgabe des Programms
    return 0;
}
