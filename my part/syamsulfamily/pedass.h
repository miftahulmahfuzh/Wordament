
#ifndef pedass_H_
#define pedass_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define clrscr printf("\e[1;1H\e[2J")
#define gotoYX(x,y) printf("\x1B[%d;%df",(x),(y))
#define Red "\033[31m"
#define Bold "\033[1m"
#define Reset "\033[0m"
#define f(i,j,k) for(i=j;i<=k;i++)

void abahsyamsul();
/* cetak kotak tebel (bingkai) */

void syamsul();
/* cetak all high score */

void mamahsyamsul();
/* cetak how to play */

void syamsil();
/* cetak score board setelah time up */

void oomsyamsul();
/*print all words in board*/

void tantesyamsul();
/*print board statistic*/

void adiksyamsul();
/*cetak how to play multiplayer game*/

void babangsyamsul();
/*cetak menu multiplayer game*/

void kakeksyamsul();
/*cetak game over ke layar*/

#endif