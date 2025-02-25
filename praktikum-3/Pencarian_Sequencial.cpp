#include <stdio.h>

int main() {
    int data[] = {10, 1, 2, 11, 8, 7, 5, 4, 15, 16};
    int n = sizeof(data) / sizeof(data[0]); 
    int target; // data yang ingin dicari

    // input data yang ingin dicari pada array
    printf("\nMasukkan data yang ingin dicari: ");
    scanf("%d", &target);

    int i;
    for (i = 0; i < n; i++) {
        if (data[i] == target) {
            printf("\nData %d ditemukan pada indeks ke: %d\n", target, i);
            return 0;
        }
    }

    printf("\nData %d tidak ditemukan dalam array\n", target);
    return 1;
}