#include <stdlib.h>
#include "boolean.h"
#include <stdio.h>

#ifndef map_H
#define map_H

#define ValueUndef -999
typedef int infotype_map;
typedef struct 	{
					int key[26];
					infotype_map value;
				}MAP;
				

boolean IsEmptyMap(MAP M);

void CreateEmptyMap(MAP *M);

void InsertMap (char K, infotype_map V, MAP *M);

void DeleteMap (char K, MAP *M);

void Reassign (char K, infotype_map V, MAP *M);

infotype_map Value_of (char K, MAP M);

int hash(char C);

void CreateMAP(MAP *M);

int stringtopoin(char A[17]);

#endif
