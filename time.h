/*
    (Funktionsheader)
    Autor: Tim Bücker
    Datum: 25.01.2021
*/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

//Deklarierung des structs datum mit dem Jahr, Monat und dem Tag
struct datum {

    int jahr;
    int monat;
    int tag;

};

//Funktionsheader der day_of_the_year Funktion
int day_of_the_year(struct datum);

//Funktionsheader der is_leapyear Funktion
int is_leapyear(int jahr);

//Funktionsheader der get_days_for_month Funktion
int get_days_for_month(struct datum);

//Funktionsheader der exists_date Funktion
int exists_date(struct datum);

//Funktionsheader der datum input_date Funktion
struct datum input_date();


#endif // TIME_H_INCLUDED
