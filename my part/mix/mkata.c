#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <time.h>


static struct termios old_termios, new_termios;

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
int kbhit(){
	struct timeval tv = {0L,0L};
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0,&fds);
	return select(1,&fds,NULL,NULL,&tv);
}

/* read 1 character */
char getch(){
	char ch;
	ch = getchar();
	return ch;
}

/*plusplus*/
indeks i = 1;
indeks j = 1;
indeks ii,jj; // kursor posisi start
boolean play; // determining play starts

/* skeleton program for play */
void Play(double seconds){
	initTermios(); // initailize new terminal setting to make kbhit() and getch() work
	char cc;
	const double TIME_LIMIT = seconds * CLOCKS_PER_SEC;
	clock_t startTime = clock();
	while ((clock() - startTime) <= TIME_LIMIT){
		if (kbhit()){
			cc = getch();
			resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)			
			
			switch(cc)
			{
				case 's':
						ii = i;
						jj = j;
						if (!play) {
							play = true;
							kursor(&k,i,j,'*');
						}
						else play = false;
						break;
				case 'r':
						CwMATRIKS(&t,&k);
						break;
				case 'a':
						if (play) kursor(&k,i,j,'*');
						if(j>1) j -= 1;
						
						break;
				case 'd':
						if (play) kursor(&k,i,j,'*');
						if(j<4) j += 1; 
						
						break;
				case 'w':
						if (play) kursor(&k,i,j,'*');
						if(i>1) i -= 1; 
						
						break;
				case 'x':
						if (play) kursor(&k,i,j,'*');
						if(i<4) i += 1; 
						
						break;
				case 'q':
						if (play) kursor(&k,i,j,'*');
						if((i>1)&&(j>1)){
							i -= 1;
							j -= 1;
						}	
						
						break;
				case 'e':
						if (play) kursor(&k,i,j,'*');
						if((i>1) &&(j<4)){
							i -= 1;
							j += 1;
						}	
						
						break;
				case 'z':
						if (play) kursor(&k,i,j,'*');
						if((i<4)&&(j>1)) {
							i += 1;
							j -= 1;
						}
						
						break;
				case 'c':
						if (play) kursor(&k,i,j,'*');
						if((i<4) &&(j<4)){
							i += 1;
							j += 1;
						}
						break;
			}
			if (cc != 'r') {
				if ( (play) && ((ii!=i)||(jj!=j)) );
				else if ( (!(play) || (cc != 's')) || ((play) && (ii==i)&&(jj==j) && (cc != 's')) ) 
					sedot(&k); /* jika tidak sedang rotate, atau setelah mengambil kata, atau jika 
						sedang mengambil kata dan kursor kembali ke posisi ii,jj (posisi awal) */
			}
			if (cc != 'r') {
				if ( ((!play) || ((play)) && (cc != 's')) ) 
					kursor(&k,i,j,'>'); /* jika tidak sedang rotate, atau tidak sedang bermain
											atau baru mau main */
			}
			TulisMATRIKS(k,t);
			printf("\n");
			initTermios(); // use new terminal setting again to make kbhit() and getch() work
		}
	}
	printf("\nTime Up\n");
	resetTermios(); // restore default terminal setting
}

int main(){
	BacaMATRIKS(&t);
	sedot(&k);
	kursor(&k,1,1,'>');
	TulisMATRIKS(k,t);
	printf("\n");
	play = false;
	Play(30);
	
	return 0;
}
