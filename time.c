/*
    (Funktionen)
    Autor: Tim Bücker
    Datum: 25.01.2021
*/

#include <stdio.h>
#include <stdlib.h>

int day_of_the_year(int tag, int monat, int jahr)
{

    int ergebnis = 0;

    if(exists_date(tag, monat, jahr) == 1)
    {
        for(int i = 1; i < monat; i++)
        {
            ergebnis = ergebnis + get_days_for_month(i, jahr);
        }
        ergebnis = ergebnis + tag;
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

int get_days_for_month(int monat, int jahr)
{

    if(monat < 1 || monat > 12)
    {
        return -1;
    }


    if(is_leapyear(jahr) == -1)
    {
        return -1;
    }

    int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if(monat == 2 && is_leapyear(jahr) == 1)
    {
        return 29;
    }
    else
    {
        return days_per_month[monat - 1];
    }

}

int exists_date(int tag, int monat, int jahr)
{

    if(jahr < 1582 || jahr > 2400)
    {
        return 0;
    }

    if(monat < 1 || monat > 12)
    {
        return 0;
    }

    if(get_days_for_month(monat, jahr) < tag || tag < 0)
    {
        return 0;
    }

    if(get_days_for_month(monat, jahr) == -1)
    {
        return 0;
    }

    return 1;

}

void input_date(int *zeigerTag, int *zeigerMonat, int *zeigerJahr)
{

    do
    {

        printf("Bitte geben Sie den Tag ein: \n> ");
        scanf("%d", &*zeigerTag);
        fflush(stdin);

        printf("Bitte geben Sie den Monat ein: \n> ");
        scanf("%d", &*zeigerMonat);
        fflush(stdin);

        printf("Bitte geben Sie das Jahr ein: \n> ");
        scanf("%d", &*zeigerJahr);
        fflush(stdin);

        if(exists_date(*zeigerTag, *zeigerMonat, *zeigerJahr) == 0) {
            printf("\nFehlerhafte Eingabe! \n\n");
            fflush(stdin);
        }

    } while (exists_date(*zeigerTag, *zeigerMonat, *zeigerJahr) == 0);

}
