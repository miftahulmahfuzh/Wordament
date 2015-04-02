#ifndef adttanggal_h
#define adttanggal_h

#include <stdio.h>
#include "boolean.h"
//{ *** DEFINISI DAN SPESIFIKASI TYPE TANGGAL *** }
typedef struct {
				int DD; //[1..31], { hari }
				int MM; //[1..12], { bulan }
				int YY; }//integer > 0 { tahun } 
				TANGGAL;
//{ *** DEFINISI DAN SPESIFIKASI SELEKTOR *** }
//{ *** SELEKTOR GET *** }
int GetDay (TANGGAL T);
//{ Memberikan hari DD dari T yang terdiri dari <DD, MM, YY> }
int GetMonth (TANGGAL T);
//{ Memberikan bulan MM dari T yang terdiri dari <DD, MM, YY> }
int GetYear (TANGGAL T);
//{ Memberikan tahun YY dari T yang terdiri dari <DD, MM, YY> }
//{ *** SELEKTOR SET *** }
void SetDay (TANGGAL *T, int newDay);
//{ Mengubah nilai komponen DD dari T }
void SetMonth (TANGGAL *T, int newMonth);
//{ Mengubah nilai komponen MM dari T }
void SetYear (TANGGAL *T, int newYear);
//{ Mengubah nilai komponen YY dari T }
//{ *** DEFINISI DAN SPESIFIKASI KONSTRUKTOR *** }
TANGGAL MakeTANGGAL (int h, int b, int t);
//{ Membentuk TANGGAL dari tanggal h, bulan b, dan tahun t. }
//{ Prekondisi : h, b, t dapat membentuk TANGGAL yang valid. }
//{ *** DEFINISI DAN SPESIFIKASI OPERATOR BACA/TULIS *** }
boolean IsAwalTanggal(TANGGAL T1, TANGGAL T2);
boolean IsSamaTanggal(TANGGAL T1, TANGGAL T2);
void TulisTANGGAL (TANGGAL T);
//{ I.S. T terdefinisi }
//{ F.S. Nilai T ditulis ke layar dengan format DD/MM/YY }
//{ Proses : Menulis nilai setiap komponen T ke layar }
#endif
