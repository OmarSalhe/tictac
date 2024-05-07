//Problems
/*
1. Data Structure = a composite of related data items stored under the same name
2. No, due to the nature of arrays, you can only input data under the same data type the array was initialized as
3. fn_one will likely manipulate b[], while fn_two will likely read b[] because of the "const" preceding it.
4. The user will input a number, the number will be stored as an array element, and the loop will repeat this placing each input into their own designated array element. This will continue until the array has no more available elements
5.  A) 8
    B) m[x][y]: x = row, y = column
*/

//Program Desc
/*
    In this program, a file, containing test information in the format: number of questions and correct
    answers, in that order, on the first row and student's ID and and answers, in that order, on the rows after, is read.
    The student's ID and scores are then printed onto a report file with correct answers being displayed on top.
*/
#include <stdio.h>

#define max 100 // general maximum number of inputs


void grading(int num_s, int num_q, char s_ans[max][max], char c_ans[], int scores[]); //compares correct answers to student answers and scores appropriately (correct answers/total answers)

void report(int num_s, int num_q, char s_ans[max][max], char c_ans[], int scores[], int id[]); // creates a file and prints a table holding student's id and scores with the correct answers on top

int main(){
    FILE* examdata;
    int num_s, num_q, id[max], status = 0, i, scores[max], tmp_num; 
    char c_ans[max], tmp_ans[max], s_ans[max][max];


    examdata = fopen("/Users/omar./Downloads/examdata.txt", "r");

    if (NULL == examdata){
        printf("Could not access/find file\n");
        return -1;
    }  
    for (i = 0; i < max; i++){
        status = fscanf(examdata, "%d %s", &tmp_num, tmp_ans);
        
        if (status == EOF){
            break;
        }
        else{
            if (i == 0){
                num_q = tmp_num;
                for (int j = 0; j < num_q; j++){
                    c_ans[j] = tmp_ans[j];
                }
            }
            else{
                if (status != 2){                       //if either the id or answers are not scanned
                    printf("Could not read ID number and or student answers");
                    id[i - 1] = -1;
                    for (int j = 0; j < num_q; j++){    
                        s_ans[i-1][j] = 'N';    
                    }
                }
                else{
                    id[i - 1] = tmp_num;                //index starts at 0, id is not assigned until i = 1
                    for (int j = 0; j < num_q; j++){    //merges temporary array into student answers array
                        s_ans[i-1][j] = tmp_ans[j];     //index starts at 0, student aswers are not assigned until i = 1
                    }
                }
            }
        }
    }      
    num_s = i - 1;  //i (total # of iterations) = student answers (num_s) + EOF(1) + correct answers(1)

    grading(num_s,num_q, s_ans, c_ans, scores); //outputs scores values into score array
    report(num_s, num_q, s_ans, c_ans, scores, id); //prints results

    fclose(examdata);
    return 0;
}

void grading(int num_s, int num_q, char s_ans[max][max], char c_ans[], int scores[]){
    int points;

    for (int k = 0; k < num_s; k++){
        points = 0;
        for (int l = 0; l < num_q; l++){
            if (c_ans[l] == s_ans[k][l]){
                points++;
            }
        }
        scores[k] = ((float)points / num_q) * 100;
    }

}
    
void report(int num_s, int num_q, char s_ans[max][max], char c_ans[], int scores[], int id[]){
    FILE* reportfile;

    reportfile = fopen("/Users/omar./Code/C_Code/C_Class/report.txt", "w");  

    if (reportfile == NULL){
        printf("File cannot be made");
        return;
    }
    fprintf(reportfile, "       Exam Report\n");
    fprintf(reportfile, "Questions: ");
    for(int n = 0; n < num_q; n++){
        fprintf(reportfile, " %d ", (n + 1));
    }
    fprintf(reportfile, "\n");
    fprintf(reportfile, "Answer:    ");
    for(int o = 0; o < num_q; o++){
        fprintf(reportfile, " %c ", c_ans[o]);
    }
    fprintf(reportfile, "\n"); 
    fprintf(reportfile, "ID     Score\n");
    for (int p = 0; p < num_s; p++){
        fprintf(reportfile, "%d     %d \n", id[p], scores[p]);
    }

    fclose(reportfile);
}




/*
Design and implement a program that will grade a multiple choice test of up to 50 questions and provide
feedback in the form of the number of students who answered each question incorrectly. To get full credit,
your program must read the data from a text file rather than the keyboard (- 5 points for keyboard input). A
sample data file is provided with this lab, as is a sample program that reads a text file line by line but you
will have to modify the code to work with the data file in this problem.
The first line of the file contains an integer between 5 and 50 giving the number of questions on the “test”.
The rest of the first line contains the “answers” against which the students’ responses are to be compared.
Lines 2 to n+1 (n is the number of student responses) contain an integer (the student ID number) followed
by 5 to 50 characters representing the “student’s” responses.ld be its own line

psuedo
1. create an array that will store all data first row will contain correct
answers and the rest will be student attempts 
2. create a second function that compares answers and find score and stores the student
id and score into new array
3. print new arrays onto file
*/

//File read code:
/*
do{
        status = fscanf(ptr, "%d %c%c%c%c%c", &id,&c1,&c2,&c3,&c4,&c5);
        printf("%d %c %c %c %c %c\n", id,c1,c2,c3,c4,c5);
    }    
while (status != EOF);

*/