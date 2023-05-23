#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id;
    int grade;
    struct node *left;
    struct node *right;
} node;
node *tree = NULL;

node *createNode(int id, int grade)
{
    node *new = (struct node *)malloc(sizeof(struct node));
    new->id = id;
    new->grade = grade;
    new->left = new->right = NULL;
    return new;
}

void inorder(node *tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d %d\n", tree->id, tree->grade);
        inorder(tree->right);
    }
}

void insert(struct node **tree, int id, int grade)
{
    if (*tree == NULL)
        *tree = createNode(id, grade);

    else
    {
        if (grade < (*tree)->grade)
            insert(&(*tree)->left, id, grade);
        else
            insert(&(*tree)->right, id, grade);
    }
}

int heightOfTree(node *tree)
{
    if (tree == NULL)
        return 0;
    else
    {
        int heightOfLeftSubTree = heightOfTree(tree->left);
        int heightOfRightSubTree = heightOfTree(tree->right);

        if (heightOfLeftSubTree > heightOfRightSubTree)
            return (heightOfLeftSubTree + 1);
        else
            return (heightOfRightSubTree + 1);
    }
}

void currentLevel(node *tree, int i)
{
    node *pre = NULL;
    if (tree == NULL)
        return;
    if (i == 1)
        printf("%d %d ", tree->id, tree->grade);
    else
    {
        currentLevel(tree->left, i - 1);
        if(i == 2 && tree->left !=NULL)
            printf("(%d L) ",tree->grade);
        currentLevel(tree->right, i - 1);
        if(i == 2 && tree->right !=NULL)
            printf("(%d R)",tree->grade);
    }
}

void levelOrder(node *tree)
{
    int height = heightOfTree(tree);
    printf("%d %d\n", tree->id, tree->grade);
    for (int i = 2; i <= height; i++)
    {
        currentLevel(tree, i);
        if(i != height)
            printf("\n");
    }
}

int main()
{

    int id, grade;
    scanf("%d", &id);
    while (id != -1)
    {

        scanf("%d", &grade);
        insert(&tree, id, grade);
        scanf("%d", &id);
    }
    inorder(tree);
    printf("\n");
    levelOrder(tree);
    return 0;
}