/*
    This program will find if an integer is divisible by 9 or estimate 
    pi by using a squence of n iterations, based on user's input
*/

#include <stdio.h>

int divis_by_9(int);
double pi_estimator(int);

int main()
{
        int n;                                                                              //stores user input used in either function (# of iterations or interger) 
        int user_choice;
        do 
        {
            printf("Would you like to see if an interger is divisible by 9 (1) or estimate pi (2)? (1 or 2): \n");
            scanf("%d", &user_choice);
        }
            
        while (user_choice != 2 && user_choice != 1);                                       // ensures only 1 or 2


        if (user_choice == 1)
        {
            printf("Selected: Divisible by 9\n");
            do
            {
                printf("Enter an interger: \n");
                scanf("%d", &n);
            }
            while (n < 0);
            
            if (divis_by_9(n))
            {
                printf("%d is divisible by 9\n", n);
            }
            else
            {
                printf("%d is not divisible by 9\n", n);
            }
        }
        else
        {
            printf("Selected: Pi Estimator\n");
            do
            {
                printf("Enter number of iterations: \n");
                scanf("%d", &n);
            }
            while (n < 0);

            printf("The estimated value of pi is %lf \n", pi_estimator(n) );
        }
    return 0;
}

int divis_by_9(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return (sum % 9 == 0);                                                                  // returns true/false based on condition
}
/*
        TESTS
n = 154368 -> 154368 is divisible by 9
n = 621594 -> 621594 is divisible by 9
n = 123456 -> 123456 is not divisible by 9

*/
double pi_estimator(int n)
{   
    int counter;                                                                            // counts number of iterations done
    double i = 1.0;                                                                         // pi series has a denominator that increments by 2 starting from 1
    double pi;                                                                              // pi series equation
    double estimate = 0;                                                                    // result after n number of iterations
   
    for (counter = 1; counter < n; counter++)                                               
    {   
        pi = 4 / i;
        if (counter % 2 == 0)                                                               // every other value is negative in the series
        {
            pi *= - 1;
            
        }
        estimate += pi;
        i += 2;                                                                             // in the series denominator increments by 2 
    }

    return estimate;
}

/*
        TESTS
n = 99999 -> The estimated value of pi is 3.141583 
math.tools -> 3.141592
2 digits off

n = 9999 -> The estimated value of pi is 3.141493 
math.tools -> 3.141592
3 digits off
*/
