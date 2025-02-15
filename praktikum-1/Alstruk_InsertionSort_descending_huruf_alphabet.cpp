
#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr[j] > arr[j + 1] && ascending) || (arr[j] < arr[j + 1] && !ascending)) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int elemenHuruf;
    printf("\n");
    printf("Masukkan jumlah elemen huruf: ");
    scanf("%d", &elemenHuruf);

    char arr[elemenHuruf];
    printf("Masukkan %d huruf:\n", elemenHuruf);
    for (int i = 0; i < elemenHuruf; i++) {
        scanf(" %c", &arr[i]);
    }
    printf("\n");

    printf("Huruf sebelum diurutkan: ");
    for (int i = 0; i < elemenHuruf; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n\n");

    bubbleSort(arr, elemenHuruf, 1);
    printf("Huruf setelah diurutkan ascending : ");
    for (int i = 0; i < elemenHuruf; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, elemenHuruf, 0);
    printf("Huruf setelah diurutkan descending: ");
    for (int i = 0; i < elemenHuruf; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n\n");

    return 0;
}
