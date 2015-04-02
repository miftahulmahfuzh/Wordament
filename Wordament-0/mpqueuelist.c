#include "pqueuelist.h"

int main()
{
	int prio, i, pil;
	infotype x;
	PQueue PQ;
	printf("Format masukan : \n");
	printf("menambah elemen \t: 1 [prio] [infotype]\nmenghapus elemen\t: 2\nmenampilkan isi elemen \t: 3\nkeluar \t\t\t: 0\n\n");
	CreateEmptyPQ(&PQ);
	scanf("%d", &pil);
	while(pil)
	{
		switch(pil)
		{
			case 1 :
				i = 0;
				scanf("%d", &prio);
				scanf("%s", x);
				AddPQ(&PQ,x, prio);
				break;
			case 2 :
				if(IsEmptyPQ(PQ))
					printf("PQ sudah kosong.\n");
				else
				{
					DelPQ(&PQ, &x, &prio);
				}
				break;
			default :
				PrintPQ(PQ);
		}
		scanf("%d", &pil);
	}
	return 0;
}
