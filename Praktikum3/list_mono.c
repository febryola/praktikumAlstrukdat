#include <stdio.h>
#include "listpos.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 9 September 2021
Topik praktikum     : ADT List Pada C
Deskripsi           : Membuat implementasi dengan file list_mono.c
*/

int main(){

    ListPos l, ldesc, lasc; //tipe data list
    readList(&l);           //membaca list
    ldesc = l;              //mengganti nilai list
    lasc = l;               //mengganti nilai list

    sort(&ldesc, false);    //melakukan sorting pada list
    sort(&lasc, true);      //melakukan sorting pada list

    if (isListEqual(l, ldesc) && isListEqual(l, lasc)){ //jika kedua list saling equal
        printf("Static Monotonic List\n");
    } else {
        if (isListEqual(l, lasc)){
            printf("Non-descending Monotonic List\n");  //jika list tidak mengecil
        } else if (isListEqual(l, ldesc)){
            printf("Non-ascending Monotonic List\n");   //jika list tidak membesar
        } else {
            printf("Non-monotonic List\n");             //bukan list monotonic
        }
    }
}

//Program selesai
