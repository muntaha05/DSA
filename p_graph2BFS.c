#include<stdio.h>
#include<stdlib.h>
#define maxVer 100
void enqueue(int data);
int dequeue();
int vertice,queue[maxVer],front=-1,rear=-1;
void enqueue(int data){
    if(rear==maxVer-1){
        printf("overflow");
        return ;
    }
    else{
       if(front==-1)
       {
        front=0;
       }
       rear++;
       queue[rear]=data;


    }
}
int dequeue(){
    int item;
    if(front ==-1 || front>rear){
        printf("underflow");
        return -1;
    }
    else{
     item=queue[front];
    front++;
     if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
    return item;
}

void BFS(int adj[][maxVer],int vertice,int start){
    int color[vertice],visited[vertice];
    for(int i=1;i<=vertice;i++){
        if(i!=start){
            color[i]=0;
        }
    }color[start]=1;
    enqueue(start);
    while(front!=-1){
        int u=dequeue();
        printf("%d ",u);
        for(int i=1;i<=vertice;i++){
        if(adj[u][i]==1 && color[i]==0){
            color[i]=1;
            enqueue(i);
        }
        }
        color[u]=2;
    }

}
int main(){
    
    int adj[maxVer][maxVer],source,dest;
    int edge,start;
    printf("vertice?");
    scanf("%d",&vertice);
    printf("edge?");
    scanf("%d",&edge);
    for(int i=1;i<=vertice;i++){
        for(int j=1;j<=vertice;j++){
            adj[i][j]=0;
        }
    }
    printf("enter edge:");
    for(int i=0;i<edge;i++)
    {
       printf("from");
       scanf("%d",&source);
       printf("to");
       scanf("%d",&dest);
       adj[source][dest]=1;
       adj[dest][source]=1;

    }
    printf("enter root");
    scanf("%d",&start);
    BFS(adj,vertice,start);
}