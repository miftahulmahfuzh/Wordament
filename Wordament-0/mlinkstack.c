/* File : mlinkstack.c */
#include "linkstack.h"
#include <stdio.h>


int main()
{	/* KAMUS */
	int pilihan ;
	char X;
	Stack S;
	char str[100];
	
	/* ALGORITMA */
	CreateEmpty(&S);
	do
	{
		printf("\n***** MENU PILIHAN *****\n");
		printf("1. Mengosongkan stack\n");
		printf("2. Menambah satu elemen stack\n");
		printf("3. Menghapus satu elemen stack\n");
		printf("4. Konversi Stack ke String\n");
		printf("0. Keluar\n");
		printf("Masukan pilihan : ");
		scanf("%d%*c",&pilihan);
		printf("\n");
		switch(pilihan)
		{
			case 1 : CreateEmpty(&S);
					 printf("Stack telah menjadi kosong.\n");
					 break;
			case 2 : printf("Masukan nilai yang akan ditambahkan ke stack : ");
					 scanf("%c",&X);
					 Push(&S,X);
					 printf("Nilai %c berhasil ditambahkan.\n",InfoTop(S));
					 break;
			case 3 : if(IsEmpty(S))
					 	printf("Maaf stack sudah kosong, tidak bisa menhapus elemen lagi.\n");
					 else
					 {
					 	Pop(&S,&X);
					 	printf("Nilai %c berhasil dihapus.\n", X);
					 }
					 break;
			case 4 : StackToString(&S,str);
					 printf("Isi stack diubah menjadi string adalah sebagai berikut :\n%s\n", str);
					 break;
					
			default :
					 printf("Driver berakhir.\n\n");
		}
	} while(pilihan > 0 && pilihan < 5);
	return 0;
}
