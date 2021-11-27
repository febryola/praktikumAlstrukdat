#include <stdio.h>
#include "matrix.h"
#include "boolean.h"
#include "matrixop.c"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 23 September 2021
Topik praktikum     : ADT Matrix
Deskripsi           : Melakukan realisasi program
*/

/*Tuan Sans merupakan pemilik suatu komplek perumahan,
 komplek perumahan ini dapat direpresentasikan sebagai matrix 
 berukuran N x N, yang artinya ada N x N rumah. Suatu hari, 
 terdapat kasus pencurian dengan setiap rumah melaporkan jumlah kasus masing-masing.

Tuan Sans, tidak sanggup untuk mengecek semua rumah karena kompleknya cukup besar, 
oleh karena itu, Tuan Sans ingin melakukan investigasi hanya pada subperumahan atau 
submatrix M x M (M <= N) saja di komplek perumahan itu. Tuan Sans penasaran dengan 
maksimal dari jumlah kasus yang ada pada beberapa submatrix M x M dari N x N kompleks 
perumahan tersebut. Bantulah tuan Sans!

Buatlah sebuah program yang menerima satu buah bilangan TC, 
menyatakan jumlah uji kasus. Setiap uji kasus akan dimulai dengan 
melakukan input bilangan bulat N, kemudian mengambil N x N nilai 
yang digunakan untuk membuat Matrix Jumlah Kasus Perumahan. 
Program kemudian menerima satu buah bilangan M, menyatakan 
submatrix yang dibutuhkan Tuan Sans (M <= N) Untuk setiap uji kasus, 
Tuliskan jumlah X di layar, menyatakan jawaban dari persoalan ini!*/

int maxSubsum (Matrix N, int m){

    //kamus
    Index i,j,k,l;
    int sum, max;

    //Algoritma
    max = 0;
    for (i = 0 ; i <= getLastIdxRow(N) - m +1 ; i++){
        for (j = 0 ; j <= getLastIdxCol(N)- m +1; j++){
            sum = 0;
            for (k = i; k < m + i; k++){
                for(l = j; l <m + j; l++){
                    sum += ELMT(N,k,l);
                }
            }

            if (sum >= max) {
                max = sum;
            }

        }
    }

    return max;
}

int main()
{
   /* KAMUS */ 
   int TC, i, n,m;
   Matrix N;


   /* ALGORITMA */
    scanf("%d", &TC);
    for (i =0 ; i <TC; i++){
        scanf("%d", &n);
        readMatrix(&N, n,n);
        scanf("%d", &m);
        printf("%d\n", maxSubsum(N,m));
    }

  return 0;
}