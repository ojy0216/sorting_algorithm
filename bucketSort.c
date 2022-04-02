#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

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

// void printArray(int arr[], int len);

void bucketSort(int arr[], int len, int bucketNum){
    int** bucket = malloc(sizeof(int*) * bucketNum);
    for(int i = 0; i < bucketNum; i++){
        bucket[i] = malloc(sizeof(int) * N);
        memset(bucket[i], 0, sizeof(int) * len);
    }

    int* bucketIndex = malloc(sizeof(int) * bucketNum);
    memset(bucketIndex, 0, sizeof(int) * bucketNum);

    int min = arr[0];
    for(int i = 1; i < len; i++){
        if(arr[i] < min)
            min = arr[i];
    }

    int idx;
    for(int i = 0; i < len; i++){
        idx = (arr[i] - min) / (len / bucketNum);
        bucket[idx][bucketIndex[idx]++] = arr[i];
    }

    // for(int i = 0; i < bucketNum; i++){
    //     printf("Bucket %d\n", i + 1);
    //     printArray(bucket[i], bucketIndex[i]);
    // }

    for(int i = 0; i < bucketNum; i++)
        insertionSort(bucket[i], bucketIndex[i]);

    int totalCount = 0;
    for(int i = 0; i < bucketNum; i++){
        int j = 0;
        while(bucket[i][j] != 0)
            arr[totalCount++] = bucket[i][j++];
    }

    for(int i = 0; i < bucketNum; i++)
        free(bucket[i]);
    free(bucket);
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

    int bucketNum;
    switch(N){
        case 10000:
            bucketNum = 50;
            break;
        case 1000:
            bucketNum = 20;
            break;
        default:
            bucketNum = 10;
    }
    printf("Bucket Num: %d\n", bucketNum);

    printArray(arr, N);
    bucketSort(arr, N, bucketNum);
    printArray(arr, N);

    free(arr);    
}