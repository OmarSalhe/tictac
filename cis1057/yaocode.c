#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define char_lim 256
#define date_and_time 17

void clearInputBuffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int addEvent(){
    char input, event[char_lim];
    int i = 0;

    FILE* ptr;
    ptr = fopen("fileName.txt", "a");

    if (ptr == NULL){
        perror("Error opening the file");
        return -1;
    }
    do{
        printf("Do you want to add an event (enter Y for yes and N for No): ");
        input = getchar();

        clearInputBuffer();

        if (toupper(input) == 'Y'){
            printf("Input the date (MM/DD/YYYY), the time, following a 24-hour clock (00:00), of the event and the event (all separated by space)\nand enter twice: \n");
            printf("Example: 12/34/5678 23:59 'Lorem Ipsum' \n");

            fgets(event, char_lim * sizeof(char), stdin);
            clearInputBuffer();

            fprintf(ptr, "%s", event);
            fflush(ptr); //ensures event is printed onto file

            i++;
        }
        else if (toupper(input) == 'N'){
            printf("Ok. events added.\n");
        }
        else{
            printf("Invalid input. Y or N\n");
        }
    }
    while (toupper(input) != 'N');
    fclose(ptr);
    return 0;
}


//Modify event function

int modifyEvent(){
    FILE* ptr;
    char lineEdit[date_and_time], line[256], filler[char_lim];
    ptr = fopen("File.txt", "r+");
    if (ptr == NULL){
        perror("Error opening the file\n");
        return 1;
    }

    printf("Input the date (MM/DD/YYYY), the time, following a 24-hour clock (00:00), of the event being changed (separated by a space) \nand enter twice: ");

    fgets(lineEdit, sizeof(lineEdit), stdin);
    clearInputBuffer();
    
    while (fgets(line, sizeof(line), ptr) != NULL){  //Keeps scanning until EOF reached
            if (strncmp(line, lineEdit, strlen(lineEdit)) == 0){
                printf("Enter the new event: ");
                fgets(lineEdit, sizeof(char) * char_lim, stdin);
                clearInputBuffer();

                fseek(ptr, -strlen(line), SEEK_CUR);

                fprintf(ptr, "%s", lineEdit);
                fflush(ptr); //ensures modified line is printed onto file
        
                printf("edited successfully.\n");
                break;
            }
        }
    fclose(ptr);
    return 0;
}

int main(void){
    modifyEvent();
    return 0;
}

/*

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

    printf("Would you like to edit or delete any events (E or D) or quit (anything else)");
    scanf("%c", &input);
    clearInputBuffer();

    if (toupper(input) == 'E' ){
        modifyEvent(fileName);
    }
    else if (toupper(input) == 'D' ){
        deleteEvent(fileName);
    }

    return 0;
}

int modifyEvent(const char* fileName){
    FILE* ptr;
    char lineEdit[date_and_time], event[char_lim], input;
    ptr = fopen(fileName, "r+");
    if (ptr == NULL){
        perror("Error opening the file\n");
        return 1;
    }

    do {
        printf("Would you like to edit any events (Y or N)");
        scanf("%c", &input);
        if (toupper(input) == 'Y') {   
            printf("Input the date (MM/DD/YYYY), the time, following a 24-hour clock (00:00), of the event being changed (separated by a space):\n");
            fgets(lineEdit, sizeof(lineEdit), stdin);
            clearInputBuffer();
            
            while (fgets(event, sizeof(event), ptr) != NULL){  //Keeps scanning until EOF reached
                    if (strncmp(event, lineEdit, strlen(lineEdit)) == 0){
                        printf("Enter the new event: ");
                        fgets(lineEdit, sizeof(char) * char_lim, stdin);
                        clearInputBuffer();

                        fseek(ptr, -strlen(event), SEEK_CUR);

                    if (fprintf(ptr, "%s", lineEdit) < 0) {
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
                printf("To save changes quit edit mode with 'N'\n");
            }
        else if (toupper(input) == 'N'){
                printf("Ok\n");
        }
        else
            printf("Invalid Input. Y or N");
    }
    while (toupper(input) != 'N');
    fclose(ptr);

    printf("Would you like to add or delete any events (A or D) or quit (anything else)");
    scanf("%c", &input);
    clearInputBuffer();

    if (toupper(input) == 'A' ){
        addEvent(fileName);
    }
    else if (toupper(input) == 'D' ){
        deleteEvent(fileName);
    }
    return 0;
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
    
    do {
        printf("Do you want to delete an event(Y for yes and N for No? ");
        scanf(" %c", &decision);
        clearInputBuffer();

        if(toupper(decision) == 'Y'){
            printf("Input the date (MM/DD/YYYY), the time, following a 24-hour clock (00:00), of the event being deleted (separated by a space) \nand enter twice: ");

            fgets(lineDelete, sizeof(lineDelete), stdin);
            clearInputBuffer();

            while (fgets(line, sizeof(line), ptr) != NULL){
                if (strncmp(line, lineDelete, strlen(lineDelete)) == 0){
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
        else if (toupper(decision) == 'N'){
            printf("Ok\n");
        }
    }
    while(toupper(decision) != 'N');
    fclose(ptr);

    printf("Would you like to edit or add any functions (E or A) or are you done (anything else)");
    scanf(" %c", &decision);
    clearInputBuffer();

    if (toupper(decision) == 'A'){
        addEvent(fileName);
    }
    else if (toupper(decision) == 'E'){
        modifyEvent(fileName);
    }
    return 0;
} 


*/