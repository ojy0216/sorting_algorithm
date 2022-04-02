#include <stdio.h>
#include <stdlib.h>

#define N 100

void swap(int arr[], int idx1, int idx2){
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int partition(int arr[], int left, int right){
    int pivot = arr[left];  // Pivot = first element
    int l_idx = left, r_idx;

    for(r_idx = left + 1; r_idx <= right; r_idx++){
        if(arr[r_idx] < pivot)
            swap(arr, ++l_idx, r_idx);
    }
    swap(arr, left, l_idx);

    return l_idx;
}

void quickSort(int arr[], int left, int right){
    if(left < right){
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
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
    quickSort(arr, 0, N - 1);
    printArray(arr, N);

    free(arr);    
}