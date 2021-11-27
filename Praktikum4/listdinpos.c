/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 16 September 2021
Topik praktikum     : ADT List Dinamis Pada C
Deskripsi           : Implementasi dari header listdinpos.h
*/

/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori list dinamik */

#include <stdio.h>
#include <stdlib.h>
#include "listdinpos.h"


/*  Kamus Umum */

/* Indeks tak terdefinisi*/

/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */

/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  List kosong: semua elemen bernilai VAL_UNDEF
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i terbesar
                                             sehingga l.buffer[i] != VAL_UNDEF
  Definisi nEff: jumlah elemen efektif, di mana l.buffer[nEff] == VAL_UNDEF
                                             dan l.buffer[nEff-1] != VAL_UNDEF */

/* ********** SELEKTOR ********** */


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
{
    int i;
    BUFFER(*l)=(int *) malloc (capacity * sizeof(int));
    CAPACITY(*l) = capacity;
    for(i=0;i<capacity;i++){
        ELMT(*l,i)=VAL_UNDEF;
    }
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */

void dealocate(ListDin *l)
{
    free(BUFFER(*l));
    CAPACITY(*l)=0;
}
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l)
{
    int i,tot=0;
    for(i=0;i<CAPACITY(l);i++)
    {
        if(ELMT(l,i)!=VAL_UNDEF)
            tot++;
    }
    return tot;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l){
    return (length(l)-1);
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
{
    return ((i>=0)&&(i<CAPACITY(l)));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i)
{
    return ((i>=0)&&(i<=getLastIdx(l)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..getLastIdx(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
{
    return (length(l)==0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l)
{
    return (length(l)==CAPACITY(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
{
    int value,i;
    scanf("%d",&value);
    while(value<0 || value > CAPACITY(*l)){
        scanf("%d",&value);
    }
    if (value!=0){
        for (i=0;i<value;i++)
        {
            scanf("%d",&ELMT(*l,i));
        }
    }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void displayList(ListDin l)
{
    int i,len;
    len = length(l);
    printf("[");
    for(i=0;i<len;i++){
        printf("%d",ELMT(l,i));
        if(i!=len-1)
            printf(",");
    }
    printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
    ListDin LL;
    int i;
    CreateListDin(&LL,CAPACITY(l1));
    for(i=0;i<length(l1);i++){
        if(plus){
            ELMT(LL,i)=ELMT(l1,i)+ELMT(l2,i);
        }
        else{
            ELMT(LL,i)=ELMT(l1,i)-ELMT(l2,i);
        }
    }
    return LL;
}
/* Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
{
    int i=0,flag=0;
    sort(&l1,true);sort(&l2,true);
    if(length(l1)!=length(l2))
        return false;
    else{
        while ((flag==0) && (i<length(l1)))
        {
            if(ELMT(l1,i)!=ELMT(l2,i)){
                flag++;
            }
            i++;
        }
        if(flag!=0)
            return false;
        else
            return true;
    }
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
{
    if(isEmpty(l))
        return VAL_UNDEF;
    else{
        int i=0;
        boolean flag=true;
        while(flag==true && i<length(l)){
            if(ELMT(l,i)==val)
                flag=false;
            i++;
        }
        if (flag==true)
            return VAL_UNDEF;
        else
            return i-1;
    }
}
/* Search apakah ada elemen list l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan VAL_UNDEF */
/* Menghasilkan nilai tak terdefinisi (VAL_UNDEF) jika list l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min)
{
    *max = -999;
    *min = 999;
    int i;
    for(i=0;i<length(l);i++){
        if(ELMT(l,i)>*max)
            *max = ELMT(l,i);
        else if (ELMT(l,i)<*min)
            *min = ELMT(l,i);
    }
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
{
    CreateListDin(lOut,CAPACITY(lIn));
    int i;

    for(i=0;i<length(lIn);i++)
    {
        ELMT(*lOut,i)=ELMT(lIn,i);
    }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
ElType sumList(ListDin l)
{
    int i,flag=0;
    if (length(l)==0)
        return 0;
    else
    {
        for(i=0;i<length(l);i++){
            flag=flag+ELMT(l,i);
        }
        return flag;
    }
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val)
{
    if(length(l)==0)
        return 0;
    else{
        int i,temu=0;
        for(i=0;i<length(l);i++){
            if (ELMT(l,i)==val)
                temu++;
        }
        return temu;
    }
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
boolean isAllEven(ListDin l)
{
    boolean flag=true;
    int i;
    i=0;
    while(flag==true && i<length(l)){
        if(ELMT(l,i)%2 !=0)
            flag = false;
        i++;
    }
    return flag;   
}
/* Menghailkan true jika semua elemen l genap. l boleh kosong */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
{
    int i,j,temp;
    if((length(*l)!=0) && (asc == true)){
        for(i=1;i<length(*l);i++){
            j=i-1;
            while((j>=0) && (ELMT(*l,j)>ELMT(*l,i))){
                temp = ELMT(*l,j+1);
                ELMT(*l,j+1) = ELMT(*l,j);
                ELMT(*l,j) = temp;
                i=j;
                j--;
            }
        }
    }
    else if((length(*l)!=0) && (asc == false)){
        for(i=1;i<length(*l);i++){
            j=i-1;
            while((j>=0) && (ELMT(*l,j)<ELMT(*l,i))){
                temp = ELMT(*l,j+1);
                ELMT(*l,j+1) = ELMT(*l,j);
                ELMT(*l,j) = temp;
                i=j;
                j--;
            }
        }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
{
    ListDin tempAr;
    int i;
    if (length(*l)==CAPACITY(*l)){
        CAPACITY(*l)=CAPACITY(*l)+1;
        CreateListDin(&tempAr,CAPACITY(*l));
        for (i=0;i<length(*l);i++)
            ELMT(tempAr,i)=ELMT(*l,i);
        dealocate(l);
        BUFFER(*l)=BUFFER(tempAr);
    }
    ELMT(*l,length(*l))=val;
}
/* Proses: Menambahkan X sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
{
    *val = ELMT(*l,length(*l)-1);
    ELMT(*l,length(*l)-1)=VAL_UNDEF;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num)
{
    CAPACITY(*l)=CAPACITY(*l)+num;
}
/* Proses : Menambahkan kapasitas sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num)
{
    if ((CAPACITY(*l)>num)&&(length(*l)<(CAPACITY(*l)-num)))
        CAPACITY(*l)=CAPACITY(*l)-num;
}
/* Proses : Mengurangi kapasitas sebanyak num */
/* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compactList(ListDin *l)
{
    CAPACITY(*l)=length(*l);
}
/* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran Capacity = nEff */
