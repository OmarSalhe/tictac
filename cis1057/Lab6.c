/*
    Lab06, Program by: Omar Salhe

In this program, two functions will be used if called upon. The first being list reader, which makes a list using user input until a sentinel
value is inputted, and then gives the length of the list, the numbers inside of it, the smallest and largest number, and the average value of the list.
The second function is quadratic equation solver, which, after being given the constants in a quadratic equation, finds both solutions to the equation
and determines whether or not if the solutions are complex (contains i) or not. 
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define SENTINEL -1

void list_read();
void quadratic_form();

int main(){
    int choice;

    do{
        printf("List Reader (1) or Quadratic Equation Solver (2): \n");
        scanf("%d", &choice);
    }
    while (choice < 1 || choice > 3);

    if (choice == 1){
        list_read();     
    }
    else {
        quadratic_form();
    }
    return 0;
}

void list_read(){
    int i = 0, counter = 0, total = 0, small = 0, large = 0;
    double avg = 0;
    int nums[999];  //assumed amount of inputs won't pass 999

    //Input loop
    do {
        printf("Enter a positive interger interger: \n");
        scanf("%d", &nums[i]);

        if (nums[i] == SENTINEL){
            printf("List Ended\n");
            break;
        }
        else if (nums[i] >= 0){
            i++;
        }
        else {
            printf("Must be a positive interger\n");
        }
    }
    while(TRUE);

    printf("\n");

    printf("You inputted: \n");

    for (int j = 0; j < i; j++){
           if (nums[j] != SENTINEL){    //excludes sentinel from processes
            if(j + 1 < i){
                printf("%d,", nums[j]);
                }
            else if (j + 1 == i){
                printf("%d \n", nums[j]);
                }
            
            small = nums[0];
            large = nums[0];

            if (small > nums[j]){   //compares every value to find the smallest
                small = nums[j];
                }

            if (large < nums[j]){   //compares every value to find the greatest
                large = nums[j];
                }
           }
            total += nums[j];
            counter++;  //number of iterations is equal to number of values in the list, excluding the sentinel
    }

    if (counter > 0){
        avg = (double) total / counter;
    }

    printf("Number of inputs: %d \n", counter);
    printf("Largest inputted number: %d \n", large);
    printf("Smallest inputted number: %d \n", small);
    printf("Estimated average of inputted values: %lf \n", avg);

/*
        TESTS
    List                    Output
1 2 4 9 33                  Number of inputs: 5 
                            Largest inputted number: 33 
                            Smallest inputted number: 1 
                            Estimated average of inputted values: 9 

1 18 43 28 999              Number of inputs: 5 
                            Largest inputted number: 999 
                            Smallest inputted number: 1 
                            Estimated average of inputted values: 217 

10 9 8 7 6 5 3 2 1          Number of inputs: 9 
                            Largest inputted number: 10 
                            Smallest inputted number: 1 
                            Estimated average of inputted values: 5 

210 012 102 201 021 120     Number of inputs: 6 
                            Largest inputted number: 210 
                            Smallest inputted number: 120 
                            Estimated average of inputted values: 111 

*/
}

void quadratic_form(){
    double a, b, c;
    double discrim, first_half, second_half; //first and second half of the quadratic formula
    int has_i = 0; //i as in imaginary number

    char ans[4];
    int no = 0;
        
        //loop allows for multiple equations to be solved without Command Line usage
        do {
            printf("Quadratic Equation = ax^2 + bx +c \n");

            printf("a = ");
            scanf("%lf", &a);
            printf("\n");

            printf("b = ");
            scanf("%lf", &b);
            printf("\n");

            printf("c = ");
            scanf("%lf", &c);
            printf("\n");

            discrim = pow(b, 2) - (4 * a * c);
            first_half = (-b) / (2 * a);

            if (discrim < 0){
                discrim *= -1;
                has_i = TRUE;
            }

            second_half = sqrt(discrim) / (2 * a);

            printf("\n");

            printf("Solutions: \n");
            
            if (has_i){
                printf("Solutions are complex\n");
                printf("%lf + %lfi \n", first_half, second_half);
                printf("%lf - %lfi \n", first_half, second_half);
            }
            else {
                printf("%lf + %lf \n", first_half, second_half);
                printf("%lf - %lf \n", first_half, second_half);
            }

            do{
                printf("Would you like to solve another equation? (yes or no) \n");
                scanf("%3s", ans);

                printf("\n");

                printf("You entered: %s \n", ans);

                if (strcmp(ans, "no") == 0){
                    no = 1; //sets the no response to true
                    break;
                }

                else if (strcmp(ans, "yes") == 0){      
                    break;
                }

                else {
                    printf("Please enter yes or no \n");
                }
            }
            while (TRUE);
        
        printf("\n");

        if (no){ //if no was stated do not ask again
            break;
        }
    }
    while(TRUE);

/*
        TESTS
    a    b    c       solutions
    1    0   -25    -0.000000 + 5.000000 and -0.000000 - 5.000000 
    2    -2  -12    0.500000 + 2.500000 and 0.500000 - 2.500000
    1    2    1     -1.000000 + 0.000000 and -1.000000 - 0.000000 
    3    4    5     Solutions are complex -0.666667 + 1.105542i and -0.666667 - 1.105542i
    
*/
}
