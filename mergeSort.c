#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

void merge(int arr[], int left, int mid, int right){
    int l_idx = left;
    int r_idx = mid + 1;
    int idx = left;

    int* sorted = malloc(sizeof(int) * (right + 1));

    while(l_idx <= mid && r_idx <= right){
        if(arr[l_idx] <= arr[r_idx])
            sorted[idx++] = arr[l_idx++];
        else
            sorted[idx++] = arr[r_idx++];
    }

    if(l_idx > mid){
        for(int i = r_idx; i <= right; i++)
            sorted[idx++] = arr[i];
    }
    else{
        for(int i = l_idx; i <= mid; i++)
            sorted[idx++] = arr[i];
    }

    memcpy(arr + left, sorted + left, sizeof(int) * (right - left + 1));
    // for(int i = left; i <= right; i++)
    //     arr[i] = sorted[i];

    free(sorted);
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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
    mergeSort(arr, 0, N - 1);
    printArray(arr, N);

    free(arr);    
}