#include<stdio.h>
int vertice;
void print(int adj[][vertice]){
    printf("\ngraph represented in adjacency matrix:\n");
    for(int i=0;i<vertice;i++){
        for(int j=0;j<vertice;j++){
            printf("  %d  ",adj[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int source,dest;
    printf("num of vertices: ");
    scanf("%d",&vertice);
    int adj[vertice][vertice];
    for(int i=0;i<vertice;i++){
        for(int j=0;j<vertice;j++){
            adj[i][j]=0;
        }
    }
    while(source!=-1 && dest !=-1){
        printf("enter edge from node (0 to %d) to (0 to %d): ",vertice,vertice);
        scanf("%d %d",&source,&dest);
        adj[source][dest]=1;
        adj[dest][source]=1;
    }
    print(adj);
}