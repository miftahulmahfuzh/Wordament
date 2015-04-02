#include "pedass.h"

void abahsyamsul()
/* cetak kotak tebel (bingkai) */
{
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
	printf("\u2503"); gotoYX(i,100); printf("\u2503");}
	
	/*cetak alas*/
	printf("\u2517"); for (i=1;i<=98;i++) printf("\u2501"); printf("\u251b");
}

void syamsul()
/* cetak all high score */
{
	/*kamus lokal*/
	int i,j;
	/*algoritma*/                  
	gotoYX(4,40);	printf(Bold "<< HALL OF FAME >>" Reset);

	/*cetak ID*/
	gotoYX(7,34);	printf(Bold "ID" Reset);
	j = 9;
	f(i,9,17) {gotoYX(j,25);  printf("0%d  SYAMSULGANTENG\n",i-8); j += 2;	}
	gotoYX(27,25); printf("10  SYAMSULGANTENG\n");
	
	/*cetak score*/
	gotoYX(7,48);	printf(Bold "SCORES" Reset);
	j = 9;
	f(i,9,18) {gotoYX(j,48);  printf("000%d",i*27); j += 2;}

	/*cetak waktu*/
	gotoYX(7,64);	printf(Bold "WHEN" Reset);
	j = 9;
	f(i,9,18) {gotoYX(j,58);  printf("22-12-2014 22.30"); j += 2;}
  
  /*cetak garis pembatas*/                  
	gotoYX(8,25); for (i=1;i<=49;i++) printf("\u2501");
	gotoYX(29,2);

	/*AGAIN*/
	gotoYX(29,3); printf("\u25C4  "Bold"BACK 2 PREP MENU "Reset);
	
	/*OUT*/
	gotoYX(29,88); printf("\u27F0"Bold"  LOG OUT"Reset);
}

void mamahsyamsul()
/* cetak how to play */
{
	/*kamus lokal*/
	int i;
	/*algoritma*/
	gotoYX(4,32); printf(Bold"<- HOW TO PLAY THIS AWESOME GAME ->"Reset);
	gotoYX(6,8); printf("U really need to read this before you play our ouija board. Read carefully before u");
	gotoYX(7,8); f(i,8,90) printf("\u2501"); // pint line
	gotoYX(8,24); printf("take your first step to your biggest adventure ever");
	gotoYX(9,24); f(i,8,58) printf("\u2501"); // print line
	gotoYX(11,11); printf("[First, Register your ID. pick a cool name, you can choose max 14 characters]");
	// gotoYX(12,24); f(i,8,58) printf("\u2501"); // print line
	gotoYX(13,13); printf("[Next, Choose a board. if you don`t, we will give the 1st board for you]");
	// gotoYX(14,26); f(i,8,54) printf("\u2501"); // print line
	gotoYX(15,18); printf("[Then, play it. if you dont know how, read instructions below]");
	// gotoYX(16,28); f(i,8,50) printf("\u2501"); // print line
	gotoYX(18,39); printf("Instructions-Keyboard");
	gotoYX(19,39); f(i,8,28) printf(Bold"="Reset); // print line
	/*instructions-keyboard*/
	gotoYX(20,34); printf("R -> Rotate the board clockwise");
	gotoYX(21,34); f(i,34,64) printf(Bold"-"Reset); // print line
	gotoYX(22,25); printf("Q,W,E,A,D,Z,X,C -> Move the cursor on the board");
	gotoYX(23,25); f(i,30,76) printf(Bold"-"Reset); // print line
	gotoYX(24,7); printf("S -> Toggle word (change if you want to start to make a word, or just move the cursor)");
	gotoYX(25,7); f(i,34,119) printf(Bold"-"Reset); // print line
	gotoYX(26,12); printf("Ctrl(hold) + C -> Quit the game (it will close the whole program, actually)");
	gotoYX(27,12); f(i,30,104) printf(Bold"-"Reset); // print line
	
	gotoYX(29,2);
	/*AGAIN*/
	gotoYX(29,3); printf("\u25C4  "Bold"BACK 2 PREP MENU "Reset);
	
	/*OUT*/
	gotoYX(29,88); printf("\u27F0"Bold"  LOG OUT"Reset);
}

