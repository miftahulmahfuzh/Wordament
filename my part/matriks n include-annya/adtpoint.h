#ifndef adtpoint_h
#define adtpoint_h

#include "boolean.h"
/* *** Definisi ABSTRACT DATA TYPE POINT *** */
typedef struct { int X;	/* absis */
				 int Y;	/* ordinat */ } POINT;

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int x, int y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** Operasi terhadap komponen : selektor Get dan Set *** */
/* *** Selektor POINT *** */
int GetAbsis (POINT P);
/* Mengirimkan komponen absis dari P */
int GetOrdinat (POINT P);
/* Mengirimkan komponen ordinat dari P POINT */
POINT GetPoint(POINT P);

boolean movePoint(POINT *P, int dx, int dy, int nmin, int nmax);

#endif
