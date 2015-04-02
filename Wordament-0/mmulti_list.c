#include "multi_list.h"

int main()
{	/* KAMUS */
	ListUser LU;
	int nu, ns, ss;
	char un[50], pw[50];
	WAKTU da;
	adrUser U;
	adrScore S;
	/* ALGORITMA */
	CreateEmptyUser(&LU);
	BacaUser(&LU);
	BacaScore(FirstUser(LU), 1);
	printf("Masukan banyaknya user yang akan ditambahkan : \n");
	scanf("%d", &nu);
	while(nu-->0)
	{
		printf("masukan username : ");
		scanf("%s", un);
		printf("masukan password : ");
		scanf("%s", pw);
		AddUser(&LU, un, pw);
		printf("masukan banyaknya score yang dicapai : ");
		scanf("%d", &ns);
		while(ns-->0)
		{
			printf("masukan score : ");
			scanf("%d", &ss);
			printf("masukan waktu (dd mm yy jj mm dd): ");
			scanf("%d%d%d%d%d%d", &da.TT.DD, &da.TT.MM, &da.TT.YY, &da.JJ.jj, &da.JJ.menit, &da.JJ.detik);
			AddScore(FirstUser(LU), ss, da);
		}
	}
	U = FirstUser(LU);
	while(U != Nil)
	{
		printf("%s\n", username(U));
		S = FirstScore(U);
		while(S != Nil)
		{
			printf("%d ", value(S));
			TulisWaktu(time_score(S));
			printf("\n");
			S = NextScore(S);
		}
		printf("\n");
		U = NextUser(U);
	}
	printf("masukan username yang anda cari : ");
	scanf("%s", un);
	U = SearchUser(LU, un);
	if(U != Nil)
	{
		printf("score dari %s :\n", un);
		S = FirstScore(U);
		while(S != Nil)
		{
			printf("%d ", value(S));
			TulisWaktu(time_score(S));
			printf("\n");
			S = NextScore(S);
		}
	}
	else
		printf("Tidak ada username bernama %s\n", un);
	TulisScore(FirstUser(LU), 1);
	TulisUser(&LU);
	return 0;
}
