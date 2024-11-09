#include <stdio.h>
#include <stdlib.h>
#include<string.h> 

#define SIZE 100

struct movie
{
    char name[30];
    int year;
} m[SIZE];

int size; 
// m[0]{name,year} m[1]{name,year} m[2] ..... m[99]















void addMovie()
{
    int   i;
    printf("\nhow many movies you want to enter");
    scanf("%d", &size); // 3

    for (i = 0; i < size; i++)
    {
        printf("\nEnter movie name and year : ");
        scanf("%s%d", &m[i].name, &m[i].year);
    }
}

void printAllMovies()
{
    int i;
 
    for (i = 0; i < size; i++)
    {
        printf("\n%s %d", m[i].name, m[i].year);
    }
}

void searchMovie()
{
    int i;
    char search[20];
    int found = 0; // 0 -> not found 
    printf("\nEnter the movie name");
    scanf("%s",&search); 

    for(i=0;i<size;i++){
        if(stricmp(m[i].name,search) == 0 ){
            printf("\n%s %d",m[i].name,m[i].year) ; 
            found = 1;//present 
        }
    }

    if(found == 0){
        printf("\nSorry No Movie Found...");
    }


}

void sortByYear()
{
    //h.w 
}

int main()
{

    int choice;

    while (1)
    {
        printf("\n1. add movie \n2. print all movies \n3. search movie \n4. sort all movie by year \n5. exit ");
        printf("\nEnter the choice");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addMovie();
            break;

        case 2:
            printAllMovies();
            break;
        case 3:
            searchMovie();
            break;
        case 4:
            sortByYear();
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid Choice PTA!!");
            break;
        } // switch

    } // while - infinite

    return 0;
}