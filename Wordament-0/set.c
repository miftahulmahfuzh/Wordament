#include "set.h"

void CreateEmptySet(SET *S)
{	/* Kamus Lokal */
	/* Algoritma */
	Elmt(*S)=Nil;
}

address_set AlokasiSet (infotype_set X)
{	/* Kamus Lokal */
	address_set P;
	int i;
	/* Agoritma */
	P=(address_set)malloc(sizeof(ElmtSet));
	if (P!=Nil){
		for (i=0; i<=16; i++)
			Info_Set(P)[i] = X[i];
		ElmtLain(P)=Nil;
	}
	return(P);
}

void DealokasiSet (address_set *P)
{	/* Kamus Lokal */
	/* Algoritma */
	free(*P);
}

boolean IsEmptySet(SET S)
{	/* Kamus Lokal */
	/* ALgoritma */
	return (Elmt(S)==Nil);
}

int NBElmt(SET S)
{	/* Kamus Lokal */
	address_set P;
	int count=0;
	/* Algoritma */
	P=Elmt(S);
	while(P!=Nil){
		P=ElmtLain(P);
		count++;
	}
	return(count);
}

void InsertSet(infotype_set ElmtS, SET *S)
{	/* Kamus Lokal */
	address_set P;
	/* Algoritma */
	if(!IsMember(ElmtS,*S))
	{
		P=AlokasiSet(ElmtS);
		if(P!=Nil){
			ElmtLain(P)=Elmt(*S);
			Elmt(*S)=P;
		}
	}
}

void DeleteSet(infotype_set ElmtS, SET *S)
{	/* Kamus Lokal */
	address_set Prec;
	address_set P;
	/* Algoritma */
	P=Elmt(*S);
	if (IsSama(Info_Set(P),ElmtS) && ElmtLain(Elmt(*S))==Nil){
		P=Elmt(*S);
		Elmt(*S)=Nil;
		DealokasiSet(&P);
	}
	else if (IsSama(Info_Set(P),ElmtS)){
		P=Elmt(*S);
		Elmt(*S)=ElmtLain(Elmt(*S));
		DealokasiSet(&P);
	}
	else{
		Prec=Elmt(*S);
		while(ElmtLain(Prec)!=Nil && !IsSama(Info_Set(ElmtLain(Prec)),ElmtS)){
			Prec=ElmtLain(Prec);
		}
		if(ElmtLain(Prec)!=Nil){
			P=ElmtLain(Prec);
			ElmtLain(Prec)=ElmtLain(ElmtLain(Prec));
			DealokasiSet(&P);
		}
	}
}

boolean IsMember(infotype_set ElmtS, SET S)
{	/* Kamus Lokal */
	address_set P;
	boolean found=false;
	/* Algoritme */
	P=Elmt(S);
	while(P!=Nil && !found){
		if(IsSama(Info_Set(P),ElmtS))
			found=true;
		else
			P=ElmtLain(P);
	}
	return found;
}

boolean IsSama(infotype_set X,infotype_set Y)
{	/* Kamus Lokal */
	boolean sama=true;
	int i;
	int panjang=0;
	/* Algoritma */
	i=0;
	while(((X[i]<='Z' &&  X[i]>='A') || (Y[i]<='Z' && Y[i]>='A')) || ((X[i]<='z' &&  X[i]>='a') || (Y[i]<='z' && Y[i]>='a'))){
		panjang++;
		i++;
	}
	i=0;
	while(i<=panjang && sama){
		if (X[i]!=Y[i])
			sama=false;
		i++;
	}
	return(sama);
}

boolean IsEqual(SET S1, SET S2)
{	/* Kamus Lokal */
	boolean sama=true;
	address_set P=Elmt(S1);
	/* Algoritma */
	if (NBElmt(S1)!=NBElmt(S2))
		return false;
	else
		while(P!=Nil && sama){
			if(!IsMember(Info_Set(P),S2))
				sama=false;
			else
				P=ElmtLain(P);
		}
	return sama;
}

void Union (SET S1, SET S2, SET *S3)
{	/* Kamus Lokal */
	address_set P;
	/* Algoritma */
	CreateEmptySet(S3);
	if(IsEmptySet(S1)){
		Elmt(*S3)=Elmt(S2);
	}
	else{
		Elmt(*S3)=Elmt(S1);
		P=Elmt(S2);
		while(P!=Nil){
			if (!IsMember(Info_Set(P),S1))
				InsertSet(Info_Set(P),S3);
			P=ElmtLain(P);
		}
	}
}

void Intersection (SET S1, SET S2, SET *S3)
{	/* Kamus Lokal */
	address_set P;
	/* ALgoritma */
	CreateEmptySet(S3);
	P=Elmt(S1);
	while(P!=Nil){
		if(IsMember(Info_Set(P),S2))
			InsertSet(Info_Set(P),S3);
		P=ElmtLain(P);
	}
}

void Set_Difference (SET S1, SET S2, SET *S3)
{	/* Kamus Lokal */
	address_set P;
	/* Algoritma */
	CreateEmptySet(S3);
	copy(S1,S3);
	P=Elmt(S2);
	while(P!=Nil){
		DeleteSet(Info_Set(P),S3);
		P=ElmtLain(P);
	}
}

void copy (SET S1, SET *S2)
{	/* Kamus Lokal */
	/* Algoritma */
	CreateEmptySet(S2);
	Elmt(*S2)=Elmt(S1);
}

boolean IsSubSet(SET S1, SET S2)
{	/* Kamus Lokal */
	boolean sub=true;
	address_set P;
	/* Algoritma */
	P=Elmt(S1);
	while(P!=Nil && sub){
		if(!IsMember(Info_Set(P),S2))
			sub=false;
		else
			P=ElmtLain(P);
	}
	return(sub);
}

void PrintInfo (SET S)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
{	/* Kamus Lokal */
	address_set P;
	/* Algoritma */
	P=Elmt(S);
	if (!IsEmptySet(S))
	{	printf("{");
		while(P!=Nil)
		{	
			printf("%s",Info_Set(P));
			if (ElmtLain(P)!=Nil)
				printf(",");
			P=ElmtLain(P);
		}
		printf("}");
	}
	else
		printf("{ }");
}
