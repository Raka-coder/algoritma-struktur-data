#include <stdio.h>

void selectionSortDescending(int arr[], int n) {
    int i, j, max_idx, temp;
    for (i = 0; i < n - 1; i++) {
        max_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        // Proses swapping untuk selection sort descending
        temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
        
        printf("\n");
        // Menampilkan proses selection
        printf("Proses selection ke-%d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int n, i;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Masukkan %d angka: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    selectionSortDescending(arr, n);
    
    printf("\n");
    printf("Hasil setelah diurutkan (Descending): ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
