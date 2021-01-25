/*
    Dieses Programm gibt dir die Tage des Eengegebenen Jahres aus!
    Autor: Tim Bücker
    Datum: 11.01.2021
*/

//Implementieren der Standartbibliotheken
#include <stdio.h>
#include <stdlib.h>

//Startfunktion des Programms
int main()
{
    //Daklarierung und Initialisierung der Varibalen
    int jahr = 0;
    int monat = 0;
    int tag = 0;
    int tageDesFebruars = 28;
    int alleTage = 0;

    //Konsoleneingabe des Jahres
    printf("Bitte geben Sie ein Jahre ein: ");
    scanf("%i", &jahr);
    //Leeren des Speichers
    fflush(stdin);

    //Abfrage ob das Jahr ein Schaltjahr ist
    if(jahr % 4 == 0)
    {
        //Initialisierung der Tage vom Februar, wenn Schaltjahr
        tageDesFebruars = 29;
    }

    //Daklarierung und Initialiserung der Varibale für die Max. Tage der Monate
    int tageDerMonate[12] = {31,tageDesFebruars,31,30,31,30,31,31,30,31,30,31};

    //Konsoleneingabe des Monats
    printf("Bitte geben Sie den Monat ein: ");
    scanf("%i", &monat);
    //Leeren des Speichers
    fflush(stdin);

    //Konsoleneingabe des Tages
    printf("Bitte geben Sie den Tag ein: ");
    scanf("%i", &tag);
    //Leeren des Speichers
    fflush(stdin);

    //Abfrage ob der Monat den Tag überhaupt besitzt
    if(tag > tageDerMonate[monat-1])
    {
        tag = tageDerMonate[monat-1];
        printf("Der Monat besitzt diesen Tag nicht!");
        //Abbruch des Programms
        return 0;
    }

    //Alle Tage des Jahres berechnen
    for(int i = monat - 2; i >= 0; i--)
    {
        alleTage += tageDerMonate[i];
    }
    //Initalisierung der Tage des Monats
    alleTage += tag;

    //Konsolenausgabe für die Tage des Jahres
    printf("Das Jahr %i hat bis zum %i.%i insgesamt %i Tage", jahr, tag, monat, alleTage);

    return 0;
}
