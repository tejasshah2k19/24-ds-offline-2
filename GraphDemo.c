#include <stdio.h>
#include <stdlib.h>

struct edge
{
    int src;  // 10 20 20 30 30 40 40 10
    int dest; // 20 10 30 20 40 30 10 40
};

int *visited;
int totalVisiteCount=0;
struct edge *e;
int totalEdges;
int totalVertex;

int isVisited(int num){
    int i;
    for(i=0;i<totalVertex;i++){
        if(visited[i] == num){
            return 1;//visited:true 
        }
    }
    return 0;
}

void dfs(int start){
    int i;
    printf(" %d",start);//1 2 
    visited[totalVisiteCount]=start;
    totalVisiteCount++;
    if(totalVisiteCount == totalVertex ){
        return;
    }
    for(i=0;i<totalEdges*2;i++){
        if(e[i].src == start && isVisited(e[i].dest) == 0 ){
            start = e[i].dest; 
            dfs(start);//2             
        }
    }


}

int main()
{

   

    int i;
    
    int s, d;

    printf("\nEnter total vertex and total edges");
    scanf("%d%d", &totalVertex, &totalEdges);

    visited = calloc(totalVertex,sizeof(int)); //0 0 0 0 0 0 

    e = calloc(totalEdges*2, sizeof(struct edge));

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

    // printf("\n %d is connected with : ",s);
    // for (i = 0; i < totalEdges * 2; i++)
    // {
    //     if(e[i].src == s){
    //         printf(" %d",e[i].dest);
    //     }
    // }

    dfs(1);
}
