#include <stdio.h>
#include "stack.c"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 21 Oktober 2021
Topik praktikum     : Hash
Deskripsi           : Implementasi file bigint.c
*/


void displayStack ( Stack S) {
    int i ;
    for (i =IDX_TOP(S); i >= 0; i--){
        printf("%d", S.buffer[i]);
    }
}

int charToInteger (char angka){
    if (angka == '0'){
		return 0;
	} else if (angka == '1'){
		return 1;
	} else if (angka == '2'){
		return 2;
	} else if (angka == '3'){
		return 3;
	} else if (angka == '4'){
		return 4;
	} else if (angka == '5'){
		return 5;
	} else if (angka == '6'){
		return 6;
	} else if (angka == '7'){
		return 7;
	} else if (angka == '8'){
		return 8;
	} else if (angka == '9'){
		return 9;
	} else {
		return -1;
	}
}

int main(){

    Stack S1, S2, SPlus;
    int carrie, sisa = 0;
    char angka;
    ElType angka1,angka2;
    CreateStack(&S1);
    CreateStack(&S2);
    CreateStack(&SPlus);
    
    do {
        scanf("%c", &angka);
        if ((angka != '#')&&(angka != '\n')) {
            push(&S1, charToInteger(angka));
        } 
    } while (angka != '#');

    do {
        scanf("%c", &angka);
        if ((angka != '#')&&(angka != '\n')) {
            push(&S2, charToInteger(angka));
        } 
    } while (angka != '#');

    while (!(isEmpty(S1) && isEmpty(S2))) {

        if (!isEmpty(S1) && !isEmpty(S2)) {
            pop(&S1,&angka1);pop(&S2,&angka2);
            sisa = (carrie + angka1 + angka2) % 10;
            carrie = (carrie + angka1 + angka2) / 10;
            push(&SPlus, sisa);
        }

        else if (isEmpty(S1) && !(isEmpty(S2))) {
            pop(&S2, &angka1);
            sisa = (carrie + angka1) % 10;
            carrie = (carrie + angka1) /10;
            push(&SPlus, sisa);

        }

         else if (!isEmpty(S1) && (isEmpty(S2))) {
            pop(&S1, &angka1);
            sisa = (carrie + angka1) % 10;
            carrie = (carrie + angka1) /10;
            push(&SPlus, sisa);

        }
    }
    if (carrie != 0) {
        push(&SPlus, carrie);
    }

    displayStack(SPlus);
    printf("\n");
    return 0;
}
