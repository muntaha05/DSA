#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[50];
    char account_number[8];
    char type[10];
    int balance;
    struct node* next;
};
struct node* insert(struct node* head,char *accNum,char *name,char *type,int balance){
    
if(strlen(accNum)==7){
struct node* new=(struct node*) malloc(sizeof(struct node));
    struct node* p;
    p=head;
    if(head!=NULL){
    if(!strcmp(p->account_number,accNum)){
        printf("Account already exists\n\n");
        return head;
    while(p->next!=NULL)
    {
        //&& !strlen(p->account_number)>7 && !strlen(p->account_number)<7)
        p=p->next;

       //return head;
       
    
    if(!strcmp(p->account_number,accNum)){
        printf("Account already exists\n\n");
        return head;
    }
    
    }
    }
    
    p->next=new;
    strcpy(new->name,name);
    strcpy(new->account_number,accNum);
    strcpy(new->type,type);
    new->balance=balance;
    new->next=NULL;
    return head;
    

    }
    else
    {
    head=new;
    strcpy(new->name,name);
    strcpy(new->account_number,accNum);
    strcpy(new->type,type);
    new->balance=balance;
    new->next=NULL;
    return head;
    }
    }
    else{
        printf("invalid account number\n\n");
        return head;
    }
}
void traverse(struct node* head){
    struct node* curr=head;
     while(curr != NULL){
        printf("Name: %s\n",curr->name);
        printf("Account Number: %s\n",curr->account_number);
        printf("Type: %s\n",curr->type);
        printf("Balance %d\n",curr->balance);
        
        curr = curr->next;
    }
    
}
void accountManupulation(struct node* head,char accnum[],int amount,int n){
    struct node* curr=head;
    while(curr->next!=NULL){
        if(!strcmp(curr->account_number,accnum))
        break;
        curr=curr->next;
    }
    if(n==1){
        curr->balance=curr->balance+amount;
    }
    else if(n==2 ){
        if(curr->balance<amount)
        printf("You dont have sufficient balance ");
        else
        curr->balance=curr->balance-amount;
    }
    //return head;

}
int main(){
    int n;
    printf("Number of clients ");
    scanf("%d",&n);
    struct node clients[n];
    struct node* head=NULL;

    for(int i=0;i<n;i++){
        char c=getchar();
        printf("Name: ");
        gets(clients[i].name);
        printf("Account Number: ");
        gets(clients[i].account_number);
        printf("Account type ");
        gets(clients[i].type);
        printf("Account Balance: ");
        scanf("%d",&clients[i].balance);
        clients[i].next=NULL;
    }
    for(int i=0;i<n;i++){
        head=insert(head,clients[i].account_number,clients[i].name,clients[i].type,clients[i].balance);
    }
    printf("Traversimg\n");
    traverse(head);
    printf("\n\n");
    struct node client;

     printf("Name: ");
     char c=getchar();
        gets(client.name);
        printf("Account Number: ");
        gets(client.account_number);
        printf("Account type ");
        gets(client.type);
        printf("Account Balance: ");
        scanf("%d",&client.balance);
        client.next=NULL;
        head=insert(head,client.account_number,client.name,client.type,client.balance);
        printf("\n\n");
        printf("Traversimg\n");
        traverse(head);
        printf("\n\n");

        int m,amount;
        char accnum[8];
        printf("Enter account Number to balance manipulation: ");
        c=getchar();
        gets(accnum);
        printf("What do you want to do?\nType 1 to add\nType 2 to withdraw\n ");
        scanf("%d",&m);
        printf("How much? ");
        scanf("%d",&amount);
        accountManupulation(head,accnum,amount,m);
        printf("Traversimg\n");
        traverse(head);
        
    

}