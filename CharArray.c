#include<stdio.h>

int main(){
    char x[30];
    int i; 

    printf("\nEnter name");
    // scanf("%s",&x);//royal 
    gets(x);//string scan space -> gets  


    printf("\n%s",x);//royal  


    printf("\nCharacter:\n");
    for(i=0;x[i] != '\0' ;i++){
        printf("\n%c",x[i]);//royal
    }


    return 0;
}