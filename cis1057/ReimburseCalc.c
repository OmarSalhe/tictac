#include <stdio.h>

int main()
{
double start_mile;  //declaring variables
double end_mile;

printf("Enter beginning odometer reading: \n");
scanf("%lf", &start_mile);
printf("Enter ending odometer reading: \n");
scanf("%lf", &end_mile);

double tot_mile = end_mile - start_mile;
double reimburse = tot_mile * .655; // Reimbursment rate

printf("You traveled %.2f miles. At $0.655 per hour, your reimbursement is $%.2f", tot_mile, reimburse);

return 0;
}