#include <stdio.h>
#include "tokenmachine.h"
#include "charmachine.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 30 September 2021
Topik praktikum     : Queue
Deskripsi           : implementasi header tokenmachine.h
*/

boolean endToken;
Token currentToken;

void ignoreBlank(){
    while (currentChar == BLANK){
        adv();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void startToken(){
    start();
    ignoreBlank();
    if (currentChar == MARK){
        endToken = true;
    } else {
        endToken = false;
        advToken();
    }
}
/* I.S. : currentChar sembarang 
   F.S. : endToken = true, dan currentChar = MARK; 
          atau endToken = false, currentToken adalah Token yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir Token */

void advToken(){
    ignoreBlank();
    if(currentChar == MARK){
        endToken = true;
    }else{
        salinToken();
        ignoreBlank();
    }
}

/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentToken adalah Token terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, maka endToken = true		  
   Proses : Akuisisi kata menggunakan procedure salinToken */

void salinToken(){
    int val;
    int i=0;
    int n=0;
    ignoreBlank();
    if(currentChar==MARK){
        endToken = true;
    }else if(currentChar=='+'||currentChar=='-'||currentChar=='*'||currentChar=='/'||currentChar=='^'){
        currentToken.tkn = currentChar;
        currentToken.val = -1;
        adv();
    }else{
        currentToken.tkn = 'b';
        while(currentChar != BLANK && currentChar != MARK && i<CAPACITY){
            switch (currentChar){
                case '0':
                    val = 0;
                    break;
                case '1':
                    val = 1;
                    break;
                case '2':
                    val = 2;
                    break;
                case '3':
                    val = 3;
                    break;
                case '4':
                    val = 4;
                    break;
                case '5':
                    val = 5;
                    break;
                case '6':
                    val = 6;
                    break;
                case '7':
                    val = 7;
                    break;
                case '8':
                    val = 8;
                    break;
                case '9':
                    val = 9;
                    break;
                default:
                    break;
            }
            n = n*10 + val;
            i++;
            adv();
        }
        currentToken.val = n;
    }
}
/* Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
   I.S. : currentChar adalah karakter pertama dari Token
   F.S. : currentToken berisi Token yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata "dipotong" */



