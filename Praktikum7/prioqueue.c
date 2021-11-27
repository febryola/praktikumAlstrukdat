#include "prioqueue.h"
#include <stdio.h>

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 7 Oktober 2021
Topik praktikum     : Priority Queue
Deskripsi           : Program Priority Queue
*/


/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq) {
  /* I.S. sembarang */
  /* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
  /* - Index head bernilai IDX_UNDEF */
  /* - Index tail bernilai IDX_UNDEF */
  /* Proses : Melakukan alokasi, membuat sebuah pq kosong */

  IDX_HEAD(*pq) = IDX_UNDEF;
  IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq) {
  /* Mengirim true jika pq  kosong: lihat definisi di atas */

  return IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF;
}

boolean isFull(PrioQueue pq) {
  /* Mengirim true jika tabel penampung elemen pq sudah penuh */
  /* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */

  return IDX_HEAD(pq) == 0 && IDX_TAIL(pq) == CAPACITY - 1;
}

int length(PrioQueue pq) {
  /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */

  if (isEmpty(pq)) {
    return 0;
  } else {
    return (IDX_TAIL(pq) - IDX_HEAD(pq)) + 1;
  }
}

/*** Primitif Add/Delete ***/
void enqueue(PrioQueue *pq, ElType val) {
  /* Proses: Menambahkan val pada pq dengan aturan FIFO */
  /* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
  /* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
          Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju"
     elemen-elemen pq
          menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

  if (isEmpty(*pq)) {
    IDX_HEAD(*pq) = 0;
    IDX_TAIL(*pq) = 0;
  } else if (IDX_TAIL(*pq) == CAPACITY - 1) {
    for (int i = 0; i < length(*pq); i++) {
      pq->buffer[i] = pq->buffer[IDX_HEAD(*pq) + i];
    }

    IDX_TAIL(*pq) = length(*pq);
    IDX_HEAD(*pq) = 0;
  } else {
    IDX_TAIL(*pq)++;
  }

  TAIL(*pq) = val;

  for (int i = IDX_TAIL(*pq); i > IDX_HEAD(*pq); i--) {
    if (pq->buffer[i].score > pq->buffer[i - 1].score ||
        (pq->buffer[i].score == pq->buffer[i - 1].score &&
         pq->buffer[i].tArrival < pq->buffer[i - 1].tArrival)) {
      // SWAP
      ElType tmp = pq->buffer[i];
      pq->buffer[i] = pq->buffer[i - 1];
      pq->buffer[i - 1] = tmp;
    }
  }
}

void dequeue(PrioQueue *pq, ElType *val) {
  /* Proses: Menghapus val pada q dengan aturan FIFO */
  /* I.S. pq tidak mungkin kosong */
  /* F.S. val = nilai elemen HEAD pd
  I.S., HEAD dan IDX_HEAD "mundur";
          pq mungkin kosong */

  *val = HEAD(*pq);
  if (length(*pq) == 1) {
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
  } else {
    IDX_HEAD(*pq)++;
  }
}

void displayQueue(PrioQueue q) {
  /* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara
     kurung siku; antara dua elemen dipisahkan dengan separator "koma", tanpa
     tambahan karakter di depan, di tengah, atau di belakang, termasuk spasi dan
     enter */
  /* I.S. q boleh kosong */
  /* F.S. Jika q tidak kosong: [e1,e2,...,en] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
  /* Jika Queue kosong : menulis [] */

  printf("[");

  for (int i = IDX_HEAD(q); i <= IDX_TAIL(q) && !isEmpty(q); i++) {
    printf("%d", q.buffer[i].id);

    if (i != IDX_TAIL(q)) {
      printf(",");
    }
  }

  printf("]");
}
