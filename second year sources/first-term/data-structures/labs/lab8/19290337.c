#include <stdio.h>
#include <stdlib.h>
#define RED 1
#define BLACK 0

typedef struct nodes
{
    int data;
    int colour;
    struct nodes *right;
    struct nodes *left;
    struct nodes *parent;
} node;

node *root = NULL;
node *createNewNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->colour = RED;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

node *GrandParent(node *n) //Funtion to return granparent of the given node
{
    if ((n != NULL) && (n->parent != NULL))
        return n->parent->parent;
    else
        return NULL;
}

node *Uncle(node *n) // Funtion to return uncle of the given node
{
    node *gp = GrandParent(n);
    if (gp != NULL && n->parent == gp->right)
        return gp->left;
    if (gp != NULL && n->parent == gp->left)
        return gp->right;
    else
        return NULL;
}

node *insert(node *n, node *new) //Funtion to perform normal BST insertion but additionally assigns the parent nodes
{
    if (n == NULL)
        return new;
    if (new->data < n->data)
    {
        n->left = insert(n->left, new);
        n->left->parent = n;
    }

    else if (new->data > n->data)
    {
        n->right = insert(n->right, new);
        n->right->parent = n;
    }

    return n;
}

void RotateRight(node *temp) // Funtion which performs right rotation
{
    node *newRoot = temp->left;
    temp->left = newRoot->right;

    if (temp->left != NULL)
        temp->left->parent = temp;
    newRoot->parent = temp->parent;

    if (temp->parent == NULL) //If there is no elder parent set the newroot as main root
        root = newRoot;
    else if (temp == temp->parent->left) //If there is an elder parent set the newroot as its right or left child
        temp->parent->left = newRoot;
    else
        temp->parent->right = newRoot;

    newRoot->right = temp;
    temp->parent = newRoot;
}

void RotateLeft(node *temp)
{

    node *newRoot = temp->right;
    temp->right = newRoot->left;

    if (temp->right)
        temp->right->parent = temp;

    newRoot->parent = temp->parent;

    if (!temp->parent )
        root = newRoot;

    else if (temp == temp->parent->left)
        temp->parent->left = newRoot;
    else
        temp->parent->right = newRoot;

    newRoot->left = temp;
    temp->parent = newRoot;
}

void fixTree(node **root, node *new)
{
    node *parent = NULL;
    node *grandParent = NULL;

    while ((new != (*root)) && (new->colour != BLACK) && (new->parent->colour == RED))
    {
        parent = new->parent;
        grandParent = GrandParent(new);

        // If parent is left child of grandparent
        if (grandParent->left == parent)
        {
            node *uncle = Uncle(new); //Then uncle is right child of grandparent

            // If uncle is red only recoloring required
            if (uncle != NULL && uncle->colour == RED)
            {
                grandParent->colour = RED;
                parent->colour = BLACK;
                uncle->colour = BLACK;
                new = grandParent; // To repeat process untill reach to the root
            }

            else
            {
                //new is right child of its parent so left rotate

                if (new == parent->right)
                {
                    RotateLeft(parent);
                    new = parent;
                    parent = new->parent;
                }
                else
                {//new is left child of its parent so right rotate
                RotateRight(grandParent);
                int tempColour = parent->colour;
                parent->colour = grandParent->colour;
                grandParent->colour = tempColour;
                new = parent;}
            }
        }

        else
        {
            // If parent is rigt child of grandparent

            node *uncle = Uncle(new);

            //uncle is also red only recolour

            if (uncle != NULL && uncle->colour == RED)
            {
                grandParent->colour = RED;
                parent->colour = BLACK;
                uncle->colour = BLACK;
                new = grandParent;
            }

            else
            {
                // new is leftchild so right rotate
                if (new == parent->left)
                {
                    RotateRight(parent);
                    new = parent;
                    parent = new->parent;
                }
                else
                {//new is rightchild so left rotate
                RotateLeft(grandParent);
                int tempColour = parent->colour;
                parent->colour = grandParent->colour;
                grandParent->colour = tempColour;
                new->parent;}
            }
        }
    }

    (*root)->colour = BLACK;
}

void printInOrder(node *temp)
{
    if (temp == NULL)
        return;
    printInOrder(temp->left);
    printf("%d\n", temp->data);
    printInOrder(temp->right);
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
    int t = 0;
    if (tree == NULL)
        return;
    if (i == 1)
    {
        printf("%d ", tree->data);
        if (tree->colour == RED)
            printf("R ");
        else 
            printf("B ");
    }
        
    else
    {
        currentLevel(tree->left, i - 1);
        if (i == 2 && tree->left != NULL)
            {printf("(%d L) ", tree->data);t++;}
        currentLevel(tree->right, i - 1);
        if (i == 2 && tree->right != NULL)
            {   
                printf("(%d R)", tree->data);
                if(t!=0)
                    printf(" ");
            }   
    }
}

void levelOrder(node *tree)
{
    int height = heightOfTree(tree);
    printf("%d B\n", tree->data);
    for (int i = 2; i <= height; i++)
    {
        currentLevel(tree, i);
        if (i != height)
            printf("\n");
    }
}

int main()
{

    int data;
    scanf("%d", &data);
    while (data != -1)
    {
        node *new = createNewNode(data);
        root = insert(root, new);
        fixTree(&root, new);
        scanf("%d", &data);
    }

    printInOrder(root);
    printf("\n");
    levelOrder(root);

    return 0;
}