#include "pqueuelist.h"

void AlokasiPQ (addressP *P, infotype X){
	*P = (addressP) malloc(sizeof(ElmtPQueue));
	if(*P!=Nil){
		AssignPQ(&Info(*P),X);
		Next(*P) = Nil;
		prio(*P) = 0;
	}
	else
		printf("Alokasi gagal\n");
}

void DealokasiPQ (addressP *P){
	free(*P);
}

boolean IsEmptyPQ (PQueue PQ){
	return (Head(PQ) == Nil);
}

int NBElmtPQ(PQueue PQ){
	addressP P=Head(PQ);
	int count=0;
	while(P!=Nil){
		count++;
		P=Next(P);
	}
	return count;
}

void CreateEmptyPQ(PQueue * PQ){
	Head(*PQ)=Nil;
}

void AddPQ (PQueue * PQ, infotype X, int pr){
	addressP P,P1,Prec;
	AlokasiPQ(&P,X);
	if (P!=Nil) {
		if (!IsEmptyPQ(*PQ)) {
			P1=Head(*PQ);
			Prec = Nil;
			while(P1!=Nil){
				if(pr<prio(P1)){
					Prec=P1;
					P1=Next(P1);
				}else break;
			}
			if(Prec != Nil)
			{
				Next(P)=Next(Prec);
				Next(Prec)=P;
			}
			else
			{
				Next(P) = Head(*PQ);
				Head(*PQ) = P;
			}
		} else /* PQ kosong */ {
			Head(*PQ) = P;
		}
		prio(P)=pr;
	}
}

void DelPQ(PQueue * PQ, infotype * X, int *pr){
	addressP P;
	P=Head(*PQ);
	AssignPQ(X,InfoHead(*PQ));
	*pr=prio(Head(*PQ));
	Head(*PQ) = Next(Head(*PQ));
	DealokasiPQ(&P);
}

void PrintPQ(PQueue PQ){
	addressP temp;
	if (IsEmptyPQ(PQ)){
		printf("Tidak ada kata yang ditebak \n");
	} else{
		temp = Head(PQ);
		while(temp != Nil) {		
			printf("%s",Info(temp));
			printf("				%d\n",prio(temp));
			temp = Next(temp);
		}
	}
}

void AssignPQ(infotype *PQ1, infotype PQ2){
	int i;
	for(i=0;i<=16;i++){
		(*PQ1)[i]=PQ2[i];
	}
}
