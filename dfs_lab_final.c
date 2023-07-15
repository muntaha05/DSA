#include<stdio.h>
#include<string.h>
#define maxVer 100

 char color[maxVer][10],prev[maxVer];
    int d[maxVer],f[maxVer],time,source,dest;
      char country[maxVer][100],from[100],to[100],loc[100];
   
 // char mat[10][maxVer]={"Greenland","China","India","Pakistan","Iran","Bangladesh","Turkey","USA","Canada","Thailand"};

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
         printf("%s ",country[u]);
         
         
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
             //printf("done!");

             
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
    printf("enter strating location:");
    scanf("%s",loc);
    int start=desherIndexDao(loc);
    //printf("\nloc is %d",start);

    // if (start >= 0 && start < vertice) {
    //     DFS_visit(adj, start);
    // }

    for(int i=0;i<start -1;i++){
    if( ((strcmp(color[i],"white"))==0 && i!=start) )
    {
        DFS_visit(adj,start);
    }
    }

}   
int desherIndexDao(char nam[]){
    for(int i=0; i<100; i++){
if(!strcmp(country[i], nam))
    {  
        return i;
            
    }
    
else if(!strcmp(nam, "end"))
    return -1;
    }
}    

int main(){
  
    printf("num of vertices: ");
    scanf("%d",&vertice);
    int adj[maxVer][maxVer];
    //whole mat set to 0
    for(int i=0;i<vertice;i++){
        for(int j=0;j<vertice;j++){
            adj[i][j]=0;
        }
    }
    for(int i=0;i<vertice;i++){
        printf("enter country name: ");
        scanf("%s",country[i]);

    }
    while(1){
       
        printf ("enter edge from country to country: " );
        scanf("%s %s",from,to);
      
        source=desherIndexDao(from);
        dest=desherIndexDao(to);
      
         if (source == -1 || dest == -1)
            break;

          if (source < 0 || source >= vertice || dest < 0 || dest >= vertice) {
            printf("Invalid input\n");
            continue;
        }   
        adj[source][dest]=1;
        adj[dest][source]=1;
      
    }
    print(adj,vertice);
     printf("DFS traversal result:\n");
    DFS(adj,vertice);
   
              
    return 0;

}