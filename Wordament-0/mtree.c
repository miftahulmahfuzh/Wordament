#include "tree.h"
#include <stdio.h>

int main()
{	/* KAMUS */
	Tree T;
	FILE *kamus;
	char s[20];
	int n, i;
	/* ALGORITMA */
	BacaDict(&T);
	scanf("%d", &n);
	for( i = 0; i<n; i++)
	{
		scanf("%s", s);
		printf("%s\n", (FSearch(T, s) ? "true" : "false"));
	}
	DeleteTree(&T);
	scanf("%d", &n);
	for( i = 0; i<n; i++)
	{
		scanf("%s", s);
		printf("%s\n", (FSearch(T, s) ? "true" : "false"));
	}
	return 0;
}
