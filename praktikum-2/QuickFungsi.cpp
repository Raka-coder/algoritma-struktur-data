#include <stdio.h>
#include <stdlib.h> // Untuk malloc

// Fungsi untuk menukar dua angka
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi partisi untuk mengatur ulang array di sekitar pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot adalah elemen terakhir
    int i = (low - 1);  // Indeks elemen yang lebih kecil

    for (int j = low; j < high; j++) {
        // Jika elemen saat ini lebih kecil dari pivot
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fungsi quickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Urutkan elemen sebelum dan setelah pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Koreksi dari "n" menjadi "\n"
}

int main() {
    int n;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    // Alokasikan array secara dinamis
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Gagal mengalokasikan memori\n");
        return 1;
    }

    printf("Masukkan angka: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Pengurutan: ");
    printArray(arr, n);

    // Bebaskan memori yang dialokasikan
    free(arr);

	return 0;
}