void syamsil()
/* cetak score board setelah time up */
{  
	/*kamus lokal*/
	int i,j;
	/*algoritma*/
	gotoYX(3,41); printf(Bold "YOUR TIME`S UP, PAL.." Reset);	
	gotoYX(4,41); f(i,1,21) printf("-");
	gotoYX(5,42); printf("try again next time"); 

	/*PREVIOUS PAGE*/
	gotoYX(7,38); printf("\uE2B3"Bold"  PREV PAGE"Reset);
	
	/*NEXT PAGE*/
	gotoYX(7,53); printf(Bold"NEXT PAGE "Reset"\uE2B4");

	/*1ST COL*/
	gotoYX(9,8); printf(Bold "WORDS MADE" Reset);
	gotoYX(9,27); printf(Bold "SCORE" Reset);
	
	/*SEPARATOR*/
	for (i =9;i<=25;i++) {gotoYX(i,35); printf("|");}

	/*2ND COL*/
	gotoYX(9,39); printf(Bold "WORDS MADE" Reset);
	gotoYX(9,58); printf(Bold "SCORE" Reset);
	
	/*SEPARATOR*/
	for (i =9;i<=25;i++) {gotoYX(i,66); printf("|");}

	/*3RD COL*/
	gotoYX(9,69); printf(Bold "WORDS MADE " Reset);
	gotoYX(9,88); printf(Bold "SCORE" Reset);

	/*WHAT BOARD?*/
	gotoYX(2,4); printf(Bold"BOARD ONE - HARD"Reset);	

	/*ALL WORDS IN TABLE*/
	gotoYX(2,77); printf(Bold"ALL WORDS IN BOARD "Reset"\uE023");

	/*TOTAL SCORE*/
	gotoYX(27,42); printf(Bold"TOTAL SCORE : 67100"Reset);		
	
	/*AGAIN*/
	gotoYX(29,4); printf(Bold"I`M NOT DONE YET, LET`S TRY AGAIN "Reset"\u21BA");
	
	/*LOG OUT*/
	gotoYX(29,66); printf("\u27F0"Bold"  THIS IS SHIT. I WANNA GET OUT"Reset);

	/*CHECK WORD OUTPUT*/
	/*first col*/
	j = 11; // print words
	f(i,11,18) {gotoYX(j,8);   printf("NASISIKUNINGNING"); j+=2;}
	j = 11; // print score
	f(i,11,18) {gotoYX(j,27);  printf("00123"); j+=2;}
	/*second col*/
	j = 11; // print words
	f(i,11,18) {gotoYX(j,39);  printf("BANDUNGJUARARARA"); j += 2;}
	j = 11; // print score
	f(i,11,18) {gotoYX(j,58);  printf("00123"); j+=2;}
	/*third col*/
	j = 11; // print words
	f(i,11,18) {gotoYX(j,69);  printf("----------------"); j += 2;}
	j = 11; // print score
	f(i,11,18) {gotoYX(j,88);  printf("00000"); j += 2;	}
}

void oomsyamsul()
/*print all words in board*/
{
	/*kamus lokal*/
	int i,j;
	/*algoritma*/	

	/*1ST SEPARATOR*/
	gotoYX(8,29); printf(Bold"\u2927"Reset);	
	j=9;
	for (i =9;i<=25;i++) {gotoYX(i,29); printf("\u2162");}
	gotoYX(26,29); printf(Bold"\u2929"Reset);

	/*2ND SEPARATOR*/
	gotoYX(8,51); printf(Bold"\u2927"Reset);	
	j=9;
	for (i =9;i<=25;i++) {gotoYX(i,51); printf("\u2162");}
	gotoYX(26,51); printf(Bold"\u2929"Reset);

	/*3RD SEPARATOR*/
	gotoYX(8,72); printf(Bold"\u2927"Reset);	
	j=9;
	for (i =9;i<=25;i++) {gotoYX(i,72); printf("\u2162");}
	gotoYX(26,72); printf(Bold"\u2929"Reset);

	/*WHAT BOARD?*/
	gotoYX(2,4); printf(Bold"BOARD ONE - HARD"Reset);	

	/*TITLE*/
	gotoYX(3,43); printf(Bold "ALL WORDS IN BOARD" Reset);	
	gotoYX(4,43); f(i,1,18) printf(" ");

	/*PREVIOUS PAGE*/
	gotoYX(5,39); printf("\u2962"Bold"  PREV PAGE"Reset);
	
	/*NEXT PAGE*/
	gotoYX(5,53); printf(Bold"NEXT PAGE "Reset"\u2964");

	/*AGAIN*/
	gotoYX(29,3); printf("\u25C4  "Bold"BACK TO SCORE BOARD"Reset);
	
	/*OUT*/
	gotoYX(29,88); printf("\u27F0"Bold"  LOG OUT"Reset);
	
	/*CHECK OUTPUT*/

	/*first col*/
	j = 9; // print words
	f(i,9,17) {gotoYX(j,11);   printf("NASISIKUNINGNING"); j+=2;}
	/*second col*/
	j = 9; // print words
	f(i,9,17) {gotoYX(j,33);  printf("BANDUNGJUARARARA"); j += 2;}
	/*third col*/
	j = 9; // print words
	f(i,9,17) {gotoYX(j,54);  printf("JNGNKENTUTDISINI"); j += 2;}
	/*fifth col*/
	j = 9; // print words
	f(i,9,17) {gotoYX(j,75);  printf("----------------"); j += 2;}
	gotoYX(29,55);
}

