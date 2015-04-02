/*nama file : mesinkar.h*/
/*miftahul mahfuzh [13513017]*/

#ifndef __MESIN_KAR__
#define __MESIN_KAR__
#include <stdio.h>
#include <string.h>
#include "boolean.h"
#define MARK '.'

/* State Mesin */
char CC;
boolean EOP;
boolean ndef; // simbol dari not default. digunakan pada bacaan file eksternal jika player langsung milih Play Game
int misc; // variable ini digunakan untuk print miscellaneous (selain table)
typedef char kat[30];

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita
Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */

void STAR();

void STARTmisc();

void ADV();
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */

void regis(kat id,kat pass);
#endif