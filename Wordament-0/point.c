/* File : point.c */
#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** REALISASI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float x, float y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
	/* KAMUS */
	POINT P;
	/* ALGORITMA */
	P.X = x;
	P.Y = y;
	return P;
}
/* *** Operasi terhadap komponen : selektor Get dan Set *** */
/* *** Selektor POINT *** */
float GetAbsis (POINT P)
/* Mengirimkan komponen absis dari P */
{
	/* KAMUS */
	float x;
	/* ALGORITMA */
	x = P.X;
	return x; 
}
float GetOrdinat (POINT P)
/* Mengirimkan komponen ordinat dari P POINT */
{
	/* KAMUS */
	float y;
	/* ALGORITMA */
	y = P.Y;
	return y; 
}
/* *** Set nilai komponen *** */
void SetAbsis ( POINT *P, float newX)
/* Mengubah nilai komponen absis dari P */
{
	/* KAMUS */
	/* ALGORITMA */
	P->X = newX;
}
void SetOrdinat (POINT *P, float newY)
/* Mengubah nilai komponen ordinat dari P */
{
	/* KAMUS */
	/* ALGORITMA */
	P->Y = newY;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS *** */
void BacaPOINT (POINT *P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk POINT P berdasarkan
dari nilai absis dan ordinat tersebut */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
	/* KAMUS */
	float x,y;
	/* ALGORITMA */
	scanf("%f%f",&x,&y);
	SetAbsis(P,x);
	SetOrdinat(P,y);
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layer dengan format "(X,Y)" */
{
	/* KAMUS */
	/* ALGORITMA */
	printf("(%.2f,%.2f)", GetAbsis(P),GetOrdinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
	/* KAMUS */
	/* ALGORITMA */
	return (GetAbsis(P1)==GetAbsis(P2)) && (GetOrdinat(P1)==GetOrdinat(P2));
}
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
	/* KAMUS */
	/* ALGORITMA */
	return !EQ(P1,P2);
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
	/* KAMUS */
	POINT Origin = MakePOINT(0.0,0.0);
	/* ALGORITMA */
	return EQ(P,Origin);
}
boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
	/* KAMUS */
	/* ALGORITMA */
	return (GetOrdinat(P)==0);
}
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
	/* KAMUS */
	/* ALGORITMA */
	return (GetAbsis(P)==0);
}
int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan Titik Origin, */
/* dan P tidak terletak di salah satu sumbu */
{
	/* KAMUS */
	/* ALGORITMA */
	if (IsOnSbX(P) || IsOnSbY(P))
		return 0;
	if(GetAbsis(P)>0)
	{
		if(GetOrdinat(P)>0)
			return 1;
		else
			return 4;
	}
	else
	{
		if(GetOrdinat(P)>0)
			return 2;
		else
			return 3;
	}
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
	/* KAMUS */
	/* ALGORITMA */
	return PlusDelta(P,1,0);
}
POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
	/* KAMUS */
	/* ALGORITMA */
	return PlusDelta(P,0,1);
}
POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah
Ordinat(P) + deltaY */
{
	/* KAMUS */
	/* ALGORITMA */
	return MakePOINT(GetAbsis(P)+deltaX,GetOrdinat(P)+deltaY);
}
POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
	/* KAMUS */
	/* ALGORITMA */
	if(SbX)
		return MakePOINT(GetAbsis(P),-GetOrdinat(P));
	else
		return MakePOINT(-GetAbsis(P),GetOrdinat(P));
}
float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
	/* KAMUS */
	/* ALGORITMA */
	return Panjang(P,MakePOINT(0,0));
}
float Panjang (POINT P1, POINT P2)
/* Menghitung jarak antara dua buah titik P1 dan P2 */
{
	/* KAMUS */
	/* ALGORITMA */
	return sqrt((GetAbsis(P1)-GetAbsis(P2))*(GetAbsis(P1)-GetAbsis(P2))+(GetOrdinat(P1)-GetOrdinat(P2))*(GetOrdinat(P1)-GetOrdinat(P2)));
}
void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
	/* KAMUS */
	/* ALGORITMA */
	*P = PlusDelta(*P,deltaX,deltaY);
}
void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
	/* KAMUS */
	/* ALGORITMA */
	Geser(P,0,-GetOrdinat(*P));
}
void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
	/* KAMUS */
	/* ALGORITMA */
	Geser(P,-GetAbsis(*P),0);
}
void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
	/* KAMUS */
	/* ALGORITMA */
	*P = MirrorOf(*P,SbX);
}

void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */ 
 {
	/* KAMUS */
	float radian = Sudut*acos(-1)/180.0;
	float x = GetAbsis(*P);
	float y = GetOrdinat(*P);
	/* ALGORITMA */
	SetAbsis(P,x*cos(radian)-y*sin(radian));
	SetOrdinat(P, x*sin(radian)-y*cos(radian));
}

boolean DalamRange (POINT P, POINT P1, float r)
/* Mengembalikan true apabila P1 berada dalam jarak r dari P */
/* (jarak dari P1 ke P ≤ r) */
{
	/* KAMUS */
	/* ALGORITMA */
	return (Panjang(P,P1)<=r);
}

void GlideReflection (POINT * P, boolean sbX,float delta)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan terhadap sumbu x jika sbX bernilai true atau sumbu y jika
sbX bernilai false, kemudian digeser sebesar delta searah sumbu yang digunakan
sebagai sumbu pencerminan */
/* Contoh: jika P=<3,4>, maka GlideReflection(P,true,-2) menghasilkan P=<1,-4>.
Cerminkan terhadap sumbu-X menjadi <3,-4> kemudian digeser -2 satuan
arah sumbu-X menjadi <1,-4> */
{
	Mirror(P,sbX);
	if(sbX)
		Geser(P,delta,0);
	else
		Geser(P,0,delta);
}
