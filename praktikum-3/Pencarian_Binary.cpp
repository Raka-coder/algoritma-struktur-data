#include <stdio.h>
#include <conio.h>
main()
{
    int Ar[10] = {2, 5, 6, 9, 10, 12, 15, 18, 20, 22}; // untuk proses ascending
    int i, tar, awal = 0, akhir = 10, tengah;

    printf("\nDatanya adalah = ");
    for (i = 0; i < 10; i++)
        printf("%d ", Ar[i]);

    // input data yang ingin dicari pada array    
    printf("\nMasukan data yang dicari : ");
    scanf("%d", &tar);

    while (awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (tar > Ar[tengah])
        // descending ubah tanda > menjadi <
        {
            awal = tengah + 1;
        }
        else if (tar < Ar[tengah]) // descending ubah tanda < menjadi >
        {
            akhir = tengah - 1;
        }
        else
        {
            awal = akhir + 1;
        }
    }
    if (tar == Ar[tengah])
    {
        printf("\nData ditemukan pada index ke-%d", tengah);
        return 0;
    }
    else
    {
        printf("\nData tidak ditemukan…!");
        return 0;
    }
    getch();
}