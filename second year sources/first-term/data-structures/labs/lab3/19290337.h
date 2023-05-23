#include<stdlib.h>
#include<stdio.h>
struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};

// You need to write all the function definitions to be used in this lab in this file.
// You can call other functions that you define from the mandatory functions.
// Do not make any changes to the main.c file.
// Upload the file function.h to the system as StudentNumber.h. 


void insertFB(struct nodeFB** head_ref, int id, int age){ //A function to insert new element for fb linked list

	struct nodeFB* temp = *head_ref;
	struct nodeFB* new_node = (struct nodeFB*) malloc(sizeof(struct nodeFB)); // Allocate memmory for new data
	new_node-> id = id;														  //Give datas 
	new_node-> age = age;
	new_node->next = NULL;													  //Assign the next of new node to null 
	

	if ((*head_ref)==NULL || id < (*head_ref)->id)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	
	else{
		int founded = 0;
		while (temp->next!=NULL)
		{	
			
			if ((temp->id < id) && (id < (temp->next)->id))
			{
				new_node->next = temp->next;
				temp->next = new_node;
				founded = 1;
				break;	
			}
			else
				temp = temp->next;
			
		}
		if(!founded){
			temp->next = new_node;
		}
			
	}
}

void insertGS(struct nodeGS** head_ref, int id){ //A function to insert new element for fb linked list

	struct nodeGS* temp = *head_ref;
	struct nodeGS* new_node = (struct nodeGS*) malloc(sizeof(struct nodeGS)); // Allocate memmory for new data
	new_node-> id = id;														  //Give datas 
	new_node->next = NULL;													  //Assign the next of new node to null 
	

	if ((*head_ref)==NULL || id > (*head_ref)->id)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	
	else{
		int founded = 0;
		while (temp->next!=NULL)
		{	
			
			if (( id < temp->id ) && ((temp->next)->id) < id)
			{
				new_node->next = temp->next;
				temp->next = new_node;
				founded = 1;
				break;	
			}
			else
				temp = temp->next;
			
		}
		if(!founded){
			temp->next = new_node;
		}
			
	}
}

void printFB(struct nodeFB* start){ 
	struct nodeFB* temp = start;
	while (temp!= NULL)
	{
		printf("%d %d\n",(*temp).id,(*temp).age);
		temp = temp->next;
	}
	printf("\n");
}

void printGS(struct nodeGS* start){
	struct nodeGS* temp = start;
	while (temp!= NULL)
	{
		printf("%d\n",(*temp).id);
		temp = temp->next;
	}
	printf("\n");
}

void createFinalList(struct newNodeFB** start, struct nodeFB* startFB, struct nodeGS* startGS){
	struct nodeFB* tempFB = startFB;
	struct nodeGS* tempGS = startGS;
	(*start) = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
	(*start)->id = tempFB->id;
	(*start)->age = tempFB->age;
	(*start)->next = NULL;
	struct newNodeFB* temp1 = (*start);
	tempFB = tempFB->next;
	struct  newNodeGS* temp2 = NULL;	

	int counter=2;
	while(tempGS!= NULL)
	{	
		if(counter%2==0){
			temp1->next = (struct newNodeGS*)malloc(sizeof(struct newNodeGS));
			temp1->next->id = tempGS->id;
			temp1->next->next = NULL;
			temp2 = temp1->next;
			tempGS = tempGS->next;
			counter=counter+1;
		}

		else{
			temp2->next = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
			temp2->next->id = tempFB->id;
			temp2->next->age = tempFB->age;
			temp2->next->next = NULL;
			temp1 = temp2->next;
			tempFB = tempFB->next;
			counter=counter+1;
		}

	}
}

void printAll(struct newNodeFB* start){
	while(start != NULL)
	{
		printf("%d %d\n",start->id, start->age);
		printf("%d\n",(start->next)->id);
		start=start->next->next;
	}
}