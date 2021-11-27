#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 25 November 2021
Topik praktikum     : Tree
Deskripsi           : merkle
*/

int main() {
    int bilangan; //2^N
    scanf("%d", &bilangan);

    if (bilangan <= 0){
        printf("Jumlah masukan tidak sesuai\n");
        return 0;
    }

    int temp = bilangan;
    while (bilangan%2 == 0){
        bilangan /= 2;
    }
    if (bilangan != 1){
        printf("Jumlah masukan tidak sesuai\n");
        return 0;
    }

    int batas = (temp*2)-1;
    BinTree arr[batas];
    int i, j;
    for (i=0;i<temp;i++){
        int X;
        scanf("%d", &X);
        BinTree t = NewTree(X,NULL,NULL);
        arr[i] = t;
    }

    j = 0;
    while (temp < batas){
        BinTree t1, t2, t;
        t1 = arr[j];
        t2 = arr[j+1];
        t  = NewTree((ROOT(t1)+ROOT(t2)), t1, t2);
        arr[temp] = t;
        j += 2;
        temp += 1;
    }
    printTree(arr[batas-1], 2);
}