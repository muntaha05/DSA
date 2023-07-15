#include<stdio.h>
#include<string.h>
#define maxVer 100
void enqueue(int item);
int dequeue();
int vertice;
int queue[maxVer];
 int front=-1,rear=-1;

  void enqueue(int item){
    if(rear== maxVer-1){
        printf("queue overflow");
        return;
    }
    if(front==-1)
    front=0;
    rear++;
    queue[rear]=item;
}

    int dequeue(){
    int item;
    if(front==-1 || front>rear){
        printf("queue underflow\n ");
        return -1;
    }
    else{
    item=queue[front];
    front++;
     if (front > rear) {
            front = -1;
            rear = -1;
        }
    return item;
    }

}
void print(int adj[][maxVer],int vertice){
    printf("\ngraph represented in adjacency matrix:\n");
    for(int i=0;i<vertice;i++){
        for(int j=0;j<vertice;j++){
            printf("  %d  ",adj[i][j]);
        }
        printf("\n");
    }
}
void BFS(int adj[][maxVer],int vertice, int s){  
   //prev[]= prev root vertex , d[]= discoverd vertex , s=root vertex
    char color[maxVer][10],prev[maxVer],V[vertice];
    int d[maxVer];
    int result[maxVer];
    char mat[10][maxVer]={"Greenland","China","India","Pakistan","Iran","Bangladesh","Turkey","USA","Canada","Thailand"};
     //printf("%s",mat[1]);
    for(int i=0;i<vertice;i++){
       
            if(i!=s){
                //color[i][10]="white";
                strcpy(color[i],"white");
                prev[i]=-1;
                d[i]=__INT_MAX__;  //set an infinte val in d[]
            }
    }     //set in root***
          //color[s][10]="grey";
           strcpy(color[s],"grey");
          prev[s]=-1;
          d[s]=0;

         
          enqueue(s);
          
          while(front!=-1){
            int u=dequeue();  //u= previous rooted vertex will be stored temporarily
            printf("%s ",mat[u]);
            
            
            
            
             
             for(int i=0;i<vertice;i++){
        
            if(adj[u][i]==1 && strcmp(color[i], "white") == 0){
                //the node which has not been traversed yet
                strcpy(color[i],"grey");
                d[i]=d[u]+1;
                prev[i]=u;
                enqueue(i);      
    }
          }
             strcpy(color[u],"black");
          }
          /*for(int i=0;i<vertice;i++){
            printf("\ndistance is: %d ",d[i]);
          }
          */
        

}
int main(){
    int source,dest;
    printf("num of countries: ");
    scanf("%d",&vertice);
    int adj[maxVer][maxVer],start;
    for(int i=0;i<vertice;i++){
        for(int j=0;j<vertice;j++){
            adj[i][j]=0;
        }
    }
    
    printf("Enter relation:\n1.Greenland\n2.China\n3.India\n4.Pakistan\n5.Iran\n6.Bangladesh\n7.Turkey\n8.USA\n9.Canada\n10.Thailand");

    while(1){
        printf("\nenter flights from country (0 to %d) to (0 to %d): ",vertice,vertice);
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
    print(adj,vertice);
    printf("Enter starting country: ");
    scanf("%d", &start);
     printf("She can travel: \n");
    BFS(adj,vertice,start);
    return 0;

}