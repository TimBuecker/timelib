/*
    (Funktionen)
    Autor: Tim Bücker
    Datum: 25.01.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int day_of_the_year(struct datum datum)
{

    int ergebnis = 0;

    if(exists_date(datum) == 1)
    {
        for(int i = 1; i < datum.monat; i++)
        {
            ergebnis = ergebnis + get_days_for_month(datum);
        }
        ergebnis = ergebnis + datum.tag;
        return ergebnis;
    }
    else
    {
        return -1;
    }

}

int is_leapyear(int jahr)
{

    if(jahr < 1582)
    {
        return -1;
    }

    if(jahr % 4 == 0)
    {
        if(jahr % 100 == 0)
        {
            if(jahr % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }

}

int get_days_for_month(struct datum datum)
{

    if(datum.monat < 1 || datum.monat > 12)
    {
        return -1;
    }


    if(is_leapyear(datum.jahr) == -1)
    {
        return -1;
    }

    int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if(datum.monat == 2 && is_leapyear(datum.jahr) == 1)
    {
        return 29;
    }
    else
    {
        return days_per_month[datum.monat - 1];
    }

}

int exists_date(struct datum datum)
{

    if(datum.jahr < 1582 || datum.jahr > 2400)
    {
        return 0;
    }

    if(datum.monat < 1 || datum.monat > 12)
    {
        return 0;
    }

    if(get_days_for_month(datum) < datum.tag || datum.tag < 0)
    {
        return 0;
    }

    if(get_days_for_month(datum) == -1)
    {
        return 0;
    }

    return 1;

}

struct datum input_date()
{

    struct datum datum;

    do
    {

        printf("Bitte geben Sie den Tag ein: \n> ");
        scanf("%d", &datum.tag);
        fflush(stdin);

        printf("Bitte geben Sie den Monat ein: \n> ");
        scanf("%d", &datum.monat);
        fflush(stdin);

        printf("Bitte geben Sie das Jahr ein: \n> ");
        scanf("%d", &datum.jahr);
        fflush(stdin);

        if(exists_date(datum) == 0) {
            printf("\nFehlerhafte Eingabe! \n\n");
            fflush(stdin);
        }

    } while (exists_date(datum) == 0);

    return datum;

}
