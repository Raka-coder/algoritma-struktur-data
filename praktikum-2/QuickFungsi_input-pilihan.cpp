#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menukar dua elemen
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi partisi untuk menentukan pivot
int partition(int arr[], int low, int high, int order) {
    int pivot = arr[high]; // Pilih elemen terakhir sebagai pivot
    int i = (low - 1);     // Indeks untuk elemen yang lebih kecil

    for (int j = low; j <= high - 1; j++) {
        // Untuk ascending: jika elemen saat ini <= pivot
        // Untuk descending: jika elemen saat ini >= pivot
        if ((order == 1 && arr[j] <= pivot) || (order == 0 && arr[j] >= pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Letakkan pivot di posisi yang benar
    return (i + 1);
}

// Fungsi Quick Sort rekursif
void quickSort(int arr[], int low, int high, int order, int size) {
    if (low < high) {
        // Dapatkan indeks pivot
        int pi = partition(arr, low, high, order);
        
        // // Tampilkan array setelah partisi
        // printf("Setelah partisi: ");
        // for (int k = 0; k < size; k++) {
        //     printf("%d ", arr[k]);
        // }
        // printf("\n");
        
        // Urutkan bagian kiri dan kanan dari pivot
        quickSort(arr, low, pi - 1, order, size);
        quickSort(arr, pi + 1, high, order, size);
    }
}

// Fungsi untuk menampilkan array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan %d elemen:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray sebelum diurutkan:\n");
    printArray(arr, n);

    // Menu pilihan
    printf("\nPilih metode pengurutan:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan Anda: ");
    printf("\n");
    scanf("%d", &choice);

    // Panggil Quick Sort sesuai pilihan
    switch (choice) {
        case 1:
            quickSort(arr, 0, n - 1, 1, n); // 1 untuk ascending
            break;
        case 2:
            quickSort(arr, 0, n - 1, 0, n); // 0 untuk descending
            break;
        default:
            printf("\nPilihan tidak valid!\n");
            return 1;
    }

    // Tampilkan array setelah diurutkan
    if (choice == 1) {
        printf("\nArray setelah diurutkan ascending:\n"); // 1 untuk ascending
    } else if (choice == 2) {
        printf("\nArray setelah diurutkan descending:\n"); // 0 untuk descending
    }
    printArray(arr, n);

    return 0;
}