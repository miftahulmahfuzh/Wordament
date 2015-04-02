#include "matriks.h"

/* *** Untuk sebuah MATRIKS M yang terdefinisi: *** */

el_type GetElmtMat (MATRIKS M,indeks i,indeks j)
/* Mengirimkan elemen M dg nomor baris i dan nomor kolom j */
{
  /*kamus lokal*/
  /*algoritma*/
	return(M.Mem[i][j]);
}

el_type GetElmtDiagonal (MATRIKS M,indeks i)
/* Mengirimkan elemen M(i,i) */
/* *** Operasi mengubah nilai elemen MATRIKS: Set / Assign *** */
{
  /*kamus lokal*/
  /*algoritma*/
	return(GetElmtMat(M,i,i));
}

void SetElMat (MATRIKS *M,int i,int j,el_type X)
/* I.S. M sudah terdefinisi */
/* F.S. M(i,j) bernilai X */
/* Proses: Mengisi M(i,j) dengan X */
{
  /*kamus lokal*/
  /*algoritma*/
	(*M).Mem[i][j] = X;
}

/* ********** KELOMPOK BACA/TULIS ********** */

void BacaMATRIKS (MATRIKS *M, int no_board)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK */
/* Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* dari pembacaan dengan traversal per baris */
{	
	/*kamus lokal*/
	indeks k;
  indeks i = 1;
  indeks j = 1;
  char filee[] = "Board/ .txt";
	/*algoritma*/
  filee[6] = no_board+'0';
  STARTKATA(filee);
  while (!EndKata)
  {
	 if (CC != EndKata)
    for (k=1;k<=CKata.Length;k++) 
    { 
      if ('A' <= CKata.TabKata[k] && CKata.TabKata[k] <= 'Z')
      {  
        (*M).Mem[i][j] = CKata.TabKata[k];
        j++;
        if(j == 5)
        {
        	i++;
        	j = 1;
        }
      }     
    }
    ADVKATA();
  }
}

void TulisMATRIKS (MATRIKS K, MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layar*/
/* Menulis nilai setiap indeks dan elemen M ke layar dengan traversal per baris */
{
  /*kamus lokal*/	
	indeks i,j;
  /*algoritma*/
	for(i=1;i<=4;i++)
	{	
		for(j=1;j<=3;j++)
		{
			if(j==1) printf("  ");
	 		printf("%c%c",GetElmtMat(K,i,j),GetElmtMat(M,i,j));
		}
		printf("%c%c\n",GetElmtMat(K,i,j),GetElmtMat(M,i,j));
	}
}

/*prosedur dan fungsi tambahan buat wordament*/

void sedot(MATRIKS *K)
/*set semua elmt *K jadi spasi*/
{
	/*kamus lokal*/
	indeks i,j;
	/*algoritma*/
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
			(*K).Mem[i][j] = 100;
	}
}

void pengen(MATRIKS *M, MATRIKS m)
/*nyalin m ke *M*/
{
	/*kamus lokal*/
	int i,j;
	/*algoritma*/
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
			(*M).Mem[i][j] = m.Mem[i][j];
	}
}

void CwMATRIKS (MATRIKS *M,MATRIKS *T)
/*muter matriks searah jarum jam*/
{
	/*kamus lokal*/
	MATRIKS m,t; // penyimpan sementara
	int i,j,k;
	/*algoritma*/	
	k = 4;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			m.Mem[j][k] = (*M).Mem[i][j];
			t.Mem[j][k] = (*T).Mem[i][j];
		}
		k--;
	}
	pengen(M,m);
	pengen(T,t);
}

void kursor(MATRIKS *K,POINT P,el_type k)
/*setting posisi kursor di i,j*/
{
	((*K).Mem[GetOrdinat(P)][GetAbsis(P)] = k);
}
el_type ElMat(MATRIKS M, POINT P)
{
	return M.Mem[GetOrdinat(P)][GetAbsis(P)];
}
