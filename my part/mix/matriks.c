#include "matriks.h"

/* *** Untuk sebuah MATRIKS M yang terdefinisi: *** */

el_type GetElmt (MATRIKS M,indeks i,indeks j)
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
	return(GetElmt(M,i,i));
}

void SetEl (MATRIKS *M,int i,int j,el_type X)
/* I.S. M sudah terdefinisi */
/* F.S. M(i,j) bernilai X */
/* Proses: Mengisi M(i,j) dengan X */
{
  /*kamus lokal*/
  /*algoritma*/
	(*M).Mem[i][j] = X;
}

/* ********** KELOMPOK BACA/TULIS ********** */

void BacaMATRIKS (MATRIKS *M)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK */
/* Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* dari pembacaan dengan traversal per baris */
{	
	/*kamus lokal*/
  indeks i = 1;
  indeks j = 1;
	/*algoritma*/
  STARTKAT();
  //printf("%c\n",CKata.TabKata[1]);
  
  while (!EndKata) 
  {
  	//if (CKata.TabKata[1] == ',') ADVKATA();
    if ('A' <= CKata.TabKata[1] && CKata.TabKata[1] <= 'Z')
    {  
      (*M).Mem[i][j] = CKata.TabKata[1];      
      j++;
      if(j == 5) {
      	i++;
      	j = 1;
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
	 		printf("%c%c",GetElmt(K,i,j),GetElmt(M,i,j));
		}
		printf("%c%c\n",GetElmt(K,i,j),GetElmt(M,i,j));
	}
}

/* PROSEDUR DAN FUNGSI TAMBAHAN UNTUK WORDAMENT */

void sedot(MATRIKS *K)
/*set semua elmt *K jadi spasi*/
{
	/*kamus lokal*/
	indeks i,j;
	/*algoritma*/
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
			(*K).Mem[i][j] = ' ';
	}
}

void pengen(MATRIKS *M, MATRIKS m)
/* nyalin m ke *M */
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
/* muter matriks searah jarum jam */
{
	/*kamus lokal*/
	MATRIKS m,t; // penyimpan sementara
	int i,j,k;
	/*algoritma*/	
	k = 4;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
			m.Mem[j][k] = (*M).Mem[i][j];
			t.Mem[j][k] = (*T).Mem[i][j];
		k--;
	}
	pengen(M,m);
	pengen(T,t);
}

void kursor(MATRIKS *K,indeks i,indeks j,char k)
/* setting posisi kursor di i,j */
{
	((*K).Mem[i][j] = k);
}

void mains()
{
	/*kamus lokal*/
	char mn[1]; // variabel option main menu
	kat id,pass; // string untuk login dan sign up
	int mp; // variabel option preparation menu
	misc = 0; // misc>0 menandakan pembacaan file eksternal bukan table 
	/*algoritma*/
	A :
	printf("Main Menu             \n");
	printf("   a.Register						\n");
	printf("   b.Login								\n");
	printf("   c.How To play 				\n");
	printf("   d.About								\n");
	printf("   e.Quit								\n");	
	printf(      "Choose one : ");
	scanf("%s",mn);
	switch(mn[0])
	{
		case 'a':
				printf("\n");
				printf("Welcome lads!!\n");
				printf("ID         : ");
				scanf("%s",id);
				printf("password   : ");
				scanf("%s",pass);
				printf("\n");
				regis(id,pass);
				goto B;
		case 'b':
				printf("\n");
				printf("ID         : ");
				scanf("%s",id);
				printf("password   : ");
				scanf("%s",pass);				
				printf("Welcome back!!!\n");
				B : 
				printf("\n");
				printf("Preparation Menu			\n");
				printf("   1.Play Game           \n");
				printf("   2.Select Board        \n");
				printf("   3.View My High Score  \n");
				printf("   4.View All High Score \n");
				printf("   5.Logout							\n");
				printf("Choose one : ");
				scanf("%d",&mp);
				switch(mp)
				{
					case 5:
							printf("\n"); 
							goto A;
					case 1:
							if (!ndef) BacaMATRIKS(&t); // maksudnya !ndef adalah kondisi default game, dibaca table 1 dari .txt
							sedot(&k); // isi seluruh elemen matriks kursor dengan ' '
							kursor(&k,1,1,'>');
							Play(30); // play with time limit 120 seconds (2 minutes)
							goto B;
					case 3:
							misc = 3;
							printmisc(); // printmisc ada di kata.c 
							goto B;
					case 4:
							misc = 4;
							printmisc(); // printmisc ada di kata.c 
							goto B;
					case 2:
							// set ke not default. artinya bacaan tabel dari user, bukan settingan default (tabel 1)
							ndef = true; 
							BacaMATRIKS(&t);
					default : goto B;
				}
		case 'c':
					misc = 1;
					printmisc(); // printmisc ada di kata.c 
					goto A;
		case 'd':
					misc = 2;
					printmisc(); // printmisc ada di kata.c 
					goto A;
		case 'e':
					break;
		default : goto A;
	}
}