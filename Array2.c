#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int arr[SIZE];
int i;
// DS -> complexity ->

// O(N)
void insert()
{
    int data;     //
    int location; //

    printf("\nEnter data");
    scanf("%d", &data); // 10

    printf("\nEnter location");
    scanf("%d", &location);
    // num = 50
    // location = 1
    for (i = SIZE - 1; i > location - 1; i--)
    { // i=1 1>1  Terminate
        arr[i] = arr[i - 1];
    }
    arr[location - 1] = data; // 30
    // count -> 4
    // location = 1 , loop -> 4
    // loaction = 2 , loop -> 3
    //  3 => 2
    //  4 => 1
    //  5 => 0
    //  6 => X
    // o(1) -> constant  o(n)
}
void removeElement()
{
    int location;
    printf("\nEnter the location that you want to delete? ");
    scanf("%d", &location); // 2

    for (i = location - 1; i < SIZE; i++)
    {
        arr[i] = arr[i + 1];
    }
}

// O(N)
void display()
{
    printf("\nElements in the Array : ");
    for (i = 0; i < SIZE; i++)
    {
        printf(" %d", arr[i]);
    }
}

void linearSearch()
{
    int key, flag, i;
    printf("\nEnter the key that you want to search ::::: ");
    scanf("%d", &key); // 2
    flag = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (arr[i] == key)
        {
            flag = 1;          // key == a[i] -->
            printf("\nFound"); //
            break;
        }
    }

    //
    if (flag == 0)
    {
        printf("\n%d Not Found", key);
    }
}
int main()
{

    int choice;
    int key;
    int flag;

    while (-1)
    {
        printf("\n1 For Insert\n2 For Remove\n3 For Display\n4 for exit\n5 for linear search\n6 for Shift");
        printf("\nEnter choice");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            removeElement();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        case 5:
            linearSearch();
            break;
        default:
            printf("\nInvalid Choice");
            break;
        }
    }

    return 0;
}