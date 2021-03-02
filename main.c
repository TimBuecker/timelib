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
    //Deklarierung und Initialisierung der Variablen
    int tag = 0;
    int monat = 0;
    int jahr = 0;
    int alleTage = 0;

    input_date(&tag, &monat, &jahr);

    alleTage = day_of_the_year(tag, monat, jahr);

    //Konsolenausgabe für die Tage des Jahres
    printf("\n\nDas Jahr %i hat bis zum %i.%i insgesamt %i Tage \n", jahr, tag, monat, alleTage);

    return 0;
}
