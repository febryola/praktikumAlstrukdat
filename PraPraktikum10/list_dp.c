#include <stdio.h>
#include <stdlib.h>
#include "list_dp.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 28 Oktober 2021
Topik praktikum     : variasi list linear
Deskripsi           : Implementasi Header list_dp
*/

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return (FIRST(l) == NULL) && (LAST(l) == NULL);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
    LAST(*l) = NULL;
}
/* I.S. l sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
    Address result;
    result = (Address) malloc (sizeof(Node));
    if (result != NULL){
        INFO(result) = val;
        NEXT(result) = NULL;
        PREV(result) = NULL;
    }
    return result;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL. */
/* Misalnya: menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL, PREV(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL. */
void deallocate (Address p){
    free(p);
}
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
    Address now = FIRST(l);
    while(now != NULL && INFO(now)!=val){
        now = NEXT(now);
    }
    return now;
}
/* Mencari apakah ada elemen list dengan INFO(P)=val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

/****************** PRIMITIF BERDASARKAN NULLAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address newFIRST = allocate(val);
    if (newFIRST != NULL){
        if (FIRST(*l) == NULL){
            LAST(*l) = newFIRST;
        } else {
            PREV(FIRST(*l)) = newFIRST;
        }
        NEXT(newFIRST) = FIRST(*l);
        FIRST(*l) = newFIRST;
    }
}
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NULLai X jika alokasi berhasil */
void insertLast(List *l, ElType val){
    Address newLAST = allocate(val);
    if (newLAST != NULL){
        if (LAST(*l) == NULL){
            FIRST(*l) = newLAST;
        } else {
            NEXT(LAST(*l)) = newLAST;
        }
        PREV(newLAST) = LAST(*l);
        LAST(*l) = newLAST;
    }
}
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNULLai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void insertAfter(List *L, Address p, Address pRec){
    if (pRec == LAST(*L)){
        Address newlast = p;
        if (LAST(*L) == NULL){
            FIRST(*L) = newlast;
        } else {
            NEXT(LAST(*L)) = newlast;
        }
        PREV(newlast) = LAST(*L);
        LAST(*L) = newlast;
    } else {
        NEXT(p) = NEXT(pRec);
        PREV(NEXT(pRec)) = p;
        PREV(p) = pRec;
        NEXT(pRec) = p;
    }
}
/* I.S. pRec pasti elemen list; p sudah dialokasi */
/* F.S. Insert p sebagai elemen sesudah elemen beralamat pRec */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    Address deleted = FIRST(*l);
    *val = INFO(deleted);
    if (FIRST(*l) == LAST(*l)){
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
        return;
    }
    PREV(NEXT(deleted)) = NULL;
    FIRST(*l) = NEXT(deleted);
    deallocate(deleted);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: NULLai INFO disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address deleted = LAST(*l);
    *val = INFO(deleted);
    if (FIRST(*l) == LAST(*l)){
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
        return;
    }
    NEXT(PREV(deleted)) = NULL;
    LAST(*l) = PREV(deleted);
    deallocate(deleted);
}
/* I.S. list l tidak kosong */
/* F.S. Elemen terakhir list dihapus: NULLai INFO disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */
void deleteAfter(List *l, Address *pDel, Address pRec){
    *pDel = NEXT(pRec);

    NEXT(pRec) = NEXT(*pDel);
    if (NEXT(*pDel) != NULL){
        PREV(NEXT(*pDel)) = pRec;
    }
    else{                        
        LAST(*l) = pRec;
    }

    NEXT(*pDel) = NULL;
    PREV(*pDel) = NULL;
}
/* I.S. List tidak kosong. pRec adalah anggota list. 
        NEXT(pRec)!=NULL */
/* F.S. Menghapus NEXT(pRec): */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    printf("[");
    if (!isEmpty(l)){
        Address now = FIRST(l);
        while (now != NULL) {
            printf("%d", INFO(now));
            now = NEXT(now);

            if (now != NULL)
                printf(",");
        }
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNULLai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void displayListBackwards(List l){
    printf("[");
    if (!isEmpty(l)){
        Address now = LAST(l);
        while (now != NULL) {
            printf("%d", INFO(now));
            now = PREV(now);

            if (now != NULL)
                printf(",");
        }
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen berNULLai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
