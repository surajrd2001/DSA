#include <stdio.h>
#include <stdlib.h>

//suraj diwate

struct node
{
    struct node *left;
    struct node *right;
    int a;
};

void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ->", root->a);         
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->a = value;                                   
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insertLeft(struct node *root, int value)
{
    root->left = createNode(value);                  
    return root->left;
}

struct node *insertRight(struct node *root, int value)
{
    root->right = createNode(value);              
    return root->right;
}

int main()
{
    struct node *root = createNode(1);
    insertLeft(root, 12);
    insertRight(root, 9);

    insertLeft(root->left, 5);
    insertRight(root->left, 6);

    insertLeft(root->right, 23);
    insertRight(root->right, 7);

    printf("\nPreorder traversal \n");
    preorderTraversal(root);
}