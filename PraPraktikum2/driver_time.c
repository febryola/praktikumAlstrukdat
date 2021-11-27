//Febryola Kurnia Putri
//13520140

#include "time.h"
#include <stdio.h>
#include "time.c"

int main()
{
    /* KELOMPOK BACA/TULIS                                               */
    TIME T1, T2;
    printf("Baca time 1 = ");
    BacaTIME(&T1);

    printf("Baca time 2 = ");
    BacaTIME(&T2);

    printf("Tulis time 1 = ");
    TulisTIME(T1);
    printf("\n");

    printf("Tulis time 2 = ");
    TulisTIME(T2);
    printf("\n");

    printf("time 1 ke detik = %ld \n", TIMEToDetik(T1));
    printf("time 2 ke detik = %ld \n", TIMEToDetik(T2));

    /* KELOMPOK OPERASI TERHADAP TYPE                                    */
    printf("Time 1");
    if (TEQ(T1, T2))
    {
        printf(" sama dengan");
    }
    if (TNEQ(T1, T2))
    {
        printf(" tidak sama yaitu");
        if (TGT(T1, T2))
        {
            printf(" lebih besar dari");
        }
        else if (TLT(T1, T2))
        {
            printf(" lebih kecil dari");
        }
    }
    printf(" Time 2\n");

    /* KELOMPOK KONVERSI TERHADAP TYPE                                   */
    /* *** Operator aritmatika TIME *** */
    printf("1 detik setelah time 1 = ");
    TulisTIME(NextDetik(T1));
    printf("\n");
    printf("1 detik sebelum time 1 = ");
    TulisTIME(PrevDetik(T1));
    printf("\n");

    int N;
    printf("Masukkan N: ");
    scanf("%d", &N);
    printf("N detik setelah time 1 = ");
    TulisTIME(NextNDetik(T1, N));
    printf("\n");

    /* *** Kelompok Operator Aritmetika *** */
    printf("Durasi antara time 1 ke time 2 = ");
    printf("%ld", Durasi(T1, T2));
    printf(" detik\n");

    return 0;
}