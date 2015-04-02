/* File : wordament.h */

#ifndef _wordament__H
#define _wordament__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <time.h>
#include "adtpoint.h"
#include "adtwaktu.h"
#include "adtarray.h"
#include "mesinkata1.h"
#include "matriks.h"
#include "linkstack.h"
#include "queuelist.h"
#include "pqueuelist.h"
#include "set.h"
#include "map.h"
#include "tree.h"
#include "multi_list.h"

#define BOLD	"\033[1m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE	"\x1b[37m"
#define RESET   "\x1b[0m"
#define HIDEKURSOR	printf("\e[?25l")
#define SHOWKURSOR	printf("\e[?25h")
#define setWin(x,y)   	printf("\e[8;%d;%d;t",(x), (y))
#define gotoXY(x,y)   	printf("\x1B[%d;%df", (x), (y))
#define pext(c)			printf("\e(0%c\e(B",(c))
#define clrscr			 printf("\033[2J\033[0;0f")
#define clrscr1			printf("\e[1;1H\e[2J")
#define f(i,j,k) for(i=j;i<=k;i++)
#define printberkali(x,y) for(i=1; i<=(x); i++)printf("%s",(y));
#define h1 15
static struct termios old_termios, new_termios;

extern Tree DicT;
extern adrUser User1;
extern int board_used, NPlayBoard[10], NPlayerBoard[10], rankBoard[10];
extern ListUser LU;
extern Queue Suggest;
extern TabInt AllScore;
extern double avgBoard[10];

/* restore new terminal i/o settings */
void resetTermios();
/* initialize new terminal i/o settings */
void initTermios();
/* detect keyboard press */
int kbhit();
/* read 1 character */
char getch();
void pressKey();
/* skeleton program for play */
void SelectMenu();
void opening();
void printMenu();
adrUser loginUser(ListUser LU);
adrUser registerUser(ListUser *LU);
void playGame(double seconds, PQueue *PQWord, int *total, int *N);
void phuruf(char c, int x, int y);
void drawBoard(int r, int b, MATRIKS M);
void drawWord(int r, int b);
void printPreparation();
void printAbout();
int selectBoard(int before);
void printHow(); // cetak how to play
int printAllScore();
void CetakBingkai();
int printMyScore(adrUser U);
int selectBack();
void DualPlayer(double seconds, int no_1, int no_2, int *total1, int *total2);
int printScoreWord(PQueue * PQ, int total, int N);
void BacaStatistic();
void TulisStatistic();
void UpdateStatistic(int no_board, int score, boolean IsNew);
int ViewBoardStatistic(int no_board);
int printHowMultiplayer();
int MultiplayerMenu();
int printHasilDual(int score1, int score2);
int searchWordBoard(SET *SWord, MATRIKS *board, POINT P, char word[17], int pos , pNode NodeNow);
int printBoardWord();
void selectDualBoard(int *no1, int *no2);

#endif
