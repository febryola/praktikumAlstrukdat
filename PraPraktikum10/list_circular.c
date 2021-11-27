#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 28 Oktober 2021
Topik praktikum     : variasi list linear
Deskripsi           : Implementasi Header list_circular
*/
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
{
    return (FIRST(l) == NULL);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l)=NULL;
}
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
    Address p = (Address) malloc(sizeof(ElmtList));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
void deallocate(Address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
    Address p;
    boolean found=false;
    if(isEmpty(l))
        return NULL;
    else{
        p = FIRST(l);
        if (INFO(p) == val) {
            found = true;
        } else {
            found = false;
            p = NEXT(p);
        }
        while ((p != FIRST(l)) && (!found)) {
            if (INFO(p) == val) {
                found = true;
            } else {
                p = NEXT(p);
            }
        }
        if (found) {
            return p;
        } else {
            return NULL;
        }
    }
}
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

boolean addrSearch(List l, Address p){
    Address P=FIRST(l);
    if(isEmpty(l))
        return false;
    else{
        while((NEXT(P) != FIRST(l)) && (P != p)){
            P = NEXT(P);
        }
        return (P == p);
    }
}
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address p,last;
    p=allocate(val);
    if(p != NULL){
        if(isEmpty(*l)){
            NEXT(p) = p;
        }
        else{
            last = FIRST(*l);
            while(NEXT(last) != FIRST(*l)){
                last = NEXT(last);
            }
            NEXT(p)= FIRST(*l);
            NEXT(last) = p;
        }
        FIRST(*l) = p;
    }
}
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
/* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */

void insertLast(List *l, ElType val){
    Address p,last;
    if(isEmpty(*l)){
        insertFirst(l,val);
    }
    else{
        p=allocate(val);
        if(p!=NULL){
            last=FIRST(*l);
            while(NEXT(last) != FIRST(*l)){
                last=NEXT(last);
            }
            NEXT(last)=p;
            NEXT(p)=FIRST(*l);
        }
    }
}
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val){
    Address p,last;
    p=FIRST(*l);
    *val=INFO(p);
    if(NEXT(FIRST(*l))==FIRST(*l)){
        FIRST(*l) = NULL;
    }else{
        last = FIRST(*l);
        while (NEXT(last)!=FIRST(*l))
        {
            last=NEXT(last);
        }
        FIRST(*l)=NEXT(FIRST(*l));
        NEXT(last)=FIRST(*l);
    }
    deallocate(p);
}
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama List l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen pertama list lama di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address last,last1;
    last=FIRST(*l);
    last1=NULL;
    while (NEXT(last) !=  FIRST(*l))
    {
        last1 = last;
        last=NEXT(last);
    }
    if(last1 == NULL){
        FIRST(*l) = NULL;
    }else{
        NEXT(last1) = FIRST(*l);
    }
    *val=INFO(last);
    deallocate(last);
    
}
/* I.S. List l tidak kosong */
/* F.S. val adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
/*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen terakhir list lama di-dealokasi */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    Address p,awal;
    awal = FIRST(l);
    if(isEmpty(l))
        printf("[]");
    else{
        p = FIRST(l);
        printf("[");
        while (NEXT(p) != FIRST(l)) {
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d", INFO(p));
        printf("]");
    }
}
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */