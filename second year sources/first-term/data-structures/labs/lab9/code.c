#include<stdio.h>
#include<stdlib.h>
#define DEGREE 4    // Keeps the degree of B-tree so the number of childs a node can have
#define MAX DEGREE-1 //Keeps the maximum number of elements per node    
#define MIN DEGREE/2 //Keeps the minumun number of elements per node

struct node
{
    int elements[MAX];
    int numberOfELements;
    struct node *pointers[DEGREE];
};

struct node* root = NULL;



