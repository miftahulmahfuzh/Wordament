#include "adtarray.h"

void MakeEmptyArray (TabInt *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	/* KAMUS LOKAL*/
	/* ALGORITMA */
	(*T).Neff = 0;
}

infotype_array MakeElmtArray(char name[], int howmuch, WAKTU when)
{	/* Kamus Lokal */
	infotype_array el;
	/* Algoritma */
	strcpy(el.username, name);
	el.score_value = howmuch;
	el.time_get = when;
	return el;
}
boolean IsFullArray (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	/* KAMUS LOKAL*/
	/* ALGORITMA */
	return NbElmt(T) == 20;
}

int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	/* KAMUS LOKAL*/
	/* ALGORITMA */
	return T.Neff;
}

boolean IsEmptyArray (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	/* KAMUS LOKAL*/
	/* ALGORITMA */
	return NbElmt(T) == 0;
}

void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika T kosong : Hanya menulis "Tabel kosong" */
{
	/* KAMUS LOKAL*/
	int i;
	/* ALGORITMA */
	if(IsEmptyArray(T))
		printf("Tabel kosong\n");
	else
		for(i = GetFirstIdx(T); i<= GetLastIdx(T); i++)
		{
			printf("%d : %s %d ",i,GetElmt(T,i).username, GetElmt(T,i).score_value);
			TulisWaktu(GetElmt(T,i).time_get);
			printf("\n");
		}
}

int GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
	/* KAMUS LOKAL*/
	/* ALGORITMA */
	return IdxMin;
}
int GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
	/* KAMUS LOKAL*/
	/* ALGORITMA */
	return IdxMin+T.Neff-1;
}
/* *** Menghasilkan sebuah elemen *** */
infotype_array GetElmt (TabInt T, int i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
	/* KAMUS LOKAL*/
	/* ALGORITMA */
	return T.TI[i-IdxMin+1];
}
boolean IsHigher(infotype_array el1, infotype_array el2)
{
	if(el1.score_value == el2.score_value)
		return !IsAwalWaktu(el1.time_get, el2.time_get);
	return el1.score_value < el2.score_value;
}
void Add1Urut (TabInt *T, infotype_array X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel boleh kosong, boleh penuh. */
/* Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/* Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/* Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
	/* KAMUS */
	int i;
	infotype_array Temp;
	/* ALGORITMA */
	if(!IsFullArray(*T))
	{
		SetNeff(T,NbElmt(*T)+1);
		for(i = GetLastIdx(*T); i>GetFirstIdx(*T); i--)
			if(IsHigher(GetElmt(*T,i-1),X))
				SetEl(T,i,GetElmt(*T,i-1));
			else
				break;
		SetEl(T,i,X);
		if(NbElmt(*T)>15)
			DelLastEl(T, &Temp);
	}
}

void SetEl (TabInt *T, int i, infotype_array el)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
	/* KAMUS LOKAL*/
	/* ALGORITMA */
	if(IsIdxValid(*T,i))
	{
		(*T).TI[i-IdxMin+1] = MakeElmtArray(el.username, el.score_value, el.time_get);
	}
}

boolean IsIdxValid (TabInt T, int i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	/* KAMUS LOKAL*/
	/* ALGORITMA */
	return (i>=IdxMin) && (i<=IdxMax);
}

void SetNeff (TabInt *T, int N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
	/* KAMUS LOKAL*/
	/* ALGORITMA */
	if(N<= MaxNbEl(*T) && N>=0)
		(*T).Neff = N;
	else
		if(N<0)
			(*T).Neff = 0;
		else
			(*T).Neff = MaxNbEl(*T);
}

int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	/* KAMUS LOKAL*/
	/* ALGORITMA */
	return IdxMax-IdxMin+1;
}

void DelLastEl (TabInt *T, infotype_array *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/* Banyaknya elemen tabel berkurang satu */
/* Tabel T mungkin menjadi kosong */
{
	/* KAMUS */
	/* ALGORITMA */
	*X = GetElmt(*T,GetLastIdx(*T));
	SetNeff(T,NbElmt(*T)-1);
}
void BacaAllScore(TabInt *T,  int no_board)
{	/* Kamus Lokal */
	char filee[] = "Score/AllScore_.txt", name[50];
	int sco, dd, mm, yy, hh, mi, sec;
	/* Algoritma */
	filee[14] = '0'+no_board;
	MakeEmptyArray(T);
	STARTKATA(filee);
	while(!EndKata)
	{
		KataToString(name);
		ADVKATA();
		KataToInt(&sco);
		ADVKATA();
		KataToInt(&dd);
		ADVKATA();
		KataToInt(&mm);
		ADVKATA();
		KataToInt(&yy);
		ADVKATA();
		KataToInt(&hh);
		ADVKATA();
		KataToInt(&mi);
		ADVKATA();
		KataToInt(&sec);
		ADVKATA();
		Add1Urut(T, MakeElmtArray(name, sco, MakeWAKTU(MakeTANGGAL(dd, mm, yy), MakeJAM(hh, mi, sec))));
	}
}
void TulisAllScore(TabInt *T,  int no_board)
{	/* Kamus Lokal */
	char filee[50] = "Score/AllScore_.txt", name[50];
	int n = 10, i, S;
	TANGGAL TG;
	JAM J;
	/* Algoritma */
	filee[14] = no_board+'0';
	STARTWrite(filee);
	if(n>NbElmt(*T))
		n = NbElmt(*T);
	for(i = 1; i<=n; i++)
	{
		strcpy(name, (*T).TI[i].username);
		S = (*T).TI[i].score_value;
		TG = GetTT((*T).TI[i].time_get);
		J = GetJJ((*T).TI[i].time_get);
		WritePita(name);
		WritePita(" ");
		WritePitaInt(S);
		WritePita(" ");
		WritePitaInt(GetDay(TG));
		WritePita(" ");
		WritePitaInt(GetMonth(TG));
		WritePita(" ");
		WritePitaInt(GetYear(TG));
		WritePita("   ");
		WritePitaInt(GetJam(J));
		WritePita(" ");
		WritePitaInt(GetMenit(J));
		WritePita(" ");
		WritePitaInt(GetDetik(J));
		WritePita("\n");
	}
	WritePita(".\n");
}
