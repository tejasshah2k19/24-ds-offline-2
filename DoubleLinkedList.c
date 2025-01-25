#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

void addNode(int num)
{ // 10 20 30

    if (head == NULL)
    {
        head = malloc(sizeof(struct node));
        head->data = num;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {

        struct node *tmp;
        tmp = malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = NULL;

        struct node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = tmp;
        tmp->prev = p;
    }
}

void display()
{
    struct node *p;

    p = head;

    while (p != NULL)
    {
        printf(" %d", p->data);
        p = p->next;
    }
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
        // case 3:
        //     printf("\nEnter number");
        //     scanf("%d", &num);
        //     addNodeBeg(num);
        //     break;
        // case 4:
        //     printf("\n Search H.W");
        //     break;
        // case 5:
        //     sumOfAllNodes();
        //     break;
        // case 6:
        //     printf("\nEnter source and data");
        //     scanf("%d%d", &src, &num);
        //     insertAny(src, num);
        //     break;
        // case 7:
        //     deleteEnd();
        //     break;
        // case 8:
        //     deleteBeg();
        //     break;
        // case 9:
        //     printf("\nEnter source node that you want to delete");
        //     scanf("%d", &src);
        //     deleteAny(src);
        //     break;
        // case 10:
        //     sort();
        //     break;
        case 0:
            exit(0);
        default:
            printf("\nInvalid Choice");
            break;
        }
    }

    return 0;
}