#ifndef matriks_H
#define matriks_H
#include <stdio.h>
#include "kata.h"


/* ********** Definisi TYPE MATRIKS dengan indeks int ********** */

/* Ukuran minimum dan maksimum baris dan kolom */

typedef int indeks; /* indeks baris, kolom */
typedef char el_type; 
typedef struct 
{el_type Mem[5][5];}MATRIKS; 

/* NBrsEff ≥ 1 dan NKolEff ≥ 1 */
/* Memori MATRIKS yang dipakai selalu di "ujung kiri atas" */

/*implementasi pada game*/
MATRIKS t,k;
char filee[6];

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Untuk sebuah MATRIKS M yang terdefinisi: *** */

el_type GetElmt (MATRIKS M,indeks i,indeks j);
/* Mengirimkan elemen M dg nomor baris i dan nomor kolom j */

el_type GetElmtDiagonal (MATRIKS M,indeks i);
/* Mengirimkan elemen M(i,i) */
/* *** Operasi mengubah nilai elemen MATRIKS: Set / Assign *** */

void SetEl (MATRIKS *M,int  i,int j,el_type X);
/* I.S. M sudah terdefinisi */
/* F.S. M(i,j) bernilai X */
/* Proses: Mengisi M(i,j) dengan X */

/* ********** KELOMPOK BACA/TULIS ********** */

void BacaMATRIKS (MATRIKS *M);
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK */
/* Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* dari pembacaan dengan traversal per baris */

void TulisMATRIKS (MATRIKS K,MATRIKS M);
/* I.S. M terdefinisi */
/* F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layar*/
/* Menulis nilai setiap indeks dan elemen M ke layar dengan traversal per baris */

/*tambahan buat wordament*/

void pengen(MATRIKS *M, MATRIKS m);
/*nyalin m ke *M*/

void CcwMATRIKS (MATRIKS *M);
/*muter matriks berlawanan arah jarum jam*/

void CwMATRIKS (MATRIKS *M,MATRIKS *T);
/*muter matriks searah jarum jam*/

void sedot(MATRIKS *K);
/*set semua elmt *K jadi spasi*/

void kursor(MATRIKS *K,indeks i,indeks j,char k);
/*setting posisi kursor di i,j*/

void mains();
/*prosedur utama, mengatur main menu dan preparation menu*/

#endif
