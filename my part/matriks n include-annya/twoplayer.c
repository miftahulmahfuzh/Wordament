#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <time.h>

#include "boolean.h"
#include "matriks.h"

#define clrscr printf("\e[1;1H\e[2J")
#define gotoXY(x,y) printf("\x1B[%d;%df",(x),(y))
#define Bold "\033[1m"
#define Reset "\033[0m"
#define Green "\033[32m"
#define Red "\033[31m"
#define Magenta "\033[35m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define Enter printf("\n")
#define HideCursor printf("\033[?25l")
#define ShowCursor printf("\033[?25h")
#define printberkali(x,y) for(i=1; i<=(x); i++)printf("%s",(y));

void drawWord(int r, int b)
{
	gotoXY(r,b);   printf(Bold"\e[94m ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ");
	gotoXY(r+1,b); printf("||\e[31mW\e[94m |||\e[33mO\e[94m |||\e[34mR\e[94m |||\e[35mD\e[94m |||\e[36mA\e[94m |||\e[37mM\e[94m |||\e[90mE\e[94m |||\e[91mN\e[94m |||\e[92mT\e[94m |||\e[93m-\e[94m |||\e[94m0\e[94m ||");
	gotoXY(r+2,b); printf("||__|||__|||__|||__|||__|||__|||__|||__|||__|||__|||__||");
	gotoXY(r+3,b); printf("|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|"Reset);
}

void phuruf(char c, int x, int y)
{
	gotoXY(x, y);
	printf(Bold"\e[96m");
	switch(c)
	{
		case 'A' :
			printf(".__."); gotoXY(x+1, y);
			printf("[__]");	gotoXY(x+2,y);
			printf("|  |");	break;
		case 'B' :
			printf(".__ "); gotoXY(x+1, y);
			printf("|__)");	gotoXY(x+2,y);
			printf("|__)");	break;
		case 'C' :
			printf(" __ "); gotoXY(x+1, y);
			printf("/  `");	gotoXY(x+2,y);
			printf("\\__.");	break;
		case 'D' :
			printf(".__ "); gotoXY(x+1, y);
			printf("|  \\");	gotoXY(x+2,y);
			printf("|__/");	break;
		case 'E' :
			printf(".___"); gotoXY(x+1, y);
			printf("|__ ");	gotoXY(x+2,y);
			printf("|___");	break;
		case 'F' :
			printf(".___"); gotoXY(x+1, y);
			printf("|__ ");	gotoXY(x+2,y);
			printf("|  ");	break;
		case 'G' :
			printf(".__ "); gotoXY(x+1, y);
			printf("[ __");	gotoXY(x+2,y);
			printf("[_./");	break;
		case 'H' :
			printf(".  ."); gotoXY(x+1, y);
			printf("|__|");	gotoXY(x+2,y);
			printf("|  |");	break;
		case 'I' :
			printf(" ._."); gotoXY(x+1, y);
			printf("  | ");	gotoXY(x+2,y);
			printf(" _|_");	break;
		case 'J' :
			printf("   ."); gotoXY(x+1, y);
			printf("   |");	gotoXY(x+2,y);
			printf("\\__|");	break;
		case 'K' :
			printf(".  ."); gotoXY(x+1, y);
			printf("|_/ ");	gotoXY(x+2,y);
			printf("|  \\");	break;
		case 'L' :
			printf(".   "); gotoXY(x+1, y);
			printf("|   ");	gotoXY(x+2,y);
			printf("|__.");	break;
		case 'M' :
			printf(".  ."); gotoXY(x+1, y);
			printf("|\\/|");	gotoXY(x+2,y);
			printf("|  |");	break;
		case 'N' :
			printf(".  ."); gotoXY(x+1, y);
			printf("|\\ |");	gotoXY(x+2,y);
			printf("| \\|");	break;
		case 'O' :
			printf(".__."); gotoXY(x+1, y);
			printf("|  |");	gotoXY(x+2,y);
			printf("|__|");	break;
		case 'P' :
			printf(".__ "); gotoXY(x+1, y);
			printf("|__)");	gotoXY(x+2,y);
			printf("|   ");	break;
		case 'Q' :
			printf(".__."); gotoXY(x+1, y);
			printf("| _|");	gotoXY(x+2,y);
			printf("|__\\");	break;
		case 'R' :
			printf(".__ "); gotoXY(x+1, y);
			printf("|__)");	gotoXY(x+2,y);
			printf("| \\.");	break;
		case 'S' :
			printf(" __."); gotoXY(x+1, y);
			printf("(__ ");	gotoXY(x+2,y);
			printf(".__)");	break;
		case 'T' :
			printf(".___"); gotoXY(x+1, y);
			printf("  | ");	gotoXY(x+2,y);
			printf("  | ");	break;
		case 'U' :
			printf(".  ."); gotoXY(x+1, y);
			printf("|  |");	gotoXY(x+2,y);
			printf("|__|");	break;
		case 'V' :
			printf(".  ."); gotoXY(x+1, y);
			printf("\\  /");	gotoXY(x+2,y);
			printf(" \\/ ");	break;
		case 'W' :
			printf(".  ."); gotoXY(x+1, y);
			printf("|  |");	gotoXY(x+2,y);
			printf("|/\\|");	break;
		case 'X' :
			printf(".  ."); gotoXY(x+1, y);
			printf(" \\/");	gotoXY(x+2,y);
			printf(" /\\");	break;
		case 'Y' :
			printf(".  ."); gotoXY(x+1, y);
			printf(" \\_/");	gotoXY(x+2,y);
			printf("  | ");	break;
		case 'Z' :
			printf(".__."); gotoXY(x+1, y);
			printf("  / ");	gotoXY(x+2,y);
			printf("./__");	break;	
	}
	printf(Reset);
}

