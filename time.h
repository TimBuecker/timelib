/*
    (Funktionsheader)
    Autor: Tim Bücker
    Datum: 25.01.2021
*/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

struct datum {

    int jahr;
    int monat;
    int tag;

};

int day_of_the_year(struct datum);

int is_leapyear(int jahr);

int get_days_for_month(struct datum);

int exists_date(struct datum);

struct datum input_date();

#endif // TIME_H_INCLUDED
