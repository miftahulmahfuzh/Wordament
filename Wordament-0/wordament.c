#include "wordament.h"

Tree DicT;
adrUser User1;
int board_used, NPlayBoard[10], NPlayerBoard[10], rankBoard[10];
ListUser LU;
Queue Suggest;
TabInt AllScore;
double avgBoard[10];
char num[10][6] = {"ZERO","ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN","EIGHT","NINE"},
	level[10][8] = { "HARD", "HARD", "HARD", "MEDIUM", "MEDIUM", "MEDIUM", "EASY", "EASY", "EASY", "EASY"};
MATRIKS visited;

/* restore new terminal i/o settings */
void resetTermios(){
	tcsetattr(0,TCSANOW,&old_termios);
}
/* initialize new terminal i/o settings */
void initTermios(){
	tcgetattr(0,&old_termios); // store old terminal
	new_termios = old_termios; // assign to new setting
	new_termios.c_lflag &= ~ICANON; // disable buffer i/o
	new_termios.c_lflag &= ~ECHO; // disable echo mode
	tcsetattr(0,TCSANOW,&new_termios); // use new terminal setting
}
/* detect keyboard press */
int kbhit()
{
	struct timeval tv = {0L,0L};
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0,&fds);
	return select(1,&fds,NULL,NULL,&tv);
}
/* read 1 character */
char getch()
{
	char ch;
	ch = getchar();
	return ch;
}
void pressKey() 
{
	initTermios();
	getch();
	resetTermios();
}
/* skeleton program for play */
void SelectMenu()
{
	HIDEKURSOR;
	char cc, bef[5][23] = {"  Register  ", "  Login  ", "  How To Play  ","  About  ", "  Quit  "}, aft[6][25] = {"\u25B7 Register \u25C1 ", "\u25B7 Login \u25C1 ", "\u25B7 How To Play \u25C1 ","\u25B7 About \u25C1 ", "\u25B7 Quit \u25C1 "};
	int pil = 0, id[5] = {45, 47, 44, 47, 47}, i;
	while(pil != 4)
	{
		printMenu();	
		gotoXY(14+2*pil, id[pil]);
		printf("\e[1;31m%s"RESET"\n", aft[pil]);
		while (1)
		{
			initTermios(); // use new terminal setting again to make kbhit() and getch() work
			cc = getch();
			resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
			if(cc == 27 )
			{
				initTermios();
				cc = getch();
				cc = getch();
				resetTermios();
				gotoXY(14+2*pil, id[pil]);
				printf("%s", bef[pil]);
				switch(cc )
				{
					case 'A' :
					pil = (pil+4) % 5;
					break;
					case 'B' :
					pil = (pil+1) % 5;
					break;
				}
				gotoXY(14+2*pil, id[pil]);
				printf("\e[1;31m%s"RESET, aft[pil]);
			} else
			if(cc == 10)
			{
				switch(pil)
				{
					case 0 :
						User1 = registerUser(&LU);
						getch();
						for(i = 0; i<10; i++)
						{
							TulisScore(User1, i);
							TulisSuggest(&Suggest, username(User1), i);
						}
						BacaAllScore(&AllScore, board_used);
						printPreparation();
						break;
					case 1 :
						User1 = loginUser(LU);
						getch();
						BacaScore(User1, board_used);
						BacaSuggest(&Suggest, username(User1), board_used);
						BacaAllScore(&AllScore, board_used);
						printPreparation();
						break;
					case 2 :
						printHow();
						break;
					case 3 :
						printAbout();
						break;
					case 4 :
						clrscr;
						break;
				}
				break;
			}
			
		}
	}
	printf(RESET);
	SHOWKURSOR;
}

