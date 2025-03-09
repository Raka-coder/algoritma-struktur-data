#include <stdio.h>

// Fungsi untuk menampilkan array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fungsi untuk Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar elemen
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Tukar elemen
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Fungsi untuk Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Pindahkan elemen yang lebih besar dari key ke posisi setelahnya
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice;

    printf("Array sebelum diurutkan: \n");
    printArray(arr, size);

    printf("\nPilih metode sorting:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Masukkan pilihan Anda (1/2/3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(arr, size);
            printf("Array setelah Bubble Sort: \n");
            printArray(arr, size);
            break;
        case 2:
            selectionSort(arr, size);
            printf("Array setelah Selection Sort: \n");
            printArray(arr, size);
            break;
        case 3:
            insertionSort(arr, size);
            printf("Array setelah Insertion Sort: \n");
            printArray(arr, size);
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
    }

    return 0;
}