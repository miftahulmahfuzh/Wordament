#include "adtpoint.h"

POINT MakePOINT (int x, int y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
	/* KAMUS */
	POINT P;
	/* ALGORITMA */
	P.X = x;
	P.Y = y;
	return P;
}

int GetAbsis (POINT P)
/* Mengirimkan komponen absis dari P */
{
	/* KAMUS */
	int x;
	/* ALGORITMA */
	x = P.X;
	return x; 
}
int GetOrdinat (POINT P)
/* Mengirimkan komponen ordinat dari P POINT */
{
	/* KAMUS */
	int y;
	/* ALGORITMA */
	y = P.Y;
	return y; 
}

POINT GetPoint(POINT P)
{
	P.X = GetAbsis(P);
	P.Y = GetOrdinat(P);

	return P;
}

boolean movePoint(POINT *P, int dx, int dy, int nmin, int nmax)
{
	int xx = (P->X) + dx, yy = (P->Y) + dy;
	if(xx>=nmin && xx<=nmax && yy>=nmin && yy<=nmax)
	{
		*P = MakePOINT(xx, yy);
		return true;
	}
	return false;
}
