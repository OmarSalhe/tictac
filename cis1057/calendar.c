#include <stdio.h>

#define week 7
#define months_in_year 12
#define full_year 365

int zeller();
int isLeapYear(int year);
int numberOfLeapYears(int target_year);
int numberOfDaysApart(int target_year, int target_month);
int totalDaysIntoYear(int month, int day);
int firstDayOfMonth(int target_month, int target_year);

//starting date for the calendar is October 15, 1582 or 15/10/1582
const int start_day = 15, start_month = 10, start_year = 1582;


const int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const char* dayNames[] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};
const char* monthNames[] = {   
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

/*
to go from oct 15, 1582 to any start_month and start_year
    need: # of days in between

   
    idk if this even valid ???? 
    (once you get that you can subtract the # of days left in each start_month to the # of
    days in between -> need to find a way to get start_month value every time start_month changes
    once you reach start_month 12 start_year++ and keep going until desired start_month and start_year is reached
    ->  probably a while or a for loop)
        set a break statement once the start_month and start_year is reached
    

how to find number of days between -> Done
    you could find the diff in years and multiply by 365 and add num of leap years passed
    -> (only works if exactly # start_year away)
        fix = add # of days between months too??
            so # of days = 365(years) + leap days +  (# of days in start_month)(# of months behind)

how to account for leap start_year -> Done
    to find # of leap years do a for loop that adds one to every start_year until the diff is reached
    and test the start_year in the leap start_year funct then add that to the diff in years 

when finding what start_month to be on -> i dont think i need this?
    add # of days onto start_month and then change start_month once passed
    if feb leap then add one start_day to it and keep going
    -> im thinking maybe an array
        once num > arr[i] i++ 

once all of that is done you can now find what start_day the start_month starts on :3
    find what start_day starting start_day is -> use zeller
    should be able to do (days apart) % week = # of days ahead of start_day
        if days ahead just saturday + excess
*/

/* 
TESTS:
12/23 -> Friday correct
1/1492 -> Monday correct
4/2017 -> Saturday correct
*/

int main(){
    int month = 4, year = 2017;
    printf("%s", dayNames[firstDayOfMonth(month, year)]);
    return 0;
}

int firstDayOfMonth(int target_month, int target_year){
    int daysApart = numberOfDaysApart(target_year, target_month);
    
    //what day of the week the starting day is
    int firstDay = zeller();

    // daysApart + firstDay calculates the target day. modulo week (7) confines this value to a day in the week.
    return (daysApart + firstDay) % week; 
}

int zeller(){
    // K = last two year digits, J = first two year digits
    int K = start_year % 100, J = (start_year / 100);

    //returns a value between 0-6 -> 0 = Saturday, 1 = Sunday ...
    int zellerDay = (start_day + (13 * (start_month + 1) / 5) + K + (K / 4) + (J / 4) - 2 * J) % week;

    //adjusts zeller values to traditional calendar values sunday = 0, monday = 1, ...
    return (zellerDay + 6 + week) % 7; // + week ensures return is positive
}

int isLeapYear(int year){
    //return true or false, depending on if leap year or not
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int numberOfLeapYears(int target_year){
    //# of days added due to leap years
    int leapDays = 0;
    //iterates over every year between start and target year checking for leap years
    for (int i = start_year; i < target_year + 1; i++){ 
        //adds 1 day for every leap year
        if (isLeapYear(i)){
            leapDays++;         
        }
    }
    return leapDays;
}

int numberOfDaysApart(int target_year, int target_month){
    //accounts for additional days due to leap years
    int leapDays = numberOfLeapYears(target_year);
    
    //the # of full years, in days, elapsed between start and target date
    int yearAhead = (target_year - start_year - 1) * full_year;
    
    //calculates remaining days withiin starting year
    int daysLeftStart = full_year - totalDaysIntoYear(start_month, start_day);    //subtracts remaining days in the year for the starting date
    
    //accounts for potential leap year on start
    if (isLeapYear(start_year)){ 
        daysLeftStart--;
    }

    //calculates # of days into target year
    int daysIntoCurrent = 0;
    if (target_month == 0)
         daysIntoCurrent = totalDaysIntoYear(target_month, 0); //day = 0 b/c start of month
    else
         daysIntoCurrent = totalDaysIntoYear(target_month, 1); //day = 0 b/c start of month

    printf("Year Ahead: %d, Leap Days: %d, Days Into Current: %d, Days Left Start: %d\n", yearAhead, leapDays, daysIntoCurrent, daysLeftStart);

    //returns total # of days elapesed between start and end date
    return yearAhead + leapDays + daysIntoCurrent + daysLeftStart;  //total # of days between entered month and starting date
}

int totalDaysIntoYear(int month, int day){
    int numOfDays = 0;

    //adds values of each full month passed 
    for (int i = 0; i < month - 1; i++){ 
        numOfDays += monthDays[i];
    }

    //adds # of days into current month
    numOfDays += day;

    return numOfDays;
}

