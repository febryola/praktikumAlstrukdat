#include "listpos.h"
#include "listpos.c"
#include <stdio.h>

int main(){
   int max, min, try;


   ListPos l3,l1,l2;
   ElType val;
   int i;
   printf("Masukkan panjang list 1: \n");
   readList(&l1);
   printf("Berikut tampilan list 1\n");
   displayList(l1);
   printf("\n");
   printf("\n");
   deleteAt(&l1, i);
   displayList(l1);
   printf("\n");
   printf("Masukkan panjang list 2: \n");
   readList(&l2);
   printf("Berikut tampilan list 2\n");
   displayList(l2);
   printf("\n");
   printf("\n");
   int panjang = length(l1);
   printf("Panjang list 1 adalah %d", panjang);
   printf("\n");
   printf("\n");
   printf("Jika diurutkan dari terkecil ke terbesar\n");
   sort(&l1, true);
   displayList(l1);
   printf("\n");
   printf("\n");
   printf("jika diurutkan dari terbesar ke terkecil\n");
   sort(&l1, false);
   displayList(l1);
   printf("\n");
   printf("\n");

   
   return 0;
}