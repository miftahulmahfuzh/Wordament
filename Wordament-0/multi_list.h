/* File : multi_list.h */
#ifndef MULTI_LIST_H
#define MULTI_LIST_H

#include <stdlib.h>
#include "boolean.h"
#include "adtwaktu.h"
#include "mesinkata1.h"
#include <string.h>

#define Nil NULL

typedef struct tUser *adrUser;
typedef struct tScore *adrScore;

typedef struct tUser {
	char username[50];
	char password[50];
	adrScore FirstScore;
	adrUser NextUser;
} El_User;

typedef struct tScore {
	int value;
	WAKTU time_score;
	adrScore NextScore;
} El_Score;

typedef struct { adrUser FirstUser; } ListUser;

/* Selektor User */
#define username(U) (U)->username
#define password(U) (U)->password
#define NextUser(U) (U)->NextUser
#define FirstScore(U) (U)->FirstScore

/* Selektor Score */
#define value(S) (S)->value
#define NextScore(S) (S)->NextScore
#define time_score(S) (S)->time_score

/* Selektor List of User */
#define FirstUser(L) (L).FirstUser
void CreateEmptyUser(ListUser *L);
/* I.S. Sembarang */
/* F.S. List User U menjadi kosong yaitu U == Nil */
void CreateEmptyScore(adrScore *S);
/* I.S. Sembarang */
/* F.S. List Score S menjadi kosong */
boolean IsEmptyUser(ListUser L);
/* mengirim true jika List of User kosong */
boolean IsEmptyScore(adrUser U);
/* mengirim true jika El_User U belum memiliki Score atau FirstScore = Nil */
adrUser AlokasiUser(char name[50], char pass[50]);
/* mengirim address User hasil alokasi sebuah elemen list user, jika alokasi gagal maka mengirimkan Nil */
adrScore AlokasiScore(int poin, WAKTU ttime);
/* mengirim address Score hasil alokasi sebuah elemen list Score, jika alokasi gagal maka mengirimkan Nil */

void DealokasiUser(adrUser U);
/* I.S. aU bukan Nil */
/* F.S. aU dikembalikan ke sistem */
/* melakukan dealokasi /pengembalian address user aU */
void DealokasiScore(adrScore S);
/* I.S. aS bukan Nil */
/* F.S. aS dikembalikan ke sistem */
/* melakukan dealokasi /pengembalian address score aS */

void AddUser(ListUser *L, char name[50], char pass[50]);
/* I.S. Sembarang */
/* F.S. ditambahkan elemen pertama dengan username = name */
/* Proses : alokasi sebuah elemen dengan username = name, dan menambahkan elemen list user di awal */
/* Jika alokasi gagal maka I.S. = F.S. */
void AddScore(adrUser U, int poin, WAKTU wwaktu);
/* I.S. U != Nil */
/* F.S. ditambahkan elemen pertama dengan nilai score = poin */
/* Proses : alokasi sebuah elemen dengan value = poin, dan menambahkan elemen list score di awal */
/* Jika alokasi gagal maka I.S. = F.S. */

void DelScore(adrUser U, adrScore S);
/* I.S. U dan S terdefinisi */
/* F.S. elemen score di hapus pada address S dari list dan didealokasikan */
/* Asumsi selalu benar bahwa S merupakan address elemen list score dari user dengan address U */
void DelFUser(ListUser *LU);

adrUser SearchUser(ListUser L,char name[50]);
/* mengirimkan address user dengan username = name jika ada di list U, menghasilkan Nil jika tidak ditemukan */

void BacaUser(ListUser *LU);

void TulisUser(ListUser *LU);

void BacaScore(adrUser U, int no_board);

void TulisScore(adrUser U, int no_board);

#endif
