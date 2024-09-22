#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int arr[SIZE];
int i;

void insert()
{
    int data;
    int location; 
    

    printf("\nEnter data");
    scanf("%d",&data);//10

    printf("\nEnter location");
    scanf("%d",&location);

    for(i=SIZE-1; i>location-1;i--){
        arr[i] = arr[i-1];
    }
    arr[location-1] = data; //30 

}
void removeElement()
{
}
void display()
{
    printf("\nElements in the Array : ");
    for(i=0;i<SIZE;i++){
        printf(" %d",arr[i]);
    }
}

int main()
{

    int choice;

    while (-1)
    {
        printf("\n1 For Insert\n2 For Remove\n3 For Display");
        printf("\n4 For Exit\nEnter choice");

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

        default:
            printf("\nInvalid Choice");
            break;
        }
    }

    return 0;
}