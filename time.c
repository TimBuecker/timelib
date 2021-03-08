/*
    (Funktionen)
    Autor: Tim B�cker
    Datum: 25.01.2021
*/

//Implementieren der ben�tigten Bibliotheken
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

//Funktion mit �bergabeparameter eines structs datum
//Funktion ist zust�ndig, um alle Tage des Jahres zu bekommen
int day_of_the_year(struct datum datum)
{

    //Deklarierung und Initialisierung der Variable
    int ergebnis = 0;

    //Abfrage, ob das Datum �berhaupt exestiert bzw. valide ist
    if(exists_date(datum) == 1)
    {
        //For-Schleife um dem Ergebnis alle Tage des Jahres zu den passenden Monaten zu setzen
        for(int i = 1; i < datum.monat; i++)
        {
            ergebnis = ergebnis + get_days_for_month(datum);
        }
        ergebnis = ergebnis + datum.tag;

        //Erfolgreiche R�ckgabe der Funktion mit allen Tagen
        return ergebnis;
    }
    else
    {
        //Fehlerhafte R�ckgabe der Funktion
        return -1;
    }

}

//Funktion mit �bergabeparameter eines Ints f�r das Jahr
//Funktion ist zust�ndig f�r die Abfrage, ob das Jahr ein Schaltjahr ist
int is_leapyear(int jahr)
{

    //Abfrage ob das Jahr unter 1582 liegt, wenn ja, wird ein Fehler zur�ckgegeben
    if(jahr < 1582)
    {
        //Fehlerhafte R�ckgabe der Funktion
        return -1;
    }

    //Abfrage, ob das Jahr ein Schaltjahr ist
    if(jahr % 4 == 0)
    {
        if(jahr % 100 == 0)
        {
            if(jahr % 400 == 0)
            {
                //Erfolgreiche/Positive R�ckgabe der Funktion
                return 1;
            }
            else
            {
                //Negative R�ckgabe der Funktion
                return 0;
            }
        }
        else
        {
            //Erfolgreiche/Positive R�ckgabe der Funktion
            return 1;
        }
    }
    else
    {
        //Negative R�ckgabe der Funktion
        return 0;
    }

}

//Funktion mit �bergabeparameter eines structs datum
//Funktion gibt die Anzahl der Tage, des Monats zur�ck
int get_days_for_month(struct datum datum)
{

    //Abfrage, ob der Monat valide ist, also ob der Monat unter 1 und/oder �ber 12
    if(datum.monat < 1 || datum.monat > 12)
    {
        //Fehlerhafte R�ckgabe der Funktion
        return -1;
    }


    //Abfrage, ob das Jahr ein Schaltjahr ist
    if(is_leapyear(datum.jahr) == -1)
    {
        //Fehlerhafte R�ckgabe der Funktion
        return -1;
    }

    //Array mit allen Tagen der unterschiedlichen Monate
    int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    //Abfrage ob der Monat Februar bzw. 2 ist und ob das Jahr ein Schaltjahr ist.
    if(datum.monat == 2 && is_leapyear(datum.jahr) == 1)
    {
        //Erfolgreiche R�ckgabe der Funktion mit dem Wert 29
        return 29;
    }
    else
    {
        //Erfolgreiche R�ckgabe der Funktion mit allen Tagen, des Monats
        return days_per_month[datum.monat - 1];
    }

}

//Funktion mit �bergabeparameter eines structs datum
//Funktion ist zust�ndig f�r die Abfrage, ob das Datum valide ist bzw. es �berhaupt existiert
int exists_date(struct datum datum)
{

    //Abfrage, ob das Jahr unter 1582 oder �ber 2400 liegt
    if(datum.jahr < 1582 || datum.jahr > 2400)
    {
        //Negative R�ckgabe der Funktion
        return 0;
    }

    //Abfrage, ob der Monat unter 1 oder �ber 12 liegt
    if(datum.monat < 1 || datum.monat > 12)
    {
        //Negative R�ckgabe der Funktion
        return 0;
    }

    //Abfrage, ob die max. Anzahl der Tage, des Monats mit dem Tag �bereinstimmt oder der Tag unter 0 liegt
    if(get_days_for_month(datum) < datum.tag || datum.tag < 0)
    {
        //Negative R�ckgabe der Funktion
        return 0;
    }

    //Abfrage, ob die  Anzahl der Tage, des Monats gleich -1 ist
    if(get_days_for_month(datum) == -1)
    {
        //Negative R�ckgabe der Funktion
        return 0;
    }
    //Erfolgreiche/Positive R�ckgabe der Funktion
    return 1;

}

//Funktion mit keinen �bergabeparametern
//Funktion zust�ndig f�r die Konsoleneingabe der unterschiedlichen Werte, die ben�tigt werden
struct datum input_date()
{

    //Das strcut datum wird deklariert
    struct datum datum;

    //(Kopf) Do-While Schleife, welche so lange l�uft, bis ein valides/existierendes Datum angegeben wurde
    do
    {
        //Konsolenausgabe f�r die Eingabe des Tages
        printf("Bitte geben Sie den Tag ein: \n> ");
        //Konsoleneingabe und Initialisierung des Tages
        scanf("%d", &datum.tag);
        //Leeren des speichers, um Fehler zu vermeiden
        fflush(stdin);

        //Konsolenausgabe f�r die Eingabe des Monats
        printf("Bitte geben Sie den Monat ein: \n> ");
        //Konsoleneingabe und Initialisierung des Monats
        scanf("%d", &datum.monat);
        //Leeren des speichers, um Fehler zu vermeiden
        fflush(stdin);

        //Konsolenausgabe f�r die Eingabe des Jahres
        printf("Bitte geben Sie das Jahr ein: \n> ");
        //Konsoleneingabe und Initialisierung des Jahres
        scanf("%d", &datum.jahr);
        //Leeren des speichers, um Fehler zu vermeiden
        fflush(stdin);

        //Abfrage, ob das Datum existiert, um eine Nachricht in die Konsole zu senden, falls das eingegebene Datum nicht existiert
        if(exists_date(datum) == 0) {
            //Konsolenausgabe f�r die Fehlerhafte Eingabe
            printf("\nFehlerhafte Eingabe! \n\n");
            //Leeren des speichers, um Fehler zu vermeiden
            fflush(stdin);
        }

    //(Fu�) Do-While Schleife, welche so lange l�uft, bis ein valides/existierendes Datum angegeben wurde
    } while (exists_date(datum) == 0);

    //Erfolgreiche/Positive R�ckgabe der Funktion mit dem datum
    return datum;

}
