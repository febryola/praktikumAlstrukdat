#include <stdio.h>
#include "listdin.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 14 September 2021
Topik praktikum     : ADT List Dinamis Pada C
Deskripsi           : Implementasi dari header listdin.h
*/

// Prosedur yang dipakai pada program ini
void tampilkan(ListDin l);
void lakukanOperasi(ListDin *l);
boolean operasi1(ListDin *l, int Q);
boolean operasi2(ListDin *l, int Q);
boolean operasi3(ListDin *l, int Q);
boolean operasi4(ListDin *l);


void tampilkan(ListDin l){
    printf("%d ", l.capacity);
    displayList(l); printf("\n");
    return;
}

void lakukanOperasi(ListDin *l){
    int op, Q;
    scanf("%d", &op);
    boolean r = false;
    switch (op){
        case 1:
            scanf("%d", &Q);
            r = operasi1(l, Q);
            break;
        case 2:
            scanf("%d", &Q);
            r = operasi2(l, Q);
            break;
        case 3:
            scanf("%d", &Q);
            r = operasi3(l, Q);
            break;
        case 4:
            r = operasi4(l);
            break;
        default:
            break;
    }
    if (r){
        tampilkan(*l);
    }
    return;
}


// Fungsi operasi pertama
boolean operasi1(ListDin *l, int Q){
    if (isFull(*l)){
        printf("list sudah penuh\n");
        return false;
    } else {
        insertLast(l, Q);
        return true;
    }
}

// Fungsi operasi kedua
boolean operasi2(ListDin *l, int Q){
    growList(l, Q);
    return true;
}

// Fungsi operasi ketiga
boolean operasi3(ListDin *l, int Q){
    if (l->capacity < Q){
        printf("list terlalu kecil\n");
        return false;
    } else {
       shrinkList(l, Q);
        return true;
    }
}

// Fungsi operasi keempat
boolean operasi4(ListDin *l){
    compactList(l);
    return true;
}

int main(){
    ListDin l;
    int capacity, Q;
    
    //Membuat ListDin dengan ukuran maxel
    scanf("%d", &capacity);
    CreateListDin(&l, capacity);

    //Mengisi ListDin
    readList(&l);
    //Melakukan Operasi
    scanf("%d", &Q);
    int i;
    for (i = 0; i < Q; i++){
        lakukanOperasi(&l);
    }
    return 0;
}

