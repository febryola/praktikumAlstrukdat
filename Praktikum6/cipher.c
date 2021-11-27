#include <stdio.h>
#include "charmachine.c"
#include "wordmachine.c"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 30 September 2021
Topik praktikum     : Queue
Deskripsi           : implementasi header tokenmachine.h
*/

int main()
{
    startWord();
    int panjang = currentWord.length;
    while(!endWord){
       for (int i = 0; i < currentWord.length; i++){
           if (currentWord.contents[i] == ' ')
        {
            currentWord.contents[i]= ' ';
        }
           if(currentWord.contents[i] >= 'A' && currentWord.contents[i] <= 'Z'){
        
            currentWord.contents[i] = ((currentWord.contents[i] + panjang - 'A') % 26) + 'A';
            printf("%c",currentWord.contents[i]);
            ignoreBlank();}
       }
              if (currentChar == MARK) {
            printf(".");
        } else {
            printf(" ");
        }
        
        advWord();
    }
    
    printf("\n");
    return 0;
}