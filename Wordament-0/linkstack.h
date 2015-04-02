/* File : linkstack.h */
#ifndef _LINKSTACK_H
#define _LINKSTACK_H
#include "boolean.h"
#include <stdlib.h>

#define Nil NULL
/* Deklarasi infotype */
typedef char infotype_stack;
/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * address_stack;
typedef struct tElmtStack {
	infotype_stack Info_stack;
	address_stack Next_stack;
} ElmtStack;

/* Type stack dengan ciri TOP : */
typedef struct {
	address_stack TOP; /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info_stack
#define Next_stack(P) (P)->Next_stack
#define Info_stack(P) (P)->Info_stack

/* Prototype manajemen memori */
void Alokasi (address_stack *P, infotype_stack X);
/* I.S. Sembarang */
/* F.S.Alamat P dialokasi, jika berhasil maka Info(P)=X dan
	Next(P)=Nil */
/* P=Nil jika alokasi gagal */
void Dealokasi (address_stack P);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmpty (Stack * S);
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
void Push (Stack * S, infotype_stack X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/* jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */

void Pop (Stack * S, infotype_stack * X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/* elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

void PopUntil(Stack * S, infotype_stack X);
/* Menghapus Stack S sampai elemen top dari S adalah X atau S kosong */
/* I.S. S tidak mungkin kosong */
/* F.S. elemen TOP menjadi X atau Stack menjadi kosong */

void StackToString(Stack * S, char str[]);
/* memindahkan elemen2 dari stack ke array of char */
/* I.S. str sembarang, S terdefinisi */
/* F.S. Stack S kosong, elemen2 stack dipindahkan ke str dengan karakter top dari S menjadi karakter terakhir dari str */
/* Asumsi banyaknya karakter yang dipindahkan selalu muat dalam str */
#endif
