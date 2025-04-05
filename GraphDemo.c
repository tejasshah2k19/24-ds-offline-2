#include <stdio.h>
#include <stdlib.h>

struct edge
{
    int src;  // 10 20 20 30 30 40 40 10
    int dest; // 20 10 30 20 40 30 10 40
};

// 20 : 30

int main()
{

    int totalEdges;
    int totalVertex;
    int i;
    struct edge *e;
    int s, d;

    printf("\nEnter total vertex and total edges");
    scanf("%d%d", &totalVertex, &totalEdges);

    e = calloc(8, sizeof(struct edge));

    for (i = 0; i < totalEdges * 2; i++)
    {
        printf("\nEnter Src And Dest"); // 10 20
        scanf("%d%d", &s, &d);
        e[i].src = s;
        e[i].dest = d;
        i++; // 1
        e[i].src = d;
        e[i].dest = s;
    }

    printf("\nEnter Vertex ? ");
    scanf("%d", &s); // 10

    printf("\n %d is connected with : ",s);
    for (i = 0; i < totalEdges * 2; i++)
    {
        if(e[i].src == s){
            printf(" %d",e[i].dest);
        }
    }
}
