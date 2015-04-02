#include "map.h"


boolean IsEmptyMap(MAP M)
{	/* Kamus Lokal */
	boolean kosong=true;
	int i=0;
	/* Algoritma */
	while(i<=25 && kosong){
		if(M.key[i]!=ValueUndef)
			kosong = false;
		i++;
	}
	return kosong;
}

void CreateEmptyMap(MAP *M)
{	/* Kamus Lokal */
	int i;
	/* Algoritma */
	for (i=0; i<=25; i++){
		(*M).key[i]=ValueUndef;
	}
}

void InsertMap (char K, infotype_map V, MAP *M)
{	/* Kamus Lokal */
	/* Algoritma */
	(*M).key[hash(K)]=V;
}

void DeleteMap (char K, MAP *M)
{	/* Kamus Lokal */
	/* Algoritma */
	(*M).key[hash(K)]=ValueUndef;
}

void Reassign (char K, infotype_map V, MAP *M)
{	/* Kamus Lokal */
	/* Algoritma */
	(*M).key[hash(K)]=V;
}

infotype_map Value_of (char K, MAP M)
{	/* Kamus Lokal */
	/* Algoritma */
	return(M.key[hash(K)]);
}

int hash(char C)
{	/* Kamus Lokal */
	/* Algoritma */
	return(C % 26);
}

void CreateMAP(MAP *M){
	CreateEmptyMap(M);
	InsertMap('A',2,M);
	InsertMap('B',5,M);
	InsertMap('C',3,M);
	InsertMap('D',3,M);
	InsertMap('E',1,M);
	InsertMap('F',5,M);
	InsertMap('G',4,M);
	InsertMap('H',4,M);
	InsertMap('I',2,M);
	InsertMap('J',10,M);
	InsertMap('K',6,M);
	InsertMap('L',3,M);
	InsertMap('M',4,M);
	InsertMap('N',2,M);
	InsertMap('O',2,M);
	InsertMap('P',4,M);
	InsertMap('Q',10,M);
	InsertMap('R',2,M);
	InsertMap('S',2,M);
	InsertMap('T',2,M);
	InsertMap('U',4,M);
	InsertMap('V',6,M);
	InsertMap('W',6,M);
	InsertMap('X',9,M);
	InsertMap('Y',5,M);
	InsertMap('Z',8,M);
}

int stringtopoin(char A[17])
{	/* Kamus Lokal */
	MAP M;
	int sum=0;
	char i=0;
	int bonus=0;
	int score;
	/* Algoritma */
	CreateMAP(&M);
	while(A[i]!='\0'){
		sum=sum+Value_of(A[i],M);
		i++;
	}
	if(i>=10)
			bonus=100;
	score=(sum*i)+bonus;
	return score;
}
