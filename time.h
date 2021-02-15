/*
    (Funktionsheader)
    Autor: Tim Bücker
    Datum: 25.01.2021
*/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

int day_of_the_year(int tag, int monat, int jahr, int tageDerMonate[]);

int is_leapyear(int jahr);

int get_days_for_month(int month, int year, int tageDerMonate[]);

int exists_date(int tag, int monat, int jahr);

void input_date(int *zeigerJahr, int *zeigerMonat, int *zeigerTag);

#endif // TIME_H_INCLUDED
