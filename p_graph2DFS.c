#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxVer 100
void DFS(int adj[][maxVer],int vertice,int start);
void DFS_visit(int adj[][maxVer],int u);
 int vertice;
int color[20];
char countryList[maxVer][50];

int index(char cntry[]){
    for(int i=0;i<maxVer;i++){
        if(!strcmp(countryList[i],cntry)){
            return i;
        }
    }
}
int main(){
    char from[50],to[50];
    int adj[maxVer][maxVer],source,dest;
    int edge;
    int start;
    char startCountry[50];
    printf("countries?");
    scanf("%d",&vertice);
     for(int i=1;i<=vertice;i++){
        printf("enter country name %d:  ",i);
        scanf("%s",countryList[i]);
     }
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
       printf("from ");
       //scanf("%d",&source);
       scanf("%s",from);
       source=index(from);
       printf("to ");
       //scanf("%d",&dest);
       scanf("%s",to);
       dest=index(to);
       adj[source][dest]=1;
       adj[dest][source]=1;

    }
    printf("enter root ");
    //scanf("%d",&start);
    scanf("%s",startCountry);
    start=index(startCountry);
    DFS(adj,vertice,start);
}



void DFS_visit(int adj[][maxVer],int u){
    color[u]=1;
    printf("%s ",countryList[u]);
     for(int i=1;i<=vertice;i++){
        if(adj[u][i]==1 && color[i]==0){
            DFS_visit(adj,i);
        }
     }
     color[u]=2;

}

void DFS(int adj[][maxVer],int vertice,int start){
   
    for(int i=1;i<=vertice;i++){
        color[i]=0;

    }
    //if root=1
    //for(int i=1;i<=vertice;i++)
    //i!=start lagbe na &  DFS_visit(adj,i);
     for(int i=1;i<=start-1;i++){
        if(color[i]==0 && i!=start){
            DFS_visit(adj,start);
        }
     }
    
}
