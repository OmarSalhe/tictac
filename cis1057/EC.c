//This program was made by Omar Salhe

#include <stdio.h>
#include <ctype.h>
#include <math.h>

void count_by_2();
void avg_of_list();
void fixed_code();
void with_gauss();
void colaz_conj();
void num_finder();
void is_prime();
void is_triangle();


#define TRUE 1
#define SENTINEL -1

int main(){
    int choice;
    char gauss_choice;

    printf("EC: 1, 2, 3, 4, 5, 6, 7: ");
    scanf("%d", &choice);
    printf("\n");

    if (choice == 1){
        count_by_2();
    }    
    else if (choice == 2){
        avg_of_list();
    }
    else if (choice == 3) {
        printf("with Gauss Formula? (Y or N): ");
        scanf(" %c", &gauss_choice);
        
        if (toupper(gauss_choice) == 'Y'){
            with_gauss();
        }
        else if (toupper(gauss_choice) == 'N'){
            fixed_code();
        }
    }
    else if (choice == 4){
        colaz_conj();
    }
    else if (choice == 5){
        num_finder();
    }
    else if (choice == 6){
        is_prime();
    }
    else if (choice == 7){
        is_triangle();
    }
    else{
        printf("Invalid Input");
    }
    return 0;
}

void count_by_2(){
    int bound;

    printf("Counting by 2 to ?: \n");
    scanf("%d", &bound);

    printf("starting from 2: ");
    for (int i = 2; i < bound; i+= 2){
        printf("%d ", i);
    }
    if (bound % 2 == 0)
        printf("%d", bound);

/*
    TEST
Counting by 2 to ?: 
19
starting from 2: 2 4 6 8 10 12 14 16 18

Counting by 2 to ?: 
40
starting from 2: 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40
*/
}

void avg_of_list(){
    int i = 0, avg = 0, counter = 0, length = 0;
    printf("Length of list: ");
    scanf("%d", &length);
    printf("\n");

    int nums[length];
    printf("Numbers in list: \n");

    while (counter < length){
        scanf("%d", &nums[i]);
        avg += nums[i];
        i++;
        counter++;
    }
    printf("The average of this list (rounded to two decimals): %.2lf \n", (double) avg/ i);

/*
    TEST
Length of list: 4
Numbers in list: 
1
5
6
100
The average of this list (rounded to two decimals): 28.00

Length of list: 2
Numbers in list: 
6000000
20
The average of this list (rounded to two decimals): 3000010.00 
*/
}

void fixed_code(){
int i;
long low, high, sum = 0;
printf("Please enter the lower bound: ");
scanf("%ld", &low);

printf("Please enter the upper bound: ");
scanf("%ld", &high);

for(i = low; i <= high; i++)  //just needed a less than or equal operator
    sum += i;


printf("\nThe sum of the integers from %ld to %ld is %ld",
low, high, sum);

/* 
    TESTS
Please enter the lower bound: 4
Please enter the upper bound: 5  
The sum of the integers from 4 to 5 is 9

Please enter the lower bound: 500
Please enter the upper bound: 503
The sum of the integers from 500 to 503 is 2006
*/
}

void with_gauss(){
    int lower, upper, first_sum = 0, second_sum = 0, ans = 0;

    printf("Enter lower bound: ");
    scanf("%d", &lower);

    printf("\n");

    printf("Enter upper bound: ");
    scanf("%d", &upper);

    for (int i = 1; i <= upper; i++){
        first_sum += i;
    }
    for (int j = 1; j < lower; j++){
        second_sum += j;
    }
    ans = first_sum - second_sum;
    printf("The sum from %d to %d is %d", lower, upper, ans);

    /*
        TESTS
        Please enter the lower bound: 1
        Please enter the upper bound: 10
        The sum of the integers from 1 to 10 is 55

        Please enter the lower bound: 1
        Please enter the upper bound: 3
        The sum of the integers from 1 to 3 is 6
    */
}