void tantesyamsul()
/*print board statistic*/
{
	/*kamus lokal*/
	int i,j;
	/*algoritma*/

	/*WHAT BOARD?*/
	gotoYX(2,4); printf(Bold"BOARD ONE - HARD"Reset);

	/*PRINT FRAME*/
	/*first horizontal line*/
	gotoYX(9,19);
	f(i,1,30) printf("\u25A7 ");
	/*second horizontal line*/
	gotoYX(11,19);
	f(i,1,30) printf("\u25A7 ");
	/*lowest horizontal line*/
	gotoYX(19,19);
	f(i,1,30) printf("\u25A7 ");
	/*left vertical line*/
	for (i =9;i<=19;i++) {gotoYX(i,19); printf("\u25A7");}
	/*right vertical line*/
	for (i =9;i<=19;i++) {gotoYX(i,79); printf("\u25A7");}
	

	/*TITLE*/
	gotoYX(10,43); printf(Bold "BOARD STATISTIC" Reset);	

	/*CHECK OUTPUT*/
	gotoYX(13,22); printf(Bold "Total players using this board            : 28  Players" Reset);	
	gotoYX(15,22); printf(Bold "Board average score                       : 285 Points" Reset);
	gotoYX(17,22); printf(Bold "Board difficulty (based on average score) : Hard" Reset);	

	/*BACK*/
	gotoYX(29,4); printf("\u25C4  "Bold"BACK 2 PREP MENU "Reset);
	
	/*OUT*/
	gotoYX(29,88); printf("\u27F0"Bold"  LOG OUT"Reset);
}

void adiksyamsul()
/*cetak how to play multiplayer game*/
{
	/*kamus lokal*/
	int i;
	/*algoritma*/
	gotoYX(4,33); printf(Bold"<- HOW TO PLAY MULTIPLAYER GAME ->"Reset);
	gotoYX(6,20); printf("\"This is a multiplayer game. This game not saves your score,");
	gotoYX(7,20); f(i,1,60) printf("\u2501"); // print line
	gotoYX(8,26); printf("it just tests your ability against your friends\"");
	gotoYX(9,26); f(i,1,48) printf("\u2501"); // print line
	gotoYX(11,13); printf("[ 1st player uses right area of keyboard, and 2nd player uses left area ]");
	gotoYX(13,15); printf("[ Read instructions below to know how to use keyboard when playing ]");
	
	/*keyboard instructions*/
	gotoYX(15,37); printf("left <- Keyboard -> right");
	gotoYX(16,37); f(i,1,25) printf(Bold"="Reset); // print line
	gotoYX(17,39); printf("S <--Toggle word--> J");
	gotoYX(18,39); f(i,1,21) printf(Bold"-"Reset); // print line
	gotoYX(19,25); printf("Q,W,E,A,D,Z,X,C <------Move-----> T,Y,U,G,J,B,N,M");
	gotoYX(20,25); f(i,1,49) printf(Bold"-"Reset); // print line
	gotoYX(21,39); printf("R <-----Rotate----> I");
	gotoYX(22,39); f(i,1,21) printf(Bold"-"Reset); // print line
	gotoYX(23,12); printf("Ctrl(hold) + C -> Quit the game (it will close the whole program, actually)");
	gotoYX(24,12); f(i,30,104) printf(Bold"-"Reset); // print line
	
	/*BACK 2 PREP*/
	gotoYX(29,3); printf("\u25C4  "Bold"BACK 2 PREP MENU "Reset);
	
	/*LOG OUT*/
	gotoYX(29,88); printf("\u27F0"Bold"  LOG OUT"Reset);
	
	gotoYX(29,47);
}

