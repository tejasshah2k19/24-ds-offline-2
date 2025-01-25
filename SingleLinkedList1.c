#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

// 10-> 52-> 63-> 54 85
// self referential structure

void display()
{

    struct node *p;

    p = head; // init
    while (p != NULL)
    {
        printf(" %d", p->data); // 10  20
        p = p->next;
    }
}

void addNode(int num)
{
    struct node *tmp, *p;
    if (head == NULL)
    {
        head = malloc(sizeof(struct node));
        head->data = num;
        head->next = NULL;
    }
    else
    {
        tmp = malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = NULL;
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}

void addNodeBeg(int num)
{
    struct node *tmp;
    if (head == NULL)
    {
        addNode(num);
    }
    else
    {
        tmp = malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = head;
        head = tmp;
    }
}

void search(int num)
{
    // travel -> found ->
    //->not found ->
}

void sumOfAllNodes()
{
    struct node *p = head;
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    printf("\nSum = %d", sum);
}
// oddSum  , evenSum
// oddCount , evenCount

void insertAny(int src, int num)
{
    struct node *p = head;
    struct node *tmp;
    while (p != NULL)
    {
        if (p->data == src)
        {
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        printf("\nInvalid Source");
    }
    else
    {
        tmp = malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = p->next;
        p->next = tmp;
    }
}

void deleteEnd()
{
    struct node *p = head, *q;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
}

void deleteBeg()
{
    struct node *p = head;
    head = head->next;
    free(p);
}

void deleteAny(int src)
{
    struct node *p = head;
    struct node *q;
    while (p != NULL)
    {
        if (p->data == src)
        {
            break;
        }
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("\nInvalid Source , can not delete ");
    }
    else
    {
        q->next = p->next;
        free(p);
    }
}

void sort(){
    //task
}

int main()
{
    
    int num, src;
    int ch;
    while (1)
    {
        printf("\n0 For exit\n1 AddNode \n2 Display\n3 for add beg\n4 for search\n5 for sum of all nodes\n6 For insert any");
        printf("\n7 for delete end\n8 for delete beg\n9 for delete any");
        printf("\n10 for Sort the list");
        printf("\nEnter choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter number");
            scanf("%d", &num);
            addNode(num);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\nEnter number");
            scanf("%d", &num);
            addNodeBeg(num);
            break;
        case 4:
            printf("\n Search H.W");
            break;
        case 5:
            sumOfAllNodes();
            break;
        case 6:
            printf("\nEnter source and data");
            scanf("%d%d", &src, &num);
            insertAny(src, num);
            break;
        case 7:
            deleteEnd();
            break;
        case 8:
            deleteBeg();
            break;
        case 9:
            printf("\nEnter source node that you want to delete");
            scanf("%d", &src);
            deleteAny(src);
            break;
        case 10:
            sort();
            break;
        case 0:
            exit(0);
        default:
            printf("\nInvalid Choice");
            break;
        }
    }

    return 0;
}