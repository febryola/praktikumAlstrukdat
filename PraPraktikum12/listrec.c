#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 13 November 2021
Topik praktikum     : List rekursif
Deskripsi           : Implementasi Header listrec.h
*/

Address newNode(ElType x){
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l){
    return ((l == NULL) ? 1 : 0);
}
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
int isOneElmt(List l){
    return ((l != NULL && NEXT(l) == NULL) ? 1 : 0);
}
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

/* Primitif-Primitif Pemrosesan List */
ElType head(List l){
    return INFO(l);
}
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
List tail(List l){
    if (isEmpty(l) == 1){
        return NULL;
    } else{
        return NEXT(l);
    }
}
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
List konso(List l, ElType e){
    Address X = newNode(e);
    if (X != NULL){
        NEXT(X) = l;
        return X;
    } else {
        return l;
    }
}
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
List konsb(List l, ElType e){
    if (isEmpty(l) == 1){
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

/* Fungsi dan Prosedur Lain */
int length(List l){
    if (isEmpty(l) == 1){
        return 0;
    } else {
        return 1+length(NEXT(l));
    }
}
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
void displayList(List l){
    if (isEmpty(l) == 0){
        printf("%d\n", INFO(l));
        displayList(NEXT(l));
    }
}
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
