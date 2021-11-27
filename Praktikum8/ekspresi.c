#include <stdio.h>
#include "stack.h"
#include "tokenmachine.h"
#include "charmachine.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 21 Oktober 2021
Topik praktikum     : Hash
Deskripsi           : Implementasi fungsi ekspresi
*/


int main(){
    startToken();
    ignoreBlank();

    Stack satu, dua;
    CreateStack(&satu);
    CreateStack(&dua);

    int hasil = 0, finalhasil = 0;
    boolean kosong = true;

    while (!endToken){
        hasil = 0;
        if (kosong){
            kosong = false;
        }
        if (currentToken.tkn == 'b'){
            push(&satu, currentToken.val);
            printf("%d\n", currentToken.val);
        } else {
            int A, B;
            if (IDX_TOP(satu) >= 1){
                pop(&satu, &B);
                pop(&satu, &A);
            }
            if (currentToken.tkn == '+'){
                hasil = A+B;
                printf("%d + %d\n%d\n", A, B, hasil);
            } else if (currentToken.tkn == '-'){
                hasil = A-B;
                printf("%d - %d\n%d\n", A, B, hasil);
            } else if (currentToken.tkn == '*'){
                hasil = A*B;
                printf("%d * %d\n%d\n", A, B, hasil);
            } else if (currentToken.tkn == '/'){
                hasil = A/B;
                printf("%d / %d\n%d\n", A, B, hasil);
            } else if (currentToken.tkn == '^'){
                int i;
                int base = 1;
                for (i=0;i<B;i++){
                    base *= A;
                }
                hasil = base;
                printf("%d ^ %d\n%d\n", A, B, hasil);
            }
            push(&satu, hasil);
            finalhasil = hasil;
        }

        ignoreBlank();
        advToken();
    }

    if (!isEmpty(satu)){
        pop(&satu, &hasil);
    }

    if (kosong){
        printf("Ekspresi kosong\n");
    } else {
        printf("Hasil=%d\n", hasil);
    }
}