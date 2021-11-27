#include <stdio.h>
#include "matrixop.c"

int main(){
    int ukuran;
    Matrix m;


   /* ALGORITMA */
    scanf("%d", &ukuran);
    readMatrix(&m, ukuran,ukuran);
    if (isSegitigaBawah(m)){
        printf("True");
        } 
    else printf("Bukan");
    
    return 0;
}