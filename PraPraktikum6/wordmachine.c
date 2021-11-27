/* File: wordmachine.h */
/* Definisi Word Engine */

#include "wordmachine.h"
#include <stdio.h>

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 23 September 2021
Topik praktikum     : Matriks
Deskripsi           : ADT Matriks
*/

boolean endWord;
Word currentWord;

void ignoreBlank(){
    while (currentChar == BLANK){
        adv();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void startWord(){
    start();
    ignoreBlank();
    if (currentChar == MARK){
        endWord = true;
    } else {
        endWord = false;
        advWord();
    }
}
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void advWord(){
    ignoreBlank();
    if (currentChar == MARK && !endWord){
        endWord = true;
    } else{
        copyWord();
        ignoreBlank();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyWord(){
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK) && i != CAPACITY) {
        currentWord.contents[i] = currentChar;
        adv();
        i++;
    }
    currentWord.length = (i < CAPACITY) ? i : CAPACITY;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */


