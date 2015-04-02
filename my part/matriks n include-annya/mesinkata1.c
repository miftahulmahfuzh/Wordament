#include "mesinkata1.h"

/* ***** Definisi State Mesin Kata ***** */
boolean EndKata;
Kata CKata;

/* ***** Primitif-Primitif Mesin Kata ***** */
void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{  /* Kamus Lokal */

   /* Algoritma */
   while ((CC == BLANK || CC == BLANK1) && (CC != MARK)) {
       ADV();
   } /* CC != BLANK or CC = MARK */
}
void STARTKATA(char filee[])
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = Mark;
		atau EndKata = false, CKata adalah kata yang sudah
		diakuisisi,
		CC karakter pertama sesudah karakter terakhir kata */
{  /* Kamus Lokal */

   /* Algoritma*/
   STARTRead(filee);
   IgnoreBlank();
   if (CC == MARK) {
       EndKata = true;
   } else /* CC != MARK */ {
       EndKata = false;
       SalinKata();
   }
}
void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
		  CC adalah karakter pertama dari kata berikutnya,
		  mungkin MARK
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{  /* Kamus Lokal */

   /* Algoritma*/
   IgnoreBlank();
   if (CC == MARK) {
		EndKata = true;
   } else /* CC != MARK */ {
		SalinKata();
   }
}
void SalinKata()
/*  Mengakuisisi kata, menyimpan dalam CKata
	I.S. : CC adalah karakter pertama dari kata
	F.S. : CKata berisi kata yang sudah diakuisisi;
			CC = BLANK atau CC = MARK;
			CC adalah karakter sesudah karakter terakhir yang
			diakuisisi */
{	/* Kamus Lokal */
	int i = 1; /* inisialisasi */
	/* Algoritma*/
	for (;;) {
		CKata.TabKata[i] = CC;
		ADV();
		if ((CC == MARK) || (CC == BLANK) || (CC == BLANK1)) {
			break;
		} else {
			i++;
		}
	} /* CC = MARK or CC = BLANK */
	CKata.Length = i;
}

void KataToString(char str[])
{	/* Kamus Lokal */
	int i;
	/* Algoritma */
	for(i = 1; i<=CKata.Length; i++)
		str[i-1] = CKata.TabKata[i];
	str[i-1] = '\0';
}

void KataToInt(int *value)
{	/* Kamus Lokal */
	int i;
	/* ALgoritma */
	(*value) = 0;
	for(i = 1; i<=CKata.Length; i++)
	{
		(*value) *= 10;
		(*value) += CKata.TabKata[i]-'0';
	}
}

/* ***** Operasi Lain ***** */
boolean IsKataSama (Kata K1, Kata K2)
/* Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
urutan karakter yang menyusun kata juga sama */
{	/* Kamus Lokal */
	int i = 1;
	/* Algoritma */
	if(K1.Length != K2.Length)
		return false;
	for(; i<=K1.Length; i++ )
		if(K1.TabKata[i] != K2.TabKata[i])
			return false;
	return true;
}
