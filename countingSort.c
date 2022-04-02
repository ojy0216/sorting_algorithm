#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

void countingSort(int arr[], int len){
    int max = arr[0];
    int min = arr[0];

    for(int i = 1; i < len; i++){
        if(arr[i] > max)    
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }

    // step 1
    int aux_size = max - min + 1;

    int* aux = malloc(sizeof(int) * aux_size);
    memset(aux, 0, sizeof(int) * aux_size);
    int* dst = malloc(sizeof(int) * len);

    // step 2
    for(int i = 0; i < len; i++)
        aux[arr[i] - min]++;

    // step 3
    for(int i = 1; i < aux_size; i++)   
        aux[i] += aux[i - 1];

    // step 4
    for(int i = len - 1; i >= 0; i--)
        dst[(aux[arr[i] - min]--) - 1] = arr[i];

    memcpy(arr, dst, sizeof(int) * len);

    free(aux);
    free(dst);
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
    countingSort(arr, N);
    printArray(arr, N);

    free(arr);    
}