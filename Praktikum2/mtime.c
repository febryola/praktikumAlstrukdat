// Nama 		: Febryola Kurnia Putri
// NIM          : 13520140
// Hari, Tanggal: Kamis, 2 September 2021
// Soal 1 durasi telepon

#include <stdio.h>
#include "time.h"

long int minimum(long int a, long int b){
	if (a < b){
		return a;
	} else {
		return b;
	}
}

long int maksimum(long int a, long int b){
	if (b > a){
		return b;
	} else {
		return a;
	}
}

// PROGRAM UTAMA
int main(){
	// KAMUS
	int n;
	long int waktuawal, waktuakhir;
	long int curwaktuawal, curwaktuakhir;

	// ALGORITMA
	// INPUT
	scanf("%d", &n);
	waktuawal = 86400; waktuakhir = 0;
	TIME T, T2;
	for (int i = 0; i < n; ++i){
		printf("[%d]\n", i+1);

		// PROSES
		BacaTIME(&T); BacaTIME(&T2);
		curwaktuawal = 86400; curwaktuakhir = 0;

		curwaktuawal = minimum(TIMEToDetik(T), TIMEToDetik(T2));
		curwaktuakhir = maksimum(TIMEToDetik(T), TIMEToDetik(T2));
		waktuawal = minimum(waktuawal, curwaktuawal);
		waktuakhir = maksimum(waktuakhir, curwaktuakhir);

		// OUTPUT
		printf("%ld\n", curwaktuakhir - curwaktuawal);
	}
	TulisTIME(DetikToTIME(waktuawal)); printf("\n");
	TulisTIME(DetikToTIME(waktuakhir)); printf("\n");

	return 0;
}