void printPreparation()
{
	HIDEKURSOR;
	int i;
	char cc, bef[7][25] = {"  Play Game  ","  Multiplayer Game  " ,"  Select Board  ","  View Board Statistic  " ,"  View My Highscore  ","  View All Highscore  ", "  Logout  "},
	 aft[7][35] = {"\u25B7 Play Game \u25C1","\u25B7 Multiplayer Game \u25C1", "\u25B7 Select Board \u25C1","\u25B7 View Board Statistic \u25C1", "\u25B7 View My Highscore \u25C1","\u25B7 View All Highscore \u25C1", "\u25B7 Logout \u25C1" };
	int pil2 = 0, id2[7] = {44, 41, 43, 39, 40, 40, 46}, N, total;
	printf("\e[8;%d;%d;t", (30), (100));
	PQueue PQWord;
	while(pil2 != 6)
	{
		CetakBingkai();
	 	gotoXY(3, 35); printf(" __  __  ______  _   _  _    _ ");
		gotoXY(4, 35); printf("|  \\/  ||  ____|| \\ | || |  | |");
	 	gotoXY(5, 35); printf("| \\  / || |__   |  \\| || |  | |");
	 	gotoXY(6, 35); printf("| |\\/| ||  __|  | . ` || |  | |");
	 	gotoXY(7, 35); printf("| |  | || |____ | |\\  || |__| |");
	 	gotoXY(8, 35); printf("|_|  |_||______||_| \\_| \\____/ ");

		for(i = 0; i<7; i++)
		{
			gotoXY(12+2*i, id2[i]); printf("%s"RESET, bef[i]);
		}
		gotoXY(12 + pil2*2, id2[pil2]);
		printf("\e[1;31m%s"RESET"\n", aft[pil2]);
		while (1)
		{
			initTermios(); // initailize new terminal setting to make kbhit() and getch() work
			cc = getch();
			resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
			if(cc == 27 )
			{
				initTermios(); // initailize new terminal setting to make kbhit() and getch() work
				cc = getch();
				cc = getch();
				resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
				gotoXY(12+2*pil2, id2[pil2]);
				printf("%s", bef[pil2]);
				switch(cc )
				{
					case 'A' :
					pil2 = (pil2+6) % 7;
					break;
					case 'B' :
					pil2 = (pil2+1) % 7;
					break;
				}
				gotoXY(12+2*pil2, id2[pil2]);
				printf("\e[1;31m%s"RESET, aft[pil2]);
			} else
			if(cc == 10)
			{
				switch(pil2)
				{
					case 0 :
						do
						{
							playGame(120, &PQWord, &total, &N);
						} while(printScoreWord(&PQWord,total,N) == 1);
						break;
					case 1 :
						if(MultiplayerMenu() == 3)
							pil2 = 6;
						break;
					case 2 :
						TulisScore(User1, board_used);
						TulisSuggest(&Suggest, username(User1), board_used);
						TulisAllScore(&AllScore, board_used);
						board_used = selectBoard(board_used);
						BacaScore(User1, board_used);
						BacaSuggest(&Suggest, username(User1), board_used);
						BacaAllScore(&AllScore, board_used);
						break;
					case 3 :
						ViewBoardStatistic(board_used);
						break;
					case 4 :
						if(printMyScore(User1) == 1)
							pil2 = 6;
						break;
					case 5 :
						if (printAllScore(&AllScore) == 1)
							pil2 = 6;
				}
				break;
			}
		}
	}
	TulisScore(User1, board_used);
	TulisSuggest(&Suggest, username(User1), board_used);
	TulisAllScore(&AllScore, board_used);
	TulisStatistic();
}
void opening ()
{
	/* KAMUS */
	int i;
	char c;
	/* ALGORITMA */
	clrscr;
	HIDEKURSOR;
	printf("\e[8;%d;%d;t", (30), (100));
	printf("\u250f");for(i=1; i<=98 ; i++) printf("\u2501");printf("\u2513"); // garis atas
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
		printf("\u2503");for(i=1; i<=9 ; i++) printf("\u254b") ;printf("__          ______  _____  _____          __  __ ______ _   _ _______      ___  ");for(i=1; i<=9 ; i++) printf("\u254b");printf("\u2503");
		printf("\u2503");for(i=1; i<=9 ; i++) printf("\u254b") ;printf("\\ \\        / / __ \\|  __ \\|  __ \\   /\\   |  \\/  |  ____| \\ | |__   __|    / _ \\ ");for(i=1; i<=9 ; i++) printf("\u254b") ;printf("\u2503");
		printf("\u2503");for(i=1; i<=9 ; i++) printf("\u254b") ;printf(" \\ \\  /\\  / / |  | | |__) | |  | | /  \\  | \\  / | |__  |  \\| |  | |______| | | |");for(i=1; i<=9 ; i++) printf("\u254b") ;printf("\u2503");
		printf("\u2503");for(i=1; i<=9 ; i++) printf("\u254b") ;printf("  \\ \\/  \\/ /| |  | |  _  /| |  | |/ /\\ \\ | |\\/| |  __| | . ` |  | |______| | | |");for(i=1; i<=9 ; i++) printf("\u254b") ;printf("\u2503");
		printf("\u2503");for(i=1; i<=9 ; i++) printf("\u254b") ;printf("   \\  /\\  / | |__| | | \\ \\| |__| / ____ \\| |  | | |____| |\\  |  | |      | |_| |");for(i=1; i<=9 ; i++) printf("\u254b") ;printf("\u2503");
		printf("\u2503");for(i=1; i<=9 ; i++) printf("\u254b") ;printf("    \\/  \\/   \\____/|_|  \\_\\_____/_/    \\_\\_|  |_|______|_| \\_|  |_|       \\___/ ");for(i=1; i<=9 ; i++) printf("\u254b") ;printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2503");for(i=1; i<=98 ; i++) printf("\u254b");printf("\u2503");
	printf("\u2517");for(i=1; i<=98 ; i++) printf("\u2501");printf("\u251b"); // garis bawah
	for(i=1; i<=35; i++) printf(" ");printf("Press Any Key to Continue.....\e[8m");
	pressKey();
	printf(RESET);
}
void printMenu()
{
	int i;

	clrscr;
	setWin(30, 100);
	gotoXY(1,1);
	printf("\u250f"); for(i=1; i<=98 ; i++) printf("\u2501");printf("\u2513"); // garis atas
	gotoXY(2,1); printf("\u2503"); gotoXY(2,100); printf("\u2503");
	gotoXY(3,1); printf("\u2503"); gotoXY(3, 24); printf("___  ___  ___  _____ _   _  ___  ___ _____ _   _ _   _ ");for (i=1; i<=21; i++) printf(" ");printf("\u2503\n");
	printf("\u2503"); for(i=1; i<=22; i++) printf(" "); printf("|  \\/  | / _ \\|_   _| \\ | | |  \\/  ||  ___| \\ | | | | |");for (i=1; i<=21; i++) printf(" ");printf("\u2503\n");
	printf("\u2503"); for(i=1; i<=22; i++) printf(" "); printf("| .  . |/ /_\\ \\ | | |  \\| | | .  . || |__ |  \\| | | | |");for (i=1; i<=21; i++) printf(" ");printf("\u2503\n");
	printf("\u2503"); for(i=1; i<=22; i++) printf(" "); printf("| |\\/| ||  _  | | | | . ` | | |\\/| ||  __|| . ` | | | |");for (i=1; i<=21; i++) printf(" ");printf("\u2503\n");
	printf("\u2503"); for(i=1; i<=22; i++) printf(" "); printf("| |  | || | | |_| |_| |\\  | | |  | || |___| |\\  | |_| |");for (i=1; i<=21; i++) printf(" ");printf("\u2503\n");
	printf("\u2503"); for(i=1; i<=22; i++) printf(" "); printf("\\_|  |_/\\_| |_/\\___/\\_| \\_/ \\_|  |_/\\____/\\_| \\_/\\___/ ");for (i=1; i<=21; i++) printf(" ");printf("\u2503\n");

	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");

	printf("\u2503"); for(i=1; i<=45; i++) printf(" ");printf("Register");for (i=1; i<=45; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503"); for(i=1; i<=47; i++) printf(" ");printf("Login");for (i=1; i<=46; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503"); for(i=1; i<=44; i++) printf(" ");printf("How to Play");for (i=1; i<=43; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503"); for(i=1; i<=47; i++) printf(" ");printf("About");for (i=1; i<=46; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503"); for(i=1; i<=47; i++) printf(" ");printf("Quit");for (i=1; i<=47; i++) printf(" ");printf("\u2503\n");

	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	printf("\u2503");for (i=1; i<=98; i++) printf(" ");printf("\u2503\n");
	
	printf("\u2517");for(i=1; i<=98 ; i++) printf("\u2501");printf("\u251b"); // garis bawah
}
adrUser loginUser(ListUser LU)
{	/* KAMUS */
	char id[50], pass[50];
	int i, l = 30, h = 30, w = 100, n;
	adrUser U;
	/* ALGORITMA */
	setWin(h, w);
	SHOWKURSOR;
	CetakBingkai();
	gotoXY(h1-10,(w-44)/2); printf(" o       .oOOOo.   .oOOOo.  ooOoOOo o.     O \n");
	gotoXY(h1-9,(w-44)/2); printf("O       .O     o. .O     o     O    Oo     o \n");
	gotoXY(h1-8,(w-44)/2); printf("o       O       o o            o    O O    O \n");
	gotoXY(h1-7,(w-44)/2); printf("o       o       O O            O    O  o   o \n");
	gotoXY(h1-6,(w-44)/2); printf("O       O       o O   .oOOo    o    O   o  O \n");
	gotoXY(h1-5,(w-44)/2); printf("O       o       O o.      O    O    o    O O \n");
	gotoXY(h1-4,(w-44)/2); printf("o     . `o     O'  O.    oO    O    o     Oo \n");
	gotoXY(h1-3,(w-44)/2); printf("OOoOooO  `OoooO'    `OooO'  ooOOoOo O     `o \n");
	                                            
	gotoXY(h1,(w-l)/2);
	printf(BOLD RED"Enter your ID :"BOLD BLUE);
	gotoXY(h1+1,(w-l)/2 -1);	pext(108); for(i=0; i<l; i++) pext(113); pext(107);
	gotoXY(h1+2,(w-l)/2 -1);	pext(120); gotoXY(h1+2, (w-l)/2 + l); pext(120);
	gotoXY(h1+3,(w-l)/2 -1);  pext(109); for(i=0; i<l; i++) pext(113); pext(106);
	gotoXY(h1+2, (w-l)/2); printf(RESET GREEN);
	scanf("%s", id);
	
	gotoXY(h1+4,(w-l)/2);
	printf(BOLD RED"Enter your password :"BOLD BLUE);
	gotoXY(h1+5,(w-l)/2 -1);	pext(108); for(i=0; i<l; i++) pext(113); pext(107);
	gotoXY(h1+6,(w-l)/2 -1);	pext(120); gotoXY(h1+6, (w-l)/2 + l); pext(120);
	gotoXY(h1+7,(w-l)/2 -1);  pext(109); for(i=0; i<l; i++) pext(113); pext(106);
	gotoXY(h1+6, (w-l)/2); printf(GREEN"\e[8m");
	scanf("%s", pass);
	printf(RESET);
	U = SearchUser(LU, id);
	if(U != Nil && strcmp(password(U), pass)==0)
	{
		gotoXY(h1+8, (w-17)/2);
		printf(RESET"\x1b[1m\033[37mLogin succesfull.\n"RESET);
		return U;
	}
	while(1)
	{
		gotoXY(h1+8, 2);
		printf("\x1b[1m\033[37m");
		for(i = 0; i< 98; i++) printf(" ");
		gotoXY(h1+8, (w-l)/2);
		if(U == Nil)
			printf("\x1B[%d;%dfNo user with ID %s.\n",h1+8,(w-17-strlen(id))/2, id);
		else
			if(strcmp(password(U), pass) == 0)
			{
				printf("\x1B[%d;%dfLogin succesfull."RESET,h1+8,(w-17)/2);
				HIDEKURSOR;
				return U;
			}
			else
			{
				printf("\x1B[%d;%dfWrong password.",h1+8,(w-15)/2);
			}
		printf(RESET);
		gotoXY(h1+2,(w-l)/2 -1); pext(120); for(i = 0; i<l; i++)	printf(" "); pext(120);
		gotoXY(h1+8,(w-l)/2);	gotoXY(h1+2, (w-l)/2); printf(RESET GREEN);
		scanf("%s", id);
		gotoXY(h1+6, (w-l)/2); printf(GREEN"\e[8m");
		scanf("%s", pass);
		printf(RESET);
		U = SearchUser(LU, id);
	}
}
adrUser registerUser(ListUser *LU)
{	/* KAMUS */
	char id[50], pass[50], verpass[50];
	adrUser U;
	int i, l, h, w;
	/* ALGORITMA */
	CetakBingkai();
	SHOWKURSOR;
	h = 30;
	w = 100;
	l = 30;
	gotoXY(h1-10,(w-71)/2); printf("`OooOOo.  o.OOoOoo  .oOOOo.  ooOoOOo .oOOOo.  oOoOOoOOo o.OOoOoo `OooOOo.  \n");
	gotoXY(h1-9,(w-71)/2); printf(" o     `o  O       .O     o     O    o     o      o      O        o     `o \n");
	gotoXY(h1-8,(w-71)/2); printf(" O      O  o       o            o    O.           o      o        O      O \n");
	gotoXY(h1-7,(w-71)/2); printf(" o     .O  ooOO    O            O     `OOoo.      O      ooOO     o     .O \n");
	gotoXY(h1-6,(w-71)/2); printf(" OOooOO'   O       O   .oOOo    o          `O     o      O        OOooOO'  \n");
	gotoXY(h1-5,(w-71)/2); printf(" o    o    o       o.      O    O           o     O      o        o    o   \n");
	gotoXY(h1-4,(w-71)/2); printf(" O     O   O        O.    oO    O    O.    .O     O      O        O     O  \n");
	gotoXY(h1-3,(w-71)/2); printf(" O      o ooOooOoO   `OooO'  ooOOoOo  `oooO'      o'    ooOooOoO  O      o \n");
	                                            
	gotoXY(h1,(w-l)/2);
	printf(BOLD RED"Enter your ID :"BOLD BLUE);
	gotoXY(h1+1,(w-l)/2 -1);	pext(108); for(i=0; i<l; i++) pext(113); pext(107);
	gotoXY(h1+2,(w-l)/2 -1);	pext(120); gotoXY(h1+2, (w-l)/2 + l); pext(120);
	gotoXY(h1+3,(w-l)/2 -1);  pext(109); for(i=0; i<l; i++) pext(113); pext(106);
	gotoXY(h1+2, (w-l)/2); printf(RESET GREEN);
	scanf("%s", id);
	gotoXY(h1+4,(w-l)/2);
	printf(BOLD RED"Enter your password :"BOLD BLUE);
	gotoXY(h1+5,(w-l)/2 -1);	pext(108); for(i=0; i<l; i++) pext(113); pext(107);
	gotoXY(h1+6,(w-l)/2 -1);	pext(120); gotoXY(h1+6, (w-l)/2 + l); pext(120);
	gotoXY(h1+7,(w-l)/2 -1);  pext(109); for(i=0; i<l; i++) pext(113); pext(106);
	gotoXY(h1+6, (w-l)/2); printf(GREEN"\e[8m");
	scanf("%s", pass);
	gotoXY(h1+8,(w-l)/2);
	printf(RESET BOLD RED "Re-type your password :"BOLD BLUE);
	gotoXY(h1+9,(w-l)/2 -1);	pext(108); for(i=0; i<l; i++) pext(113); pext(107);
	gotoXY(h1+10,(w-l)/2 -1);	pext(120); gotoXY(h1+10, (w-l)/2 + l); pext(120);
	gotoXY(h1+11,(w-l)/2 -1);  pext(109); for(i=0; i<l; i++) pext(113); pext(106);
	gotoXY(h1+10, (w-l)/2); printf(GREEN"\e[8m");
	scanf("%s", verpass);
	printf(RESET);
	U = SearchUser(*LU, id);
	if(U != Nil && strcmp(pass, verpass) == 0)
	{
		gotoXY(h1+12,(w-24)/2);
		printf("\x1b[1m\033[37m""Registration successful.\n"RESET);
		return U;
	}
	while(1)
	{
		gotoXY(h1+12,2);
		printf("\x1b[1m\033[37m");
		for(i = 0; i<98; i++) printf(" ");
		gotoXY(h1+12,(w-l)/2);
		if(U != Nil)
			printf("\x1B[%d;%dfID %s already exists.\n"RESET, h1+12, (w-19-strlen(id))/2, id);
		else
		{
			if(strcmp(pass, verpass) == 0)
			{
				AddUser(LU, id, pass);
				U = SearchUser(*LU, id);
				if(U != Nil)
				{
					printf("\x1B[%d;%dfRegistration successful.\n"RESET, h1+12,(w-24)/2);
					HIDEKURSOR;
					return U;
				}
				else
					printf("\x1B[%d;%dfRegistrasi failed.\n"RESET, h1+12, (w-18)/2);
			}
			else
				printf("\x1B[%d;%dfWrong password verification.\n"RESET,h1+12, (w-28)/2);
		}
		gotoXY(h1+2,(w-l)/2 -1); pext(120); for(i = 0; i<l; i++) printf(" "); pext(120);
		gotoXY(h1+2, (w-l)/2); printf(RESET GREEN);
		scanf("%s", id);
		gotoXY(h1+6, (w-l)/2); printf(RESET GREEN"\e[8m");
		scanf("%s", pass);
		gotoXY(h1+10, (w-l)/2);
		scanf("%s", verpass);
		printf(RESET);
		U = SearchUser(*LU, id);
	}
}
/* skeleton program for play */
void playGame(double seconds, PQueue *PQWord, int *total, int *N)
{	/* Kamus Lokal */
	POINT P;
	MATRIKS MBoard, Mark;
	char cc, ck = 0, word[17], ark[4][18] ={"\e[92m\u21F6>\e[0m","\e[92m\u2505>\e[0m", "\e[91m \u2573\e[0m", "  "};
	time_t T1, T2;
	int detik = seconds, deika = seconds, x = 10, y = 10, i, j;
	boolean play = false;
	Stack StackWord;
	SET SetWord;
	int Score = 0;
	WAKTU time_now;
	
	/* Algoritma */
	CetakBingkai();
	BacaMATRIKS(&MBoard, board_used);
	drawWord(2, 23);
	drawBoard(y, x,MBoard);
	P = MakePOINT(1,1);
	CreateEmpty(&StackWord);
	CreateEmptySet(&SetWord);
	CreateEmptyPQ(PQWord);
	*N = 0;
	sedot(&Mark);
	printf("\x1B[%d;%df%s"RESET, y-2+GetOrdinat(P)*4, x-7+GetAbsis(P)*8,ark[1]);
	gotoXY(8, 43);
	printf("Time remaining:");
	gotoXY(9, 47);
	printf("\e[1;46m %02d:%02d "RESET, (int)seconds / 60, (int)seconds % 60);
	gotoXY(8, 11); printf("Score :");
	gotoXY(9, 13); printf("\e[1;35m%d"RESET, 0);
	gotoXY(8, 82);
	printf("ID :");
	gotoXY(9, 66+(34-strlen(username(User1)))/2);
	printf("\e[1;92m%s"RESET, username(User1));
	gotoXY(11, 58);
	printf("Suggestion word :");
	if(!IsEmptyQ(Suggest))
	{
		gotoXY(13, 64);
		printf("\e[1;92m\t%s"RESET,InfoHead(Suggest));
	}
	gotoXY(15,58);
	printf("Your word :");
	gotoXY(17, 64);
	printf("\e[1;92m\t");
	printf(RESET);
	initTermios(); // initailize new terminal setting to make kbhit() and getch() work
	time(&T1);
	while (detik>0 )
	{
		time(&T2);
		deika = (int)(seconds - difftime(T2,T1));
		if(detik != deika)
		{
			resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
			detik = deika;
			gotoXY(9, 47);
			printf("\e[1;46m %02d:%02d "RESET, detik/60, detik % 60);
			initTermios(); // use new terminal setting again to make kbhit() and getch() work
		}
		if (kbhit())
		{
			cc = getch();
			resetTermios();
			printf("\x1B[%d;%df%s", y-2+GetOrdinat(P)*4, x-7+GetAbsis(P)*8,(play ? ark[2] : ark[3]));
			switch(cc)
			{
				case 'S':
				case 's':
						if (!play)
						{
							play = true;
							ck = 0;
							kursor(&Mark,P,++ck);
							Push(&StackWord, ElMat(MBoard, P));
							printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ElMat(MBoard, P));
						}
						else
						{
							play = false;
							for(; ck>0; ck--)
								printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ' ');
							for(i = 1; i <= 4; i++)
								for(j = 1; j <= 4; j++)
								{
									SetElMat(&Mark, i, j, 100);
									printf("\x1B[%d;%df%s", y-2+i*4, x-7+j*8, ark[3]);
								}
							StackToString(&StackWord, word);
							if(FSearch(DicT, word) && !IsMember(word, SetWord))
							{
								InsertSet(word, &SetWord);
								Score += stringtopoin(word);
								(*N)++;
								AddPQ(PQWord, word, stringtopoin(word));
								gotoXY(9, 13); printf("\e[1;35m%d"RESET, Score);
								while(!IsEmptyQ(Suggest))
									if(IsMember(InfoHead(Suggest),SetWord))
									{
										DelQ(&Suggest, &word);
										gotoXY(13, 64);
										printf("\e[1;92m\t%s"RESET, "                 " );
										if (!IsEmptyQ(Suggest))
										{
											gotoXY(13, 64);
											printf("\e[1;92m\t%s"RESET, InfoHead(Suggest));
										}
									}
									else
										break;
							}
						}
						break;
				case 'R':
				case 'r':
						CwMATRIKS(&MBoard,&Mark);
						P = MakePOINT(5-GetOrdinat(P),GetAbsis(P));
						drawBoard(y,x,MBoard);
						for(i = 1; i<=4; i++)
							for(j = 1; j<=4; j++)
								if(GetElmtMat(Mark,i, j)<ck)
									printf("\x1B[%d;%df%s", y-2+i*4, x-7+j*8, ark[2]);
								else
									if(GetElmtMat(Mark,i, j)>ck)
										printf("\x1B[%d;%df%s", y-2+i*4, x-7+j*8, ark[3]);
									else
										printf("\x1B[%d;%df%s", y-2+i*4, x-7+j*8, (play ? ark[0] : ark[1]));
										
						break;
				case 'A':
				case 'a':
						if(movePoint(&P, -1, 0, 1, 4))
						{
							if(play)
							{
								if(ck>ElMat(Mark, P))
								{
									PopUntil(&StackWord, ElMat(MBoard, P));
									for(;ck>ElMat(Mark, P);ck--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck<GetElmtMat(Mark, i, j))
										{
											SetElMat(&Mark, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark,P,++ck);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ElMat(MBoard, P));
									Push(&StackWord, ElMat(MBoard,P));
								}
							}
						}
						break;
				case 'D':
				case 'd':
						if (movePoint(&P, 1, 0, 1, 4))
						{
							if(play)
							{
								if(ck>ElMat(Mark, P))
								{
									PopUntil(&StackWord, ElMat(MBoard, P));
									for(;ck>ElMat(Mark, P);ck--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ' ');
									ck = ElMat(Mark, P);
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck<GetElmtMat(Mark, i, j))
										{
											SetElMat(&Mark, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark,P,++ck);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ElMat(MBoard, P));
									Push(&StackWord, ElMat(MBoard,P));
								}
							}
						}
						break;
				case 'W':
				case 'w':
						if (movePoint(&P, 0, -1, 1, 4))
						{
							if(play)
							{
								if(ck>ElMat(Mark, P))
								{
									PopUntil(&StackWord, ElMat(MBoard, P));
									for(;ck>ElMat(Mark, P);ck--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck<GetElmtMat(Mark, i, j))
										{
											SetElMat(&Mark, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark,P,++ck);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ElMat(MBoard, P));
									Push(&StackWord, ElMat(MBoard,P));
								}
							}
						}
						break;
				case 'X':
				case 'x':
						if (movePoint(&P, 0, 1, 1, 4))
						{
							if(play)
							{
								if(ck>ElMat(Mark, P))
								{
									PopUntil(&StackWord, ElMat(MBoard, P));
									for(;ck>ElMat(Mark, P);ck--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck<GetElmtMat(Mark, i, j))
										{
											SetElMat(&Mark, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark,P,++ck);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ElMat(MBoard, P));
									Push(&StackWord, ElMat(MBoard,P));
								}
							}
						}
						break;
				case 'Q':
				case 'q':
						if (movePoint(&P, -1, -1, 1, 4))
						{
							if(play)
							{
								if(ck>ElMat(Mark, P))
								{
									PopUntil(&StackWord, ElMat(MBoard, P));
									for(;ck>ElMat(Mark, P);ck--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck<GetElmtMat(Mark, i, j))
										{
											SetElMat(&Mark, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark,P,++ck);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ElMat(MBoard, P));
									Push(&StackWord, ElMat(MBoard,P));
								}
							}
						}
						break;
				case 'E':
				case 'e':
						if (movePoint(&P, 1, -1, 1, 4))
						{
							if(play)
							{
								if(ck>ElMat(Mark, P))
								{
									PopUntil(&StackWord, ElMat(MBoard, P));
									for(;ck>ElMat(Mark, P);ck--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck<GetElmtMat(Mark, i, j))
										{
											SetElMat(&Mark, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark,P,++ck);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ElMat(MBoard, P));
									Push(&StackWord, ElMat(MBoard,P));
								}
							}
						}
						break;
				case 'Z':
				case 'z':
						if (movePoint(&P, -1, 1, 1, 4))
						{
							if(play)
							{
								if(ck>ElMat(Mark, P))
								{
									PopUntil(&StackWord, ElMat(MBoard, P));
									for(;ck>ElMat(Mark, P);ck--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck<GetElmtMat(Mark, i, j))
										{
											SetElMat(&Mark, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark,P,++ck);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ElMat(MBoard, P));
									Push(&StackWord, ElMat(MBoard,P));
								}
							}
						}
						break;
				case 'C':
				case 'c':
						if (movePoint(&P, 1, 1, 1, 4))
						{
							if(play)
							{
								if(ck>ElMat(Mark, P))
								{
									PopUntil(&StackWord, ElMat(MBoard, P));
									for(;ck>ElMat(Mark, P);ck--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck<GetElmtMat(Mark, i, j))
										{
											SetElMat(&Mark, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark,P,++ck);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", 17, 64+ck, ElMat(MBoard, P));
									Push(&StackWord, ElMat(MBoard,P));
								}
							}
						}
						break;
			}
			printf("\x1B[%d;%df%s", y-2+GetOrdinat(P)*4, x-7+GetAbsis(P)*8,(play? ark[0] : ark[1]));
			initTermios(); // use new terminal setting again to make kbhit() and getch() work
		}
		printf(RESET);
		HIDEKURSOR;
	}
	*total = Score;
	UpdateStatistic(board_used, Score,IsEmptyScore(User1));
	CurrentTime(&time_now);
	AddScore(User1, Score, time_now);
	Add1Urut(&AllScore, MakeElmtArray(username(User1), Score, time_now));
	while(!IsEmptyQ(Suggest))
	{
		DelQ(&Suggest, &word);
		InsertSet(word, &SetWord);
	}
	while(!IsEmptySet(SetWord))
	{
		strcpy(word, Info_Set(Elmt(SetWord)));
		DeleteSet(word, &SetWord);
		AddQ(&Suggest, word);
	}
	resetTermios(); // restore default terminal setting
}

