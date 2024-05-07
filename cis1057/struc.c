#include <stdio.h>
#include <stdlib.h>

struct string{
    char *string;
};


void str(struct string);

int main()
{
    int len;
    struct string say;

    len = printf("Say sum: \n");
    say.string = malloc(len + 1);
    scanf("%s", say.string);

    str(say);
    return 0;
}

void str(struct string say)
{
    printf("%s", say.string);
}