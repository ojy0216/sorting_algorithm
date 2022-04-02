#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 199

void radixSort(int arr[], int len){
    int div = 1;
    int idx;

    int max_digit = 0;
    int max = arr[0];
    for(int i = 1; i < len; i++){
        if(arr[i] > max)
            max = arr[i];
    }

    while(max > 0){
        max /= 10;
        max_digit++;
    }
    printf("Max digit: %d\n", max_digit);

    for(int digit = 0; digit < max_digit; digit++){
        //step 1
        int* aux = malloc(sizeof(int) * 10);
        memset(aux, 0, sizeof(int) * 10);
        int* dst = malloc(sizeof(int) * len);

        // step 2
        for(int i = 0; i < len; i++){
            idx = arr[i] / div;
            while(idx >= 10)
                idx %= 10;

            aux[idx]++;
        }

        // step 3
        for(int i = 1; i < 10; i++)
            aux[i] += aux[i - 1];

        // step 4
        for(int i = len - 1; i >= 0; i--){
            idx = arr[i] / div;
            while(idx >= 10)
                idx %= 10;

            dst[(aux[idx]--) - 1] = arr[i];
        }

        div *= 10;

        memcpy(arr, dst, sizeof(int) * len);

        free(aux);
        free(dst);
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
    radixSort(arr, N);
    printArray(arr, N);

    free(arr);    
}