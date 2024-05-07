#include <stdio.h>

/* Farenheit to Celsius Converter*/
int main()
{
double temp_F; // creating a variable to store users input
printf("INSERT temprature Farenheit: \n");
scanf("%lf", &temp_F); // stores user input

double temp_C = (temp_F - 32.0) * (5.0 / 9.0); // conversion from F to C

printf("%.2f is %.2f in Celsius\n", temp_F, temp_C);

return 0;
}
