#include "set.h"

int main (){
	/* KAMUS */
	SET S1,S2,S3;
	address P;
	infotype ElmtS;
	/* Algoritma */
	CreateEmpty(&S1);	
	CreateEmpty(&S2);
	printf("masukkan elemen set 1 : ");
	scanf("%s",&ElmtS);
	while(ElmtS[0]!='.'){
		Insert(ElmtS,&S1);
		printf("masukkan elemen set 1 : ");
		scanf("%s",&ElmtS);
	}
	printf("masukkan elemen set 2 : ");
	scanf("%s",&ElmtS);
	while(ElmtS[0]!='.'){
		Insert(ElmtS,&S2);
		printf("masukkan elemen set 2 : ");
		scanf("%s",&ElmtS);
	}
	printf("set 1 : \n");
	PrintInfo(S1);
	printf("set 2 : \n");
	PrintInfo(S2);
	printf("masukkan elemen yang ingin dihapus : ");
	scanf("%s",&ElmtS);
	Delete(ElmtS,&S1);
	printf("masukkan elemen yang ingin di tes ada dalam set : ");
	scanf("%s",&ElmtS);
	if(IsMember(ElmtS,S1))
		printf("ada dalam set\n");
	else
		printf("tidak ada dalam set\n");
	printf("mengcopy set 1 ke set 3\n");
	copy(S1,&S3);
	PrintInfo(S3);
	if (IsSubSet(S1,S2))
		printf("S1 subset dari S2\n");
	else
		printf("S1 bukan subset dari S2\n");
	/*printf("union dari set1 dan set 2");
	Union(S1,S2,&S3);
	PrintInfo(S3);*/
	//printf("Intersection set 1 dan set 2\n");
	/*Set_Difference(S1,S2,&S3);
	PrintInfo(S3);*/
	if (IsEqual(S1,S2))
		printf("Set 1 sama dengan Set S2\n");
	else
		printf("Set 1 tidak sama dengan Set S2\n");
}