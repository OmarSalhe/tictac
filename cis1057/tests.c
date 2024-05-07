#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define char_lim 100
#define date_and_time 17
#define max_event 50

int modifyEvent(char* fileName);
void clearInputBuffer();
int addEvent(char* fileName);
int deleteEvent(char* fileName);
int deleteEvent2(char* fileName);
void date_read(char relevantEvents[max_event][char_lim], char* fileName, int target_month, int target_year);

void printEvents(char relevantEvents[max_event][char_lim], int numEvents) {
    printf("\nEvents for the selected month:\n");
    for (int i = 0; i < numEvents; ++i) {
    printf("%s\n", relevantEvents[i]);
    }
}

void date_read(char relevantEvents[max_event][char_lim], char* fileName, int target_month, int target_year){
    int month, day, year;
    FILE* file;
    file = fopen(fileName, "r");
    int i = 0;

    char event[char_lim];

    while (fgets(event, char_lim, file) != NULL && i < max_event){
        sscanf(event, "%d/%d/%d", &month, &day, &year);

        if (month == target_month && year == target_year){
            strcpy(relevantEvents[i], event);
            i++;
        }
    }
    fclose(file);

    printEvents(relevantEvents, i);
}

void clearInputBuffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int modifyEvent(char* fileName){
    FILE* ptr;
    char eventdate[date_and_time], event[char_lim], lineEdit[char_lim], input, quit[5]; //quit is 4 letters plus '/0'
    ptr = fopen(fileName, "r+");
    if (ptr == NULL){
        perror("Error opening the file\n");
        return 1;
    }
        
    do {
        printf("Input the date (MM/DD/YYYY), the time, following a 24-hour clock (00:00), of the event being changed (separated by a space):\n");
        fgets(eventdate, sizeof(eventdate), stdin);
        clearInputBuffer();
    
        while (fgets(event, sizeof(event), ptr) != NULL){  //Keeps scanning until EOF reached
            if (strncmp(event, eventdate, strlen(eventdate)) == 0){
                printf("Enter the new events date, time, and description/title: ");
                fgets(lineEdit, sizeof(char) * char_lim, stdin);
                clearInputBuffer();

                fseek(ptr, -strlen(event), SEEK_CUR);

                fprintf(ptr, "%s", lineEdit);
                fflush(ptr);

                printf("edited successfully.\n");

                fseek(ptr, 0, SEEK_SET);
                break;
            }
        }
        printf("To quit enter 'quit' ");
        scanf("%4s", quit);
        clearInputBuffer();

        if (strcasecmp(quit, "quit") == 0){
            break;
        }
    }
    while(1);
  
    fclose(ptr);

    printf("Would you like to add or delete any events (A or D) or quit (anything else)");
    scanf(" %c", &input);
    clearInputBuffer();

    if (toupper(input) == 'A'){
        addEvent(fileName);
    }
    else if (toupper(input) == 'D'){
        deleteEvent(fileName);
    }
    return 0;
}

int addEvent(char* fileName){
    char input, event[char_lim], quit[5];

    FILE* ptr;
    ptr = fopen(fileName, "a");

    if (ptr == NULL){
        perror("Error opening the file");
        return -1;
    }
    do{
        printf("Input the date (MM/DD/YYYY), the time, following a 24-hour clock (00:00), of the event and the event (all separated by space): \n");
        printf("Example: 12/34/5678 23:59 'Lorem Ipsum' \n");
        fgets(event, sizeof(event), stdin);
        clearInputBuffer();

        if ((fprintf(ptr, "%s", event)) > 0){   //
            fflush(ptr);
            printf("Sucessfully added\n");
        }

        printf("To quit enter 'quit' ");
        scanf("%4s", quit);
        clearInputBuffer();

        if (strcasecmp(quit, "quit") == 0)
            break;
    }
    while (1);

    fclose(ptr);

    printf("Would you like to edit or delete any events (E or D) or quit (anything else)\n");
    scanf(" %c", &input);
    clearInputBuffer();

    if (toupper(input) == 'E' ){
        modifyEvent(fileName);
    }
    else if (toupper(input) == 'D' ){
        deleteEvent(fileName);
    }

    return 0;
}

int deleteEvent(char* fileName){
    char lineDelete[date_and_time], line[char_lim], filler[char_lim], decision, quit[5];
    int found = 0;
    FILE* ptr;
    FILE* tmp;

    ptr = fopen(fileName, "r");
    tmp = fopen("tmp.txt", "w");

    if (ptr == NULL || tmp == NULL){
        perror("Error opening the file\n");
        return 1;
    }

    do {
        printf("Input the date (MM/DD/YYYY), the time, following a 24-hour clock (00:00), of the event being deleted (separated by a space): ");
        fgets(lineDelete, sizeof(lineDelete), stdin);
        clearInputBuffer();
        while (fgets(line, sizeof(line), ptr) != NULL) {
            if (strncmp(line, lineDelete, strlen(lineDelete)) == 0){
                found = 1;
                printf("Event found and deleted successfully.\n");
            }
            else {
                fprintf(tmp, "%s", line);
            }
        }

        if (!found){
            printf("Event not found\n");
        }
        fseek(ptr, 0, SEEK_SET);

        printf("Enter 'quit' to quit: ");
        scanf("%4s", quit);
        clearInputBuffer();

        if (strcasecmp(quit, "quit") == 0){
            break;
        }
    }
    while (1);

    fclose(ptr);
    fclose(tmp);

    remove(fileName);
    rename("tmp.txt", fileName);

    printf("Would you like to edit or add any events (E or A) or quit (anything else)\n");
    scanf(" %c", &decision);
    clearInputBuffer();

    if (toupper(decision) == 'E' ){
        modifyEvent(fileName);
    }
    else if (toupper(decision) == 'A' ){
        deleteEvent(fileName);
    }

    return 0;
}

int main(void)
{
    int target_month = 12, target_year = 2023;
    char relevantEvents[max_event][char_lim];
    char* fileName = "File.txt";
    addEvent(fileName);
    //modifyEvent(fileName);

    date_read(relevantEvents, fileName, target_month, target_year);

}