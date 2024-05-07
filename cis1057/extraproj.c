#include <stdio.h>

enum days {Saturday, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday};

#define date_size 10
#define week 7

int dayMonthStarts(int given_day, int month, int year);
int zeller(int given_day, int month, int year);
int date_splice(char* date, int* given_day, int* month, int* year);

int main(){
    int given_day, month, year;

    printf("%d", zeller(5, 12, 2023));
    return 0;
}

int dayMonthStarts(int given_day, int month, int year){
    int dayOfWeek = zeller(given_day, month, year);   //finds what given_day the inputted date is
    int daysIntoFirst = (given_day - dayOfWeek + week) % week;    //by going # of days back
    
    return (dayOfWeek - daysIntoFirst) % week;
}


/*
int date_splice(char* date, int* given_day, int* month, int* year){
    int count = sscanf(date, "%d %d %d", given_day, month, year);

    if (count != 3){    //ensures sscanf successfully scans
        printf("Failed to scan date\n");
        return -1;
    }

    if (*year > 1582){         
    }
    else if (year == 1582){   //not before oct 15 1582
        if (*month > 9){
            if (given_day > 14){
                if (*month < 3){
                    *month += 12;
                }
            }
            else {
                printf("Too Early!! Must be before 15/10/1582");
                return -1;
            }
        }
        else {
            printf("Too Early!! Must be before 15/10/1582");
            return -1;
        }
    }
}

*/

int zeller(int given_day, int month, int year){
    int K = year % 100, J = (year / 100);
    return (given_day + (13 * (month + 1) / 5) + K + (K / 4) + (J / 4) - 2 * J) % 7;
}
/*Zeller’s Congruence: Calculates the given_day of the week for the Gregorian Calendar (also available for the Julian Calendar) 
h = (q + (13 * (m + 1) / 5) + K + (K / 4) + (J / 4) - 2 * J) % 7 
where:
h = given_day of week (0 = Saturday, 1 = Sunday, 2 = Monday, … , 6 = Friday) 
q = given_day of the month 
m = month (3 = March, 4 = April, 5 = May, … 12 = December, 13 = January, 14 = February 
K = year of the century (year mod 100) 
J is the zero based century (actually) e.g. 1995 -> 19 
[...] is the floor function (integer part of a non-negative real, e.g., 
mod is the modulus operator or remainder after division (%)

in this algorithm January and February are counted as months 13 and 14 of the previous year. e.g. if it is 2 February 2010, the algorithm counts
the date as the second given_day of the fourteenth month of 2009 (02/14/2009 in DD/MM/YYYY format)*/