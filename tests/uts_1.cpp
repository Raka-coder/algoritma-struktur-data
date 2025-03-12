#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
       
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        
        swap(&arr[max_idx], &arr[i]);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int arr[] = {7, 3, 17, 23, 88, 84, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\n");
    printf("======= OUTPUT ========= ");

    printf("\n");
    printf("Array sebelum diurutkan: ");
    printArray(arr, n);

    selectionSortDescending(arr, n);

    printf("Array setelah diurutkan secara (Descending): ");
    printArray(arr, n);

    return 0;
}