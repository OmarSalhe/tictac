#include <stdio.h>
#include <string.h>

#define char_lim 256
#define max_event 50

void date_read(char[max_event][char_lim], char[], int target_month, int target_day, int target_year);

int main(){

    return 0;
}

#include <stdio.h>
#include <string.h> // for strcmp

#define week 7
#define months_in_year 12
#define full_year 365

int zeller();
int isLeapYear(int year);
int numberOfLeapYears(int target_year);
int numberOfDaysApart(int target_year, int target_month);
int totalDaysIntoYear(int month, int day);
int firstDayOfMonth(int target_month, int target_year);

void printAllCalendars(int year);

// starting date for the calendar is October 15, 1582 or 15/10/1582
const int start_day = 15, start_month = 10, start_year = 1582;

const int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const char *dayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
const char *monthNames[] = {"January",   "February", "March",    "April",
                            "May",       "June",     "July",     "August",
                            "September", "October",  "November", "December"};



void printEvents(char relevantEvents[], int numEvents) {
  printf("\nEvents for the selected month:\n");
  for (int i = 0; i < max_events; ++i) {
    printf("%s\n", relevantEvents[i]);
    }
}


int firstDayOfMonth(int target_month, int target_year) {
  int daysApart = numberOfDaysApart(target_year, target_month);

  // what day of the week the starting day is
  int firstDay = zeller();

  // daysApart + firstDay calculates the target day. modulo week (7) confines
  // this value to a day in the week.
  return (daysApart + firstDay) % week;
}

int zeller() {
  // K = last two year digits, J = first two year digits
  int K = start_year % 100, J = (start_year / 100);

  // returns a value between 0-6 -> 0 = Saturday, 1 = Sunday ...
  int zellerDay = (start_day + (13 * (start_month + 1) / 5) + K + (K / 4) + (J / 4) - 2 * J) % week;

  // adjusts zeller values to traditional calendar values sunday = 0, monday = 1,...
  return (zellerDay + 6 + week) % 7; // + week ensures return is positive
}

int isLeapYear(int year) {
  // return true or false, depending on if leap year or not
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int numberOfLeapYears(int target_year) {
  // # of days added due to leap years
  int leapDays = 0;
  // iterates over every year between start and target year checking for leap
  // years
  for (int i = start_year; i < target_year + 1; i++) {
    // adds 1 day for every leap year
    if (isLeapYear(i)) {
      leapDays++;
    }
  }
  return leapDays;
}

int numberOfDaysApart(int target_year, int target_month) {
  // accounts for additional days due to leap years
  int leapDays = numberOfLeapYears(target_year);

  // the # of full years, in days, elapsed between start and target date
  int yearAhead = (target_year - start_year - 1) * full_year;

  // calculates remaining days within starting year
  int daysLeftStart =
      full_year - totalDaysIntoYear(
                      start_month, start_day); // subtracts remaining days in
                                               // the year for the starting date

  // accounts for a potential leap year on start
  if (isLeapYear(start_year)) {
    daysLeftStart--;
  }

  // calculates # of days into the target year
  int daysIntoCurrent = 0;
  if (target_month == 0)
    daysIntoCurrent =
        totalDaysIntoYear(target_month, 0); // day = 0 because start of month
  else
    daysIntoCurrent = totalDaysIntoYear(target_month, 1);

  // returns the total # of days elapsed between the start and end date
  return yearAhead + leapDays + daysIntoCurrent +
         daysLeftStart; // total # of days between entered month and starting
                        // date
}

int totalDaysIntoYear(int month, int day) {
  int numOfDays = 0;

  // adds values of each full month passed
  for (int i = 0; i < month - 1; i++) {
    numOfDays += monthDays[i];
  }

  // adds # of days into the current month
  numOfDays += day;

  return numOfDays;
}

int deleteEvent(char* fileName) //Replaces event with spaces
{
    FILE* ptr;
    char lineDelete[date_and_time], line[char_lim], spaces[char_lim], decision;
    ptr = fopen(fileName, "r+");

    if (ptr == NULL){
        perror("Error opening the file\n");
        return 1;
    }

    do
    {
        printf("Do you want to delete an event(Y for yes and N for No? ");
        scanf(" %c", &decision);
        clearInputBuffer();

        if(toupper(decision) == 'Y'){
            printf("Input the date (MM/DD/YYYY), the time, following a 24-hour clock (00:00), of the event being deleted (separated by a space) \nand enter twice: ");

            fgets(lineDelete, sizeof(lineDelete), stdin);
            clearInputBuffer();

            while (fgets(line, sizeof(line), ptr) != NULL)  //Keeps scanning until EOF reached
            {
                if (strncmp(line, lineDelete, strlen(lineDelete)) == 0)
                {
                    int linelen = strlen(line);
                    for(int i = 0; i < linelen; i++)
                    {
                        spaces[i] = ' ';
                    }
                    spaces[linelen] = '\0';

                    fseek(ptr, -strlen(line), SEEK_CUR);

                    fprintf(ptr, "%s", spaces);
                    fflush(ptr);//ensures modified line is printed onto file

                    printf("edited successfully.\n");
                    break;
                }
            }

        }
        else if (toupper(decision) == 'N')
            printf("Ok\n");
    }
    while(toupper(decision) != 'N');
    fclose(ptr);

    printf("Would you like to edit or add any functions (E or A) or are you done (anything else)");
    scanf("%c", &decision);

    if (toupper(decision) == 'A'){
        addEvent(fileName);
    }
    else if (toupper(decision) == 'E'){
        modifyEvent(fileName);
    }
    else{
        return 0;
    }

    return 0;
} 




void date_read(char relevantEvents[max_event][char_lim], char* fileName, int target_month, int target_day, int target_year){
    int month, day, year;
    FILE* file;
    file = fopen(fileName, "r");
    int i = 0;

    char line[char_lim];

    while (fgets(line, char_lim, file) != NULL && i < max_event){
        sscanf(line, "%d %d %d", &month, &day, &year); //first three intergers are the date
        if (month == target_month && year == target_year){
            strcpy(relevantEvents[i], line);
            i++;
        }
    }

    fclose(file);
}

/* 
how to print out events for specific months

make a function to scan through the users events
store the dates for each events and find the values
compare the found month and year values to the inputted date
if match print them below the monthly calendar


    how to store dates of each events?
        use fgets to look through each line and sscanf to store the values

    how to print?
    if months match then store the event string into a new array
    pass array into the print calendar function
    print array after month calendar finished

*/