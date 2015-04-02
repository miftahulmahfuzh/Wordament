#ifndef adtjam_h
#define adtjam_h

//{ *** DEFINISI DAN SPESIFIKASI TYPE TANGGAL *** }
#include <stdio.h>
#include "boolean.h"
typedef struct {
				int detik; //[1..31], { hari }
				int menit; //[1..12], { bulan }
				int jj; }//integer > 0 { tahun } 
				JAM;
//{ *** DEFINISI DAN SPESIFIKASI SELEKTOR *** }
//{ *** SELEKTOR GET *** }
int GetDetik (JAM J);
//{ Memberikan hari DD dari T yang terdiri dari <DD, MM, YY> }
int GetMenit (JAM J);
//{ Memberikan bulan MM dari T yang terdiri dari <DD, MM, YY> }
int GetJam (JAM J);
//{ Memberikan tahun YY dari T yang terdiri dari <DD, MM, YY> }
//{ *** SELEKTOR SET *** }
void SetDetik (JAM *J, int newDetik);
//{ Mengubah nilai komponen DD dari T }
void SetMenit (JAM *J, int newMenit);
//{ Mengubah nilai komponen MM dari T }
void SetJam (JAM *J, int newJam);
//{ Mengubah nilai komponen YY dari T }
//{ *** DEFINISI DAN SPESIFIKASI KONSTRUKTOR *** }
JAM MakeJAM (int j, int m, int d);
//{ Membentuk TANGGAL dari tanggal h, bulan b, dan tahun t. }
//{ Prekondisi : h, b, t dapat membentuk TANGGAL yang valid. }
//{ *** DEFINISI DAN SPESIFIKASI OPERATOR BACA/TULIS *** }
boolean IsAwalJAM(JAM J1, JAM J2);
boolean IsSamaJAM(JAM J1, JAM J2);
void TulisJAM (JAM J);
//{ I.S. T terdefinisi }
//{ F.S. Nilai T ditulis ke layar dengan format DD/MM/YY }
//{ Proses : Menulis nilai setiap komponen T ke layar }
#endif
