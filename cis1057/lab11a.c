//PROBLEMS
/*
1.  run-tim error -> segmentation fault -> accessing unintended memory
    for (i = 0; i <= 8; ++i) -> for (i = 0; i < 8; ++i)

2.  No, unless the array is a struct, arrays can only contain one data type.

3. void reverse(int n, int x[], int y[]){
    for (int i = 0; i < n; i++){
        y[i] = x[(n - 1) - i];
    }
}

4.  for(int i = 0; i < row_height; i++){
    int sum = 0;
        for (int j = 0; j < row_width; j++){
            sum += table[i][j];
        }
    printf("\n row %d: sum = %d", (i + 1), sum);

}

*/





#include <stdio.h>

#define max_arr 25
#define SENTINEL -1

void selection_sort(int, int arr[]);
void merge(int, int, int arr[], int arr2[], int big_arr[]);
void result(int, int arr[]);

int main(){
    int arr1[max_arr], arr2[max_arr], a = 0, b = 0, merge_arr[2 * max_arr], i;

    printf("To break out of either loop enter -1");
 
    while (a < max_arr){
        printf("\nEnter an interger for Array 1: ");
        scanf("%d", &i);

        if (i == SENTINEL){ 
            break;
        }
        else{
            arr1[a] = i;
            a++;
        }
    }

    while (b < max_arr){
        printf("\nEnter an interger for Array 2: ");
        scanf("%d", &i);

        if (i == SENTINEL){
            break;
        }
        else{
            arr2[b] = i;
            b++;
        }
    }

    printf("\nUnsorted Array 1: ");
    result(a, arr1);
    
    printf("\nUnsorted Array 2: ");
    result(b, arr2);

    selection_sort(a, arr1);
    selection_sort(b, arr2);

    printf("\nSorted Array 1: ");
    result(a, arr1);

    printf("\nSorted Array 2: ");
    result(b, arr2);

    merge(a, b, arr1, arr2, merge_arr); //merging

    printf("\nMerged and Sorted Array: ");
    result(a + b, merge_arr);
    return 0;
}

void selection_sort(int a, int arr[]){
    for (int j = 0; j < a; j++){
        int min = j;
        for (int k = j + 1; k < a; k++){
            if (arr[min] > arr[k]){
                min = k;
            }
        }
        int tmp = arr[j];
        arr[j] = arr[min];
        arr[min] = tmp;
    }
}

void merge(int a, int b, int arr[], int arr2[], int big_arr[]){
    //while arr1 is less than arr2 place arr1 into big arr
    int l = 0, m = 0, k = 0;
    while ((l < a) && (m < b)){
        if (arr[l] < arr2[m]){
            big_arr[k] = arr[l];
            l++; 
        } 
        else{
            big_arr[k] = arr2[m];
            m++;
        }
        k++;
    }

    while (l < a){  // just in case, for any remaining values
        big_arr[k] = arr[l];
        k++;
        l++;
    }
    
    while (m < b){  // just in case, for any remaining values
        big_arr[k] = arr2[m];
        k++;
        m++;
    }
}

void result(int n, int arr[]){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

//TESTS
/*
Unsorted Array 1: 1 3 5 9 7
Unsorted Array 2: 2 0 4 8 6
Sorted Array 1: 1 3 5 7 9
Sorted Array 2: 0 2 4 6 8
Merged and Sorted Array: 0 1 2 3 4 5 6 7 8 9

Unsorted Array 1: 1 18 9 4 7 22 
Unsorted Array 2: 4 26 3 0 7 
Sorted Array 1: 1 4 7 9 18 22 
Sorted Array 2: 0 3 4 7 26 
Merged and Sorted Array: 0 1 3 4 4 7 7 9 18 22 26

Unsorted Array 1: 5 3 9 2 10 28 
Unsorted Array 2: 4 16 3 9 7 
Sorted Array 1: 2 3 5 9 10 28 
Sorted Array 2: 3 4 7 9 16 
Merged and Sorted Array: 2 3 3 4 5 7 9 9 10 16 28
*/