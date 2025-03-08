#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;

} *root = NULL;

int main()
{

    root = malloc(sizeof(struct node));
    root->data = 7;
    root->left = NULL;
    root->right = NULL;

    struct node *leftChild = malloc(sizeof(struct node));
    leftChild->data = 9;
    leftChild->left = NULL;
    leftChild->right = NULL;

    root->left = leftChild; 

    printf(" %d %d ",root->data,root->left->data);
    return 0;
}