void drawBoard(int r, int b, MATRIKS M)
{
	indeks i, j;
	gotoXY(r,b);
	printf(Bold Yellow"\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2566");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2566");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2566");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\n");
	gotoXY(r+1,b);
	printf("\u2551       \u2551       \u2551       \u2551       \u2551\n");
	gotoXY(r+2,b);
	printf("\u2551       \u2551       \u2551       \u2551       \u2551\n");
	gotoXY(r+3,b);
	printf("\u2551       \u2551       \u2551       \u2551       \u2551\n");
	gotoXY(r+4,b);
	printf("\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\n");
	gotoXY(r+5,b);
	printf("\u2551       \u2551       \u2551       \u2551       \u2551\n");
	gotoXY(r+6,b);
	printf("\u2551       \u2551       \u2551       \u2551       \u2551\n");
	gotoXY(r+7,b);
	printf("\u2551       \u2551       \u2551       \u2551       \u2551\n");
	gotoXY(r+8,b);
	printf("\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\n");
	gotoXY(r+9,b);
	printf("\u2551       \u2551       \u2551       \u2551       \u2551\n");
	gotoXY(r+10,b);
	printf("\u2551       \u2551       \u2551       \u2551       \u2551\n");
	gotoXY(r+11,b);
	printf("\u2551       \u2551       \u2551       \u2551       \u2551\n");
	gotoXY(r+12,b);		
	printf("\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256c");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\n");
	gotoXY(r+13,b);
	printf("\u2551       \u2551       \u2551       \u2551       \u2551\n");
	gotoXY(r+14,b);
	printf("\u2551       \u2551       \u2551       \u2551       \u2551\n");
	gotoXY(r+15,b);
	printf("\u2551       \u2551       \u2551       \u2551       \u2551\n");
	gotoXY(r+16,b);
	printf("\u255a\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2569");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2569");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2569");
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255d\n"Reset);
	for(i = 1; i<= 4; i++)
		for(j = 1; j<=4; j++)
			phuruf(GetElmtMat(M, i, j),r-3+i*4, b+8*j-5);
	gotoXY(r+2, b+10);
}

int main (){
	int i;
	MATRIKS MBoard;

	clrscr;
	printf("\e[8;%d;%d;t", (30), (100));

	BacaMATRIKS(&MBoard,1);
	drawWord(2,22);
	drawBoard(10,9,MBoard);
	drawBoard(10,58,MBoard);
	gotoXY(9,9);printf(Bold Red "Player 1" Reset);
	gotoXY(9,58);printf(Bold Blue "Player 2" Reset);
	gotoXY(12,43);printf(Red Bold"Score Player 1" Reset);
	gotoXY(15,43);printf("xxxxxxxxxxxxxx");
	gotoXY(19,43);printf(Blue Bold"Score Player 2" Reset);
	gotoXY(22,43);printf("xxxxxxxxxxxxxx");
	gotoXY(27,9);printf("Player 1 Word : ");
	gotoXY(27,58);printf("Player 2 Word : ");

	scanf("%*c");
	
	return 0;
}