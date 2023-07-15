#include<stdio.h>
#include<string.h>
#define maxVer 100

 char color[maxVer][10],prev[maxVer];
    int d[maxVer],f[maxVer],time,result[maxVer],transpose[][maxVer],fSorted[maxVer],topological[maxVer];
   
void swap(int *i,int *j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
void insertion_sort(int list[],int N)
{ 
    for(int i=2;i<N;i++)
    {
        for(int j=i-1;j<N;j++)
        {
            if(list[i]<list[j])
            {
                swap(&list[i],&list[j]);
            }
        }
    }
}

int vertice;
void print(int adj[][maxVer],int vertice){
    printf("\ngraph represented in adjacency matrix:\n");
    for(int i=0;i<vertice;i++){
        for(int j=0;j<vertice;j++){
            printf("  %d  ",adj[i][j]);
        }
        printf("\n");
    }
}

void  DFS_visit(int adj[][maxVer],int u){
         // printf("done traverse");
           strcpy(color[u],"grey");
         time=time+1;
          d[u]=time;
         printf(" %d ",u);
         result[u]=u;
         
             for(int i=0;i<vertice;i++){
        
           if (adj[u][i] == 1 && (strcmp(color[i], "white") == 0))
{
                //the node which has not been traversed yet
                strcpy(color[i],"grey");
                prev[i]=u; 
                DFS_visit(adj,i);  
    }
          }
             strcpy(color[u],"black");
             time=time+1;
             f[u]=time;
             topological[time]=u;
            // printf("done!");

             
          }
         
  void DFS(int adj[][maxVer],int vertice){  
   //prev[]= prev root vertex , d[]= discoverd vertex , s=root vertex,f[]=finished vertex
   
    for(int i=0;i<vertice;i++){
                strcpy(color[i],"white");
                prev[i]=-1;
                d[i]=__INT_MAX__;  //set an infinte val in d[]
                f[i]=__INT_MAX__;
            
    } 
    time=0;
    for(int i=0;i<vertice;i++){
    if( (strcmp(color[i],"white"))==0)
    {
        DFS_visit(adj,i);
        //DFS(transpose,vertice);
    }
    }

}       
 void SSC(int adj[][maxVer],int vertice){  
   //prev[]= prev root vertex , d[]= discoverd vertex , s=root vertex,f[]=finished vertex
   
    for(int i=0;i<vertice;i++){
                strcpy(color[i],"white");
                prev[i]=-1;
                d[i]=__INT_MAX__;  //set an infinte val in d[]
                f[i]=__INT_MAX__;
            
    } 
    time=0;
    for(int i=100;i>0;i--){
    if( (strcmp(color[i],"white"))==0 && topological[i]!=-2)
    {
        DFS_visit(adj,topological[i]);
        //DFS(transpose,vertice);
    }
    }

}       
void Transpose(int adj[][maxVer],int transpose[][maxVer],int vertice){
    int i, j;
    for (i = 0; i < vertice; i++){
        for (j = 0; j < vertice; j++){
            transpose[i][j] = adj[j][i];
        }
    }
    printf("\ntranspose matrix\n");
    for(int i=0;i<vertice;i++){
        for(int j=0;j<vertice;j++){
            printf("  %d  ",transpose[i][j]);
        }
        printf("\n");
    }
}


int main(){
    for(int i=0;i<maxVer;i++){
        topological[i]=-1;
    }
    int source,dest;
    printf("num of vertices: ");
    scanf("%d",&vertice);
    int adj[maxVer][maxVer];
    for(int i=0;i<vertice;i++){
        for(int j=0;j<vertice;j++){
            adj[i][j]=0;
        }
    }
    while(1){
        printf("enter edge from node (0 to %d) to (0 to %d): ",vertice,vertice);
        scanf("%d %d",&source,&dest);
         if (source == -1 || dest == -1)
            break;

          if (source < 0 || source >= vertice || dest < 0 || dest >= vertice) {
            printf("Invalid input\n");
            continue;
        }   
        adj[source][dest]=1;
        adj[dest][source]=1;
    }
    Transpose(adj,transpose,vertice);
    print(adj,vertice);
     printf("DFS traversal result:\n");
    DFS(adj,vertice);
    printf("\nvertex backtracking time:");
     for(int i=0;i<vertice;i++){
                printf("%d ",f[i]);
              }
     printf("\nvertex forward tracking time:");
     for(int i=0;i<vertice;i++){
                printf("%d ",d[i]);
              }


     printf("\n");
     for(int i=0;i<maxVer;i++){
         if(topological[i]!=-1)
         {printf(" %d ",topological[i]);}

     }   
     //SSC(transpose,vertice);           
    return 0;

}