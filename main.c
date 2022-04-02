#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

#define SEC_TO_US 1000000

typedef struct timeval time_st;

void swap(int arr[], int idx1, int idx2);

void bubbleSort(int arr[], int len);
void selectionSort(int arr[], int len);
void insertionSort(int arr[], int len);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void countingSort(int arr[], int len);
void radixSort(int arr[], int len);
void bucketSort(int arr[], int len, int bucketNum);

void printArray(int arr[], int len);
long getTimeDiff(time_st start, time_st end);

enum sorting{
    BUBBLE,
    SELECTION,
    INSERTION,
    MERGE,
    QUICK,
    RADIX,
    BUCKET,
    NUM_OF_SORTING
};

int main(){
    time_st start, end;

    long result[NUM_OF_SORTING][3] = {0, }; 

    const int N[3] = {100, 1000, 10000};

    const char sortingNames[NUM_OF_SORTING][10] = {
        "Bubble",
		"Selection",
        "Insertion",
        "Merge",
        "Quick",
        "Radix",
        "Bucket"
    };

    // BubbleSort
    for(int n = 0; n < 3; n++){
        int* input = malloc(sizeof(int) * N[n]);
        for(int i = 0; i < N[n]; i++)
            input[i] = N[n] - i;
        
        printf("Bubble Sort, Size: %d, Unsorted\n", N[n]);
        printArray(input, N[n]);

        sleep(1);

        gettimeofday(&start, NULL);
        bubbleSort(input, N[n]);
        gettimeofday(&end, NULL);
        result[BUBBLE][n] = getTimeDiff(start, end);

        printf("Bubble Sort, Size: %d, Sorted\n", N[n]);
        printArray(input, N[n]);

        free(input);
    }

    // SelectionSort
   for(int n = 0; n < 3; n++){
	   int* input = malloc(sizeof(int) * N[n]);
	   for(int i = 0; i < N[n]; i++)
		   input[i] = N[n] - i;

	   printf("Selection Sort, Size: %d, Unsorted\n", N[n]);
	   printArray(input, N[n]);

	   sleep(1);

	   gettimeofday(&start, NULL);
	   selectionSort(input, N[n]);
	   gettimeofday(&end, NULL);
	   result[SELECTION][n] = getTimeDiff(start, end);

	   printf("Selection Sort, Size: %d, Sorted\n", N[n]);
	   printArray(input, N[n]);

	   free(input);
   }

    // InsertionSort
    for(int n = 0; n < 3; n++){
        int* input = malloc(sizeof(int) * N[n]);
        for(int i = 0; i < N[n]; i++)
            input[i] = N[n] - i;
        
        printf("Insertion Sort, Size: %d, Unsorted\n", N[n]);
        printArray(input, N[n]);

        sleep(1);

        gettimeofday(&start, NULL);
        insertionSort(input, N[n]);
        gettimeofday(&end, NULL);
        result[INSERTION][n] = getTimeDiff(start, end);

        printf("Insertion Sort, Size: %d, Sorted\n", N[n]);
        printArray(input, N[n]);

        free(input);
    }

    // MergeSort
    for(int n = 0; n < 3; n++){
        int* input = malloc(sizeof(int) * N[n]);
        for(int i = 0; i < N[n]; i++)
            input[i] = N[n] - i;
        
        printf("Merge Sort, Size: %d, Unsorted\n", N[n]);
        printArray(input, N[n]);

        sleep(1);

        gettimeofday(&start, NULL);
        mergeSort(input, 0, N[n] - 1);
        gettimeofday(&end, NULL);
        result[MERGE][n] = getTimeDiff(start, end);

        printf("Merge Sort, Size: %d, Sorted\n", N[n]);
        printArray(input, N[n]);

        free(input);
    }

    // QuickSort
    for(int n = 0; n < 3; n++){
        int* input = malloc(sizeof(int) * N[n]);
        for(int i = 0; i < N[n]; i++)
            input[i] = N[n] - i;
        
        printf("Quick Sort, Size: %d, Unsorted\n", N[n]);
        printArray(input, N[n]);

        sleep(1);

        gettimeofday(&start, NULL);
        quickSort(input, 0, N[n] - 1);
        gettimeofday(&end, NULL);
        result[QUICK][n] = getTimeDiff(start, end);

        printf("Quick Sort, Size: %d, Sorted\n", N[n]);
        printArray(input, N[n]);

        free(input);
    }

    // RadixSort
    for(int n = 0; n < 3; n++){
        int* input = malloc(sizeof(int) * N[n]);
        for(int i = 0; i < N[n]; i++)
            input[i] = N[n] - i;
        
        printf("Radix Sort, Size: %d, Unsorted\n", N[n]);
        printArray(input, N[n]);

        sleep(1);

        gettimeofday(&start, NULL);
        radixSort(input, N[n]);
        gettimeofday(&end, NULL);
        result[RADIX][n] = getTimeDiff(start, end);

        printf("Radix Sort, Size: %d, Sorted\n", N[n]);
        printArray(input, N[n]);

        free(input);
    }

    // BucketSort
    for(int n = 0; n < 3; n++){
        int* input = malloc(sizeof(int) * N[n]);
        for(int i = 0; i < N[n]; i++)
            input[i] = N[n] - i;
        
        printf("Bucket Sort, Size: %d, Unsorted\n", N[n]);
        printArray(input, N[n]);

        int bucketNum;
        switch(n){
            case 2:             // n = 10000
                bucketNum = 50;
                break;
            case 1:             // n = 1000
                bucketNum = 20;
                break;
            default:            // n = 100
                bucketNum = 10;
        }

        sleep(1);

        gettimeofday(&start, NULL);
        bucketSort(input, N[n], bucketNum);
        gettimeofday(&end, NULL);
        result[BUCKET][n] = getTimeDiff(start, end);

        printf("Bucket Sort, Size: %d, Sorted\n", N[n]);
        printArray(input, N[n]);

        free(input);
    }

    // show results 
    printf("%64s\n", "[Results]");
    printf("%10c", 'N');
    for(int i = 0; i < NUM_OF_SORTING; i++)
        printf("%15s", sortingNames[i]);
    printf("\n");

    for(int i = 0; i < 3; i++){
        printf("%10d", N[i]);
        for(int j = 0; j < NUM_OF_SORTING; j++)
            printf("%12ld us", result[j][i]);
        printf("\n");
    }
}

