#include "prioqueue.h"
#include <stdio.h>

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 7 Oktober 2021
Topik praktikum     : m Priority Queue
Deskripsi           : Program m Priority Queue
*/

ElType readData() {
  ElType res;

  scanf("%d", &res.tArrival);
  scanf("%d", &res.id);
  scanf("%d", &res.score);
  scanf("%d", &res.dService);

  return res;
}

void printData(int layani, int id, int waktuMenunggu) {
  printf("%d %d %d\n", layani, id, waktuMenunggu);
}

int main() {
  PrioQueue pq;
  CreatePrioQueue(&pq);

  int n, t = 1;
  scanf("%d", &n);

  if (n <= 0) {
    printf("Tidak ada layanan\n");
    return 0;
  }

  for (int i = 0; i < n; i++) {
    ElType input = readData();

    if (t <= input.tArrival) {
      ElType layanan;

      if (isEmpty(pq)) {
        layanan = input;
        t = layanan.tArrival;
        printData(t, layanan.id, 0);
        t += layanan.dService;
      } else {
        while (!isEmpty(pq) && t <= input.tArrival) {
          ElType antrian;

          dequeue(&pq, &antrian);
          printData(t, antrian.id, t - antrian.tArrival);
          t += antrian.dService;
        }

        if (t <= input.tArrival) {
          t = input.tArrival;
          printData(t, input.id, 0);
          t += input.dService;
        } else {
          enqueue(&pq, input);
        }
      }

    } else {
      enqueue(&pq, input);
    }
  }

  while (!isEmpty(pq)) {
    ElType antrian;

    dequeue(&pq, &antrian);
    printData(t, antrian.id, t - antrian.tArrival);
    t += antrian.dService;
  }

  return 0;
}