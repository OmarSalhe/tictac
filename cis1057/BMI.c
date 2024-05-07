/* Your #include directives go here */
#include <stdio.h>
#include <math.h>

/* Your # define directives, if any, go here */

#define SENTINEL  -1  //input sentinel value; end of input, exit program when entered
#define TRUE 1
#define inchPerFeet 12

/* function prototype */

double ComputeBMI(int HeightInches, int WeightPounds);
void userBMIClass(double BMI);

int main(){
    int feet, inches;  //Height in inches, weight in pounds
    char ft[] = {" ft "}, in[] = {"in"};
    double weight;

    do { 
        printf("Enter height in feet and inches\n");

        printf("Make sure to separate units with a space. Ex. : 5 ft 7 in\n");

        scanf("%d%4s %d %2s", &feet, ft, &inches, in ); 

        printf("Enter weight in pounds: \n");

        scanf("%lf", &weight );

        printf("Your BMI is %.1lf\n", ComputeBMI ((feet * inchPerFeet) + inches, weight));

        userBMIClass(ComputeBMI ((feet * inchPerFeet) + inches, weight));

        printf("Enter %d to exit?  \n", SENTINEL);

        scanf("%d", &feet );
        
        if (feet == SENTINEL){
            break;
        }
    }
    while (TRUE);    

    return 0;
    } //end main

//your ComputeBMI() function goes here:
double ComputeBMI(int HeightInches, int WeightPounds){
    int BMI = (703 * WeightPounds) / pow(HeightInches, 2);
    return BMI;
}

void userBMIClass(double BMI){
    printf("BMI             Status \n18.5            underweight\n18.5-24.9	    normal\n25.0-29.9	    overweight\n30.0 and above	Obese\n");

    if (BMI <= 18.5){
        printf("You are Underweight\n");
    }
    else if (BMI >= 18.5 && BMI <= 24.9){
        printf("You are Normal\n");
    }
    else if (BMI >= 25 && BMI <= 29.9){
        printf("You are Overweight\n");
    }
    else{
        printf("You are Obese\n");
    }
}
