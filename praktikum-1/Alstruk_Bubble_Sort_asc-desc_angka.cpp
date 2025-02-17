
#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[], int n, int ascending)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((arr[j] > arr[j + 1] && ascending) || (arr[j] < arr[j + 1] && !ascending))
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int elemenAngka;
    printf("\n");
    printf("Masukkan banyak elemen angka: ");
    scanf("%d", &elemenAngka);

    char arr[elemenAngka];
    printf("Masukkan %d angka:\n", elemenAngka);
    for (int i = 0; i < elemenAngka; i++)
    {
        scanf(" %d", &arr[i]);
    }
    printf("\n");

    printf("Angka sebelum diurutkan: ");
    for (int i = 0; i < elemenAngka; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");


    bubbleSort(arr, elemenAngka, 0);
    printf("Angka setelah diurutkan descending: ");
    for (int i = 0; i < elemenAngka; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    return 0;
}