void colaz_conj(){
    int n;
    
    printf("Enter any positive interger: ");
    scanf("%d", &n);

    while (n != 1){
        int tmp = n;
        if (n % 2 == 0){
            n /= 2;
            printf("n = %d      %d / 2 = %d\n", tmp, tmp, n);
        }

        else{
            n = 3 * n + 1;
            printf("n = %d      3 * %d + 1 = %d\n", tmp, tmp, n);
        }
    }
    /*
        TESTS
        Enter any positive interger: 51  
        n = 51      3 * 51 + 1 = 154
        n = 154      154 / 2 = 77
        n = 77      3 * 77 + 1 = 232
        n = 232      232 / 2 = 116
        n = 116      116 / 2 = 58
        n = 58      58 / 2 = 29
        n = 29      3 * 29 + 1 = 88
        n = 88      88 / 2 = 44
        n = 44      44 / 2 = 22
        n = 22      22 / 2 = 11
        n = 11      3 * 11 + 1 = 34
        n = 34      34 / 2 = 17
        n = 17      3 * 17 + 1 = 52
        n = 52      52 / 2 = 26
        n = 26      26 / 2 = 13
        n = 13      3 * 13 + 1 = 40
        n = 40      40 / 2 = 20
        n = 20      20 / 2 = 10
        n = 10      10 / 2 = 5
        n = 5      3 * 5 + 1 = 16
        n = 16      16 / 2 = 8
        n = 8      8 / 2 = 4
        n = 4      4 / 2 = 2
        n = 2      2 / 2 = 1

        Enter any positive interger: 2
        n = 2      2 / 2 = 1
    */
}

void num_finder(){
    int num, tmp, find, found = 0;

    do {   
        printf("Enter a 5 to 6 digit interger: ");
        scanf("%d", &num);

        if (num == SENTINEL){
            printf("END");
            break;
        }

        printf("\n");

        printf("Enter a single digit number: ");
        scanf("%d", &find);

        printf("\n");

        tmp = num;
        for (int digit = 0; digit < 6; digit++){
            if (num % 10 == find){
                found++;
            }
            num /= 10;
        }
        
        if (found == 1){
            printf("%d appears in %d %d time\n", find, tmp, found);
        }
        else{
            printf("%d appears in %d %d times\n", find, tmp, found);
        }
    }
    while (TRUE);

    /*
        TESTS
    Enter a 5 to 6 digit interger: 123451
    Enter a single digit number: 1
    1 appears in 123451 2 times

    Enter a 5 to 6 digit interger: 133594
    Enter a single digit number: 1
    1 appears in 133594 1 time
    */
}

void is_prime(){
    int n, prime = 0;

    do {
        printf("Enter an interger (0 to quit) >=2: ");
        scanf("%d", &n);

        if (n == 0){
            printf("END");
            break;
        }
        else if((n % 2) == 0){
            if (n != 2){
                printf("%d is even, so not prime\n", n);
            }
            else{
                printf("%d is prime\n", n);
            }
        }
        else{
            for (int i = 3; i <= sqrt(n); i += 2){
                if ((n % i) == 0){
                    printf("%d is not prime; divisible by %d\n", n, i);
                    break;
                }
                else
                    prime = 1;
            }
            if (prime){
                printf("%d is prime\n", n);
            }
        }
    }
    while (TRUE);

/*
    TESTS
Enter an interger (0 to quit) >=2: 0
END

Enter an interger (0 to quit) >=2: 38
38 is even, so not prime

Enter an interger (0 to quit) >=2: 276
276 is even, so not prime

Enter an interger (0 to quit) >=2: 991
991 is prime

*/
}

void is_triangle(){
    int a, b, c;    //three sides to triangle

    printf("Enter size of side a: ");
    scanf("%d", &a);

    printf("Enter size of side b: ");
    scanf("%d", &b);

    printf("Enter size of side c: ");
    scanf("%d", &c);

    if ((a + b) > c && (a + c) > b && (b + c) > a)
        printf("can be a triangle");
    
    else
        printf("can not be a triangle");  

/*
    TESTS
Enter size of side a: 1
Enter size of side b: 2
Enter size of side c: 3
can not be a triangle

Enter size of side a: 5
Enter size of side b: 6
Enter size of side c: 4
can be a triangle
*/ 
}
