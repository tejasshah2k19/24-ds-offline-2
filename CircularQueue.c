#include <stdio.h>
#define SIZE 5

int cq[SIZE];
int f = -1;
int r = -1;

void insert(int num)
{
    if (r == SIZE - 1 && f == 0)
    {
        printf("\nQueue is Full");
    }
    else if (r == f - 1)
    {
        printf("\nQueue is Full");
    }
    else if (r == SIZE - 1)
    {
        r = 0;
        cq[r] = num;
    }
    else
    {
        r++;
        cq[r] = num;
        if (f == -1)
        {

            f = 0;
        }
    }
}

int removeData()
{
    int num;
    if (f == -1)
    {
        printf("\nQueue is Empty");
        return -1;
    }
    else if (f == r)
    {
        num = cq[f];
        f = -1;
        r = -1;
        return num;
    }
    else if (f == SIZE - 1)
    {
        num = cq[f];
        f = 0;
        return num;
    }
    else
    {
        num = cq[f];
        f++;
        return num;
    }
    return -1;
}

void display()
{
    // cqDisplay
    int i;

    // CQ
    if (r < f)
    {
        for (i = f; i < SIZE; i++)
        {
            printf(" %d", cq[i]);
        }

        for (i = 0; i <= r; i++)
        {
            printf(" %d", cq[i]);
        }
    }
    else
    {

        // SQ
        for (i = f; i <= r; i++)
        {
            printf(" %d", cq[i]);
        }
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
            if (num == -1)
                printf("\nCQ is Empty");
            else
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