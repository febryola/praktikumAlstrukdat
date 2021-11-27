/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen 
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 7 September 2021
Topik praktikum     : ADT List Pada C
Deskripsi           : Implementasi dari header listpos.h
*/

#include <stdio.h>
#include "listpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
{
   int i;
   for (i = 0; i <= CAPACITY-1; i++){
      ELMT(*l, i) = VAL_UNDEF;
   }
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
   int i, count = 0;
   for(i = 0; i <= CAPACITY-1; i++){
      if (l.contents[i] != VAL_UNDEF){
         count++;
      } else {
         break;
      }
   }
   return count;
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
   return ((i>=0) && (i<=CAPACITY-1));
}
boolean isIdxEff(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
   return (i>=0 && i<=(length(l)-1));
}  

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
{
   return (length(l) == 0);
}

boolean isFull(ListPos l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
   return (length(l) == CAPACITY);
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l)
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
{
   CreateListPos(l);
    
   int n;
   while (true){
      scanf("%d\n", &n);
      if (n >= 0 && n <= CAPACITY){
         break;
      }
   }

   if (n > 0){
      int i;
      for(i = 0;i < n; i++){
         scanf("%d\n", &(l->contents[i]));
      }
   }
}

void displayList(ListPos l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
   printf("[");
   if (!isEmpty(l)){
      int i;
      for (i = 0; i <= (length(l)-1); i++){
         printf("%d", l.contents[i]);

         if (i != (length(l)-1)){
            printf(",");
         }
      }
   }
   printf("]");
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus)
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
{  
   ListPos l3;
   CreateListPos(&l3);
   int i;
   for (i=0;i<=(length(l1)-1);i++){
      if (plus){
         ELMT(l3,i)=ELMT(l1,i)+ELMT(l2,i);
      }else{
         ELMT(l3,i)=ELMT(l1,i)-ELMT(l2,i);
      }
   }
   return l3;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
{

   if (length(l1)!=length(l2)){
      return false;
   }
   boolean hasil = (length(l1)==length(l2));
   int i;
   for(i=0;i<=(length(l1)-1);i++){
      hasil = hasil && (ELMT(l1, i) == ELMT(l2, i));
   }
   return hasil;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
   if (isEmpty(l)){
      return IDX_UNDEF;
   }

   int i,result=IDX_UNDEF;
   for(i=0; i <= (length(l)-1); i++){
      if (ELMT(l, i) == val){
         result = i;
         break;
      } 
   }
   return result;
}
/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
{
   int nmax, nmin, i;
   nmin = ELMT(l, 0);
   nmax = ELMT(l, 0);
   for(i=0; i <= (length(l)-1); i++){
      if (ELMT(l,i) > nmax){
         nmax = ELMT(l,i);
      } else if (ELMT(l,i) < nmin) {
         nmin = ELMT(l,i);
      }
   }
   *max = nmax;
   *min = nmin;
}
/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l)
/* Menghailkan true jika semua elemen l genap */
{
   boolean genap = true;
   int i = 0;
   while(genap && i <= (length(l)-1)){
      genap = (genap && (ELMT(l,i)%2 == 0));
      i++;
   }
   return genap;
}
/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
   int i, j;
   int key;

   for (i = 1; i <= (length(*l)-1); i++){
      key = ELMT(*l, i);
      j = i-1;
      while (j >= 0 && ((!asc && ELMT(*l,j) < key) || (asc && ELMT(*l,j) > key))){
         ELMT(*l,j+1) = ELMT(*l, j);
         j--;
      }
      ELMT(*l,j+1) = key;
   }
}
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
{
   if (!isFull(*l)) {
      l->contents[(length(*l))] = val;
   }
}

void insertFirst(ListPos *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
{
   int i;
   if (!isFull(*l)) {
      for (i=CAPACITY-1; i >= 0;i--){
         l->contents[i+1] = l->contents[i];
      }
      l->contents[0] = val;
   }
}

void deleteLast(ListPos *l, ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
   if (isEmpty(*l)) return;
   
   *val = l->contents[(length(*l)-1)];
   l->contents[(length(*l)-1)] = VAL_UNDEF;
}

void deleteFirst(ListPos *l, ElType *val)
{  
   int i;
   *val = l->contents[0];
   for (i=0; i <=length(*l)-1;i++){
      l->contents[i] = l->contents[i+1];
   }
 
}

void deleteAt(ListPos *l, int i)
{
   int j;
   scanf("%d\n", &i);
   for (j = i; j<=length(*l)-1;j++){
      l->contents[j] = l->contents[j+1];
   }
}