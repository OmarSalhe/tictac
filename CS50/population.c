#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        printf("Starting size: ");
        scanf("%d", start);
    }
    while (start < 9);

    // TODO: Prompt for end size
    int final;
    do
    {
        printf("Final size: \n");
        scanf("%d", final);
    }
    while (final < start);
    
    // TODO: Calculate number of years until we reach threshold

    int yrs = 0;
    int born;
    int pass;

    if (start < final)
    {
        do
        {
            born = start / 3;
            pass = start / 4;
            start = start + born - pass;
            yrs++;
        }
        while (start < final);
    }
    else
    {
        printf("Years: 0");
    }
    printf("Years: %d \n", yrs);
    return 0;
}
