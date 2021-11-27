#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

/*
NIM                 : 13520140
Nama                : Febryola Kurnia putri
Tanggal             : 25 November 2021
Topik praktikum     : Tree
Deskripsi           : invertBtree
*/

void invertBtree(BinTree *p){
    if (!isTreeEmpty(*p)){
        invertBtree(&(LEFT(*p)));
        invertBtree(&(RIGHT(*p)));
        *p = NewTree(ROOT(*p), RIGHT(*p), LEFT(*p));
    }
}