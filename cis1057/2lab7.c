#include <stdio.h>
#include <string.h>
#include <ctype.h>

void stats(char arr[], int);

#define max 100 //upper input size of 100 characters

int main()
{
    char p_stat[max];
    int p_num;

    printf("Stat format: W(walk), H(hits), O(outs), S(sacrifice), P(hit by pitch)\n");
    
    printf("Enter player number and stats (under 100 characters): ");

    if (scanf("%d", &p_num) == 1) //if scanf successfully finds an interger in user input
    {
        scanf("%s", p_stat);
        stats(p_stat, p_num);
    }
    else 
    {
        printf("Incorrect Input\n");
        printf("Must begin with player number\n"); 
    }

    return 0;
}

void stats(char p_stat[], int p_num)
{
    int hit = 0, pitch = 0, out = 0, walk = 0, sac = 0, at_bat = 0, at_plate = 0; 
    for (int i = 0, n = strlen(p_stat); i < n; i++)
    {
        switch(toupper(p_stat[i])) //only accepts capital letters
        {
            case 'H':
                hit++;
                at_bat++;
                at_plate++;
                break;

            case'W':
                walk++;
                at_plate++;
                break;
            
            case'S':
                sac++;
                at_plate++;
                break;
            
            case 'O':
                out++;
                at_bat++;
                at_plate++;
                break;
            
            case'P':
                pitch++;
                at_plate++;
                break;
            
            default:
            printf("%c is not a valid input\n", toupper(p_stat[i]));
            break;
        }
    }

    printf("\n");
    printf("Player Number: %d\n", p_num);
    printf("Number of times at plate: %d\n", at_plate);
    printf("Official at-bats: %d\n", at_bat);
    printf("Hits: %d\n", hit);
   
    if (at_bat == 0) //prevents division by 0
        printf("Batting average (rounded to 3 decimal places): 0\n");
    else
        printf("Batting average (rounded to 3 decimal places): %.3lf\n", (double)hit / at_bat);
}
/*
        TESTS
Enter player number: 12 HOOOWSHHOOHPWWHO
Number of times at plate: 16
Official at-bats: 11
Hits: 5
Batting average (rounded to 3 decimal places): 0.455

Enter player number: 4 OSOHHHWWOHOHOOO
Number of times at plate: 15
Official at-bats: 12
Hits: 5
Batting average (rounded to 3 decimal places): 0.417

Enter player number and stats: 7 HOWOOWOSHOPHWOWOOHOSP
Number of times at plate: 21
Official at-bats: 13
Hits: 4
Batting average (rounded to 3 decimal places): 0.308

Enter player number and stats: hi HOWOWOWHOSPHOW
Incorrect Input

Enter player number and stat: wowowowo21wowowow
Incorrect Input
Must begin with player number

Enter player number and stats (under 100 characters): 21WHOOSHOSOP
Player Number: 21
Number of times at plate: 10
Official at-bats: 6
Hits: 2
Batting average (rounded to 3 decimal places): 0.333

Stat format: W(walk), H(hits), O(outs), S(sacrifice), P(hit by pitch)
Enter player number and stats (under 100 characters): 12 abcde
A is not a valid input
B is not a valid input
C is not a valid input
D is not a valid input
E is not a valid input

Player Number: 12
Number of times at plate: 0
Official at-bats: 0
Hits: 0
Batting average (rounded to 3 decimal places): 0

*/