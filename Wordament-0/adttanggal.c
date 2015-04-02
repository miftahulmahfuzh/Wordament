#include "adttanggal.h"
//{ *** DEFINISI DAN SPESIFIKASI TYPE TANGGAL *** }

//{ *** DEFINISI DAN SPESIFIKASI SELEKTOR *** }
//{ *** SELEKTOR GET *** }
int GetDay (TANGGAL T)
//{ Memberikan hari DD dari T yang terdiri dari <DD, MM, YY> }
{
	return T.DD;
}


int GetMonth (TANGGAL T)
//{ Memberikan bulan MM dari T yang terdiri dari <DD, MM, YY> }
{
	return T.MM;
}
int GetYear (TANGGAL T)
//{ Memberikan tahun YY dari T yang terdiri dari <DD, MM, YY> }
{
	return T.YY;
}
//{ *** SELEKTOR SET *** }
void SetDay (TANGGAL *T, int newDay)
//{ Mengubah nilai komponen DD dari T }
{
	(*T).DD = newDay;
}
void SetMonth (TANGGAL *T, int newMonth)
//{ Mengubah nilai komponen MM dari T }
{
	(*T).MM = newMonth;
}
void SetYear (TANGGAL *T, int newYear)
//{ Mengubah nilai komponen YY dari T }
{
	(*T).YY = newYear;
}
//{ *** DEFINISI DAN SPESIFIKASI KONSTRUKTOR *** }
TANGGAL MakeTANGGAL (int h, int b, int t)
//{ Membentuk TANGGAL dari tanggal h, bulan b, dan tahun t. }
//{ Prekondisi : h, b, t dapat membentuk TANGGAL yang valid. }
{
	TANGGAL T;
	T.DD = h;
	T.MM = b;
	T.YY = t;
	return T;
}
boolean IsAwalTanggal(TANGGAL T1, TANGGAL T2 )
{
	if(GetYear(T1) == GetYear(T2))
		if(GetMonth(T1)==GetMonth(T2))
			return GetDay(T1)<GetDay(T2);
		else
			return GetMonth(T1)<GetMonth(T2);
	else
		return GetYear(T1) < GetYear(T2);
}
boolean IsSamaTanggal(TANGGAL T1, TANGGAL T2)
{
	return GetDay(T1) == GetDay(T2) && GetYear(T1) == GetYear(T2) && GetMonth(T1) == GetMonth(T2);
}
//{ *** DEFINISI DAN SPESIFIKASI OPERATOR BACA/TULIS *** }

void TulisTANGGAL (TANGGAL T)
//{ I.S. T terdefinisi }
//{ F.S. Nilai T ditulis ke layar dengan format DD/MM/YY }
//{ Proses : Menulis nilai setiap komponen T ke layar }
{
	printf("%d:%d:%d\n",T.DD,T.MM,T.YY);
}
