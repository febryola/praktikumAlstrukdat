/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 14 September 2021
Topik praktikum     : ADT List Dinamis Pada C
Deskripsi           : Implementasi dari header listdin.h
*/

#include <stdio.h>
#include "listdin.h"
#include <stdlib.h>
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
      l->nEff = 0;
      l->capacity = capacity;
      l->buffer = (int *) malloc(capacity * sizeof(int));
      IdxType i;
      for(i=0; i < capacity; i++){
            l->buffer[i] = 0;
    }

}
void dealocate(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    l->nEff = 0;
    l->capacity = 0;
    free((l->buffer));
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
      return l.nEff;
}
/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
      return l.nEff-1;
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
      return (i >= 0 && i < l.capacity);
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
      return (i >= 0 && i < l.nEff);
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
{
      return (l.nEff == 0);
}
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
      return (l.nEff == l.capacity);
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
      int N;
      while (true){
            scanf("%d\n", &N);
            if (N >= 0 && N <= CAPACITY(*l)){
                  break;
            }
      }

      if (N > 0){
            IdxType i;
            l->nEff = N;
            for(i=0; i <= getLastIdx(*l); i++){
                  scanf("%d\n", &(l->buffer[i]));
            }
      } else if (N == 0){
            l->nEff = 0;
      }

}
void displayList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
      printf("[");
      if (!isEmpty(l)){
            int i;
            for (i=0; i <= getLastIdx(l); i++){
                  printf("%d", l.buffer[i]);
                  
                  if (i != getLastIdx(l)){
                  printf(",");
                  }
            }
      }
      printf("]");
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
      ListDin l3;
      CreateListDin(&l3, l1.capacity);
      l3.nEff = l1.nEff;
      
      IdxType i;
      for(i=0; i <=getLastIdx(l3); i++){
            if (plus){
                  ELMT(l3,i)=ELMT(l1,i)+ELMT(l2,i);
            }else{
                  ELMT(l3,i)=ELMT(l1,i)-ELMT(l2,i);
            }
      }
      return l3;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
      boolean equal = (l1.nEff == l2.nEff);

      IdxType i;
      for(i=0; i <=getLastIdx(l1); i++){
            if (i > getLastIdx(l2) || !equal){
                  break;
            }

            equal = (equal && (l1.buffer[i] == l2.buffer[i]));
      }
      return equal;
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
      if (isEmpty(l)){
            return IDX_UNDEF;
      }

      int i,result=IDX_UNDEF;
      for(i=0; i <= getLastIdx(l); i++){
            if (ELMT(l, i) == val){
                  result = i;
                  break;
            } 
      }
      return result;
}
/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
      int i;
      *min = ELMT(l, 0);
      *max = ELMT(l, 0);

      for(i=0; i <= getLastIdx(l); i++){
            if (ELMT(l,i) > *max){
                  *max = ELMT(l,i);
            } else if (ELMT(l,i) < *min) {
                  *min = ELMT(l,i);
            }
      }
}
/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
      ListDin lResult;
      CreateListDin(&lResult, lIn.capacity);
      lResult.nEff = lIn.nEff;

      IdxType i;
      for(i=0; i <= getLastIdx(lIn); i++){
            ELMT(lResult, i) = ELMT(lIn, i);
      }
      *lOut = lResult;
}
ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
      if (isEmpty(l)){
            return 0;
      }

      int i,sum = 0;
      for(i=0; i <= getLastIdx(l); i++){
            sum += ELMT(l,i);
      }
      return sum;
}
int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
      if (isEmpty(l)){
            return 0;
      }
      int i,count=0;
      for(i=0; i <= getLastIdx(l); i++){
            if(ELMT(l,i) == val){
                  count += 1; 
            }
      };
      return count;
}
boolean isAllEven(ListDin l)
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
{
      boolean even = true;
      int i = 0;
      while(even && i <= getLastIdx(l)){
            even = (even && (ELMT(l,i)%2 == 0));
            i++;
      }
      return even;
}
/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
      int i, j;
      IdxType key;

      for (i = 1; i <= getLastIdx(*l); i++){
            key = ELMT(*l, i);
            j = i-1;
            while (j >= 0 && ((!asc && ELMT(*l,j) < key) || (asc && ELMT(*l,j) > key))){
                  ELMT(*l,j+1) = ELMT(*l, j);
                  j--;
            }
            ELMT(*l,j+1) = key;
      }
      return;
}
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
      if (!isFull(*l)) {
            l->buffer[(getLastIdx(*l)+1)] = val;
            l->nEff += 1;
      }
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List lidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
      *val = l->buffer[getLastIdx(*l)];
      l->nEff -= 1;
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
      ListDin lBaru;
      CreateListDin(&lBaru, ((l->capacity)+num));
      lBaru.nEff = l->nEff;

      IdxType i;
      for(i=0; i <= getLastIdx(*l); i++){
            ELMT(lBaru, i) = ELMT((*l), i);
      }
      dealocate(l);
      *l = lBaru;
}
void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
      ListDin lBaru;
      int shrinked = (l->capacity)-num;
      CreateListDin(&lBaru, shrinked);
      lBaru.nEff = (l->nEff < shrinked ? l->nEff : shrinked);

      IdxType i;
      for(i=0; i <=getLastIdx(lBaru); i++){
            ELMT(lBaru, i) = ELMT((*l), i);
      }
      dealocate(l);
      *l = lBaru;
}
void compactList(ListDin *l)
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
{
      ListDin lBaru;
      CreateListDin(&lBaru, l->nEff);
      lBaru.nEff = l->nEff;

      IdxType i;
      for(i=0; i <= getLastIdx(lBaru); i++){
            ELMT(lBaru, i) = ELMT((*l), i);
      }
      dealocate(l);
      *l = lBaru;
}

