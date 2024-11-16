#include <stdio.h>
#define SIZE 5

int q[SIZE];
int f = -1; // empty
int r = -1; // empty

void insert(int num)
{

    if (r == SIZE - 1)
    {
        printf("\nQueue is full");
    }
    else
    {
        r++; // 0
        q[r] = num;
        if (f == -1)
        {
            f = 0;
        }
    }
}

int removeData()
{
    int del = q[f];
    if (f == -1)
    {
        printf("\nQueue is Empty");
        return 0; 
    }
    else if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        f++;
    }

    return del;
}

void display(){
        int i;
        printf("\n===========QUEUE DATA==========\n");
        for(i=f;i<=r;i++){
            printf("  %d",q[i]);
        }
}
int main()
{
    int choice;
    int num;

    while (1)
    {
        printf("\n1 For Add\n2 For Remove\n3 For Display\n0 Exit\nEnter choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter number");
            scanf("%d", &num); // 10
            insert(num);       // 10
            break;
        case 2:
            num = removeData();
            printf("\n%d removed", num);
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);

        default:
            break;
        }
    }
    return 0;
}