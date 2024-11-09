#include<stdio.h>

struct movie{
    char name[30];
    char type[30];
    int year; 

};

struct ticket{
    int goldCount;
    int silverCount;
};


int main(){
     
    //how to access name type and year ? 
    struct movie m[5];//name type year 
    int i; 

    //dot operator 
    
    for(i=0;i<3;i++){  
        printf("\nEnter name type and year");
        scanf("%s%s%d",&m[i].name,&m[i].type,&m[i].year);
    } 


    printf("\nName      Type      Year");
    for(i=0;i<3;i++){
        printf("\n%-10s%-10s%d",m[i].name,m[i].type,m[i].year); 
    }

    return 0;   
}