void babangsyamsul()
/*cetak menu multiplayer game*/
{
	/*kamus lokal*/
	int i,j;
	/*algoritma*/
	/*TITLE FRAME*/
	j=34; // print 1st horizontal line
	f(i,1,18) {gotoYX(10,j);  printf(Bold "\u25A7" Reset); j+=2;}
	
	j=34; // print 2nd horizontal line
	f(i,1,18) {gotoYX(6,j);  printf(Bold "\u25A7" Reset); j+=2;}

	/*TITLE*/
	gotoYX(8,36); printf("\u24C2"); // M
	gotoYX(8,38); printf("\u24CA"); // U
	gotoYX(8,40); printf("\u24C1"); // L
	gotoYX(8,42); printf("\u24C9"); // T
	gotoYX(8,44); printf("\u24BE"); // I

	gotoYX(8,47); printf("\u24C5"); // P
	gotoYX(8,49); printf("\u24C1"); // L
	gotoYX(8,51); printf("\u24B6"); // A
	gotoYX(8,53); printf("\u24CE"); // Y
	gotoYX(8,55); printf("\u24BA"); // E
	gotoYX(8,57); printf("\u24C7"); // R

	gotoYX(8,60); printf("\u24BC"); // G
	gotoYX(8,62); printf("\u24B6"); // A
	gotoYX(8,64); printf("\u24C2"); // M
	gotoYX(8,66); printf("\u24BA"); // E

	/*PLAY OPT*/
	gotoYX(14,43); printf("\u24DB"); // l
	gotoYX(14,45); printf("\u24D4"); // e
	gotoYX(14,47); printf("\u24E3"); // t
	gotoYX(14,49); printf("\u24E2"); // s

	gotoYX(14,52); printf("\u24D1"); // b
	gotoYX(14,54); printf("\u24D4"); // e
	gotoYX(14,56); printf("\u24D6"); // g
	gotoYX(14,58); printf("\u24D8"); // i
	gotoYX(14,60); printf("\u24DD"); // n

	/*HOWTO OPT*/
	gotoYX(18,43); printf("\u24D7"); // h 
	gotoYX(18,45); printf("\u24DE"); // o
	gotoYX(18,47); printf("\u24E6"); // w

	gotoYX(18,50); printf("\u24E3"); // t
	gotoYX(18,52); printf("\u24DE"); // o

	gotoYX(18,55); printf("\u24DF"); // p
	gotoYX(18,57); printf("\u24DB"); // l
	gotoYX(18,59); printf("\u24D0"); // a
	gotoYX(18,61); printf("\u24E8"); // y

	/*POINTER*/
	gotoYX(18,41); printf("\u25B6");

	/*BACK*/
	gotoYX(29,4); printf("\u25C4  "Bold"BACK 2 PREP MENU "Reset);
	
	/*OUT*/
	gotoYX(29,88); printf("\u27F0"Bold"  LOG OUT"Reset);

	
	gotoYX(22,55);
}

void kakeksyamsul()
/*cetak game over ke layar*/
{	
	printf(Red);
	gotoYX(5,28); printf( "  @@@@@@@@   @@@@@@   @@@@@@@@@@   @@@@@@@@");  
	gotoYX(6,28); printf( " @@@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@");  
	gotoYX(7,28); printf( " !@@        @@!  @@@  @@! @@! @@!  @@!     ");  
	gotoYX(8,28); printf( " !@!        !@!  @!@  !@! !@! !@!  !@!     ");  
	gotoYX(9,28); printf( " !@! @!@!@  @!@!@!@!  @!! !!@ @!@  @!!!:!  ");  
	gotoYX(10,28); printf(" !!! !!@!!  !!!@!!!!  !@!   ! !@!  !!!!!:  ");  
	gotoYX(11,28); printf(" :!!   !!:  !!:  !!!  !!:     !!:  !!:     ");  
	gotoYX(12,28); printf(" :!:   !::  :!:  !:!  :!:     :!:  :!:     ");  
	gotoYX(13,28); printf("  ::: ::::  ::   :::  :::     ::    :: ::::");  
	gotoYX(14,28); printf("  :: :: :    :   : :   :      :    : :: :: ");  
	                                             
	printf(Reset);                                         
	gotoYX(16,28); printf("  @@@@@@    @@@  @@@   @@@@@@@@@   @@@@@@@  "); 
	gotoYX(17,28); printf(" @@@@@@@@   @@@  @@@   @@@@@@@@@   @@@@@@@@ "); 
	gotoYX(18,28); printf(" @@!  @@@   @@!  @@@   @@@!        @@!  @@@ "); 
	gotoYX(19,28); printf(" !@!  @!@   !@!  @!@   !@!!        !@!  @!@ "); 
	gotoYX(20,28); printf(" @!@  !@!   @!@  !@!   @!!!:!      @!@!!@!  "); 
	gotoYX(21,28); printf(" !@!  !!!   !@!  !!!   !!!!!:      !!@!@!   "); 
	gotoYX(22,28); printf(" !!:  !!!   :!:  !!:   !!:         !!: :!!  "); 
	gotoYX(23,28); printf(" :!:  !:!    ::!!:!    :!:         :!:  !:! "); 
	gotoYX(24,28); printf(" ::::: ::     ::::      ::::::::   ::   ::: "); 
	gotoYX(25,28); printf("  : :  :       :       : :: :::    :   : :");	
}