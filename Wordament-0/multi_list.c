/* File : multi_list.h */
#include "multi_list.h"

void CreateEmptyUser(ListUser *L)
/* I.S. Sembarang */
/* F.S. List User L menjadi kosong yaitu FirstUser(L) == Nil */
{	/* Kamus Lokal */
	/* Algoritma */
	FirstUser(*L) = Nil;
}
void CreateEmptyScore(adrScore *S)
/* I.S. Sembarang */
/* F.S. List Score S menjadi kosong */
{	/* Kamus Lokal */
	/* Algoritma */
	(*S) = Nil;
}
boolean IsEmptyUser(ListUser L)
/* mengirim true jika List of User kosong */
{	/* kamus Lokal */
	/* Algoritma */
	return FirstUser(L) == Nil;
}
boolean IsEmptyScore(adrUser U)
/* mengirim true jika El_User U belum memiliki Score atau FirstScore = Nil */
{	/* Kamus Lokal */
	/* Algoritma */
	return FirstScore(U) == Nil;
}
adrUser AlokasiUser(char name[50], char pass[50])
/* mengirim address User hasil alokasi sebuah elemen list user, jika alokasi gagal maka mengirimkan Nil */
{	/* Kamus Lokal */
	adrUser U;
	int i;
	/* Algoritma */
	U = (adrUser) malloc(sizeof(El_User));
	if(U != Nil)
	{
		strcpy(username(U), name);
		strcpy(password(U), pass);
//		for(i=0; i<=9; i++)
			FirstScore(U) = Nil;
		NextUser(U) = Nil;
	}
	return U;
}
adrScore AlokasiScore(int poin, WAKTU ttime)
/* mengirim address Score hasil alokasi sebuah elemen list Score, jika alokasi gagal maka mengirimkan Nil */
{	/* Kamus Lokal */
	adrScore S;
	/* Algoritma */
	S = (adrScore) malloc(sizeof(El_Score));
	if(S != Nil)
	{
		value(S) = poin;
		time_score(S) = ttime;
		NextScore(S) = Nil;
	}
}
void DealokasiUser(adrUser U)
/* I.S. U bukan Nil */
/* F.S. U dikembalikan ke sistem */
/* melakukan dealokasi /pengembalian address user U */
{	/* Kamus Lokal */
	/* Algoritma */
	free(U);
}
void DealokasiScore(adrScore S)
/* I.S. S bukan Nil */
/* F.S. S dikembalikan ke sistem */
/* melakukan dealokasi /pengembalian address score S */
{	/* Kamus Lokal */
	/* Algoritma */
	free(S);
}
void AddUser(ListUser *L, char name[50], char pass[50])
/* I.S. Sembarang */
/* F.S. ditambahkan elemen pertama dengan username = name */
/* Proses : alokasi sebuah elemen dengan username = name, dan menambahkan elemen list user di awal */
/* Jika alokasi gagal maka I.S. = F.S. */
{	/* Kamus Lokal */
	adrUser Q;
	/* Algoritma */
	Q = AlokasiUser(name, pass);
	if(IsEmptyUser(*L))
		FirstUser(*L) = Q;
	else
	{
		NextUser(Q) = FirstUser(*L);
		FirstUser(*L) = Q;
	}
}
void AddScore(adrUser U, int poin, WAKTU wwaktu)
/* I.S. U != Nil */
/* F.S. ditambahkan elemen pertama dengan nilai score = poin */
/* Proses : alokasi sebuah elemen dengan value = poin, dan menambahkan elemen list score di awal */
/* Jika alokasi gagal maka I.S. = F.S. */
{	/* Kamus Lokal */
	adrScore S, P, Prec;
	/* Algoritma */
	S = AlokasiScore(poin, wwaktu);
	if(S != Nil)
	{
		P = FirstScore(U);
		Prec = Nil;
		while(P != Nil)
		{
			if(value(P) > poin)
			{
				Prec = P;
				P = NextScore(P);
			}
			else
				break;
		}
		if(Prec != Nil)
		{
			NextScore(S) = NextScore(Prec);
			NextScore(Prec) = S;
		}
		else
		{
			NextScore(S) = FirstScore(U);
			FirstScore(U) = S;
		}
	}
}
void DelScore(adrUser U, adrScore S)
/* I.S. U dan S terdefinisi */
/* F.S. elemen score di hapus pada address S dari list dan didealokasikan */
/* Asumsi selalu benar bahwa S merupakan address elemen list score dari user dengan address U */
{	/* Kamus Lokal */
	adrScore P;
	/* Algoritma */ 
	if(FirstScore(U) != Nil)
	{
		if(FirstScore(U) == S)
		{
			FirstScore(U) = NextScore(S);
		}
		else
		{
			P = FirstScore(U);
			while(NextScore(P) != Nil)
			{
				if(NextScore(P) == S)
					break;
				P = NextScore(P);
			}
			if(NextScore(P) == S)
				NextScore(P) = NextScore(S);
		}
		DealokasiScore(S);
	}
}