void swap(int arr[], int idx1, int idx2){
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

void bubbleSort(int arr[], int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < (len - i) - 1; j++){
            if(arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
}

void selectionSort(int arr[], int len){
	int minIdx;

	for(int i = 0; i < len - 1; i++){
		minIdx = i;
		for(int j = i + 1; j < len; j++){
			if(arr[j] < arr[minIdx])
				minIdx = j;
		}

		swap(arr, i, minIdx);
	}
}

void insertionSort(int arr[], int len){
    int key, j;

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

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

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

    for(int i = left; i <= right; i++)
        arr[i] = sorted[i];

    free(sorted);
}

void quickSort(int arr[], int left, int right){
    if(left < right){
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int partition(int arr[], int left, int right){
    // int pivot = arr[left];
    int pivot = arr[(left + right) / 2];
    int l_idx = left;

    for(int r_idx = left + 1; r_idx <= right; r_idx++){
        if(arr[r_idx] < pivot)
            swap(arr, ++l_idx, r_idx);
    }
    swap(arr, left, l_idx);

    return l_idx;
}

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
    for(int i = len - 1; i >= 0; i++)
        dst[(aux[arr[i] - min]--) - 1] = arr[i];

    memcpy(arr, dst, sizeof(int) * len);

    free(aux);
    free(dst);
}

void radixSort(int arr[], int len){
    int div = 1;
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

    // countingSort for each digit
    int idx;
    for(int digit = 0; digit < max_digit; digit++){
        // step1
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

void bucketSort(int arr[], int len, int bucketNum){
    int** bucket = malloc(sizeof(int*) * bucketNum);
    for(int i = 0; i < bucketNum; i++){
        bucket[i] = malloc(sizeof(int) * len);
        memset(bucket[i], 0, sizeof(int) * len);
    }
    // each bucketSize = len for worst case

    int* bucketCount = malloc(sizeof(int) * bucketNum);
    memset(bucketCount, 0, sizeof(int) * bucketNum);

    int min = arr[0];
    for(int i = 1; i < len; i++){
        if(arr[i] < min)
            min = arr[i];
    }

    int idx;
    for(int i = 0; i < len; i++){
        idx = (arr[i] - min) / (len / bucketNum);
        bucket[idx][bucketCount[idx]++] = arr[i];
    }

    for(int i = 0; i < bucketNum; i++)
        insertionSort(bucket[i], bucketCount[i]);

    int totalCount = 0;
    for(int i = 0; i < bucketNum; i++){
        int j = 0;
        while(bucket[i][j] != 0)
            arr[totalCount++] = bucket[i][j++];
    }

    for(int i = 0; i < bucketNum; i++)
        free(bucket[i]);
    free(bucket);
    free(bucketCount);
}

void printArray(int arr[], int len){
    if(len <= 100){
        for(int i = 0; i < len; i++)
            printf("%d ", arr[i]);
    }
    else{
        for(int i = 0; i < 100; i++){
            printf("%d ", arr[i]);
        }
        printf("... ");
        for(int i = len - 101; i < len; i++){
            printf("%d ", arr[i]);
        }
    }
    printf("\n\n");
}

long getTimeDiff(time_st start, time_st end){
    return (long)((end.tv_sec - start.tv_sec) * SEC_TO_US + (end.tv_usec - start.tv_usec));
}
