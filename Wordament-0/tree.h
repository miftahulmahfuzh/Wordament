/* FIle : tree.h */

#include "boolean.h"
#include <stdlib.h>
#include "mesinkata1.h"

#ifndef TREE_CHAR
#define TREE_CHAR

#define Nil NULL

typedef struct tElmtTree *pNode;	/* pointer untuk node */
/*
typedef struct tEl_pNode *A_pNode;	
typedef struct tList_pNode {
	pNode info_pNode;
	A_pNode next_pNode;
} El_pNode;

typedef List_pNode { El_pNode First; }
*/
typedef struct tElmtTree {
	char infoNode;
	boolean mark;		/* Menendakan diterima atau tidak */
	pNode child[26];	/* kumpulan Child */
} Node;

typedef pNode Tree;

/* Selektor List of pNode*/
/*#define info_pNode(P) (P).info_pNode
#define next_pNode(P) (P).next_pNode*/

/* Selektor Tree */
#define info(N) (N).infoNode
#define mark(N) (N).mark
#define child(N, i) (N).child[(i)]

void CreateTree(Tree *T);
/* I.S Sembarang */
/* F.S terbentuk Tree T kosong */

pNode AlokasiNode(char C, boolean B);
/* Menghasilkan address hasil alokasi node baru */
/* Jika alokasi gagal menghasilkan Nil */

void DealokasiNode(pNode *pN);
/* I.S. pN terdefinisi */
/* F.S. pN dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian pNode */

boolean IsEmptyTree(Tree T);
/* Menghasilkan true jika Tree T kosong */

void setRoot(Tree *T, char value, boolean B );
/* I.S T sembarang */
/* F.S Root dari Tree (Node pertama) terdefinisi memiliki infoNode = value dan mark = B */

void AddChild(Node *N, char value, boolean B);
/* I.S. T tidak kosong */
/* F.S. jika child dengan infoNode value kosong maka akan ditambahkan child baru
  yang memiliki infoNode = value dan mark = B dengan cara alokasi baru dan   
  jika alokasi gagal maka T tidak berubah */
/* atau jika sudah ada maka hanya melakukan operasi mark = mark || B */
void DelChild(Node *N, char value);
/* I.S. T tidak kosong */
/* F.S. jika child dengan infoNode value kosong maka  T tidak berubah */
/* atau jika ada maka child tersebut dihapus dan di dealokasi  */
void AddWord(Tree *T, char s[]);
/* I.S. T tidak kosong */
/* F.S. Kata dari string s ditambahkan dalam tree */
boolean FSearch(Tree T, char s[]);
/* Menghasilkan true jika ada kata dari string s pada tree T */
void BacaDict(Tree *T);
void DeleteTree(Tree *T);
#endif
