#include <stdio.h>
#include "mesinkar.h"

char CC;
boolean EOP;

static FILE *pita;
static int retval;

void STARTRead(char filee[]) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka
	EOP akan padam (false). Jika CC = MARK maka EOP akan menyala (true)
	*/

	/* Algoritma */
	pita = fopen(filee,"r");
	ADV();
}

void STARTWrite(char filee[]) {
	pita = fopen(filee, "w");
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
		  CC mungkin = MARK
		  Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
	EOP = (CC == MARK);
	if (EOP) {
		fclose(pita);
	}
}

void WritePita(char strin[]) {
	retval = fprintf(pita,"%s", strin);
	if(strin[0] == MARK)
		fclose(pita);
}

void WritePitaInt(int value) {
	retval = fprintf(pita,"%d",value);
}
