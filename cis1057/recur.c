#include <stdio.h>

int factorial(int);
void pyramid(int);

int main(){
    int num;
    
    printf("Enter interger: \n");
    scanf("%d", &num);

    pyramid(num);

    
    return 0;
}

int factorial(int num){
    if (num <= 0){
        return 1;
    }
    else{
        int ans = num * factorial(num - 1);
        // x! = x(x-1)(x-2)*....1 = x!*x!(x-1)!*....*1

    printf("%d! = %d", num, factorial(num));
    return 0;
    }
}

void pyramid(int num){
    if (num <= 0){
        return;
    }
    pyramid(num -1);

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++) 
        {
            print(" ");
        }
        printf("#");
    }

    printf("\n");
}