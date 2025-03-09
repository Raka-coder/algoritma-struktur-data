#include <stdio.h>
#include <stdlib.h>

//  Untuk menampilkan array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//  Untuk menukar dua elemen
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int size, int ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (ascending ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int size, int ascending) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && (ascending ? arr[j] > key : arr[j] < key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right, int ascending) {
   
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (ascending ? L[i] <= R[j] : L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right, int ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);
        merge(arr, left, mid, right, ascending);
    }
}

// Selection Sort
void selectionSort(int arr[], int size, int ascending) {
    for (int i = 0; i < size - 1; i++) {
        int minMaxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (ascending ? arr[j] < arr[minMaxIndex] : arr[j] > arr[minMaxIndex]) {
                minMaxIndex = j;
            }
        }
        swap(&arr[minMaxIndex], &arr[i]);
    }
}

// Quick Sort
int partition(int arr[], int low, int high, int ascending) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (ascending ? arr[j] < pivot : arr[j] > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int ascending) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending);
        quickSort(arr, low, pi - 1, ascending);
        quickSort(arr, pi + 1, high, ascending);
    }
}

int main() {
    int size;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &size);

    int arr[size];
    printf("Masukkan elemen-elemen array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int pilihMetode, pilihPengurutan;
    printf("\nPilih metode sorting:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Selection Sort\n");
    printf("5. Quick Sort\n");
    printf("\n");
    printf("Masukkan pilihan (1/2/3/4/5): ");
    scanf("%d", &pilihMetode);

    printf("\nPilih urutan:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("\n");
    printf("Masukkan pilihan Anda (1/2): ");
    scanf("%d", &pilihPengurutan);

    int ascending = (pilihPengurutan == 1);

    switch (pilihMetode) {
        case 1:
            bubbleSort(arr, size, ascending);
            printf("\nHasil Bubble Sort:\n");
            break;
        case 2:
            insertionSort(arr, size, ascending);
            printf("\nHasil Insertion Sort:\n");
            break;
        case 3:
            mergeSort(arr, 0, size - 1, ascending);
            printf("\nHasil Merge Sort:\n");
            break;
        case 4:
            selectionSort(arr, size, ascending);
            printf("\nHasil Selection Sort:\n");
            break;
        case 5:
            quickSort(arr, 0, size - 1, ascending);
            printf("\nHasil Quick Sort:\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
            return 1;
    }

    printArray(arr, size);
    return 0;
}