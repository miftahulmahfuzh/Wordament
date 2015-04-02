#ifndef __MESINKATA1_H__
#define __MESINKATA1_H__

#include "mesinkar.h"

/* ***** Kontanta ***** */
#define NMax 50
#define BLANK ' '
#define BLANK1 '\n'

/* ***** Definisi Type Kata ***** */
typedef struct {
	char TabKata[NMax+1];
	int Length;
} Kata;
/* TabKata adalah tempat penampung/container kata,
   Length menyatakan panjangnya kata */
 
/* ***** Definisi State Mesin Kata ***** */
extern boolean EndKata; /* penanda akhir akuisisi kata */
extern Kata CKata;		/* kata yang sudah diakuisisi dan akan diproses */

/* ***** Primitif-Primitif Mesin Kata ***** */
void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
void STARTKATA();
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = Mark;
		atau EndKata = false, CKata adalah kata yang sudah
		diakuisisi,
		CC karakter pertama sesudah karakter terakhir kata */
void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
		  CC adalah karakter pertama dari kata berikutnya,
		  mungkin MARK
   Proses : Akuisisi kata menggunakan procedure SalinKata */
void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
		  CC = BLANK atau CC = MARK;
		  CC adalah karakter sesudah karakter terakhir yang
		  diakuisisi */
void KataToString(char str[]);
void KataToInt(int *value);

/* ***** Operasi Lain ***** */
boolean IsKataSama (Kata K1, Kata K2);
/* Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
urutan karakter yang menyusun kata juga sama */
#endif
