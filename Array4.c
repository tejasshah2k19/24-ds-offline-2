#include <stdio.h>
#define S 5

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int i;
    int tmp; 
    

    for (i = 0; i < S; i++)
    {
        printf(" %d", a[i]);
    }

    tmp = a[S-1];//50 
 
    for (i = S - 1; i >0 ; i--)
    {
        a[i] = a[i-1];
    }

    a[0] = tmp; 

    printf("\nAfter Shifting.....\n");
    for (i = 0; i < S; i++)
    {
        printf(" %d", a[i]);
    }
    //50 10 20 30 40 
    //40 50 10 20 30 
    
    return 0;
}