void drawWord(int r, int b)
{
	gotoXY(r,b);   printf(BOLD"\e[94m ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ");
	gotoXY(r+1,b); printf("||\e[31mW\e[94m |||\e[33mO\e[94m |||\e[34mR\e[94m |||\e[35mD\e[94m |||\e[36mA\e[94m |||\e[37mM\e[94m |||\e[90mE\e[94m |||\e[91mN\e[94m |||\e[92mT\e[94m |||\e[93m-\e[94m |||\e[94m0\e[94m ||");
	gotoXY(r+2,b); printf("||__|||__|||__|||__|||__|||__|||__|||__|||__|||__|||__||");
	gotoXY(r+3,b); printf("|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|"RESET);
}

void drawBoard(int r, int b, MATRIKS M)
{
	indeks i, j;
	gotoXY(r,b);
	printf(BOLD YELLOW"\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2566");
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
	printf("\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255d\n"RESET);
	for(i = 1; i<= 4; i++)
		for(j = 1; j<=4; j++)
			phuruf(GetElmtMat(M, i, j),r-3+i*4, b+8*j-5);
	gotoXY(r+2, b+10);
}

void phuruf(char c, int x, int y)
{
	gotoXY(x, y);
	printf(BOLD"\e[96m");
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
	printf(RESET);
}

