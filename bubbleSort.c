#include <stdio.h>
#include <stdlib.h>

#define N 100

void bubbleSort(int arr[], int len){
    int tmp;

    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < (len - i) - 1; j++){
            if(arr[j] > arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
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
    bubbleSort(arr, N);
    printArray(arr, N);

    free(arr);    
}