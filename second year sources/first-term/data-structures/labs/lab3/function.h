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


