#include <stdio.h>
#include "queue_linked.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 11 November 2021
Topik praktikum     : queue_linked
Deskripsi           : Implementasi file mqueue.c
*/


int main() {
  Queue q;
  CreateQueue(&q);
  int input;
  scanf("%d", &input);
  for (int i = 0; i < input; i++) {
    int waktu;
    scanf("%d", &waktu);
    while (!isEmpty(q) && HEAD(q) < waktu - 300) {
      int p;
      dequeue(&q, &p);
    }
    enqueue(&q, waktu);
    printf("%d\n", length(q));
  }
  return 0;
}