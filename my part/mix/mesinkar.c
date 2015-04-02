/*nama file : mesinkar.c*/
/*miftahul mahfuzh [13513017]*/

#include <stdio.h>
#include "mesinkar.h"

static FILE *pita;
static int retval;

void START() 
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada
jendela.
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka
EOP akan padam (false). Jika CC = MARK maka EOP akan menyala (true)
*/
/* Algoritma */
{
	int d;
	char filee[13] = "tables/ .txt";
	/*algoritma*/
	if (!ndef) d = 1;
	else
	{ 
		printf("masukkan pilihan board anda [0..9] : ");
  	scanf("%d",&d);
  }
  filee[6] = d + '0';
 	pita = fopen(filee,"r");
 	ADV();
}

void STAR()
{
	pita = fopen("1.txt","r");
	ADV();
}


void STARTmisc()
{
	/*kamus lokal*/
	char loc1[20] = "howto/howtoplay.txt";
	char loc2[16] = "about/about.txt";
	char loc3[19] = "users/syamsul.txt"; // lihat high score seluruh board untuk seorang player  
	char loc4[12] = "highs/1.txt"; // lihat high score seluruh player pada board 1

	/*algoritma*/
	switch(misc)
	{
		case 1: 
				pita = fopen(loc1,"r");
				break;
		case 2:	
				pita = fopen(loc2,"r");
				break;
		case 3:	
				pita = fopen(loc3,"r");
				break;
		case 4:	
				pita = fopen(loc4,"r");
	}
	ADV();
}

void ADV() 
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = MARK. Jika CC = MARK maka EOP akan menyala (true) */
{
 /* Algoritma */
 retval = fscanf(pita,"%c",&CC);
 EOP = (CC == MARK);
 if (EOP) fclose(pita);
}

/*special wordament*/
void regis(kat id,kat pass)
{
	/*kamus lokal*/
	char newe[30] = "users/";
	char c[4] = ".txt";
	int i,j;
	/*algoritma*/
	j = 6;
	for (i=0;i<=strlen(id)-1;i++)
	{
		newe[j] = id[i];
		j++;
	}
	for (i=0;i<=3;i++)
	{
		newe[j] = c[i]; 
	}
	pita = fopen(newe,"w");

}