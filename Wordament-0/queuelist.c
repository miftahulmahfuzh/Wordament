#include "queuelist.h"

void AlokasiQ (address *P, infotype X){
	int i;
	*P = (address) malloc (sizeof(ElmtQueue));
	if(*P!=Nil){
		for(i=0;i<=16;i++){
			Info(*P)[i] = X[i];
		}
		Next(*P) = Nil;
	}
}

void DealokasiQ (address P){
	free(P);
}

boolean IsEmptyQ (Queue Q){
	return (Head(Q) == Nil && Tail(Q)==Nil);
}

int NBElmtQ(Queue Q){
	address P=Head(Q);
	int count=0;
	while(P!=Nil){
		count++;
		P=Next(P);
	}
	return count;
}

void CreateEmptyQ(Queue * Q){
	Head(*Q)=Nil;
	Tail(*Q)=Nil;
}

void AddQ (Queue * Q, infotype X){
	address P;
	AlokasiQ(&P,X);
	if (P!=Nil) {
		if (!IsEmptyQ(*Q)) {
			Next(Tail(*Q)) = P;
		} else /* Q kosong */ {
			Head(*Q) = P;
		}
		Tail(*Q) = P;
	}
}

void DelQ(Queue * Q, infotype * X){
	address P;
	int i;
	P=Head(*Q);
	for(i=0;i<=16;i++){
		(*X)[i] = InfoHead(*Q)[i];
	}
	Head(*Q) = Next(Head(*Q));
	if (Head(*Q)==Nil) {
		Tail(*Q) = Nil;
	}
	DealokasiQ(P);
}

void PrintHeadQ(Queue Q){
	printf("Suggestion: %s\n",&InfoHead(Q));
}

void BacaSuggest(Queue *Q, char name[], int no_board)
{	/* Kamus Lokal */
	char filee[50] = "Suggest/_/";
	infotype X;
	/* Algoritma */
	filee[8] = no_board + '0';
	strcat(filee, name);
	strcat(filee, ".txt");
	CreateEmptyQ(Q);
	STARTKATA(filee);
	while(!EOP)
	{
		KataToString(X);
		AddQ(Q, X);
		ADVKATA();
	}
}

void TulisSuggest(Queue *Q, char name[], int no_board)
{	/* Kamus Lokal */
	char filee[50] = "Suggest/_/";
	infotype X;
	/* Algoritma */
	filee[8] = no_board + '0';
	strcat(filee, name);
	strcat(filee, ".txt");
	STARTWrite(filee);
	while(!IsEmptyQ(*Q))
	{
		DelQ(Q, &X);
		WritePita(X);
		WritePita("\n");
	}
	WritePita(".\n");
}
