#ifndef adtarray_h
#define adtarray_h
#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "adtwaktu.h"
#include "mesinkata1.h"

#define IdxMin 1
#define IdxMax 25

typedef struct
{
	char username[50];
	int score_value;
	WAKTU time_get;
} infotype_array;

typedef struct 
{
	infotype_array TI[IdxMax-IdxMin+1];
	int Neff;
} TabInt;

void MakeEmptyArray (TabInt *T);
infotype_array MakeElmtArray(char name[], int howmuch, WAKTU when);
boolean IsFullArray (TabInt T);
int NbElmt (TabInt T);
boolean IsEmptyArray (TabInt T);
void TulisIsi (TabInt T);
int GetFirstIdx (TabInt T);
int GetLastIdx (TabInt T);
infotype_array GetElmt (TabInt T, int i);
boolean IsHigher(infotype_array el1, infotype_array el2);
void Add1Urut (TabInt *T, infotype_array el );
void SetEl (TabInt *T, int i, infotype_array el);
boolean IsIdxValid (TabInt T, int i);
void SetNeff (TabInt *T, int N);
int MaxNbEl (TabInt T);
void DelLastEl (TabInt *T, infotype_array *el);
void BacaAllScore(TabInt *T,  int no_board);
void TulisAllScore(TabInt *T,  int no_board);

#endif
