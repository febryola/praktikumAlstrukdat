#include <stdio.h>
#include "listrec.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 18 November 2021
Topik praktikum     : List rekursif
Deskripsi           : kasus undian
*/


List splitOddIndex(List l) {
  /* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada
  indeks ganjil pada list L, sesuai dengan urutannya. Elemen HEAD merupakan
  indeks 1. Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
  if (isEmpty(l)) {
    return NULL;
  } else if (isOneElmt(l)) {
    return l;
  } else {
    return konso(splitOddIndex(tail(tail(l))), head(l));
  }
}

List splitEvenIndex(List l) {
  /* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada
  indeks genap pada list L, sesuai dengan urutannya. Elemen HEAD merupakan
  indeks 1. Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
  if (isOneElmt(l) || isEmpty(l)) {
    return NULL;
  } else {
    return splitOddIndex(tail(l));
  }
}

List splitBeforeX(List l, ElType x) {
  /* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen di depan
  elemen dengan nilai x pada list l, sesuai dengan urutannya. Jika x tidak ada
  pada list, maka kembalikan list l. Jika tidak ada elemen yang bisa diambil,
  kembalikan NULL */
  if (isEmpty(l) || head(l) == x) {
    return NULL;
  } else {
    return konso(splitBeforeX(tail(l), x), head(l));
  }
}

List reverseList(List l) {
  /* Mengembalikan sebuah list baru yang urutannya merupakan kebalikan dari list
  l. Jika l kosong, kembalikan list kosong. */
  if (isEmpty(l)) {
    return NULL;
  } else {
    return konsb(reverseList(tail(l)), head(l));
  }
}

int main() {
  char perintah = '\0';
  List player = NULL;
  while (perintah != 'X') {
    scanf("%c", &perintah);
    int x;
    switch (perintah) {
      case 'B':
        scanf("%d", &x);
        player = konsb(player, x);
        break;
      case 'F':
        scanf("%d", &x);
        player = konso(player, x);
        break;
      case 'O':
        player = splitOddIndex(player);
        break;
      case 'E':
        player = splitEvenIndex(player);
        break;
      case 'P':
        scanf("%d", &x);
        player = splitBeforeX(player, x);
        break;
      case 'R':
        player = reverseList(player);
        break;
    }
  }
  if (player) {
    displayList(player);
  } else {
    printf("Semua gugur\n");
  }
  return 0;
}