#include <stdio.h>
#include <stdbool.h>

// Fungsi untuk menukar dua elemen
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


void insertionSortAscending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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


void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
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

void mergeSortDescending(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortDescending(arr, left, mid);
        mergeSortDescending(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Masukkan jumlah elemen array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan elemen array:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemen ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    char choice;
    bool running = true;

    while (running) {
        printf("\nPilih menu:\n");
        printf("a/A: Pengurutan Ascending\n");
        printf("d/D: Pengurutan Descending\n");
        printf("s/S: Searching\n");
        printf("q/Q: Keluar\n");
        printf("Masukkan pilihan: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
            case 'A': {
                int sortChoice;
                printf("\nPilih metode pengurutan Ascending:\n");
                printf("1. Bubble Sort\n");
                printf("2. Insertion Sort\n");
                printf("Masukkan pilihan: ");
                scanf("%d", &sortChoice);

                if (sortChoice == 1) {
                    bubbleSortAscending(arr, n);
                    printf("Array setelah Bubble Sort Ascending: ");
                } else if (sortChoice == 2) {
                    insertionSortAscending(arr, n);
                    printf("Array setelah Insertion Sort Ascending: ");
                } else {
                    printf("Pilihan tidak valid.\n");
                    break;
                }
                printArray(arr, n);
                break;
            }

            case 'd':
            case 'D': {
                int sortChoice;
                printf("\nPilih metode pengurutan Descending:\n");
                printf("1. Selection Sort\n");
                printf("2. Merge Sort\n");
                printf("Masukkan pilihan: ");
                scanf("%d", &sortChoice);

                if (sortChoice == 1) {
                    selectionSortDescending(arr, n);
                    printf("Array setelah Selection Sort Descending: ");
                } else if (sortChoice == 2) {
                    mergeSortDescending(arr, 0, n - 1);
                    printf("Array setelah Merge Sort Descending: ");
                } else {
                    printf("Pilihan tidak valid.\n");
                    break;
                }
                printArray(arr, n);
                break;
            }

            case 's':
            case 'S': {
                int searchChoice, target;
                printf("\nPilih metode searching:\n");
                printf("1. Binary Search\n");
                printf("2. Sequential Search\n");
                printf("Masukkan pilihan: ");
                scanf("%d", &searchChoice);

                printf("Masukkan nilai yang ingin dicari: ");
                scanf("%d", &target);

                int result;
                if (searchChoice == 1) {
                    // Binary Search memerlukan array terurut
                    bubbleSortAscending(arr, n);
                    printf("Array diurutkan terlebih dahulu untuk Binary Search: ");
                    printArray(arr, n);
                    result = binarySearch(arr, n, target);
                } else if (searchChoice == 2) {
                    result = sequentialSearch(arr, n, target);
                } else {
                    printf("Pilihan tidak valid.\n");
                    break;
                }

                if (result != -1) {
                    printf("Nilai %d ditemukan di indeks %d.\n", target, result);
                } else {
                    printf("Nilai %d tidak ditemukan.\n", target);
                }
                break;
            }

            case 'q':
            case 'Q':
                running = false;
                printf("Program selesai.\n");
                break;

            default:
                printf("Menu pilihan tidak ada.\n");
                break;
        }
    }

    return 0;
}