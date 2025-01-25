#include <stdio.h>
#include <stdlib.h>
#define MAX 500
struct student
{
    char name[30];
    int maths, sci, eng;
    float perc;
    char grade;

    struct student *next; // self referntial structure -->
}; // 60*499

struct student s[MAX];
int count = 0;
void getData()
{
    // scan
    // name maths
    printf("\nEnter name and marks of three subjects");
    scanf("%s%d%d%d", &s[count].name, &s[count].maths, &s[count].sci, &s[count].eng);
    s[count].perc = (s[count].maths + s[count].eng + s[count].sci) / 3.0;

    if (s[count].perc > 90)
    {
        s[count].grade = 'A';
    }
    else if (s[count].perc > 80)
    {
        s[count].grade = 'B';
    }
    else if (s[count].perc > 70)
    {
        s[count].grade = 'C';
    }
    else if (s[count].perc > 35)
    {
        s[count].grade = 'D';
    }
    else
    {
        s[count].grade = 'F';
    }
    count++;
}

void printData()
{
    // print
    int x;
    for (x = 0; x < count; x++)
    {
        printf(" %s %d %d %d %f %c", s[x].name, s[x].maths, s[x].sci, s[x].eng, s[x].perc, s[x].grade);
    }
}

int main()
{

    int choice;
    while (1)
    {
        printf("\n1 For Add Student\n2 For List Student\n0 For exit\nEnter choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            getData();
            break;
        case 2:
            printData();
            break;
        default:
            break;
        case 0:
            exit(0);
        }
    }
    return 0;
}