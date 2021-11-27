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
/* F.S. Jika list tidak kosong, NULLai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen berNULLai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */

/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
ElType maxList (List l){
    if (isOneElmt(l) == 1){
        return INFO(l);
    } else {
        return (INFO(l) > maxList(tail(l)) ? INFO(l) : maxList(tail(l)));
    }
}
/* Mengirimkan NULLai INFO(p) yang maksimum */

ElType minList (List l){
    if (isOneElmt(l) == 1){
        return INFO(l);
    } else {
        return (INFO(l) < minList(tail(l)) ? INFO(l) : minList(tail(l)));
    }
}
/* Mengirimkan NULLai INFO(p) yang minimum */

ElType sumList (List l){
    if (isEmpty(l) == 1){
        return 0;
    } else {
        return INFO(l) + sumList(tail(l));
    }
}
/* Mengirimkan total jumlah elemen List l */

float averageList (List l){
    return (sumList(l)*1.0f)/(length(l)*1.0f);
}
/* Mengirimkan NULLai rata-rata elemen list l */

/*** Operasi-Operasi Lain ***/
List inverseList (List l){
    if (isEmpty(l)) {
        return NULL;
    } else {
        return konsb(inverseList(tail(l)), INFO(l));
    }
}
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

void splitPosNeg (List l, List *l1, List *l2){
    if (isEmpty(l)) {
        *l1 = NULL;
        *l2 = NULL;
    } else {
        splitPosNeg(tail(l), l1, l2);
        if (INFO(l) < 0) {
            *l2 = konso(*l2, INFO(l));
        } else {
            *l1 = konso(*l1, INFO(l));
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */

void splitOnX (List l, ElType x, List *l1, List *l2){
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    } else {
        splitOnX(tail(l), x, l1, l2);
        if(INFO(l) >= x){
            *l2 = konso(*l2, INFO(l));
        } else {
            *l1 = konso(*l1, INFO(l));
    }
}
}
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */

int compareList (List l1, List l2){
    if (isEmpty(l1) && isEmpty(l2)){
        return 0;
    } else if (isEmpty(l1) && (!isEmpty(l2))){
        return -1;
    } else if ((!isEmpty(l1) && isEmpty(l2))){
        return 1;
    } else {
        if (INFO(l1) < INFO(l2)) {
            return -1;
        } else if (INFO(l1) > INFO(l2)){
            return 1;
        } else {
            return compareList(tail(l1), tail(l2));
        }
    }
}
/* Menghasilkan: -1 jika l1 < l2, 0 jika l1 = l2, dan 1 jika l1 > l2 */
/* Jika l[i] adalah elemen l pada urutan ke-i dan |l| adalah panjang l: */
/* l1 = l2: |l1| = |l2| dan untuk semua i, l1[i] = l2[i] */
/* l1 < l2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari l1 dan l2, l1[i]<l2[i] atau: Jika pada semua elemen pada
urutan i yang sama, l1[i]=l2[i], namun |l1|<|l2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* l1>l2: kebalikan dari l1<l2 */
boolean search (List l, ElType x){

   if(isEmpty(l)){
      return false;
   } else {
      if (head(l)==x) return true;
      else return search(tail(l),x);
   }
}

boolean isAllExist (List l1, List l2){
    if(isEmpty(l1)) return false;
    if (search(l2,head(l1))) return isEmpty(tail(l1)) ? true : isAllExist(tail(l1),l2);
    return false;
}
/* Menghasilkan true jika semua elemen dalam l1 terdapat dalam l2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika l1 kosong, maka hasilnya false. */

