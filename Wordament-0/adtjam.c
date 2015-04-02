#include "adtjam.h"
//{ *** DEFINISI DAN SPESIFIKASI SELEKTOR *** }
//{ *** SELEKTOR GET *** }
int GetDetik (JAM J)
//{ Memberikan hari DD dari T yang terdiri dari <DD, MM, YY> }
{
	return J.detik;
}
int GetMenit (JAM J)
//{ Memberikan bulan MM dari T yang terdiri dari <DD, MM, YY> }
{
	return J.menit;
}
int GetJam (JAM J)
//{ Memberikan tahun YY dari T yang terdiri dari <DD, MM, YY> }
{
	return J.jj;
}
//{ *** SELEKTOR SET *** }
void SetDetik (JAM *J, int newDetik)
//{ Mengubah nilai komponen DD dari T }
{
	(*J).detik = newDetik;
}
void SetMenit (JAM *J, int newMenit)
//{ Mengubah nilai komponen MM dari T }
{
	(*J).menit = newMenit;
}
void SetJam (JAM *J, int newJam)
//{ Mengubah nilai komponen YY dari T }
{
	(*J).jj = newJam;
}
//{ *** DEFINISI DAN SPESIFIKASI KONSTRUKTOR *** }
JAM MakeJAM (int j, int m, int d)
//{ Membentuk TANGGAL dari tanggal h, bulan b, dan tahun t. }
//{ Prekondisi : h, b, t dapat membentuk TANGGAL yang valid. }
//{ *** DEFINISI DAN SPESIFIKASI OPERATOR BACA/TULIS *** }
{
	JAM J;
	J.detik = d;
	J.menit = m;
	J.jj = j;
	return J;
}
boolean IsAwalJAM(JAM J1, JAM J2)
{
	if(GetJam(J1) == GetJam(J2))
		if(GetMenit(J1)==GetMenit(J2))
			return GetDetik(J1)<GetDetik(J2);
		else
			return GetMenit(J1)<GetMenit(J2);
	else
		return GetJam(J1)<GetJam(J2);
}
boolean IsSamaJAM(JAM J1, JAM J2)
{
	return (GetDetik(J1) == GetDetik(J2)) && (GetMenit(J1) == GetMenit(J2)) && (GetJam(J1) == GetJam(J2));
}
void TulisJAM (JAM J)
//{ I.S. T terdefinisi }
//{ F.S. Nilai T ditulis ke layar dengan format DD/MM/YY }
//{ Proses : Menulis nilai setiap komponen T ke layar }
{
	printf("%d:%d:%d\n",J.detik,J.menit,J.jj);
}
