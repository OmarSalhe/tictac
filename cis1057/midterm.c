/*
prog 1: how_many()
reads how many x's are found (upper or lower)
stops at !
prints num of x's
prints tot num of ltrs

make a for loop if ltr[i] = ! break 
else 
    if ltr[i]== 'x'
        num_x++
    
    num_ltr++
*/


#include <stdio.h>

int how_many()
{
    int max = 102; //max char entered including ! and \0
    char ltr[max];
    int num_x = 0;
    int num_ltr = 0;

    printf("Enter a combination of letters and x's ending in a ! (max of 100): \n");
    scanf("%s",ltr);

    for (int i = 0; i < max; i++)
    {
        if (ltr[i] == '!')
            break;
        
        else
        {
            if (ltr[i] == 'x')
                num_x++;
            
            num_ltr++;
        }
    }

    return 0;
}