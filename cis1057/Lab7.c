#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
to do:

enter num and then stats as ltrs WHOSP

find num of indiivdual ltr given

find num of times at plate
official at bats (h + o)
hits
batting avg round 3 dec (= h / h + o )

    p = hit by pitch
    h = hit
    s = sacrifice
    w = walk
    o = out
*/

void stats(int, char*);                                             //processes inputted data
char uppercase(char*, int);                                         //prevents case related errors

#define TRUE 1

int main(){  
    int p_num;
    char* p_stat = malloc(101);                                     //capping input size to 100 bytes (aka 100 char's)

    char sentinel[3];                                               //only meant to store "end"

    do                                                              //removes the need to repeatedly recompile program
    {
        printf("Enter player number: ");
        scanf("%d", &p_num);

        printf("Formatting W (walks),H (hits),O (outs),S (sacrifice), and P (hit by pitch)\n");
        printf("Enter player stats in the given format (under 100 characters): ");
        scanf("%s", p_stat);

        printf("\n");

        *(p_stat + strlen(p_stat)) = '\0';                          //prevents program from accessing unwanted memory

        stats(p_num, p_stat);   

        printf("Enter 'end' to quit program\n");
        scanf("%s", sentinel);

        if (strcmp(sentinel, "end") == 0)
        {
            printf("Sentinel Inputted\n");
            printf("Program Ended\n");
            break;
        }
    }
    while (TRUE);

    free(p_stat);
    return 0;
}

void stats(int p_num, char* p_stat){
    int hit = 0, pitch = 0, out = 0, walk = 0, sac = 0, at_bat = 0, at_plate = 0; 
    for (int i = 0, n = strlen(p_stat); i < n; i++)
    {
        switch(uppercase(p_stat, i))
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
            printf("%c is not a valid input\n", uppercase(p_stat, i));
            break;
        }
    }
    printf("Number of times at plate: %d\n", at_plate);
    printf("Official at-bats: %d\n", at_bat);
    printf("Hits: %d\n", hit);
    
    if (at_bat == 0)
        printf("Batting average (rounded to 3 decimal places): 0");
    else
        printf("Batting average (rounded to 3 decimal places): %.3lf\n", (double)hit / at_bat);
}


char uppercase(char* p_stat, int i){
    char ltr = *(p_stat + i);       
    if (ltr >= 'a' && ltr <= 'z' )
    {
        return ltr - 32;
    }
    return ltr;
}

/*
        TESTS
Enter player number: 12
Enter player stats: HOOOWSHHOOHPWWHO

Number of times at plate: 16
Official at-bats: 11
Hits: 5
Batting average (rounded to 3 decimal places): 0.455

Enter player number: 4
Enter player stats: OSOHHHWWOHOHOOO

Number of times at plate: 15
Official at-bats: 12
Hits: 5
Batting average (rounded to 3 decimal places): 0.417

Enter player number: 7
Enter player stats: HOWOOWOSHOPHWOWOOHOSP

Number of times at plate: 21
Official at-bats: 13
Hits: 4
Batting average (rounded to 3 decimal places): 0.308


*/