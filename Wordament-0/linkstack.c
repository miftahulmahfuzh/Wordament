/* File : linkstack.c */

#include "linkstack.h"

/* Prototype manajemen memori */
void Alokasi (address_stack *P, infotype_stack X)
/* I.S. Sembarang */
/* F.S.Alamat P dialokasi, jika berhasil maka Info(P)=X dan
	Next(P)=Nil */
/* P=Nil jika alokasi gagal */
{	/* Kamus Lokal */
	/* Algoritma */
	*P = (address_stack) malloc(sizeof(Stack));
	if(*P != Nil)
	{
		Info_stack(*P) = X;
		Next_stack(*P) = Nil;
	}
}
void Dealokasi (address_stack P)
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{	/* Kamus Lokal */
	/* Algoritma */
	free(P);
}
/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{	/* Kamus Lokal */
	/* Algoritma */
	return Top(S) == Nil;
}
void CreateEmpty (Stack * S)
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
{	/* Kamus Lokal */
	/* Algoritma */
	Top(*S) = Nil;
}
void Push (Stack * S, infotype_stack X)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/* jika tidak, S tetap */
{	/* Kamus Lokal */
	address_stack P;
	/* Algoritma */
	Alokasi(&P, X);
	Next_stack(P) = Top(*S);
	Top(*S) = P;
}
void Pop (Stack * S, infotype_stack * X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/* elemen TOP yang lama didealokasi */
{	/* Kamus Lokal */
	address_stack P;
	/* Algoritma */
	*X = InfoTop(*S);
	P = Top(*S);
	Top(*S) = Next_stack(P);
	Dealokasi(P);
}
void PopUntil(Stack * S, infotype_stack X)
/* Menghapus Stack S sampai elemen top dari S adalah X atau S kosong */
/* I.S. S tidak mungkin kosong */
/* F.S. elemen TOP menjadi X atau Stack menjadi kosong */
{	/* Kamus Lokal */
	infotype_stack Y;
	/* Algoritma */
	while(!IsEmpty(*S))
	{
		if(InfoTop(*S) == X)
			break;
		Pop(S, &Y);
	}
}

void StackToString(Stack * S, char str[])
/* memindahkan elemen2 dari stack ke array of char */
/* I.S. str sembarang, S terdefinisi */
/* F.S. Stack S kosong, elemen2 stack dipindahkan ke str dengan karakter top dari S menjadi karakter terakhir dari str */
/* Asumsi banyaknya karakter yang dipindahkan selalu muat dalam str */
{	/* Kamus Lokal */
	Stack Stemp;
	infotype_stack X;
	int id;
	/* Algoritma */
	CreateEmpty(&Stemp);
	while(!IsEmpty(*S))
	{
		Pop(S, &X);
		Push(&Stemp, X);
	}
	id = 0;
	while(!IsEmpty(Stemp))
	{
		Pop(&Stemp, &X);
		str[id] = X;
		id++;
	}
	str[id] = '\0';
}
