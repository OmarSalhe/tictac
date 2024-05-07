#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void coding_problem1();
int letter_grade(char*, bool*, int); //Problem 1

void coding_problem2();
void two_points(double*, double*, double*, double*, double*, double*, bool*);
void point_slope(double*, double*, double*,  double*, bool*);
void slope_inter(double*, double*, bool*);

int main(){
    int choice;
    printf("coding problem: letter grades (1) or coding problem: line forms (2)");
    scanf("%d", &choice);

    if (choice == 1)
        coding_problem1();
    else if (choice == 2)
        coding_problem2();
    
    return 0;
}
void coding_problem1(){
    int points;
    bool just_missed = false;
    char letter;

    printf("Enter a score: ");
    scanf("%d", &points);
    if(points <=100)
    {
        letter_grade(&letter, &just_missed, points);
        printf("You scored a %c", letter);
        if (just_missed){
            printf("and you just missed a %c ", letter_grade(&letter, &just_missed, points));
            }
    }
    else
        printf("Invalid Score");
}
// Problem 1: DONE
int letter_grade(char* y, bool* z, int x){

    if (x >= 90)
        *y = 'A';
    else if (x >= 80 && x < 90)
        *y = 'B';
    else if (x >= 70 && x < 80)
        *y = 'C';
    else if (x >= 60 && x < 70)
        *y = 'D';
    else if (x < 60)
        *y = 'F';
        
    if ((x % 10) == 9 && x < 90)
        *z = true;
    return *(y-1);
}

/*Problem 2: DONE
By using non-void function's retrun statement, a program can be split into smaller functions based on tasks.
By splitting up the tasks, the coding process is simplified into smaller, easier, tasks improving overall program
conciseness and readability. This also makes updating and debugging easier as each tasks are done independently,
in their own function, and won't be affected by changes to another function.
*/

/*Problem 3: DONE
int grumpy(int dopey) can recursively call itself and int main(void) can call grumpy normally.
*/

//Coding Problem
void coding_problem2(){
    double x1, x2, y1, y2, m, b;
    char choice;
    bool og_input = false;
    printf("Choose a line form:\n");
    printf("Two-points(A), Point-slope(B), Slope-intercept(C): ");
    scanf("%c", &choice);

    switch (tolower(choice))
    {
        case 'a':
            two_points(&x1, &x2, &y1, &y2, &m, &b, &og_input);
            break;
        case 'b':
            point_slope(&x1, &y1, &m, &b, &og_input);
            break;
        case 'c':
            slope_inter(&m, &b, &og_input);
            break;
        default:
            printf("A, B, or C!");
            break;
    }

    printf("Slope-Intercept Form: y = %lfx + %lf", m, b);
}
void two_points(double* x1, double* x2, double* y1, double* y2, double* m, double* b, bool* og_input){
    printf("Enter 2 pairs of coordinates separated by a comma one at a time (Ex. x, y): ");
    scanf("%lf,%lf,%lf,%lf", x1, y1, x2, y2);

    *m = (*y2 - *y1)/(*x2 - *x1);

    *og_input = true;

    point_slope(m, x1, y1, b, og_input);
}

void point_slope(double* y1, double* x1, double* slope, double* y_inter, bool* not_b ){
    if (!*not_b){
        printf("Enter one point and a slope seperated by a comma (Ex. x, y, m): ");
        scanf("%lf,%lf,%lf", y1, x1, slope);
    }

    *y_inter = *y1 - *slope * *x1;

    *not_b = true;
    
    slope_inter(y_inter, slope, not_b);
}

void slope_inter(double* slope , double* y_inter, bool* not_c){
    if (!*not_c){
        printf("Enter a slope and a y-intercept seperated by a comma (m, b): ");
        scanf("%lf, %lf", slope, y_inter);
    }
}
/*
Coding problem:
Design and implement a program that permits a user to choose among the three forms for a line and
converts all inputs to the slope-intercept form. See next page for description and formulas. The program
should print out a set of instructions (see below), allow the user to choose one of the three methods of
describing a line: a) given two points, b) given one point plus a slope, or c) given the slope and the y-
intercept and output the slope intercept form of the line: if the slope is m and intercept is b the slope-
intercept form is y = mx + b . If option a or b is chosen, the program computes the slope and intercept then
prints the slope-intercept form for the line described by the inputs. If given the slope and intercept (option
c), no calculation is necessary and the slope-intercept form can be printed immediately

goal = turn line info into slope intercept form
a = two points (y2 - y1 / x2 - x1) = m)
b = one point + slope (y - y1 = m(x2 - x1))
c = slope + intercept (y = mx + b)

a -> b -> c -> print (c)

if a is selected find m and give one point to b
if b is selected find b and give to c
no process done for 3

not_c = input was not c
not_b = input was not b

if not_b dont ask for inputs, just do processes

if not_c do same as not_b


*/
