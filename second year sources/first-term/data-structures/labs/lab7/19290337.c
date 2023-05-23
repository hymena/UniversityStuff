#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
    int balance;
    struct Node *left;
    struct Node *right;
};

int maxOfTwo(int a, int b)//funtion to compare two value
{
    if (a > b)
        return a;
    else
        return b;
}

int heightOfTree(struct Node *tree)//Funtion to return height of a tree
{
    if (tree == NULL)
        return 0;
    return tree->height;
}

int calculateBalance(struct Node *tree)//function to calculate balance
{
    if (tree == NULL)
        return 0;
    return heightOfTree(tree->left) - heightOfTree(tree->right);
}
struct Node *newNode(int data) // function for allocating spaces to new nodes
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->height = 1;//All leaf nodes has height 1
    new->left = NULL;
    new->right = NULL;
    new->balance = 0;
    return new;
}

struct Node *rotateRight(struct Node *tree)
{
    struct Node *newRoot = tree->left;
    struct Node *changedLeaf = newRoot->right;

    newRoot->right = tree;
    tree->left = changedLeaf;

    tree->height = maxOfTwo(heightOfTree(tree->left), heightOfTree(tree->right)) + 1;//Update the height of the changed trees
    newRoot->height = maxOfTwo(heightOfTree(newRoot->left), heightOfTree(newRoot->right)) + 1;//Update the height of the changed trees



    return newRoot;
}

struct Node *rotateLeft(struct Node *tree)
{
    struct Node *newRoot = tree->right;
    struct Node *changedLeaf = newRoot->left;

    newRoot->left = tree;
    tree->right = changedLeaf;

    tree->height = maxOfTwo(heightOfTree(tree->left), heightOfTree(tree->right)) + 1; //Update the height of the changed trees
    newRoot->height = maxOfTwo(heightOfTree(newRoot->left), heightOfTree(newRoot->right)) + 1;//Update the height of the changed trees
    


    return newRoot;
}

struct Node *insert(struct Node *tree, int data)
{
    if (tree == NULL)
        return newNode(data);
    if (data < tree->data)
        tree->left = insert(tree->left, data);
    else if (data > tree->data)
        tree->right = insert(tree->right, data);

    tree->height = maxOfTwo(heightOfTree(tree->left), heightOfTree(tree->right)) + 1; //update the height of tree

    tree->balance = calculateBalance(tree);//calculate the balance after the heigh updated

    if (tree->balance > 1) 
    {
        if (data < tree->left->data)// LL case just apply right rotate
        {
            return rotateRight(tree);
        }
        else//LR case
        {
            tree->left = rotateLeft(tree->left);//first apply left rotate for left subtree
            return rotateRight(tree);//then apply right rotate
        }
    }

    if (tree->balance < -1)
    {
        if (data > tree->right->data)//RR case just apply left rotate
            return rotateLeft(tree);
        else//RL case
        {
            tree->right = rotateRight(tree->right);//first apply right rotate for the right subtree
            return rotateLeft(tree);//then apply left rotate
        }
    }
    
    return tree;//return the tree at the end 
}

void inorderDisplay(struct Node *tree)
{
    if (tree != NULL)
    {
        inorderDisplay(tree->left);
        printf("%d\n", tree->data);
        inorderDisplay(tree->right);
    }
}

void currentLevel(struct Node *tree, int i)
{
    struct Node *pre = NULL;
    if (tree == NULL)
        return;
    if (i == 1)
        printf("%d ", tree->data);
    else
    {
        currentLevel(tree->left, i - 1);
        if (i == 2 && tree->left != NULL)
            printf("(%d L) (%d B) ", tree->data, calculateBalance(tree->left));
        currentLevel(tree->right, i - 1);
        if (i == 2 && tree->right != NULL)
            printf("(%d R) (%d B) ", tree->data, calculateBalance(tree->right));
    }
}

void levelOrder(struct Node *tree)
{
    int height = heightOfTree(tree);
    printf("%d (%d B)\n", tree->data, calculateBalance(tree));
    for (int i = 2; i <= height; i++)
    {
        currentLevel(tree, i);
        if (i != height)
            printf("\n");
    }
}


int main()
{
    struct Node *tree = NULL;
    int value;
    scanf("%d", &value);
    while (value != -1)
    {
        tree = insert(tree, value);
        scanf("%d", &value);
    }

    inorderDisplay(tree);
    printf("\n");
    levelOrder(tree);
    printf("\n");


    return 0;
}