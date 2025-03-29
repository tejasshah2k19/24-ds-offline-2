#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
} *root = NULL;

int calculateHeight(struct node *root)
{
    int lh = 0;
    int rh = 0;

    if (root->left != NULL)
    {
        lh = root->left->height;
    }

    if (root->right != NULL)
    {
        rh = root->right->height;
    }

    return lh > rh ? lh + 1 : rh + 1;
}

int calculateBF(struct node *root)
{
    int lh = 0;
    int rh = 0;

    if (root->left != NULL)
    {
        lh = root->left->height;
    }

    if (root->right != NULL)
    {
        rh = root->right->height;
    }

    return lh - rh;
}

struct node *addNode(struct node *root, int num)
{ // root:NULL,10
    if (root == NULL)
    {
        root = malloc(sizeof(struct node));
        root->data = num;
        root->left = NULL;
        root->right = NULL;
        root->height = 1;
    }
    else if (num > root->data)
    {
        // right
        root->right = addNode(root->right, num);
    }
    else
    {
        root->left = addNode(root->left, num);
    }

    root->height = calculateHeight(root);

    int bf = calculateBF(root);

   
    
    if (bf < -1 )
    {
        printf("R");

        if(root->right->data < num){
            printf("R");
        }else{
            printf("L");
        }
        printf("\n %d %d\n", root->data, bf);
        
    }else if(bf>1){
        printf("L");
        if(root->left->data < num)
        {
            printf("R");
        }else{
            printf("L");
        }
        printf("\n %d %d\n", root->data, bf);
    }
    

    return root;
}

void inOrder(struct node *root)
{

    if (root != NULL)
    {
        inOrder(root->left);
        printf(" %d(%d)", root->data, root->height);
        inOrder(root->right);
    }
}

int main()
{

    // RR
        //  root = addNode(root, 30);
        // root = addNode(root, 50);
        // root = addNode(root, 200);

    // LL
    //  root = addNode(root, 200);
    //  root = addNode(root, 50);
    //  root = addNode(root, 30);

    // LR
    // root = addNode(root, 200);
    // root = addNode(root, 30);
    // root = addNode(root, 50);


    // RL
    // root = addNode(root, 30);
    // root = addNode(root, 200);
    // root = addNode(root, 50);


    //   inOrder(root);
    return 0;
}