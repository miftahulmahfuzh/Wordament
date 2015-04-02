/* How to Compile :
	gcc -std=c99 -o wordament-0 wordament-0.c adtpoint.c adtjam.c adttanggal.c adtwaktu.c adtarray.c linkstack.c map.c matriks.c mesinkar.c mesinkata1.c multi_list.c pqueuelist.c queuelist.c set.c tree.c wordament.c
*/

#include "wordament.h"
/* KAMUS GLOBAL */
Tree DicT;
adrUser User1;
int board_used, NPlayBoard[10], NPlayerBoard[10], rankBoard[10];
ListUser LU;
Queue Suggest;
TabInt AllScore;
double avgBoard[10];

int main()
{	/* KAMUS */
	/* ALGORITMA */
	opening();
	CreateEmptyQ(&Suggest);
	CreateEmptyUser(&LU);
	board_used = 1;
	BacaUser(&LU);
	BacaStatistic();
	BacaDict(&DicT);
	SelectMenu();
	TulisUser(&LU);
	TulisStatistic();
	DeleteTree(&DicT);
	return 0;
}
