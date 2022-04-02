#include <stdio.h>
#include <stdlib.h>

#define N 100

void insertionSort(int arr[], int len){
    int key;
    int j;

    for(int i = 1; i < len; i++){
        key = arr[i];

        for(j = i - 1; j >= 0; j--){
            if(arr[j] > key)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int len){
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int* arr = malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++)
        arr[i] = N - i;

    printArray(arr, N);
    insertionSort(arr, N);
    printArray(arr, N);

    free(arr);    
}