void DelFUser(ListUser *LU)
{	/* Kamus Lokal */
	adrUser DUser;
	adrScore DScore;
	/* ALgoritma */	
	if(!IsEmptyUser(*LU))
	{
		DUser = FirstUser(*LU);
		while(!IsEmptyScore(DUser))
		{
			DScore = FirstScore(DUser);
			DelScore(DUser, DScore);
		}
		FirstUser(*LU) = NextUser(DUser);
		DealokasiUser(DUser);
	}
}
adrUser SearchUser(ListUser L,char name[50])
/* mengirimkan address user dengan username = name jika ada di list U, menghasilkan Nil jika tidak ditemukan */
{	/* Kamus Lokal */
	adrUser U;
	/* Algoritma */
	U = FirstUser(L);
	while(U != Nil)
	{
		if(strcmp(name, username(U)) == 0)
			return U;
		U = NextUser(U);
	}
	return Nil;
}
void BacaUser(ListUser *LU)
{	/* Kamus Lokal */
	char name[50], pass[50];
	int i;
	/* Algoritma */
	CreateEmptyUser(LU);
	STARTKATA("AllUser.txt");
	while(!EOP)
	{
		KataToString(name);
		ADVKATA();
		KataToString(pass);
		ADVKATA();
		AddUser(LU, name, pass);
	}
}
void TulisUser(ListUser *LU)
{	/* Kamus Lokal */
	adrUser P;
	/* Algoritma */
	STARTWrite("AllUser.txt");
	while(!IsEmptyUser(*LU))
	{
		P = FirstUser(*LU);
		WritePita(username(P));
		WritePita(" ");
		WritePita(password(P));
		WritePita("\n");
		DelFUser(LU);
	}
	WritePita(".\n");
}
void BacaScore(adrUser U, int no_board)
{	/* Kamus Lokal */
	char filee[50] = "Score/_/";
	int sco, dd, mm, yy, hh, mi, sec;
	/* ALgoritma */
	filee[6] = no_board+'0';
	strcat(filee, username(U));
	strcat(filee, ".txt");
//	printf("%s\n", filee);
	STARTKATA(filee);
	while(!EOP)
	{
		KataToInt(&sco);
		ADVKATA();
		KataToInt(&dd);
		ADVKATA();
		KataToInt(&mm);
		ADVKATA();
		KataToInt(&yy);
		ADVKATA();
		KataToInt(&hh);
		ADVKATA();
		KataToInt(&mi);
		ADVKATA();
		KataToInt(&sec);
		ADVKATA();
//		printf("%d %d %d %d %d %d %d\n", sco, dd,mm,yy,hh,mi,sec);
		AddScore(U, sco, MakeWAKTU(MakeTANGGAL(dd, mm, yy), MakeJAM(hh, mi, sec)));
	}
}
void TulisScore(adrUser U, int no_board)
{	/* Kamus Lokal */
	char filee[50] = "Score/_/";
	adrScore S;
	TANGGAL T;
	JAM J;
	/* Algoritma */
	filee[6] = no_board+'0';
	strcat(filee, username(U));
	strcat(filee, ".txt");
	STARTWrite(filee);
	while(!IsEmptyScore(U))
	{
		S = FirstScore(U);
		T = GetTT(time_score(S));
		J = GetJJ(time_score(S));
		WritePitaInt(value(S));
		WritePita(" ");
		WritePitaInt(GetDay(T));
		WritePita(" ");
		WritePitaInt(GetMonth(T));
		WritePita(" ");
		WritePitaInt(GetYear(T));
		WritePita("   ");
		WritePitaInt(GetJam(J));
		WritePita(" ");
		WritePitaInt(GetMenit(J));
		WritePita(" ");
		WritePitaInt(GetDetik(J));
		WritePita("\n");
		DelScore(U, S);
	}
	WritePita(".\n");
}

