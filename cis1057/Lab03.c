// Code by Omar Salhe
// Factorial Approximator + Monthly Loan Payment Finder

#include <stdio.h>
#include <math.h>
double monthly_payment(double, double, double, double); // Introduces functions later used
double factorial_find(double);

#define PI 3.1415926
#define E 2.718281827

int main()
{   
    int user_choice;
    
    double cost;
    double d_pay;
    double number_of_pay;
    double yr_rate;
    double factorial;

    do
    {
        printf("Calculate Loan Payment or Factorial Approximation (1 or 2): \n");
        scanf ("%d",&user_choice);
    }
    while (user_choice != 2 || user_choice != 1 );


        if (user_choice == 1) // gives user choice and allows for a more interactive experience
          {
            printf("Enter cost of car: \n");
            scanf("%lf", &cost);
            
            printf("Enter down payment: \n");
            scanf("%lf", &d_pay);
            
            printf("Enter annual interest rate: \n");
            scanf("%lf", &yr_rate);
            
            printf("Enter number of payments: \n");
            scanf("%lf", &number_of_pay);
            
            double monthly_pay = monthly_payment(cost, d_pay, yr_rate, number_of_pay); // uses inputted variables and sets value to another variable
            
            printf("Your monthly payment is: $%.2f \n", monthly_pay);
            printf("\n");
           }
           else if (user_choice == 2) 
           {
            printf("Enter an interger: \n");
            scanf ("%lf", &factorial);
                
            double factor = factorial_find(factorial);
            
            if (factorial < 0)
            {
                printf("Inputted Value Must Be Greater Than 0");
            }
            else
            {
                printf("%.0f! is approximately %lf \n",factorial, factor);
                printf("\n");
            }
            
           }
    return 0;
}
    
    double monthly_payment(double cost, double d_pay, double yr_rate, double number_of_pay)
    {
        double monthly_rate = yr_rate / 12;
        double principal = cost - d_pay;
            
        return (principal * monthly_rate) / (1 - pow((1 + monthly_rate), (-1 * number_of_pay))); // monthly payment equation
        
    }
    /* 
        Input: 30000, 1000, .06, 24     Output: Your monthly payment is $1285.30.
        
        Car: 2023 Lamborghini Huracan Sterrato
        Price = $237,177
        Principal = $235,000
        Rates: .0507, .0644, .0899, .1172, MyOwn
        
        Rate: .0507         Payment: Your monthly payment is: $4442.28 
        Rate: .0644         Payment: Your monthly payment is: $4591.44
        Rate: .0899         Payment: Your monthly payment is: $4877.07
        Rate: .1172         Payment: Your monthly payment is: $5194.26
        Rate: .0389         Payment: Your monthly payment is: $4316.23
        
    */;
        
    double factorial_find(double factorial)
    {
        double factor;
        if (factorial == 1 || 0)
        {
            factor = 1; // prevents 0! from equalling 0
        }
        else if (factorial > 1)
        {
            factor = pow((factorial / E), factorial) * (sqrt( (2 * factorial * PI) + (PI / 3))); // Gosper's Formula
        }
        return factor;
    }
    
    /*  
    n: 0  Actual: 1    My: 1

    n: 1  Long: 1.190473759458304 Short: 0.9960 Actual: 1  My: 1
    
    n: 2  Long: 1.997363055661086 Short: 1.9974  Actual: 2 My: 1.997363
    
    n: 3  Long: 5.996135354859048 Short: 5.9961 Actual: 6 My: 5.996135
    
    n: 4  Long:24.0000034728 Short: 23.9909 Actual: 24  My: 23.990889
    
    n: 5  Long: 119.9700301696  Short: 119.9700  Actual: 120  My: 119.970029
    
    n: 6  Long: 720.0000545381  Short: 719.8728  Actual: 720 My: 719.872825
    
    n: 7  Long: 5040.0002442346  Short: 4980.3958 Actual: 5040 My: 5039.337455
    
    n: 8  Long: 40320.0012812592 Short: 40315.9028 Actual: 40320 My: 40315.902652
    
    n: 9  Actual: 362880 My: 362850.645448
    */

