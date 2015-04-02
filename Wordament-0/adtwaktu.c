#include "adtwaktu.h"

WAKTU MakeWAKTU(TANGGAL T, JAM J)
{
	WAKTU W;
	SetJJ(&W, J);
	SetTT(&W, T);
	return W;
}

JAM GetJJ(WAKTU W)
{
	return W.JJ;
}
TANGGAL GetTT(WAKTU W)
{
	return W.TT;
}
void SetJJ(WAKTU * W, JAM J)
{
	(*W).JJ = J;
}
void SetTT(WAKTU * W, TANGGAL T)
{
	(*W).TT = T;
}
boolean IsAwalWaktu(WAKTU W1, WAKTU W2)
{
	if(IsSamaTanggal(GetTT(W1), GetTT(W2)))
		return IsAwalJAM(GetJJ(W1), GetJJ(W2));
	return IsAwalTanggal(GetTT(W1), GetTT(W2));
}
boolean IsSamaWaktu(WAKTU W1, WAKTU W2)
{
	return IsSamaJAM(GetJJ(W1), GetJJ(W2)) && IsSamaTanggal(GetTT(W1), GetTT(W2));
}
void TulisWaktu(WAKTU W)
{
	printf("%02d-%02d-%04d  %02d:%02d:%02d",W.TT.DD,W.TT.MM,W.TT.YY,W.JJ.jj,W.JJ.menit,W.JJ.detik);
}
void CurrentTime(WAKTU *W)
{
	time_t timer;
	struct tm *gg;
	time(&timer);
	gg = localtime(&timer);

	(*W).TT.YY = (*gg).tm_year + 1900;
	(*W).TT.MM = (*gg).tm_mon;
	(*W).TT.DD = (*gg).tm_mday;
	(*W).JJ.jj = (*gg).tm_hour;
	(*W).JJ.menit = (*gg).tm_min;
	(*W).JJ.detik = (*gg).tm_sec;

}