void printAbout()
{
	int i;
	CetakBingkai();
	gotoXY(2,2);
	for(i=1; i<=3; i++) printf("\n");printf(BOLD);
	printf(RESET"\u2503"); for(i=2; i<=37; i++) printf(" ");printf(RED".________________________  \n");
	printf(RESET"\u2503"); for(i=2; i<=37; i++) printf(" ");printf(RED"|   \\__    ___/\\______   \\ \n");
	printf(RESET"\u2503"); for(i=2; i<=37; i++) printf(" ");printf(RED"|   | |    |    |    |  _/ \n");
	printf(RESET"\u2503"); for(i=2; i<=37; i++) printf(" ");printf("|   | |    |    |    |   \\ \n");
	printf(RESET"\u2503"); for(i=2; i<=37; i++) printf(" ");printf("|___| |____|    |______  / \n");
	printf(RESET"\u2503"); for(i=2; i<=37; i++) printf(" ");printf("                       \\/  \n");
	printf(RESET);
	
	for(i=1; i<=2; i++) printf("\n");
	printf("\u2503"); 
	for(i=2; i<=99; i++) printf("\u25c8");
	printf("\u2503"); 
	for(i=1; i<=3; i++) printf("\n");
	printf(RESET"\u2503"); for(i=2; i<=37; i++) printf(" ");printf(BOLD "Wiwit Rifa'i nim(13513073)\n"RESET);
	printf(RESET"\u2503"); for(i=2; i<=35; i++) printf(" ");printf(BOLD "Miftahul Mahfuzh nim(13513017)\n"RESET);
	printf(RESET"\u2503"); for(i=2; i<=32; i++) printf(" ");printf(BOLD "Muhammad Aodyra Khaidir nim(13513063)\n"RESET);
	printf(RESET"\u2503"); for(i=2; i<=31; i++) printf(" ");printf(BOLD "Muhammad Ginanjar Busiri nim(xxxxxxxx)\n"RESET);
	printf(RESET"\u2503"); for(i=2; i<=33; i++) printf(" ");printf(BOLD "Ahmad Rizdaputra Scemo nim(xxxxxxxx)\n"RESET);
	for(i=1; i<=4; i++) printf("\n");
	printf("\u2503"); for(i=2; i<=35; i++) printf(" ");printf("Press any key to main menu.....");
	gotoXY(29, 99);
//	scanf("%*c");
	pressKey();
}

