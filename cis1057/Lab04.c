#include <stdio.h>

/*
  This program will ask the user to decide between the Day Number Finder and Substance Identifier. 
  Once the decision is made the program will then either determine the number of the day, of the inputted date, 
  out of the 365 days in the year, taking into account of leap years, or identify what a substance is based on its boiling point, also
  from user input.
*/
int day_of_year(char);                                                          //outputs result
int leap_year(int);                                                            
int day_number(int, int, int);                                                  //does the math to find day number

int substance_identifier(char);                                                 //outputs result
int within_X_percent(double);                                                   //runs test to find substance

int main()
{   
    char user_choice;  
    printf("Day Counter or Substance Identifier (D or S): \n");
    scanf("%c", &user_choice);

    if (user_choice == 's' || user_choice == 'S' || user_choice == 'd' || user_choice == 'D')
    {
        if (user_choice == 'd' || user_choice == 'D') 
       {
            printf("Day Counter chosen \n");
            day_of_year(user_choice);
       }      
       else
       {
            printf("Substance Identifier chosen \n");
            substance_identifier(user_choice);
       }       
    }    
    else
    {
        printf("Invlaid Input");
    }                                         
                                          
    return 0;
}

int day_of_year(char user_choice)
{   
    int month, day, year;
    
    printf("Enter the date in the format Month Day Year, seperate values with a space: \n");
    scanf("%d %d %d", &month, &day, &year);
        
    if (leap_year(year))
    {
        printf("The year %d is a leap year.\n", year);
    }
    else
    {
        printf("The year %d is not a leap year\n", year);
    }
    
    printf("%d/%d/%d is the %dth day of %d\n", month, day, year, day_number(day, month, leap_year(year)), year);

    return 0;
}

int leap_year(int year)
{
   if (year % 4 == 0 || year % 400 == 0)                                           //returns true or false depending on if it's a leap year
   {
    return 1;                                                                      
   }
   else
   {
    return 0;
   }
}

int day_number(int day, int month, int leap_year)
{ 
    int i;
    int day_num = 0;
    int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};           //days in every month
    
    if (leap_year)                                                                  //adds a day to february if its a leap year
    {
        month_day[1] += 1;                                                       
    }
   
    for (i = 0; i < (month - 1); i++)                                               // adds each month in array until one month before inputted month
    {
        day_num += month_day[i];                                                 
    }
    day_num += day;                                                                 //adds days passed in inputted month
    return day_num;
}

int substance_identifier(char user_choice)
{
    double boiling_pt;
    const char *substance[5] = {"Gold", "Silver", "Copper", "Mercury", "Water"};    //substance in the same order as substance boiling points

    printf("Enter observed boiling point: \n");
    scanf("%lf", &boiling_pt);

    if (within_X_percent(boiling_pt))             
    {
        printf("Substance Found\n");
        printf("Substance: %s \n", substance[within_X_percent(boiling_pt)]);
    }
    else
    {
        printf("Unknown Substance\n");
    }
    return 0;
}

int within_X_percent(double boiling_pt)
{  
    double upper, lower;
    int i;
    int found = 1;

    double boiling[5] = {2660.0, 2193.0, 1187.0, 357.0, 100.0};                     //boiling points of substance

    for (i = 0; found && i < 4; i++ )                                               //found determines if substance is found i ensures loop remains within the array
    {
        upper = 1.05 * boiling[i];                                                  //5 percent increase (upper bound)
        lower = 0.95 * boiling[i];                                                  //5 percent decrease (lower bound)
        if (boiling_pt >= lower && boiling_pt <= upper)                             //if within range
        {
            found = 0;                                                              
            return i;                                                               //return substance's index value which is true
        }  
    }
    if (found)
    {
        return 0;                                                                   //returns false
    } 
}
