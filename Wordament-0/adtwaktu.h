#ifndef adtwaktu_h
#define adtwaktu_h
#include "adttanggal.h"
#include "adtjam.h"
#include <time.h>

typedef struct 
{
	JAM JJ;
	TANGGAL TT;
} WAKTU;

WAKTU MakeWAKTU(TANGGAL T, JAM J);
JAM GetJJ(WAKTU W);
TANGGAL GetTT(WAKTU W);
void SetJJ(WAKTU * W, JAM J);
void SetTT(WAKTU * W, TANGGAL T);
boolean IsAwalWaktu(WAKTU W1, WAKTU W2);
boolean IsSamaWaktu(WAKTU W1, WAKTU W2);
void TulisWaktu(WAKTU W);
void CurrentTime(WAKTU * W);



#endif
