#include <stdio.h>
#include <string.h> // for strcmp
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define week 7
#define months_in_year 12
#define full_year 365

#define max_name 747 //based on the longest recorded name

#define char_lim 256
#define date_and_time 17

void calendarChoice();
int returnUser(const char* fileName);
void clearInputBuffer();
int modifyEvent(const char* fileName);

int main() {
    char username[max_name];
    char txt[] = {".txt"};
    char* fileName;
    char choice;

    printf("Enter your name: ");
    scanf("%s", username);

    fileName = malloc(sizeof(char) * (strlen(username) + strlen(txt) + 1)); // + 1 for '\0'
    if (fileName == NULL){
        printf("failed to make pointer");
        return -1;
    }
    strcpy(fileName, username);
    strcat(fileName, txt);  // = "username.txt"

    if (returnUser(fileName)){
        printf("Would you like to add or make changes to your events (Y or N): ");
        scanf(" %c", &choice);

        if (toupper(choice) == 'Y'){
            printf("Add events or change events (A or C)");
            scanf(" %c", &choice);
                if (toupper(choice) == 'A'){
                    addEvent(fileName);
                }
                else if (toupper(choice) == 'C'){
                    modifyEvent(fileName);
                }
        }
        else if (toupper(choice) == 'N'){
            printf("Ok\n");
        }
    }
    else{
        addEvent(fileName);
    }
    calendarChoice();


    free(fileName);
    return 0;
}

int returnUser(const char* fileName){
    FILE* file;
    file = fopen(fileName, "r");
    if (file != NULL){
        printf("Welcome back: %.*s! You have saved events.",strlen(fileName) - 4, 0);
        fclose(file);
        return TRUE;

    }
    else{ 
        printf("Welcome new user: %.*s. You have no saved events", strlen(fileName) - 4, 0);
        fclose(file);
        return FALSE;

    }
}

void calendarChoice(){
    int year, month;
    char user_input[4]; // 4 = 'all' + '\0'

    printf("Enter year: ");
    scanf("%d", &year);

    if (year == 1582){
        printf("Calendar does not support year calendars on %d and month calendars on or before October (10) ", 1582);
        printf("Either 11 - or 12, Enter a month: ");
        scanf("%d", &month);
        if (month < 0 || month > 12) {
            printf("Invalid input. Either 11 or 12\n");
            return 1;
        }
        printCalendar(year, month);
    }
    else if (year < 1582){
        printf("Year calendar does not support years before %d", 1582);
        return;
    }
    else{
        printf("Enter month ('all' or 1-12): ");
        if ((scanf("%3s", user_input)) != 1){
            clearInputBuffer();
            printf("Failed to scan user input\n");
        }

        if (strcmp(user_input, "all") == 0) {
            printAllCalendars(year);
        }
        else {
            if ((sscanf(user_input, "%d", &month)) != 1){   //for cases where a string besides 'all' is inputted
                clearInputBuffer();
                printf("Invalid input. Enter 1 - 12 or 'all'.\n");
                return;
            }
            clearInputBuffer();

            printCalendar(year, month);
        }
    }
}

void clearInputBuffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Add Event function
int addEvent(char* fileName){
    char input, event[char_lim];

    FILE* ptr;
    ptr = fopen(fileName, "a");

    if (ptr == NULL){
        perror("Error opening the file");
        return -1;
    }
    do{
        printf("Do you want to add an event (enter Y for yes and N for No): ");
        input = getchar();

        clearInputBuffer();

        if (toupper(input) == 'Y'){
            printf("Input the date (MM/DD/YYYY), the time, following a 24-hour clock (00:00), of the event and the event (all separated by space): \n");
            printf("Example: 12/34/5678 23:59 'Lorem Ipsum' \n");

            fgets(event, sizeof(event), stdin);
            clearInputBuffer();

            if (fprintf(ptr, "%s\n", event) < 0) { //if no lines printed onto file, quit
                perror("Error writing to the file\n");
                fclose(ptr);
                return 1;
            }

            if (fflush(ptr) != 0) { //ensures event is printed onto file, quits if fails
                perror("Error flushing the file\n");
                fclose(ptr);
                return 1;
            }
        }
        else if (toupper(input) == 'N'){
            printf("Ok\n");
        }
        else{
            printf("Invalid input. Y or N\n");
        }
    }
    while (toupper(input) != 'N');
    fclose(ptr);
    return 0;
}

//Modify Event function
int modifyEvent(const char* fileName){
    FILE* ptr;
    char lineEdit[date_and_time], line[char_lim];
    ptr = fopen(fileName, "r+");
    if (ptr == NULL){
        perror("Error opening the file\n");
        return 1;
    }

    printf("Input the date (MM/DD/YYYY), the time, following a 24-hour clock (00:00), of the event being changed (separated by a space):\n");
    printf("And press enter twice: once to save and one extra time to submit\n");

    fgets(lineEdit, sizeof(lineEdit), stdin);
    clearInputBuffer();
    
    while (fgets(line, sizeof(line), ptr) != NULL){  //Keeps scanning until EOF reached
            if (strncmp(line, lineEdit, strlen(lineEdit)) == 0){
                printf("Enter the new event: ");
                fgets(lineEdit, sizeof(char) * char_lim, stdin);
                clearInputBuffer();

                fseek(ptr, -strlen(line), SEEK_CUR);

                if (fprintf(ptr, "%s\n", lineEdit) < 0) {
                perror("Error writing to the file\n");
                fclose(ptr);
                return 1;
                }

            if (fflush(ptr) != 0) {
                perror("Error flushing the file\n");
                fclose(ptr);
                return 1;
                }
        
                printf("edited successfully.\n");
                break;
            }
        }
    fclose(ptr);
    return 0;
}

