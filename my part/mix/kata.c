#include "kata.h"

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC ≠ BLANK atau CC = MARK */
{
  /* Algoritma */
  while ((CC == BLANK) && (CC != MARK)) 
    ADV();
  /* CC != BLANK or CC = MARK */
}

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = Mark;
       atau EndKata = false, CKata adalah kata yang sudah
diakuisisi, CC karakter pertama sesudah karakter terakhir kata */
{ 
  /* Algoritma*/
  if (misc == 0) START();
  else STARTmisc();
  if (misc == 0) IgnoreBlank();
  if (CC == MARK) 
    EndKata = true;
  else 
   {/* CC != MARK */
    EndKata = false;
    SalinKata();
   }
}

void STARTKAT()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = Mark;
       atau EndKata = false, CKata adalah kata yang sudah
diakuisisi, CC karakter pertama sesudah karakter terakhir kata */
{ 
  /* Algoritma*/
  STAR();
  IgnoreBlank();
  if (CC == MARK) 
    EndKata = true;
  else 
   {/* CC != MARK */
    EndKata = false;
    SalinKata();
   }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya,
mungkin MARK
Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  /* Algoritma*/
  if (misc == 0) IgnoreBlank();
  if (CC == MARK) 
    EndKata = true;
  else /* CC != MARK */ 
    SalinKata();
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */
{
  /* Kamus Lokal */
  int i = 1; /* inisialisasi */
  /* Algoritma*/
  for (;;) 
  {
    CKata.TabKata[i] = CC;
    ADV();
    if ((CC == MARK) || (CC == BLANK))
      break;
    else
      i++;
  } /* CC = MARK or CC = BLANK */
  CKata.Length = i;
}

void printmisc()
{
  int j;
  Kata pass;
  /*algoritma*/
  printf("\n");
  STARTKATA();
  
  // jika pita = user, maka ambil nilai pass nya
  if(misc==3) 
  putpas(&pass);

  while (!EndKata) 
  {
    for (j=1;j<=CKata.Length;j++) {
      if (misc==3) { 
        if (j>8) printf("%c",CKata.TabKata[j]);
      }else printf("%c",CKata.TabKata[j]);
    }
    ADVKATA();
  }
  printf("\n");
  misc = 0;
}

void putpas(Kata *pass)
{ // assign password dari file ID user
  /*kamus lokal*/
  int j;
  char c;
  /*algoritma*/
  (*pass).Length = 0;
  for (j=1;j<=8;j++) {
    c = CKata.TabKata[j];
    if(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
    {  
      (*pass).Length++;
      (*pass).TabKata[j] = c;
    }
  }
}