#include <stdio.h>
#include "list_circular.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 4 November 2021
Topik praktikum     : Variasi Linked_List
Deskripsi           : Implementasi file roundrobin.c
*/

void deleteRR (List *l, ElType tQ)
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
- jika INFO(last)>tQ, maka last "diantrikan" kembali sebagai first elemen dengan INFO(last)=INFO(last)-tQ
- jika INFO(last)<=tQ, maka deleteLast(l,x) dan menampilkan x ke layar */
/* Jika l kosong, cetak "List kosong" */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai aturan round-robin.
l mungkin menjadi kosong. */
{
    Address last;
    ElType waktu;
    if (!isEmpty(*l)) {
        last = FIRST(*l);
        while (NEXT(last) != FIRST(*l)) {
            last = NEXT(last);
        }
        if (INFO(last)>tQ) {
            FIRST(*l) = last;
            INFO(FIRST(*l)) -= tQ;
            printf("%d\n",tQ);
        } else {
            deleteLast(l, &waktu);
            printf("%d\n", waktu);
        }
    } else {
        printf("List kosong\n");
    }
}

float average (List l)
/* Menghasilkan nilai rata-rata elemen l. l tidak kosong. */
{
    Address p;
	float nilai;
	int hitung = 1;
    p = FIRST(l);
    nilai = INFO(p);
	while (NEXT(p) != FIRST(l)) {
		p = NEXT(p);
		nilai += INFO(p);
		hitung++;
	}
	return (nilai/hitung);
}

int main() //implementasi dari fungsi utama
{
    List L;
    CreateList(&L);
    ElType TQ;
    char dummy;
    ElType waktu;
    boolean var = true;
    // input waktu slice
    do {
        scanf("%d",&TQ);
    } while (TQ <= 0);

    while (var){
        scanf("\n%c",&dummy);
        if (dummy=='A') {
            scanf("%d",&waktu);
            if (waktu > 0 ){
                insertFirst(&L,waktu);
            }
        } else if (dummy=='D') {
            deleteRR(&L,TQ);
        } else if (dummy=='F') {
            var = false;
        } else {
            printf("Kode salah\n");
        }
    }
    if(!isEmpty(L)) {
        float nilai=average(L);
        printf("%.2f\n",nilai);
    } else {
        printf("Proses selesai\n");
    }
    return 0;
}