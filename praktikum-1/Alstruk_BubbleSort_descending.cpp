// nama file : Alstruk_BubleSort1
// descending 

#include <stdio.h>

void bubbleSort(int arr[], int n){
  int i, j, tmp;
  for(i = 0; i < n; i++){
    for(j=0; j < n-i-1; j ++){
      if(arr[j] < arr[j+1]){
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}

int main() {
  int array[100], n, i, j;
  printf("Masukkan banyak elemen: ");
  scanf("%d", &n);

  printf("Masukkan nilai: \n");

  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }

  bubbleSort(array, n);
  printf("\n");

  printf("Hasil pengurutan descending sebagai berikut:\n");
  for(i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n\n");
}
