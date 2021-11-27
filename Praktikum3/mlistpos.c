#include <stdio.h>
#include "listpos.h"
#include "listpos.c"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 9 September 2021
Topik praktikum     : ADT List Pada C
Deskripsi           : Membuat implementasi dengan file mlistpos.c
*/

/* 
membuat fungsi baru yang melakukan pencarian apakah ada nilai dalam list l yang bernilai X
*/
boolean Search(ListPos l, ElType X){     //Membuat fungsi boolean
    if (isEmpty(l)){                     //jika list kosong
        return false;
    }
    boolean found = false;
    int i;
    for(i=0; i < CAPACITY; i++){         //perulangan i dan batasnya
        if (ELMT(l, i) == X){
            found = true;
            break;
        } 
    }
    return found;
}
int main(){                              //fungsi utama untuk memanggil program
    ListPos l;                           //memberi tipe data
    readList(&l);                        //membaca elemen pada list
    int X = -1, max = -1, min = -1;      //menginisialisasi nilai
    scanf("%d", &X);                     //menginput nilai X
    displayList(l);printf("\n");         //menampilkan list ke layar  
    if (Search(l, X)){                   //Mengimplementasikan fungsi boolean di atas
        printf("%d\n", indexOf(l, X));   //output
        extremes(l, &max, &min);         //menerapkan fungsi extremes
        sort(&l, true);                  //mengeluarkan true jika list l merupakan sorting

        // Maksimum
        if (X == max){                   //jika X = max
            printf("maksimum\n");        //mengeluarkan pesan "maksimum"
        }

        // Minimum
        if (X == min){                   //jika X = min
            printf("minimum\n");         //mengeluarkan pesan "minimum"
        }

        // Median
        int median = 0;                 //menginisialisasi nilai median dengan 0
        if (length(l) % 2 == 0){        //jika banyak elemen merupakan bilangan genap
            median = ((length(l))/2)-1;
        } else {                        //jika banyak elemen merupakan bilangan ganji
            median = ((length(l))/2);
        }

        if (ELMT(l, median) == X && median >= 0){  //jika elemen ke media pada l sama dengan X
            printf("median\n");         //output      
        }
    } else {                           
        printf("%d tidak ada\n", X);    //output
    }
    return 0;
}

// Program selesai