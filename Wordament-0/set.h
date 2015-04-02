#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef set_H
#define set_H

#define Info_Set(P) (P)->info
#define ElmtLain(P) (P)->ElmtLain
#define Elmt(S) ((S).Elmt)
#define Nil NULL

typedef char infotype_set[17];
typedef struct tElmtSet *address_set;
typedef struct 	tElmtSet{ 
					infotype_set info;
					address_set ElmtLain;
				}ElmtSet;

typedef struct	{ 
					address_set Elmt;
				}SET;
				
void CreateEmptySet(SET *S);

address_set AlokasiSet (infotype_set X);

void DealokasiSet (address_set *P);

boolean IsEmptySet(SET S);

boolean IsFullSet(SET S);

int NBElmt(SET S);

void InsertSet(infotype_set ElmtS, SET *S);

void DeleteSet(infotype_set ElmtS, SET *S);

boolean IsMember(infotype_set ElmtS, SET S);

boolean IsEqual(SET S1, SET S2);

void Union (SET S1, SET S2, SET *S3);

void Intersection (SET S1, SET S2, SET *S3);

void Set_Difference (SET S1, SET S2, SET *S3);

void copy (SET S1, SET *S2);

boolean IsSubSet(SET S1, SET S2);

void PrintInfo (SET S);

boolean IsSama(infotype_set X,infotype_set Y);

#endif
