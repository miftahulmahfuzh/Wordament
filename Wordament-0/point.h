/* File : point.h */

#ifndef POINT_h
#define POINT_h

#include "boolean.h"
/* *** Definisi ABSTRACT DATA TYPE POINT *** */
typedef struct { float X;	/* absis */
				 float Y;	/* ordinat */ } POINT;

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float x, float y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** Operasi terhadap komponen : selektor Get dan Set *** */
/* *** Selektor POINT *** */
float GetAbsis (POINT P);
/* Mengirimkan komponen absis dari P */
float GetOrdinat (POINT P);
/* Mengirimkan komponen ordinat dari P POINT */
/* *** Set nilai komponen *** */
void SetAbsis ( POINT *P, float newX);
/* Mengubah nilai komponen absis dari P */
void SetOrdinat (POINT *P, float newY);
/* Mengubah nilai komponen ordinat dari P */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS *** */
void BacaPOINT (POINT *P);
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk POINT P berdasarkan
dari nilai absis dan ordinat tersebut */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)" */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layer dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P);
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P);
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P);
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P);
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan Titik Origin, */
/* dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P);
/* Mengirim salinan P dengan absis ditambah satu */
POINT NextY (POINT P);
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PlusDelta (POINT P, float deltaX, float deltaY);
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah
Ordinat(P) + deltaY */
POINT MirrorOf (POINT P, boolean SbX);
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
float Jarak0 (POINT P);
/* Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2);
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis.
Tuliskan spec fungsi yang lebih tepat. */
void Geser (POINT *P, float deltaX, float deltaY);
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void GeserKeSbX (POINT *P);
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
void GeserKeSbY (POINT *P);
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
void Mirror (POINT *P, boolean SbX);
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
void Putar (POINT *P, float Sudut);
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */ 


boolean DalamRange (POINT P, POINT P1, float r);
/* Mengembalikan true apabila P1 berada dalam jarak r dari P */
/* (jarak dari P1 ke P ≤ r) */

void GlideReflection (POINT * P, boolean sbX,float delta);
/* I.S. P terdefinisi */
/* F.S. P dicerminkan terhadap sumbu x jika sbX bernilai true atau sumbu y jika
sbX bernilai false, kemudian digeser sebesar delta searah sumbu yang digunakan
sebagai sumbu pencerminan */
/* Contoh: jika P=<3,4>, maka GlideReflection(P,true,-2) menghasilkan P=<1,-4>.
Cerminkan terhadap sumbu-X menjadi <3,-4> kemudian digeser -2 satuan
arah sumbu-X menjadi <1,-4> */
#endif
