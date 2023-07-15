#include<stdio.h>
#include<string.h>

char desherNam[100][100];

int graph[100][100];

int desherIndexDao(char nam[]){
    for(int i=0; i<100; i++){
        if(!strcmp(desherNam[i], nam))
            return i;
    }

    return -1;
}


int vis[100];
//
//void dfs(int u){
//    if(vis[u])
//        return;
//    vis[u] = 1;
//
//    for(int v=0; v<100; v++){
//        if(graph[u][v])
//            dfs(v);
//    }
//}

int dis[100];
int queue[100];
int front=0, back=-1;

void push(int x){
    back++;
    queue[back] = x;
}

int getFront(){
    return queue[front];
}

void pop(){
    front++;
}

void bfs(int src){
    dis[src] = 0;

    push(src);

    while(front <= back){
        int u = getFront();
        pop();

        if(vis[u]) //if node has been traversed
            continue;
        vis[u] = 1;

        for(int v=0; v<100; v++){
            if(!vis[v] && graph[u][v]){
                dis[v] = dis[u] + 1;
                push(v);
            }
        }
    }
}

int main(){
    printf("Number of country: ");
    int n;
    scanf("%d", &n);
    getchar();

    for(int i=0; i<n; i++){
        gets(desherNam[i]);
    }

    printf("Number of routes: ");
    int m;
    scanf("%d", &m);
    getchar();

    for(int i=0; i<m; i++){
        char from[100], to[100];

        printf("From: ");
        gets(from);
        int f = desherIndexDao(from);

        printf("To: ");
        gets(to);
        int t = desherIndexDao(to);

        graph[f][t] = graph[t][f] = 1;
    }

    char home[100];
    printf("Start from: ");
    gets(home);
    int h = desherIndexDao(home);

    bfs(h);

    printf("You can go to:\n");
    for(int i=0; i<n; i++){
        if(vis[i])
            printf("%s\n", desherNam[i]);
    }

    return 0;
}