int selectBoard(int before)
{
	int i=0, no = before;
	MATRIKS MBoard;
	char arah;
	
	clrscr;
	printf("\e[8;%d;%d;t", (30), (100));
	HIDEKURSOR;
	
	printf("\u259a");

	gotoXY(3,15);printf(" ___  ____  __    ____  ___  ____    ____  _____    __    ____  ____  ");
	gotoXY(4,15);printf("/ __)( ___)(  )  ( ___)/ __)(_  _)  (  _ \\(  _  )  /__\\  (  _ \\(  _ \\ ");
	gotoXY(5,15);printf("\\__ \\ )__)  )(__  )__)( (__   )(     ) _ < )(_)(  /(__)\\  )   / )(_) )");
	gotoXY(6,15);printf("(___/(____)(____)(____)\\___) (__)   (____/(_____)(__)(__)(_)\\_)(____/ ");

	
	gotoXY(9,43);printf("\uE694");
	gotoXY(9,46);printf(BOLD GREEN "BOARD %d",no);printf(RESET);
	gotoXY(9,54);printf("\uE695");
	
	gotoXY(1,1);printberkali(100,"\u259a");
	for(i=1; i<=28; i++){
		gotoXY(i,1);printf("\u259a");gotoXY(i,100);printf("\u259a");
	}
	gotoXY(9,67);printf("klik arah -> pada keyboard untuk");
	gotoXY(10,67);printf("ke board selanjutnya");
	gotoXY(9,3);printf("klik arah <- pada keyboard untuk");
	gotoXY(10,3);printf("ke board sebelumnya");
	gotoXY(29,1);printberkali(100,"\u259a");
	BacaMATRIKS(&MBoard,no);
	drawBoard(11,33,MBoard);
	while(1){
		initTermios();
		arah=getch();
		resetTermios();
		if(arah==27){
			initTermios();
			arah=getch();
			arah=getch();
			resetTermios();
			switch(arah){
				case 'C':
					no = (no+1)%10;
					gotoXY(9,43);printf("\uE694 ");
					gotoXY(9,54);printf(RED "\uE695 " RESET);
					
				break;
				case 'D':
					no = (no+9) % 10;
					gotoXY(9,43);printf(RED "\uE694 " RESET);
					gotoXY(9,54);printf("\uE695 ");
				break;
				case '\n':
				break;
			}
		}
		else if(arah=='\n')
			break;
		gotoXY(9,46);printf(BOLD GREEN "BOARD %d",no);printf(RESET);
		BacaMATRIKS(&MBoard,no);
		drawBoard(11,33,MBoard);
	}
	return no;
}
void printHow()
{ // cetak how to play
	/*kamus lokal*/
	int i;
	/*algoritma*/
	CetakBingkai();
	gotoXY(4,32); printf(BOLD"<- HOW TO PLAY THIS AWESOME GAME ->"RESET);
	gotoXY(6,8); printf("U really need to read this before you play our ouija board. Read carefully before u");
	gotoXY(7,8); f(i,8,90) printf("\u2501"); // pint line
	gotoXY(8,24); printf("take your first step to your biggest adventure ever");
	gotoXY(9,24); f(i,8,58) printf("\u2501"); // print line
	gotoXY(11,11); printf("[First, Register your ID. pick a cool name, you can choose max 14 characters]");
	// gotoXY(12,24); f(i,8,58) printf("\u2501"); // print line
	gotoXY(13,13); printf("[Next, Choose a board. if you don`t, we will give the 1st board for you]");
	// gotoXY(14,26); f(i,8,54) printf("\u2501"); // print line
	gotoXY(15,18); printf("[Then, play it. if you dont know how, read instructions below]");
	// gotoXY(16,28); f(i,8,50) printf("\u2501"); // print line
	gotoXY(18,39); printf("Instructions-Keyboard");
	gotoXY(19,39); f(i,8,28) printf(BOLD"="RESET); // print line
	/*instructions-keyboard*/
	gotoXY(20,34); printf("R -> Rotate the board clockwise");
	gotoXY(21,34); f(i,34,64) printf(BOLD"-"RESET); // print line
	gotoXY(22,25); printf("Q,W,E,A,D,Z,X,C -> Move the cursor on the board");
	gotoXY(23,25); f(i,30,76) printf(BOLD"-"RESET); // print line
	gotoXY(24,7); printf("S -> Toggle word (change if you want to start to make a word, or just move the cursor)");
	gotoXY(25,7); f(i,34,119) printf(BOLD"-"RESET); // print line
	gotoXY(26,34); printf("Ctrl(hold) + C -> Quit the game");
	gotoXY(27,34); f(i,30,60) printf(BOLD"-"RESET); // print line
	gotoXY(29,2);
	/*AGAIN*/
	gotoXY(29,3); printf("\u25C4  "BOLD"\e[4mBACK 2 MENU"RESET);
	pressKey();
}
int printAllScore(TabInt * T)
{
	/* Kamus Lokal */
	int i, j, n = 10, pil = 0;
	char cc;
	infotype_array X;
	/* Algoritma */
	CetakBingkai();
	gotoXY(4,41);	printf(BOLD "<< HALL OF FAME >>" RESET);
	/* Cetak Baris pertama */
	gotoXY(7,22);	printf(BOLD "NO" RESET);
	gotoXY(7,33);	printf(BOLD "ID" RESET);
	gotoXY(7,47);	printf(BOLD "SCORES" RESET);
	gotoXY(7,68);	printf(BOLD "WHEN" RESET);
	gotoXY(8,22); for (i=1;i<=58;i++) printf("\u2501");
	gotoXY(5,70); printf("Board : %d", board_used);
	/* Cetak per skor */
	if(NbElmt(*T)<n)
		n = NbElmt(*T);
	for(i = 1; i<= n; i++)
	{
		gotoXY(7+2*i,22);
		printf("%02d  %s", i, GetElmt(*T,i).username);
		gotoXY(7+2*i,47);
		printf("%06d", GetElmt(*T,i).score_value);
		gotoXY(7+2*i,60);
		TulisWaktu(GetElmt(*T,i).time_get);
	}
	return selectBack();
}
void CetakBingkai()
{// cetak kotak tebel (bingkai)
	/*kamus lokal*/
	int i,j,k;
	/*algoritma*/
	clrscr;
	
	/*cetak ukuran layar*/
	printf("\e[8;%d;%d;t",(30),(100));
	
	/*cetak atap*/
	printf("\u250f"); for (i=1;i<=98;i++) printf("\u2501"); printf("\u2513");
	
	/*cetak dinding kiri kanan*/
	for (i =2;i<=29;i++) {
	printf("\u2503"); gotoXY(i,100); printf("\u2503");}
	
	/*cetak alas*/
	printf("\u2517"); for (i=1;i<=98;i++) printf("\u2501"); printf("\u251b");
}
int printMyScore(adrUser U)
{
	/* Kamus Lokal */
	int i;
	adrScore S, P;
	/* Algoritma */
	CetakBingkai();
	gotoXY(4,41); printf(BOLD "<< MY HIGHSCORE >>" RESET);
	gotoXY(5,27); printf("ID : %s", username(U));
	gotoXY(5,66); printf("Board : %d", board_used);
	/* Cetak Baris pertama */
	gotoXY(7,27); printf(BOLD "NO          SCORES                  WHEN" RESET);
	gotoXY(8,27); for (i=1;i<=48;i++) printf("\u2501");
	/* Cetak per skor */
	S = FirstScore(U);
	for(i = 1; i<= 10 && S != Nil; i++)
	{
		gotoXY(7+2*i,27);
		printf("%02d          %06d          ", i, value(S));
		TulisWaktu(time_score(S));
		S = NextScore(S);
	}
	while(S != Nil)
	{
		P = S;
		S = NextScore(S);
		DelScore(U, P);
	}
	return selectBack();
}
int selectBack()
{
	int pil;
	char cc;
	gotoXY(29,3); printf("\u25C4  "BOLD"\e[4mBACK 2 PREV MENU"RESET);
	gotoXY(29,88); printf("\u27F0""  LOG OUT"RESET);
   	initTermios();
   	cc = pil = 0;
    while(cc != '\n')
    {
    		cc = getch();
    		if(cc == 27)
    		{
    			cc = getch();
    			cc = getch();
    			resetTermios();
    			pil ^= 1;
    			if(pil)
    			{
					gotoXY(29,3); printf("\u25C4  ""BACK 2 PREV MENU"RESET);
					gotoXY(29,88); printf("\u27F0"BOLD"  \e[4mLOG OUT"RESET);
    			}
    			else
    			{
					gotoXY(29,3); printf("\u25C4  "BOLD"\e[4mBACK 2 PREV MENU"RESET);
					gotoXY(29,88); printf("\u27F0""  LOG OUT"RESET);
    			}
    			initTermios();
    		}
    }
    resetTermios();
	return pil;
}
/* skeleton program for play */
void DualPlayer(double seconds, int no_1, int no_2, int *total1, int *total2)
{	/* Kamus Lokal */
	POINT P1, P2;
	MATRIKS Board1, Mark1, Board2, Mark2;
	char cc, ck1 = 0, ck2 = 0, word[17], ark[4][18] ={"\e[92m\u21F6>\e[0m","\e[92m\u2505>\e[0m", "\e[91m \u2573\e[0m", "  "};
	time_t T1, T2;
	int detik = seconds, deika = seconds, x1 = 10, y = 10, x2 = 59, i, j;
	boolean play1 = false, play2 = false;
	Stack StackWord1, StackWord2;
	SET SetWord1, SetWord2;
	int Score1 = 0, Score2 = 0;

	/* Algoritma */
	CetakBingkai();
	BacaMATRIKS(&Board1, no_1);
	BacaMATRIKS(&Board2, no_2);
	drawWord(2, 22);
	drawBoard(y, x1, Board1);
	drawBoard(y, x2, Board2);
	P1 = MakePOINT(1,1);
	P2 = MakePOINT(1,1);
	CreateEmpty(&StackWord1);
	CreateEmpty(&StackWord2);
	CreateEmptySet(&SetWord1);
	CreateEmptySet(&SetWord2);
	gotoXY(y-1,x1);printf(BOLD RED "Player 1" RESET);
	gotoXY(y-1,x2);printf(BOLD BLUE "Player 2" RESET);
	gotoXY(y+2,44);printf(RED BOLD"Score Player 1" RESET);
	gotoXY(y+5,44);printf("    %06d    ", Score1);
	gotoXY(y+9,44);printf(BLUE BOLD"Score Player 2" RESET);
	gotoXY(y+12,44);printf("    %06d    ", Score2);
	gotoXY(y+17,x1);printf("Player 1 Word : ");
	gotoXY(y+17,x2);printf("Player 2 Word : ");
	sedot(&Mark1);
	sedot(&Mark2);
	printf("\x1B[%d;%df%s"RESET, y-2+GetOrdinat(P1)*4, x1-7+GetAbsis(P1)*8,ark[1]);
	printf("\x1B[%d;%df%s"RESET, y-2+GetOrdinat(P2)*4, x2-7+GetAbsis(P2)*8,ark[1]);
	gotoXY(y-1,47);
	printf("\e[1;46m %02d:%02d "RESET, (int)seconds / 60, (int)seconds % 60);
	printf(RESET);
	initTermios(); // initailize new terminal setting to make kbhit() and getch() work
	detik = deika = seconds;
	time(&T1);
	while (detik>0 )
	{
		time(&T2);
		deika = (int)(seconds - difftime(T2,T1));
		if(detik != deika)
		{
			resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
			detik = deika;
			gotoXY(y-1, 47);
			printf("\e[1;46m %02d:%02d "RESET, detik/60, detik % 60);
			initTermios(); // use new terminal setting again to make kbhit() and getch() work
		}
		if (kbhit())
		{
			cc = getch();
			resetTermios();
			printf("\x1B[%d;%df%s", y-2+GetOrdinat(P1)*4, x1-7+GetAbsis(P1)*8,(play1 ? ark[2] : ark[3]));
			printf("\x1B[%d;%df%s", y-2+GetOrdinat(P2)*4, x2-7+GetAbsis(P2)*8,(play2 ? ark[2] : ark[3]));
			switch(cc)
			{
				case 'S':
				case 's':
						if (!play1)
						{
							play1 = true;
							ck1 = 0;
							kursor(&Mark1,P1,++ck1);
							Push(&StackWord1, ElMat(Board1, P1));
							printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ElMat(Board1, P1));
						}
						else
						{
							play1 = false;
							for(; ck1>0; ck1--)
								printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ' ');
							for(i = 1; i <= 4; i++)
								for(j = 1; j <= 4; j++)
								{
									SetElMat(&Mark1, i, j, 100);
									printf("\x1B[%d;%df%s", y-2+i*4, x1-7+j*8, ark[3]);
								}
							StackToString(&StackWord1, word);
							if(FSearch(DicT, word) && !IsMember(word, SetWord1))
							{
								InsertSet(word, &SetWord1);
								Score1 += stringtopoin(word);
								gotoXY(y+5,44);printf("    %06d    ", Score1);
							}
						}
						break;
				case 'H':
				case 'h':
						if (!play2)
						{
							play2 = true;
							ck2 = 0;
							kursor(&Mark2,P2,++ck2);
							Push(&StackWord2, ElMat(Board2, P2));
							printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ElMat(Board2, P2));
						}
						else
						{
							play2 = false;
							for(; ck2>0; ck2--)
								printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ' ');
							for(i = 1; i <= 4; i++)
								for(j = 1; j <= 4; j++)
								{
									SetElMat(&Mark2, i, j, 100);
									printf("\x1B[%d;%df%s", y-2+i*4, x2-7+j*8, ark[3]);
								}
							StackToString(&StackWord2, word);
							if(FSearch(DicT, word) && !IsMember(word, SetWord2))
							{
								InsertSet(word, &SetWord2);
								Score2 += stringtopoin(word);
								gotoXY(y+12,44);printf("    %06d    ", Score2);
							}
						}
						break;
				case 'R':
				case 'r':
						CwMATRIKS(&Board1,&Mark1);
						P1 = MakePOINT(5-GetOrdinat(P1),GetAbsis(P1));
						drawBoard(y,x1,Board1);
						for(i = 1; i<=4; i++)
							for(j = 1; j<=4; j++)
								if(GetElmtMat(Mark1,i, j)<ck1)
									printf("\x1B[%d;%df%s", y-2+i*4, x1-7+j*8, ark[2]);
								else
									if(GetElmtMat(Mark1,i, j)>ck1)
										printf("\x1B[%d;%df%s", y-2+i*4, x1-7+j*8, ark[3]);
									else
										printf("\x1B[%d;%df%s", y-2+i*4, x1-7+j*8, (play1 ? ark[0] : ark[1]));
										
						break;
				case 'I':
				case 'i':
						CwMATRIKS(&Board2,&Mark2);
						P2 = MakePOINT(5-GetOrdinat(P2),GetAbsis(P2));
						drawBoard(y,x2,Board2);
						for(i = 1; i<=4; i++)
							for(j = 1; j<=4; j++)
								if(GetElmtMat(Mark2,i, j)<ck2)
									printf("\x1B[%d;%df%s", y-2+i*4, x2-7+j*8, ark[2]);
								else
									if(GetElmtMat(Mark2,i, j)>ck2)
										printf("\x1B[%d;%df%s", y-2+i*4, x2-7+j*8, ark[3]);
									else
										printf("\x1B[%d;%df%s", y-2+i*4, x2-7+j*8, (play2 ? ark[0] : ark[1]));
										
						break;
				case 'A':
				case 'a':
						if(movePoint(&P1, -1, 0, 1, 4))
						{
							if(play1)
							{
								if(ck1>ElMat(Mark1, P1))
								{
									PopUntil(&StackWord1, ElMat(Board1, P1));
									for(;ck1>ElMat(Mark1, P1);ck1--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck1<GetElmtMat(Mark1, i, j))
										{
											SetElMat(&Mark1, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x1-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark1,P1,++ck1);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ElMat(Board1, P1));
									Push(&StackWord1, ElMat(Board1,P1));
								}
							}
						}
						break;
				case 'G':
				case 'g':
						if(movePoint(&P2, -1, 0, 1, 4))
						{
							if(play2)
							{
								if(ck2>ElMat(Mark2, P2))
								{
									PopUntil(&StackWord2, ElMat(Board2, P2));
									for(;ck2>ElMat(Mark2, P2);ck2--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck2<GetElmtMat(Mark2, i, j))
										{
											SetElMat(&Mark2, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x2-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark2,P2,++ck2);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ElMat(Board2, P2));
									Push(&StackWord2, ElMat(Board2,P2));
								}
							}
						}
						break;
				case 'D':
				case 'd':
						if (movePoint(&P1, 1, 0, 1, 4))
						{
							if(play1)
							{
								if(ck1>ElMat(Mark1, P1))
								{
									PopUntil(&StackWord1, ElMat(Board1, P1));
									for(;ck1>ElMat(Mark1, P1);ck1--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck1<GetElmtMat(Mark1, i, j))
										{
											SetElMat(&Mark1, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x1-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark1,P1,++ck1);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ElMat(Board1, P1));
									Push(&StackWord1, ElMat(Board1,P1));
								}
							}
						}
						break;
				case 'J':
				case 'j':
						if (movePoint(&P2, 1, 0, 1, 4))
						{
							if(play2)
							{
								if(ck2>ElMat(Mark2, P2))
								{
									PopUntil(&StackWord2, ElMat(Board2, P2));
									for(;ck2>ElMat(Mark2, P2);ck2--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck2<GetElmtMat(Mark2, i, j))
										{
											SetElMat(&Mark2, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x2-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark2,P2,++ck2);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ElMat(Board2, P2));
									Push(&StackWord2, ElMat(Board2,P2));
								}
							}
						}
						break;
				case 'W':
				case 'w':
						if (movePoint(&P1, 0, -1, 1, 4))
						{
							if(play1)
							{
								if(ck1>ElMat(Mark1, P1))
								{
									PopUntil(&StackWord1, ElMat(Board1, P1));
									for(;ck1>ElMat(Mark1, P1);ck1--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck1<GetElmtMat(Mark1, i, j))
										{
											SetElMat(&Mark1, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x1-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark1,P1,++ck1);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ElMat(Board1, P1));
									Push(&StackWord1, ElMat(Board1,P1));
								}
							}
						}
						break;
				case 'Y':
				case 'y':
						if (movePoint(&P2, 0, -1, 1, 4))
						{
							if(play2)
							{
								if(ck2>ElMat(Mark2, P2))
								{
									PopUntil(&StackWord2, ElMat(Board2, P2));
									for(;ck2>ElMat(Mark2, P2);ck2--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck2<GetElmtMat(Mark2, i, j))
										{
											SetElMat(&Mark2, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x2-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark2,P2,++ck2);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ElMat(Board2, P2));
									Push(&StackWord2, ElMat(Board2,P2));
								}
							}
						}
						break;
				case 'X':
				case 'x':
						if (movePoint(&P1, 0, 1, 1, 4))
						{
							if(play1)
							{
								if(ck1>ElMat(Mark1, P1))
								{
									PopUntil(&StackWord1, ElMat(Board1, P1));
									for(;ck1>ElMat(Mark1, P1);ck1--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck1<GetElmtMat(Mark1, i, j))
										{
											SetElMat(&Mark1, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x1-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark1,P1,++ck1);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ElMat(Board1, P1));
									Push(&StackWord1, ElMat(Board1,P1));
								}
							}
						}
						break;
				case 'N':
				case 'n':
						if (movePoint(&P2, 0, 1, 1, 4))
						{
							if(play2)
							{
								if(ck2>ElMat(Mark2, P2))
								{
									PopUntil(&StackWord2, ElMat(Board2, P2));
									for(;ck2>ElMat(Mark2, P2);ck2--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck2<GetElmtMat(Mark2, i, j))
										{
											SetElMat(&Mark2, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x2-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark2,P2,++ck2);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ElMat(Board2, P2));
									Push(&StackWord2, ElMat(Board2,P2));
								}
							}
						}
						break;
				case 'Q':
				case 'q':
						if (movePoint(&P1, -1, -1, 1, 4))
						{
							if(play1)
							{
								if(ck1>ElMat(Mark1, P1))
								{
									PopUntil(&StackWord1, ElMat(Board1, P1));
									for(;ck1>ElMat(Mark1, P1);ck1--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck1<GetElmtMat(Mark1, i, j))
										{
											SetElMat(&Mark1, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x1-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark1,P1,++ck1);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ElMat(Board1, P1));
									Push(&StackWord1, ElMat(Board1,P1));
								}
							}
						}
						break;
				case 'T':
				case 't':
						if (movePoint(&P2, -1, -1, 1, 4))
						{
							if(play2)
							{
								if(ck2>ElMat(Mark2, P2))
								{
									PopUntil(&StackWord2, ElMat(Board2, P2));
									for(;ck2>ElMat(Mark2, P2);ck2--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck2<GetElmtMat(Mark2, i, j))
										{
											SetElMat(&Mark2, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x2-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark2,P2,++ck2);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ElMat(Board2, P2));
									Push(&StackWord2, ElMat(Board2,P2));
								}
							}
						}
						break;
				case 'E':
				case 'e':
						if (movePoint(&P1, 1, -1, 1, 4))
						{
							if(play1)
							{
								if(ck1>ElMat(Mark1, P1))
								{
									PopUntil(&StackWord1, ElMat(Board1, P1));
									for(;ck1>ElMat(Mark1, P1);ck1--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck1<GetElmtMat(Mark1, i, j))
										{
											SetElMat(&Mark1, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x1-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark1,P1,++ck1);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ElMat(Board1, P1));
									Push(&StackWord1, ElMat(Board1,P1));
								}
							}
						}
						break;
				case 'U':
				case 'u':
						if (movePoint(&P2, 1, -1, 1, 4))
						{
							if(play2)
							{
								if(ck2>ElMat(Mark2, P2))
								{
									PopUntil(&StackWord2, ElMat(Board2, P2));
									for(;ck2>ElMat(Mark2, P2);ck2--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck2<GetElmtMat(Mark2, i, j))
										{
											SetElMat(&Mark2, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x2-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark2,P2,++ck2);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ElMat(Board2, P2));
									Push(&StackWord2, ElMat(Board2,P2));
								}
							}
						}
						break;
				case 'Z':
				case 'z':
						if (movePoint(&P1, -1, 1, 1, 4))
						{
							if(play1)
							{
								if(ck1>ElMat(Mark1, P1))
								{
									PopUntil(&StackWord1, ElMat(Board1, P1));
									for(;ck1>ElMat(Mark1, P1);ck1--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck1<GetElmtMat(Mark1, i, j))
										{
											SetElMat(&Mark1, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x1-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark1,P1,++ck1);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ElMat(Board1, P1));
									Push(&StackWord1, ElMat(Board1,P1));
								}
							}
						}
						break;
				case 'B':
				case 'b':
						if (movePoint(&P2, -1, 1, 1, 4))
						{
							if(play2)
							{
								if(ck2>ElMat(Mark2, P2))
								{
									PopUntil(&StackWord2, ElMat(Board2, P2));
									for(;ck2>ElMat(Mark2, P2);ck2--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck2<GetElmtMat(Mark2, i, j))
										{
											SetElMat(&Mark2, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x2-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark2,P2,++ck2);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ElMat(Board2, P2));
									Push(&StackWord2, ElMat(Board2,P2));
								}
							}
						}
						break;
				case 'C':
				case 'c':
						if (movePoint(&P1, 1, 1, 1, 4))
						{
							if(play1)
							{
								if(ck1>ElMat(Mark1, P1))
								{
									PopUntil(&StackWord1, ElMat(Board1, P1));
									for(;ck1>ElMat(Mark1, P1);ck1--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck1<GetElmtMat(Mark1, i, j))
										{
											SetElMat(&Mark1, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x1-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark1,P1,++ck1);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x1+15+ck1, ElMat(Board1, P1));
									Push(&StackWord1, ElMat(Board1,P1));
								}
							}
						}
						break;
				case 'M':
				case 'm':
						if (movePoint(&P2, 1, 1, 1, 4))
						{
							if(play2)
							{
								if(ck2>ElMat(Mark2, P2))
								{
									PopUntil(&StackWord2, ElMat(Board2, P2));
									for(;ck2>ElMat(Mark2, P2);ck2--)
										printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ' ');
									for(i = 1; i <= 4; i++)
										for(j = 1; j <= 4; j++)
										if(ck2<GetElmtMat(Mark2, i, j))
										{
											SetElMat(&Mark2, i, j, 100);
											printf("\x1B[%d;%df%s", y-2+i*4, x2-7+j*8,ark[3]);
										}
								}
								else
								{
									kursor(&Mark2,P2,++ck2);
									printf("\x1B[%d;%df\e[1;92m%c\e[0m", y+17, x2+15+ck2, ElMat(Board2, P2));
									Push(&StackWord2, ElMat(Board2,P2));
								}
							}
						}
						break;
			}
			printf("\x1B[%d;%df%s", y-2+GetOrdinat(P1)*4, x1-7+GetAbsis(P1)*8,(play1? ark[0] : ark[1]));
			printf("\x1B[%d;%df%s", y-2+GetOrdinat(P2)*4, x2-7+GetAbsis(P2)*8,(play2? ark[0] : ark[1]));
			initTermios(); // use new terminal setting again to make kbhit() and getch() work
		}
		printf(RESET);
		HIDEKURSOR;
		gotoXY(100,100);
	}
	resetTermios(); // restore default terminal setting
	*total1 = Score1;
	*total2 = Score2;
}
int printScoreWord(PQueue * PQ, int total, int N)
/* cetak score board setelah time up */
{  
	/*kamus lokal*/
	int i,j,k,pr, pil, mod;
	char cc;
	infotype X;
	/*algoritma*/
	HIDEKURSOR;
	pil = 0;
	while(pil != 1 && pil != 2)
	{
		CetakBingkai();
		gotoXY(3,41); printf(BOLD "YOUR TIME`S UP, PAL.." RESET);	
		gotoXY(4,41); f(i,1,21) printf("-");
		gotoXY(5,42); printf("try again next time");

		/*TOTAL SCORE*/
		gotoXY(7,42); printf(BOLD"TOTAL SCORE : %d"RESET, total);		

		/*1ST COL*/
		gotoXY(9,8); printf(BOLD "WORDS MADE" RESET);
		gotoXY(9,27); printf(BOLD "SCORE" RESET);
	
		/*SEPARATOR*/
		for (i =9;i<=27;i++) {gotoXY(i,35); printf("|");}

		/*2ND COL*/
		gotoXY(9,39); printf(BOLD "WORDS MADE" RESET);
		gotoXY(9,58); printf(BOLD "SCORE" RESET);
	
		/*SEPARATOR*/
		for (i =9;i<=27;i++) {gotoXY(i,66); printf("|");}

		/*3RD COL*/
		gotoXY(9,69); printf(BOLD "WORDS MADE " RESET);
		gotoXY(9,88); printf(BOLD "SCORE" RESET);

		/*WHAT BOARD?*/
		gotoXY(2,4); printf(BOLD"BOARD %s - %s"RESET, num[board_used], level[rankBoard[board_used]-1]);

		/*ALL WORDS IN TABLE*/
		gotoXY(2,77); printf(BOLD"\e[4mALL WORDS IN BOARD "RESET"\uE023");

		/*NEXT PAGE*/
		if(N>27)
		{
			gotoXY(29,46); printf("NEXT PAGE ""\u22b3"RESET);
		}
	
		/*AGAIN*/
		gotoXY(29,4); printf("I`M NOT DONE YET, LET`S TRY AGAIN "RESET"\u21BA");
	
		/*LOG OUT*/
		gotoXY(29,66); printf("\u27F0""  THIS IS SHIT. I WANNA GET OUT"RESET);

		/*CHECK WORD OUTPUT*/
		/*first col*/
		do{
			if(pil == 3 && N<=27)
			{
				pil = 0;			
				gotoXY(29,46); printf("           "RESET);
			}
			j = 11;
			i = 8;
			mod =  (N>27 ? 3 : 2);
			while(!IsEmptyPQ(*PQ) && i <= 69)
			{
				DelPQ(PQ, &X, &pr);
				N--;
				gotoXY(j,i);
				printf("%s",X);
				for(k = strlen(X); k<16; k++ )
					printf("-");
				printf("   %06d",pr);
				j += 2;
				if(j > 27)
				{
					j = 11;
					switch(i)
					{
						case 8 : i = 39; break;
						case 39 : i = 69; break;
						default : i = 101;
					}
				}
			}
			while(i <= 69)
			{
				gotoXY(j,i);
				printf("----------------",X);
				printf("   %06d",0);
				j += 2;
				if(j > 27)
				{
					j = 11;
					switch(i)
					{
						case 8 : i = 39; break;
						case 39 : i = 69; break;
						default : i = 101;
					}
				}
			}
		   	initTermios();
		   	cc = 0;
			while(cc != '\n')
			{
					cc = getch();
					if(cc == 27)
					{
						cc = getch();
						cc = getch();
						resetTermios();
						if(pil == 0)
						{
							if(cc == 'A' || cc == 'B')
							{
								pil = mod;
								gotoXY(2,77); printf(BOLD"ALL WORDS IN BOARD "RESET"\uE023");
							}		 			
						}
						else
						{
							switch(pil)
							{
								case 1 : gotoXY(29,4); printf("I`M NOT DONE YET, LET`S TRY AGAIN "RESET"\u21BA"); break;
								case 3 : gotoXY(29,46); printf("NEXT PAGE ""\u22b3"RESET); break;
								case 2 : gotoXY(29,66); printf("\u27F0""  THIS IS SHIT. I WANNA GET OUT"RESET); break;
							}
							if(cc == 'A' || cc == 'B')
								pil = 0;
							else if(cc == 'C')
								pil = ((pil + mod-2) % mod)+1;
							else if(cc == 'D')
								pil = (pil % mod) + 1;
						}
						switch(pil)
						{
							case 0 : gotoXY(2,77); printf(BOLD"\e[4mALL WORDS IN BOARD \uE023"RESET);break;
							case 3 : gotoXY(29,46); printf(BOLD"\e[4mNEXT PAGE \u22b3"RESET); break;
							case 1 : gotoXY(29,4); printf(BOLD"\e[4mI`M NOT DONE YET, LET`S TRY AGAIN \u21BA"RESET); break;
							case 2 : gotoXY(29,66); printf(BOLD"\e[4m\u27F0  THIS IS SHIT. I WANNA GET OUT"RESET); break;
						}
						initTermios();
					}
			}
			resetTermios();
		} while(pil == 3);
		if(pil == 0)
			if(printBoardWord() == 3)
				pil = 2;
	}
	while(!IsEmptyPQ(*PQ))
		DelPQ(PQ,&X,&pr);
    resetTermios();
    return pil;
}
void BacaStatistic()
{	/* Kamus Lokal */
	int i, bul, des;
	/* Algoritma */
	STARTKATA("BoardStatistic.txt");
	for(i = 0; i<10; i++)
	{
		KataToInt(&bul);
		ADVKATA();
		KataToInt(&des);
		ADVKATA();
		avgBoard[i] = (double) bul + (double) des/1000;
		KataToInt(&NPlayBoard[i]);
		ADVKATA();
		KataToInt(&NPlayerBoard[i]);
		ADVKATA();
		KataToInt(&rankBoard[i]);
		ADVKATA();
	}
}
void TulisStatistic()
{	/* Kamus Lokal */
	int i, bul, des;
	/* Algoritma */
	STARTWrite("BoardStatistic.txt");
	for(i = 0; i<10; i++)
	{
		bul = (int)avgBoard[i];
		des = (int)(avgBoard[i]*1000) % 1000;
		WritePitaInt(bul);
		WritePita(" ");
		WritePitaInt(des);
		WritePita(" ");
		WritePitaInt(NPlayBoard[i]);
		WritePita(" ");
		WritePitaInt(NPlayerBoard[i]);
		WritePita(" ");
		WritePitaInt(rankBoard[i]);
		WritePita("\n");
	}
	WritePita(".\n");
}
void UpdateStatistic(int no_board, int score, boolean IsNew)
{
	int tempRank[10], i, temp;
	for(i = 0; i<10; i++)
		tempRank[rankBoard[i]-1] = i;
	if(IsNew)
		NPlayerBoard[no_board]++;
	avgBoard[no_board] = (avgBoard[no_board]*NPlayBoard[no_board] + score)/(NPlayBoard[no_board]+1);
	NPlayBoard[no_board]++;
	i = rankBoard[no_board]-1;
	while(i<9)
	{
		if(avgBoard[tempRank[i]]>avgBoard[tempRank[i+1]])
		{
			temp = tempRank[i];
			tempRank[i] = tempRank[i+1];
			tempRank[i+1] = temp;
			i++;
		}
		else
			break;
	}
	while(i>0)
	{
		if(avgBoard[tempRank[i]]<avgBoard[tempRank[i-1]])
		{
			temp = tempRank[i];
			tempRank[i] = tempRank[i-1];
			tempRank[i-1] = temp;
			i--;
		}
		else
			break;
	}
	for(i = 0; i<10; i++)
		rankBoard[tempRank[i]] = i+1;
}
int ViewBoardStatistic(int no_board)
{
		/*kamus lokal*/
	int i,j;
	/*algoritma*/
	CetakBingkai();
	/*WHAT BOARD?*/
	gotoXY(2,4); printf(BOLD"BOARD %s - %s"RESET, num[no_board], level[rankBoard[no_board]-1]);

	/*PRINT FRAME*/
	/*first horizontal line*/
	gotoXY(9,17);
	f(i,1,34) printf("\u25A7 ");
	/*second horizontal line*/
	gotoXY(11,17);
	f(i,1,34) printf("\u25A7 ");
	/*lowest horizontal line*/
	gotoXY(19,17);
	f(i,1,34) printf("\u25A7 ");
	/*left vertical line*/
	for (i =9;i<=19;i++) {gotoXY(i,17); printf("\u25A7");}
	/*right vertical line*/
	for (i =9;i<=19;i++) {gotoXY(i,83); printf("\u25A7");}
	

	/*TITLE*/
	gotoXY(10,44); printf(BOLD "BOARD STATISTIC" RESET);	

	/*CHECK OUTPUT*/
	gotoXY(13,20); printf(BOLD "Total players using this board            : %d  Players" RESET, NPlayerBoard[no_board]);
	gotoXY(15,20); printf(BOLD "Board average score                       : %.2lf Points" RESET, avgBoard[no_board]);
	gotoXY(17,20); printf(BOLD "Board difficulty (based on average score) : %s" RESET, level[rankBoard[no_board]-1]);

	return selectBack();
}
int printHowMultiplayer()
/*cetak how to play multiplayer game*/
{
	/*kamus lokal*/
	int i;
	/*algoritma*/
	CetakBingkai();
	gotoXY(4,33); printf( BOLD"<- HOW TO PLAY MULTIPLAYER GAME ->"RESET);
	gotoXY(6,20); printf("\"This is a multiplayer game. This game not saves your score,");
	gotoXY(7,20); f(i,1,60) printf("\u2501"); // print line
	gotoXY(8,26); printf("it just tests your ability against your friends\"");
	gotoXY(9,26); f(i,1,48) printf("\u2501"); // print line
	gotoXY(11,13); printf("[ 1st player uses right area of keyboard, and 2nd player uses left area ]");
	gotoXY(13,15); printf("[ Read instructions below to know how to use keyboard when playing ]");
	
	/*keyboard instructions*/
	gotoXY(15,37); printf("left <- Keyboard -> right");
	gotoXY(16,37); f(i,1,25) printf( BOLD"="RESET); // print line
	gotoXY(17,39); printf("S <--Toggle word--> J");
	gotoXY(18,39); f(i,1,21) printf( BOLD"-"RESET); // print line
	gotoXY(19,25); printf("Q,W,E,A,D,Z,X,C <------Move-----> T,Y,U,G,J,B,N,M");
	gotoXY(20,25); f(i,1,49) printf( BOLD"-"RESET); // print line
	gotoXY(21,39); printf("R <-----Rotate----> I");
	gotoXY(22,39); f(i,1,21) printf( BOLD"-"RESET); // print line
	gotoXY(23,12); printf("Ctrl(hold) + C -> Quit the game (it will close the whole program, actually)");
	gotoXY(24,12); f(i,30,104) printf( BOLD"-"RESET); // print line
	
	return selectBack();
}

