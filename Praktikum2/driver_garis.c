
#include <stdio.h>
#include "garis.c"
#include "point.c"
int main()
{
    GARIS L;

    // Test Baca/tulis
    printf("Masukkan nilai pada absis dan ordinat dari 2 titik: \n");
    BacaGARIS(&L);
    printf("Titik yang dibaca adalah ");
    TulisGARIS(L);
    printf("\n");

    printf("Jarak kedua titik pada garis ");
    TulisGARIS(L);
    printf("  adalah %.2f\n", PanjangGARIS(L));
    printf("\n");

    printf("Gradien garis ");
    TulisGARIS(L);
    printf("  adalah %.2f\n", Gradien(L));
    printf("\n");

    float deltaX,deltaY;
    printf("Geser Titik 1 dan Titik 2 pada garis ke sumbu-x= ");
    scanf("%f", &deltaX);
    printf("Geser Titik 1 dan Titik 2 pada garis ke sumbu-y= ");
    scanf("%f", &deltaY);
    TulisGARIS(L);
    printf(" setelah digeser P1 menjadi ");
    GeserGARIS(&L, deltaX, deltaY);
    TulisGARIS(L);
    printf("\n");
    printf("\n");

    GARIS L2;

    // Test Baca/tulis
    printf("Masukkan nilai pada absis dan ordinat dari 2 titik: \n");
    BacaGARIS(&L2);
    printf("Titik yang dibaca adalah ");
    TulisGARIS(L2);
    printf("\n");

    if (IsTegakLurus(L, L2))
    {
        printf("kedua garis tegak lurus\n");
    }
    if (IsSejajar(L, L2))
    {
        printf("kedua garis sejajar\n");
    }

    return 0;
}
   