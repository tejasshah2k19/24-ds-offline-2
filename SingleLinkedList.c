#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

int main()
{

    // head = (struct node*)malloc(sizeof(struct node));

    head = malloc(sizeof(struct node));
    head->data = 10; // scan
    head->next = NULL;

    struct node *tmp;
    tmp = malloc(sizeof(struct node));
    tmp->data = 20; // scan
    tmp->next = NULL;
    head->next = tmp;

    tmp = malloc(sizeof(struct node));
    tmp->data = 30; // scan
    tmp->next = NULL;
    head->next->next = tmp;

    tmp = malloc(sizeof(struct node));
    tmp->data = 40; // scan
    tmp->next = NULL;
    head->next->next->next = tmp;

    printf("\n%d", head->data);
    printf("\n%d", head->next->data);
    printf("\n%d", head->next->next->data);
    printf("\n%d", head->next->next->next->data);

    return 0;
}