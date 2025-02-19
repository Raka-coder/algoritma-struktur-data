#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menggabungkan dua bagian array
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Buat array sementara
    int L[n1], R[n2];

    // Salin data ke array sementara L[] dan R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Gabungkan array sementara kembali ke arr[l..r]
    i = 0; // Indeks awal dari subarray pertama
    j = 0; // Indeks awal dari subarray kedua
    k = left; // Indeks awal dari subarray yang digabungkan
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen dari L[], jika ada
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen dari R[], jika ada
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    printf("\n");
    // Tampilkan proses merge
    printf("Proses Merge: ");
    for (i = left; i <= right; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fungsi rekursif untuk merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort pertama dan kedua bagian
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Gabungkan bagian yang sudah diurutkan
        merge(arr, left, mid, right);
    }
}

// Fungsi untuk menampilkan array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan %d elemen:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n");
    printf("Array sebelum diurutkan: \n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\n");
    printf("Array setelah diurutkan: \n");
    printArray(arr, n);

    return 0;
}