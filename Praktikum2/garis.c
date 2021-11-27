// Nama 		: Febryola Kurnia Putri
// NIM          : 13520140
// Hari, Tanggal: Kamis, 2 September 2021
// Soal 2 implementasi dari header garis.h


#include <stdio.h>
#include "garis.h"
#include <math.h>

/* *** Selektor GARIS *** */
#define P1(L) PAwal(L)           //untuk titik 1
#define P2(L) PAkhir(L)          //untuk titik 2
#define x1(L) Absis(PAwal(L))    //untuk titik 3
#define x2(L) Absis(PAkhir(L))   //untuk titik 4
#define y1(L) Ordinat(PAwal(L))  //untuk titik 5
#define y2(L) Ordinat(PAkhir(L)) //untuk titik 6

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L)
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
{
    PAwal(*L) = P1;   //input titik awal ke garis
    PAkhir(*L) = P2;  //input titik akhir ke garis
}
/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L)
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
{
    POINT P1, P2;
    BacaPOINT(&P1); BacaPOINT(&P2); //membaca point
    while(EQ(P1, P2)){
        printf("Garis tidak valid\n");
        BacaPOINT(&P1); BacaPOINT(&P2);
    }
    MakeGARIS(P1, P2, L); // membuat garis dari komponen titik 
}
void TulisGARIS (GARIS L)
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
{
    printf("((%.2f,%.2f),(%.2f,%.2f))", x1(L), y1(L), x2(L), y2(L)); //menampilkan garis ke layar
}
/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L)
/* Menghitung panjang garis L : berikan rumusnya */
{
    return Panjang(P1(L), P2(L)); // mengembalikan panjang garis dari 2 titik
}
float Gradien (GARIS L) 
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
{
    return ((y2(L)-y1(L))/(x2(L)-x1(L))); //mengembalikan gradien/kemiringan dari garis
}
void GeserGARIS (GARIS * L, float deltaX, float deltaY)
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */
{
    Geser(&PAwal(*L), deltaX, deltaY);  //menggeser titik 1 pada garis
    Geser(&PAkhir(*L), deltaX, deltaY); //menggeser titik 2 pada garis
}
/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2)
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
{
    return (Gradien(L1)*Gradien(L2) == -1); //mengembalikan true jika garis tegak lurus
}
boolean IsSejajar (GARIS L1, GARIS L2)
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
{
    return (Gradien(L1) == Gradien(L2)); //mengembalikan true jika garis sejajar
}
