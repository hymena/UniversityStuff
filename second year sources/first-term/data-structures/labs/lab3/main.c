#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "function.h"

struct nodeFB *startFB = NULL;
struct nodeGS *startGS = NULL;
struct newNodeFB *startNewFB = NULL;

int main()
{
	int id, age;
	scanf("%d", &id);
	while(id!=-1)
	{
		scanf("%d", &age);
		insertFB(&startFB, id, age); //Function to insert elements to Fenerbahce linked list 
		scanf("%d", &id);
	}

	scanf("%d", &id);
	while(id!=-1)
	{
		insertGS(&startGS, id); //Function to insert elements to Galatasaray linked list 
		scanf("%d", &id);
	}

	printFB(startFB); //Function that prints Fenerbahce linked list 
	printGS(startGS); //Function that prints Galatasaray linked list 

	createFinalList(&startNewFB,startFB,startGS); //Function that concatenates two linked lists

	printAll(startNewFB); //Function that prints the new concatenated linked list

	return 0;

}
