#include <stdio.h>
#include "queue.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 7 Oktober 2021
Topik praktikum     : queue
Deskripsi           : antrian kereta
*/


float avgElmt (Queue Q)
/* Menghasilkan rata-rata elemen dalam queue Q yang tidak kosong */
{
    float jumlah = 0;
    int i = IDX_HEAD(Q);

    while (i <= IDX_TAIL(Q)){
        jumlah += Q.buffer[i];
        i++;
    }
    return(jumlah/(length(Q)));
}

int main()
{
    //kamus
    int hitungAntri = 0;
    int input;
    ElType time;
    ElType rubbish;
    boolean loop = true;
    Queue Antrian;
    CreateQueue(&Antrian);
    scanf("%d",&input);

    while (loop)
    {
        if (input == 1){
           scanf("%d", &time);
           if (isFull(Antrian)){
               printf("Queue penuh\n");
           } else {
               enqueue(&Antrian,time);
           }
           scanf("%d",&input); 
        }
        else if (input == 2){
            if (isEmpty(Antrian)){
                printf("Queue kosong\n");
            } else {
                dequeue(&Antrian, &rubbish);
            }
            scanf("%d",&input); 
        }

        else if ( input == 0){
            loop = false;
            
        }
        


    }
    
    printf("%d\n", length(Antrian));
    if (isEmpty(Antrian)){
        printf("Tidak bisa dihitung\n");
    } else {
        printf("%.2f\n", avgElmt(Antrian));
    }



  return 0;
}