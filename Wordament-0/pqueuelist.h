/* File : pqueuelist.h */
#ifndef _PQUEUELIST_H
#define _PQUEUELIST_H
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

#define Nil NULL

/* Deklarasi infotype */
typedef char infotype[17];
/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtPQueue * addressP;
typedef struct tElmtPQueue {
	infotype Info;
	int prio;
	addressP Next;
} ElmtPQueue;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
	addressP HEAD; /* alamat penghapusan */
} PQueue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define InfoHead(Q) (Q).HEAD->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info
#define prio(P) (P)->prio

/* Prototype manajemen memori */
void AlokasiPQ (addressP *P, infotype X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */

void DealokasiPQ (addressP *P);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

boolean IsEmptyPQ (PQueue PQ);
/* Mengirim true jika PQ kosong: HEAD(PQ)=Nil and TAIL(PQ)=Nil */

int NBElmtPQ(PQueue PQ);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika PQ kosong */

/* ** Kreator ** */
void CreateEmptyPQ(PQueue * PQ);
/* I.S. sembarang */
/* F.S. Sebuah PQ kosong terbentuk */

/* ** Primitif Add/Delete ** */
void AddPQ (PQueue * PQ, infotype X, int pr);
/* Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi berhasil dengan memperhatikan prioritas; jika alokasi gagal Q tetap */
/* I.S. PQ mungkin kosong */
/* F.S. X menjadi elemen Q sesuai prioritas Pr, Q tetap terurut mengecil sesuai prioritas */

void DelPQ(PQueue * PQ, infotype * X, int *pr);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD, X berisi elemen dengan prioritas tertinggi */
/* I.S. PQ tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD dan Pr = nilai elemen prioritas HEAD pd I.S., HEAD "maju" */

void PrintPQ(PQueue PQ);
/* Menuliskan semua elemen priority queue ke layar */

void AssignPQ(infotype *PQ1, infotype PQ2);
/* assign nilai PQ2 ke PQ1 */

#endif
