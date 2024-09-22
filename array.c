#include <stdio.h>
#define SIZE 5

// global
int a[SIZE]; // 200...219
int i;

void scanArray()
{

    for (i = 0; i < SIZE; i++)
    {
        printf("\nEnter number");
        scanf("%d", &a[i]);
    }
}

void printArray()
{

    printf("\nElements in the array: ");

    for (i = 0; i < SIZE; i++)
    {
        printf(" %d", a[i]);
    }
}

int main()
{

    scanArray();
    printArray();

    return 0;
}