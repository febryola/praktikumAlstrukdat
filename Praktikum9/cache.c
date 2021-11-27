#include <stdio.h>
#include "node.h"
#include "list_linked.h"
#include "boolean.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 28 Oktober 2021
Topik praktikum     : List_Linked
Deskripsi           : Implementasi file cache.c
*/
int main()
{
    int N,x,i,miss,hit,lokasi; //deklarasi variabel
    List L;
    scanf("%d",&N); //input nilai N
    CreateList(&L); //membentuk list L awal
    for(int i = 0; i < N; i++ ){
        insertFirst(&L, N-i); //insert pada elemen pertama
    }
    scanf("%d", &lokasi); //input variabel lokasi
    for ( i = 0 ; i < lokasi ; i ++){
        scanf("%d",&x); //input nilai x
        miss = indexOf(L, x); //menginisialisasi nilai variabel miss
        if (miss != IDX_UNDEF) { //jika miss terdefinisi
            deleteAt(&L, miss,&x);
            insertFirst(&L,x);
            printf("hit ");
            displayList(L);
            printf("\n");
        } else { //jika miss tidak terdefinisi
            deleteLast(&L,&hit);
            insertFirst(&L,x);
            printf("miss ");
            displayList(L);
            printf("\n");
        }
    }
    return 0; //Program selesai
}