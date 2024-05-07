#include <stdio.h>

#define TRUE 1
#define max 101

void findPrime(int isPrime[]);

int main(){
    int isPrime[max];
    findPrime(isPrime);

    for(int i = 0; i < max; i++){
        if (i < (1 - max)){
            printf("%d, ", isPrime[i]);
        }

        else{
            printf("%d", isPrime[i]);
        }
    }
    return 0;
}

void findPrime(int isPrime[]){
    int count = 0;
    int i = 2; //first prime num

    while(TRUE){
        if (count == max){
            break;
        }

        for(int j = 1; j < i; j++){
            if ((i % j) != 0){
                isPrime[count] = i;
            }
        }
        i++;
    }
}
