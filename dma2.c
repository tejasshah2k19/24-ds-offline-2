#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *a; // 4 byte
    int i;
    a = calloc(5, sizeof(int));

    for (i = 0; i < 5; i++)
    {
        printf("\nEnter value");
        scanf("%d", &a[i]);
    }

    printf("\nArray Data : ");

    for (i = 0; i < 5; i++)
    {
        printf(" %d", a[i]);
    }
    //
    free(a);

    //
    return 0;
}