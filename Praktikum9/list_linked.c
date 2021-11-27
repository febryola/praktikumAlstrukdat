#include <stdio.h>
#include "list_linked.h"


/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 28 Oktober 2021
Topik praktikum     : list linear
Deskripsi           : Imp2ementasi Header list_linked
*/

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
    int ctr = 0;
    Address p = FIRST(l);
    while (ctr<idx){
        ctr += 1;
        p = NEXT(p);
    }
    return INFO(p);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
    int ctr = 0;
    Address p = FIRST(*l);
    if (idx == length(*l)) {
        insertLast(l, val);
    } else {
        while (ctr<idx){
            ctr += 1;
            p = NEXT(p);
        }
        INFO(p) = val;}
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
    Address p = FIRST(l);
    int idx = 0;
    boolean found = false;
    while ((p!= NULL) && (!found)) {
        if (INFO(p) == val) {
            found = true;
        } else{
            idx += 1;
            p = NEXT(p);
        }
    } 
    if (found){
        return idx;
    }else{
        return IDX_UNDEF;
    }
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address p = newNode(val);
    if (p != NULL){
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
    Address p,last;
    if (isEmpty(*l)){
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p!= NULL){
            last = FIRST(*l);
            while (NEXT(last) != NULL){
                last = NEXT(last);
        }
            NEXT(last) = p;
        
        }
        
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
    int ctr;
    Address p, loc;
    if (idx == 0){
        insertFirst(l,val);
    }else if (idx == length(*l)) {
        insertLast(l, val);}
    else{
        p = newNode(val);
        if (p!=NULL){
            ctr = 0;
            loc = FIRST(*l);
            while (ctr<idx-1) {
                loc = NEXT(loc);
                ctr += 1;}
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
            
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    Address p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);

    free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address p, loc;
    p = FIRST(*l);
    loc = NULL;
    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
    Address p, loc;
    int ctr;
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        ctr = 0;
        loc = FIRST(*l);
        while (ctr < idx - 1) {
            ctr++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
        
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void disp2ayList(List l){
    Address p;

    p = FIRST(l);
    if (isEmpty(l)) {
        printf("[]");
    } else {
        printf("[");
        while (NEXT(p) != NULL) {
            printf("%d", INFO(p));
            printf(",");
            p = NEXT(p);
        }
        printf("%d", INFO(p));
        printf("]");
    }
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int length(List l){
    int i;
    Address p;

    i = 0;
    p = FIRST(l);
    while (p != NULL) {
        i++;
        p = NEXT(p);
    }
    return i;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P) {
  /* Mencari apakah ada elemen list yang beralamat P */
  /* Mengirimkan true jika ada, false jika tidak ada */
  Address p = FIRST(L);
  boolean found = false;

  while (!found && p) {
    if (p == P) {
      found = true;
    } else {
      p = NEXT(p);
    }
  }
  return found;
}

Address searchPrec(List L, ElType X) {
  Address p = FIRST(L);
  Address p2 = NULL;
  boolean found = false;

  while (!found && p) {
    if (INFO(p) == X) {
      found = true;
    } else {
      p2 = p;
      p = NEXT(p);
    }
  }

  if (found) {
    return p2;
  } else {
    return NULL;
  }
}
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
  /* Mencari apakah ada elemen list dengan Info(P)=X */
  /* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
  /* Jika tidak ada, mengirimkan Nil */
  /* Jika P adalah elemen pertama, maka Prec=Nil */
  /* Search dengan spesifikasi seperti ini menghindari */
  /* traversal ulang jika setelah Search akan dilakukan operasi lain */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
ElType max(List L) {
  /* Mengirimkan nilai info(P) yang maksimum */
  return INFO(adrMax(L));
}

Address adrMax(List L) {
  /* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
  Address p = FIRST(L);
  Address maksimum = p;

  while (p) {
    if (INFO(p) > INFO(maksimum)) {
      maksimum = p;
    }
    p = NEXT(p);
  }
  return maksimum;
}

ElType min(List L) {
  /* Mengirimkan nilai info(P) yang minimum */
  return INFO(adrMin(L));
}

Address adrMin(List L) {
  /* Mengirimkan address P, dengan info(P) yang bernilai minimum */
  Address p = FIRST(L);
  Address minimum = p;
  while (p) {
    if (INFO(p) < INFO(minimum)) {
      minimum = p;
    }
    p = NEXT(p);
  }
  return minimum;
}

float average(List L) {
  /* Mengirimkan nilai rata-rata info(P) */
  if (isEmpty(L)) {
    return 0;
  } else {
    int panjang = 0;
    Address p = FIRST(L);
    int jumlah = 0;
    while (p) {
      jumlah += INFO(p);
      panjang++;
      p = NEXT(p);
    }
    float avg = ((float)jumlah) / panjang;
    return (avg == 0) ? 0 : avg;
  }
}

void delAll(List *L) {
  /* Delete semua elemen list dan alamat elemen di-dealokasi */
  Address p = FIRST(*L);

  while (p) {
    Address nilai = p;
    p = NEXT(p);

    free(nilai);
  }

  *L = NULL;
}

void inverseList(List *L) {
  /* I.S. sembarang. */
  /* F.S. elemen list dibalik : */
  /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
  /* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

  Address p = FIRST(*L);
  Address p2 = NULL, p3;

  while (p) {
    p3 = NEXT(p);
    NEXT(p) = p2;
    p2 = p;
    p = p3;
  }

  *L = p2;
}

List fInverseList(List L) {
  /* Mengirimkan list baru, hasil invers dari L */
  /* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
  /* Jika alokasi gagal, hasilnya list kosong */
  /* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
  Address p = FIRST(L);
  List hasil;
  boolean aksi = false;

  CreateList(&hasil);
  while (p && !aksi) {
    insertFirst(&hasil, INFO(p));
    p = NEXT(p);
  }
  if (aksi) {
    delAll(&hasil);
  }
  return hasil;
}

void copyList(List *L1, List *L2) {
  /* I.S. L1 sembarang. F.S. L2=L1 */
  /* L1 dan L2 "menunjuk" kepada list yang sama.*/
  /* Tidak ada alokasi/dealokasi elemen */
  *L2 = *L1;
}

List fCopyList(List L) {
  /* Mengirimkan list yang merupakan salinan L */
  /* dengan melakukan alokasi. */
  /* Jika ada alokasi gagal, hasilnya list kosong dan */
  /* semua elemen yang terlanjur di-alokasi, harus didealokasi */
  Address p = FIRST(L);
  List hasil;
  boolean aksi = false;
  CreateList(&hasil);
  while (p && !aksi) {
    insertLast(&hasil, INFO(p));
    p = NEXT(p);
  }
  if (aksi) {
    delAll(&hasil);
  }
  return hasil;
}

void cpAllocList(List Lin, List *Lout) {
  /* I.S. Lin sembarang. */
  /* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
  /* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur
   * dialokasi, didealokasi */
  /* dengan melakukan alokasi elemen. */
  /* Lout adalah list kosong jika ada alokasi elemen yang gagal */
  *Lout = fCopyList(Lin);
}

void splitList(List *L1, List *L2, List L) {
  /* I.S. L mungkin kosong */
  /* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
  /* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
  /* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
  /* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */
  CreateList(L1);
  CreateList(L2);

  int panjang = length(L);
  Address p = FIRST(L);

  for (int i = 0; i < panjang / 2; i++) {
    insertLast(L1, INFO(p));
    p = NEXT(p);
  }

  while (p) {
    insertLast(L2, INFO(p));
    p = NEXT(p);
  }
}