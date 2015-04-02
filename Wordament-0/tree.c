/* FIle : tree.c */

#include "tree.h"

void CreateTree(Tree *T)
/* I.S Sembarang */
/* F.S terbentuk Tree T kosong */
{	/* Kamus Lokal */
	/* Algoritma */
	(*T) = Nil;
}

pNode AlokasiNode(char C, boolean B)
/* Menghasilkan address hasil alokasi node baru */
/* Jika alokasi gagal menghasilkan Nil */
{	/* Kamus Lokal */
	pNode P;
	int i;
	/* Algoritma */
	P = (pNode) malloc(sizeof(Node));
	if(P != Nil)
	{
		info(*P) = C;
		mark(*P) = B;
		for(i = 0; i<26; i++)
			child(*P, i) = Nil;
	}
	return P;
}

void DealokasiNode(pNode *pN)
/* I.S. pN terdefinisi */
/* F.S. pN dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian pNode */
{	/* Kamus Lokal */
	/* Algoritma */
	free(*pN);
}
boolean IsEmptyTree(Tree T)
/* Menghasilkan true jika Tree T kosong */
{	/* Kamus Lokal */
	/* Algoritma */
	return T == Nil;
}

void SetRoot(Tree *T, char value, boolean B )
/* I.S T sembarang */
/* F.S Root dari Tree (Node pertama) terdefinisi memiliki infoNode = value dan mark = B */
{	/* Kamus Lokal */
	pNode P;
	/* Algoritma */
	if(IsEmptyTree(*T))
	{
		P = AlokasiNode(value, B);
		*T = P;
	}
	else
	{
		info(**T) = value;
		mark(**T) =  B;
	}
}
void AddChild(Node *N, char value, boolean B)
/* I.S. Node N tidak kosong */
/* F.S. jika child dengan infoNode value kosong maka akan ditambahkan child baru
  yang memiliki infoNode = value dan mark = B dengan cara alokasi baru dan   
  jika alokasi gagal maka N tidak berubah */
/* atau jika sudah ada maka hanya melakukan operasi mark = mark || B */
{	/* Kamus Lokal */
	pNode P = child(*N, value-'A');
	/* Algoritma */
	if(P == Nil)
		child(*N, value-'A') = AlokasiNode(value, B);
	else
		mark(*P) |= B;
}
void DelChild(Node *N, char value)
/* I.S. T tidak kosong */
/* F.S. jika child dengan infoNode value kosong maka  T tidak berubah */
/* atau jika ada maka child tersebut dihapus dan di dealokasi  */
{	/* Kamus Lokal */
	pNode P = child(*N, value-'A');
	/* Algoritma */
	if(P != Nil)
	{
		child(*N, value-'A') = Nil;
		DealokasiNode(&P);
	}
}

void AddWord(Tree *T, char s[])
/* I.S. T tidak kosong */
/* F.S. Kata dari string s ditambahkan dalam tree */
{
	int i = 0;
	pNode P = *T;
	while(s[i] != 0)
	{
		AddChild(P, s[i], (s[i+1] == '\0'));
		P = child(*P, s[i]-'A');
		i++;
	}
}

boolean FSearch(Tree T, char s[])
/* Menghasilkan true jika ada kata dari string s pada tree T */
{	/* Kamus Lokal */
	int i;
	pNode P;
	/* Algoritma */
	P = T;
	for(i = 0; s[i] != '\0'; i++)
	{
		if(P == Nil)
			return false;
		P = child(*P, s[i]-'A');
	}
	if(P == Nil)
		return false;
	return mark(*P);
}

void BacaDict(Tree *T)
{	
	char s[20];
	/* ALGORITMA */
	STARTKATA("Dictionary.txt");
	CreateTree(T);
	SetRoot(T,'\0', false);
	while(!EndKata)
	{
		KataToString(s);
		AddWord(T, s);
		ADVKATA();
	}
}
void DeleteTree(Tree *T)
{	/* Kamus Lokal */
	char c;
	/* Algoritma */
	for(c = 'A'; c <= 'Z'; c++)
		if(child(**T,c-'A') != Nil)
			DeleteTree(&child(**T,c-'A'));
	DealokasiNode(T);
	*T = Nil;
}