int MultiplayerMenu()
/*cetak menu multiplayer game*/
{
	/*kamus lokal*/
	int i,j, pil,score1,score2, no_1, no_2;
	char cc;
	/*algoritma*/
	pil = 0;
	while(pil != 2 && pil != 3)
	{
		CetakBingkai();
		/*TITLE FRAME*/
		j=34; // print 1st horizontal line
		f(i,1,18) {gotoXY(10,j);  printf( BOLD "\u25A7" RESET); j+=2;}
	
		j=34; // print 2nd horizontal line
		f(i,1,18) {gotoXY(6,j);  printf( BOLD "\u25A7" RESET); j+=2;}

		/*TITLE*/
		gotoXY(8,36); printf("\u24C2"); // M
		gotoXY(8,38); printf("\u24CA"); // U
		gotoXY(8,40); printf("\u24C1"); // L
		gotoXY(8,42); printf("\u24C9"); // T
		gotoXY(8,44); printf("\u24BE"); // I

		gotoXY(8,47); printf("\u24C5"); // P
		gotoXY(8,49); printf("\u24C1"); // L
		gotoXY(8,51); printf("\u24B6"); // A
		gotoXY(8,53); printf("\u24CE"); // Y
		gotoXY(8,55); printf("\u24BA"); // E
		gotoXY(8,57); printf("\u24C7"); // R

		gotoXY(8,60); printf("\u24BC"); // G
		gotoXY(8,62); printf("\u24B6"); // A
		gotoXY(8,64); printf("\u24C2"); // M
		gotoXY(8,66); printf("\u24BA"); // E

		/*PLAY OPT*/
		gotoXY(14,43); printf("\u24DB"); // l
		gotoXY(14,45); printf("\u24D4"); // e
		gotoXY(14,47); printf("\u24E3"); // t
		gotoXY(14,49); printf("\u24E2"); // s

		gotoXY(14,52); printf("\u24D1"); // b
		gotoXY(14,54); printf("\u24D4"); // e
		gotoXY(14,56); printf("\u24D6"); // g
		gotoXY(14,58); printf("\u24D8"); // i
		gotoXY(14,60); printf("\u24DD"); // n

		/*HOWTO OPT*/
		gotoXY(18,43); printf("\u24D7"); // h 
		gotoXY(18,45); printf("\u24DE"); // o
		gotoXY(18,47); printf("\u24E6"); // w

		gotoXY(18,50); printf("\u24E3"); // t
		gotoXY(18,52); printf("\u24DE"); // o

		gotoXY(18,55); printf("\u24DF"); // p
		gotoXY(18,57); printf("\u24DB"); // l
		gotoXY(18,59); printf("\u24D0"); // a
		gotoXY(18,61); printf("\u24E8"); // y

		/*POINTER*/
		gotoXY(14,41);
		if(pil == 0)
			printf("\u25B6");
		else
			printf(" ");
		gotoXY(18,41);
		if(pil == 1)
			printf("\u25B6");
		else
			printf(" ");
		
		/*BACK*/
		gotoXY(29,3);
		printf("\u25C4  %sBACK 2 PREV MENU "RESET, (pil == 2) ? BOLD"\e[4m" : "");
		/*OUT*/
		gotoXY(29,88);
		printf("\u27F0  %sLOG OUT"RESET, (pil == 3) ? BOLD"\e[4m" : "");
		while(1)
		{
			initTermios();
			cc = getch();
			if(cc == 27)
			{
				cc = getch();
				cc = getch();
				switch(cc)
				{
					case 'A' : 	if(pil<3)
									pil = (pil + 2) % 3;
								else
									pil = 1;
								break;
					case 'B' :	if(pil<3)
									pil = (pil + 1) % 3;
								else
									pil = 0;
								break;
					case 'C' :
					case 'D' : 	if(pil > 1)
									pil = 5 - pil;
				}
			}
			resetTermios();
			if(cc == '\n')
				break;
			/*POINTER*/
			gotoXY(14,41);
			if(pil == 0)
				printf("\u25B6");
			else
				printf(" ");
			gotoXY(18,41);
			if(pil == 1)
				printf("\u25B6");
			else
				printf(" ");
			/*BACK*/
			gotoXY(29,3);
			printf("\u25C4  %sBACK 2 PREV MENU"RESET, (pil == 2) ? BOLD"\e[4m" : "");
			/*OUT*/
			gotoXY(29,88);
			printf("\u27F0  %sLOG OUT"RESET, (pil == 3) ? BOLD"\e[4m" : "");
		}
		if(pil == 0)
		{
			selectDualBoard(&no_1, &no_2);
			DualPlayer(120, no_1,no_2, &score1, &score2);
			if(printHasilDual(score1, score2))
				pil = 3;
		}
		else if(pil == 1)
				if (printHowMultiplayer() == 1)
					pil = 3;
	}
	return pil;
}
int printHasilDual(int score1, int score2)
{	
	int i;
	CetakBingkai();
	drawWord(2,22);

	printf(BOLD);
	gotoXY(20,24);printf(RED "Score Player 1");
	gotoXY(21,24);printf(RED "    %06d    ", score1);
	gotoXY(20,62);printf(BLUE "Score Player 2");
	gotoXY(21,62);printf(BLUE "    %06d    ", score2);
	printf(RESET);
	if (score1>score2)
	{
		printf("\e[37m\e[41m");
		gotoXY(10,8);printf("██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██╗    ██╗    ██╗██╗███╗   ██╗");
		gotoXY(11,8);printf("██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ███║    ██║    ██║██║████╗  ██║");
		gotoXY(12,8);printf("██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ╚██║    ██║ █╗ ██║██║██╔██╗ ██║");
		gotoXY(13,8);printf("██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗     ██║    ██║███╗██║██║██║╚██╗██║");
		gotoXY(14,8);printf("██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║     ██║    ╚███╔███╔╝██║██║ ╚████║");
		gotoXY(15,8);printf("╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝");
		printf(RESET);
	}
	else if(score1<score2)
	{
		printf("\e[37m\e[44m");
		gotoXY(10,7);printf("██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     ██████╗     ██╗    ██╗██╗███╗   ██╗");
		gotoXY(11,7);printf("██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ╚════██╗    ██║    ██║██║████╗  ██║");
		gotoXY(12,7);printf("██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝     █████╔╝    ██║ █╗ ██║██║██╔██╗ ██║");
		gotoXY(13,7);printf("██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██╔═══╝     ██║███╗██║██║██║╚██╗██║");
		gotoXY(14,7);printf("██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ███████╗    ╚███╔███╔╝██║██║ ╚████║");
		gotoXY(15,7);printf("╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚══════╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝");
		printf(RESET);
	}
	else
	{
		printf("\e[37m\e[44m");
		gotoXY(15,43);printf("██████╗ ██████╗  █████╗ ██╗    ██╗");
		gotoXY(15,43);printf("██╔══██╗██╔══██╗██╔══██╗██║    ██║");
		gotoXY(15,43);printf("██║  ██║██████╔╝███████║██║ █╗ ██║");
		gotoXY(15,43);printf("██║  ██║██╔══██╗██╔══██║██║███╗██║");
		gotoXY(15,43);printf("██████╔╝██║  ██║██║  ██║╚███╔███╔╝");
		gotoXY(15,43);printf("╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ");
		printf(RESET);
	}
	return selectBack();
}
int searchWordBoard(SET *SWord, MATRIKS *board, POINT P, char word[17], int pos , pNode NodeNow)
{	/* Kamus Lokal */
	int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1}, dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0 }, i, ret = 0;
	POINT Ptem = P;
	pNode NodeNext;
	/* Algoritma */
	word[pos] = ElMat(*board, P);
	kursor(board, P, '\0');
	if(mark(*NodeNow))
	{
		InsertSet(word, SWord);
		ret++;
	}
	for(i = 0; i<8; i++)
	{
		Ptem = P;
		if(movePoint(&Ptem,dx[i],dy[i],1,4) && ElMat(*board, Ptem) != '\0')
		{
			NodeNext = child(*NodeNow,ElMat(*board, Ptem)-'A');
			if(NodeNext != Nil)
			{
				ret += searchWordBoard(SWord, board, Ptem, word, pos+1,NodeNext);
			}
		}
	}
	kursor(board, P, word[pos]);
	word[pos] = '\0';
	return ret;
}
int printBoardWord()
/*print all words in board*/
{
	/*kamus lokal*/
	int i,j, n, no_page, page, pil, kol[4] = {11, 33, 54, 75};
	char cc;
	SET SWord;
	MATRIKS board;
	POINT P;
	infotype * S;
	address_set Q, R;
	
	char word[17];
	/*algoritma*/	
	CetakBingkai();
	/*1ST SEPARATOR*/
	gotoXY(8,29); printf(BOLD"\u2927"RESET);
	j=9;
	for (i =9;i<=25;i++) {gotoXY(i,29); printf("\u2162");}
	gotoXY(26,29); printf(BOLD"\u2929"RESET);

	/*2ND SEPARATOR*/
	gotoXY(8,51); printf(BOLD"\u2927"RESET);
	j=9;
	for (i =9;i<=25;i++) {gotoXY(i,51); printf("\u2162");}
	gotoXY(26,51); printf(BOLD"\u2929"RESET);

	/*3RD SEPARATOR*/
	gotoXY(8,72); printf(BOLD"\u2927"RESET);
	j=9;
	for (i =9;i<=25;i++) {gotoXY(i,72); printf("\u2162");}
	gotoXY(26,72); printf(BOLD"\u2929"RESET);

	/*WHAT BOARD?*/
	gotoXY(2,4); printf(BOLD"BOARD %s - %s  "RESET, num[board_used], level[rankBoard[board_used]-1]);

	/*TITLE*/
	gotoXY(3,43); printf(BOLD "ALL WORDS IN BOARD" RESET);	
	gotoXY(4,43); f(i,1,18) printf(" ");

	/*PREVIOUS PAGE*/
	gotoXY(5,33); printf("PREV PAGE <<"RESET);
	
	/*NEXT PAGE*/
	gotoXY(5,58); printf(">> "BOLD"\e[4mNEXT PAGE"RESET);

	/*AGAIN*/
	gotoXY(29,3); printf("\u25C4  BACK TO SCORE BOARD"RESET);
	
	/*OUT*/
	gotoXY(29,88); printf("\u27F0  LOG OUT"RESET);
	
	/*CHECK OUTPUT*/
	
	for(i = 0; i<17; i++)
		word[i] = '\0';
	CreateEmptySet(&SWord);
	BacaMATRIKS(&board, board_used);
	for(i = 1; i<=4; i++)
		for(j = 1; j<=4; j++)
		{
			P = MakePOINT(i, j);
			if(!IsEmptyTree(child(*DicT,ElMat(board, P)-'A')))
				searchWordBoard(&SWord, &board, P, word,0, child(*DicT,ElMat(board, P)-'A'));
		}
	n = NBElmt(SWord);
	S = (infotype *) malloc((n+1)*sizeof(infotype));
	R = Elmt(SWord);
	i = 0;
	while(R != Nil)
	{
		strcpy(S[i],Info_Set(R));
		Q = R;
		R = ElmtLain(R);
		DealokasiSet(&Q);
		i++;
	}
	page = (n+35)/36;
	if(page <1)
		page = 1;
	gotoXY(5, 51); printf("/%05d",page);
	no_page = 0;
	pil = 1;
	while(pil <2)
	{
		gotoXY(2,4); printf(BOLD"BOARD %s - %s  "RESET, num[board_used], level[rankBoard[board_used]-1]);
		gotoXY(5, 46); printf("%05d",no_page+1);
		for(i = 0; i<36; i++)
		{
			gotoXY(9+(i % 9)*2, kol[i/9]);
			printf("%s", S[no_page*36 + i]);
			for(j = strlen(S[no_page*36 + i]); j<16; j++)
				printf("-");
		}
		cc = 0;
		while(cc != '\n')
		{
			initTermios();
			cc = getch();
			resetTermios();
			if(cc == 27)
			{
				initTermios();
				cc = getch();
				cc = getch();
				resetTermios();
				switch(pil)
				{
					case 0 : gotoXY(5,33); printf("PREV PAGE"RESET" <<"); break;
					case 1 : gotoXY(5,58); printf(">> NEXT PAGE"RESET); break;
					case 2 : gotoXY(29,3); printf("\u25C4  BACK TO SCORE BOARD"RESET); break;
					case 3 : gotoXY(29,88); printf("\u27F0  LOG OUT"RESET); break;
				}
				if(cc == 'A' || cc == 'B')
					pil = (pil <2) ? 2 : 1;
				if(cc == 'C' || cc == 'D')
					pil = (pil % 2 == 0) ? pil+1 : pil-1;
				
				switch(pil)
				{
					case 0 : gotoXY(5,33); printf(BOLD"\e[4mPREV PAGE"RESET" <<"); break;
					case 1 : gotoXY(5,58); printf(">> "BOLD"\e[4mNEXT PAGE"RESET); break;
					case 2 : gotoXY(29,3); printf("\u25C4  "BOLD"\e[4mBACK TO SCORE BOARD"RESET); break;
					case 3 : gotoXY(29,88); printf("\u27F0"BOLD"  \e[4mLOG OUT"RESET); break;
				}
			}
		}
		if(pil == 1)
			no_page = (no_page+1) % page;
		else if(pil == 0)
			no_page = (no_page+page-1) % page;
	}
	return pil;
}
void selectDualBoard(int *no1, int *no2)
{
	int i=0;
	MATRIKS MBoard1,MBoard2;
	char arah;
	boolean ready1=false;
	boolean ready2=false;
	*no1 = *no2 = 1;
	HIDEKURSOR;

	clrscr;
	printf("\e[8;%d;%d;t", (30), (100));
	gotoXY(7,44);printf(GREEN BOLD "SELECT BOARD" RESET);
	gotoXY(8,19);printf("\u21da");
	gotoXY(8,22);printf(BOLD GREEN "BOARD %d",*no1);printf(RESET);
	gotoXY(8,30);printf("\u21db");	
	/* title board */
	gotoXY(8,68);printf("\u21da");
	gotoXY(8,71);printf(BOLD GREEN "BOARD %d",*no2);printf(RESET);
	gotoXY(8,79);printf("\u21db");
	/* petunjuk */
	gotoXY(8,11);printf("press A");
	gotoXY(8,32);printf("press D");
	gotoXY(8,60);printf("press G");
	gotoXY(8,81);printf("press J");

	drawWord(2,22);
	BacaMATRIKS(&MBoard1,*no1);
	BacaMATRIKS(&MBoard2,*no2);
	drawBoard(10,9,MBoard1);
	drawBoard(10,58,MBoard2);
	gotoXY(27,17);printf("press S for READY");
	gotoXY(27,66);printf("press H for READY");
	gotoXY(9,9);printf(BOLD RED "Player 1" RESET);
	gotoXY(9,58);printf(BOLD BLUE "Player 2" RESET);

	while(1){
		initTermios();
		arah=getch();
		resetTermios();
		
		if((arah=='a' || arah=='A' || arah=='d' || arah=='D') && !ready1){
			switch(arah){
				case 'a':
				case 'A':
					*no1 = (*no1+9)%10;
					gotoXY(8,19);printf(RED "\u21da " RESET);
					gotoXY(8,30);printf("\u21db");
					
				break;
				case 'd':
				case 'D':
					*no1 = (*no1+1) % 10;
					gotoXY(8,19);printf("\u21da");
					gotoXY(8,30);printf(RED "\u21db " RESET);
				break;
			}
		}
		else if((arah=='g' || arah=='G' || arah=='j' || arah=='J') && !ready2 ){
			switch(arah){
				case 'g':
				case 'G':
					*no2 = (*no2+9) % 10;
					gotoXY(8,68);printf(RED "\u21da " RESET);
					gotoXY(8,79);printf("\u21db");
				break;
				case 'j':
				case 'J':
					*no2 = (*no2+1)%10;
					gotoXY(8,68);printf("\u21da");
					gotoXY(8,79);printf(RED "\u21db " RESET);
				break;
			}
		}
		else if(arah=='s' || arah=='S'){
			ready1=true;
			gotoXY(28,23);printf(RED BOLD "READY" RESET);
		}
		else if(arah=='h' || arah=='H'){
			ready2=true;
			gotoXY(28,72);printf(BLUE BOLD "READY" RESET);
		}

		if (ready1 && ready2){
			gotoXY(27,37);printf("press ENTER to continue...");
		}
		if(ready1 && ready2 && arah=='\n'){
			break;
		}
		gotoXY(8,22);printf(BOLD GREEN "BOARD %d",*no1);printf(RESET);
		gotoXY(8,71);printf(BOLD GREEN "BOARD %d",*no2);printf(RESET);
		BacaMATRIKS(&MBoard1,*no1);
		BacaMATRIKS(&MBoard2,*no2);
		drawBoard(10,9,MBoard1);
		drawBoard(10,58,MBoard2);
	}
}
