//Problems
/*
    1. 
        int main(){
            double ar1[30];
            char ar2[30];
            int ar3[20];

            for (int i = 0; i < 20; i++){
                printf("Entry for ar1: ");
                scanf("%lf", &ar1[i]);

                printf("Entry for ar2: ");
                scanf(" %c", &ar2[i]);

                printf("Entry for ar3: ");
                scanf("%d", &ar3[i]);
            }
        }
        return 0;
    
    2. 
        a) Valid call, combines ar1 and ar2 into c
        b) Invalid call, segmentation fault, index past 5 does not exist
        c) Valid call, stores sums of c and d into e
        d) Invalid call, specified size does not match the size of the arrays
        e) Invalid call, size of array is 6 not 3
        g) Valid call, effectively multiplies the elements of c by 2 and stores them into c
        h) Invalid call, no output array to store sums into
        i) Invalid call, specified size 7 does not match the size of the arrays, 6.
        j) Invalid call for i and ii, array size must be an integer.

    3. 
*/

//Coding Problem
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define max 20
#define SENTINEL 0
#define TRUE 1

double get_poly(double arr[], double, int*);
double eval_poly(double arr[], double, int);
double horner_eval(double arr[], double, int);

int main(){
    double coeff[max], x;
    int n;
    char choice;

    do{
        printf("Enter a value for x: ");
        scanf("%lf", &x);

        get_poly(coeff, x, &n);
        printf("\n");

        printf("With Horner's Algorithm? (Y or N): ");
        scanf(" %c", &choice);
        if (toupper(choice) == 'Y'){
            printf("f(%lf) = %lf", x, horner_eval(coeff, x, n));
        }
        
        else if (toupper(choice) == 'N'){
          printf("f(%lf) = %lf", x, eval_poly(coeff, x, n));
        }
        
        else{
            printf("Invalid Input");
        }

        printf("\n");
        printf("Input 0 to continue, anything else to quit");
        scanf("%lf", &x);

        if (x != SENTINEL){
            printf("Exited Loop\n");
            break;
        }
    }
    while(TRUE);
    
    return 0;
}

double get_poly(double arr[], double x, int* n){
    printf("Enter highest power (less than 20): \n");
    scanf("%d", n);

    printf("Enter coefficients from lowest to highest power\n");
    for (int i = 0; i < *n + 1; i++){
        printf("Enter coefficient: ");
        scanf("%lf", &arr[i]);
    }
    printf("f(%lf) = ", x);
    for (int i = 0; i < *n + 1; i++){
        
        if (i < *n){
            printf("%lf * %lf^%d +", arr[i], x, i);
        }
        else{
            printf("%lf * %lf^%d", arr[i], x, i);
        }
    }
}

double eval_poly(double arr[], double x, int n){
    double ans = 0;
    for (int i = 0; i < n + 1; i++){
        ans += arr[i] * pow(x, (double)i);
    }
    return ans;
}

double horner_eval(double arr[], double x, int n){
    if (n == 0){
        return arr[0];
    }
    return (x * arr[n]) + horner_eval(arr, x, n - 1);
}

//Horner's Algo
/* 
    a[0] + x(a[1]+x(a[2]+....+x(a[n-1] + a[n]x))
*/