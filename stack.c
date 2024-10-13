#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE];
int top = -1; //-1 STACK EMPTY

void push()
{
    int num;

    if (top == SIZE - 1)
    {
        printf("\nSTACK OVERFLOW");
    }
    else
    {
        printf("\nEnter number");
        scanf("%d", &num);
        top++;
        stack[top] = num;
    }
}

void pop()
{
    if(top == -1){
        printf("\nStack is Empty");
    }else{
        printf("\n%d pop",stack[top]);
        top--; 
    }
}

void peek(){
    if(top == -1){
        printf("\nStack is Empty");
    }else{
        printf("\n%d",stack[top]); 
    }
}

void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("\n%d", stack[i]);
    }
}

void peep(){
    int location;
    int index; 
    printf("\nEnter location");
    scanf("%d",&location);//
    index = top-location+1;

    printf("\n%d",stack[index]); 
}
int main()
{
    int choice;
    while (-1)
    {
        printf("\n0 For Exit\n1 For Push\n2 For Pop\n3 For Display\nEnter choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);
        default:
            printf("\nInvalid Choice");
            break;
        }
    }
    return 0;
}