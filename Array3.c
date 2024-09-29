#include <stdio.h>
#define S 5

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int i;
    int location;

    for (i = 0; i < S; i++)
    {
        printf(" %d", a[i]);
    }

    printf("\nEnter the location that you want to delete? ");
    scanf("%d", &location); // 2

    for (i = location - 1; i < S; i++)
    {
        a[i] = a[i + 1];
    }

    printf("\nAfter Deletion\n");
    for (i = 0; i < S; i++)
    {
        printf(" %d", a[i]);
    }

    return 0;
}