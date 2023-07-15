#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    //int index;
    char name[10],phoneNumber[11];
   struct node *next;
   struct node *prev;
};
struct node *head= NULL;
struct node *tail=NULL;

void print(){
    struct node* ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("Name: %s  Phone num: %s",ptr->name,ptr->phoneNumber);
        ptr=ptr->next;

    }
    printf("\n");
}
void createname(char nam[10],char num[11]){
   
    struct node *temp=(struct node*)malloc(sizeof(struct node)),*temp2;
    strcpy(temp->name,nam);
    strcpy(temp->phoneNumber,num);
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
        temp->prev=temp2;
        tail=temp;

    }
}
void ins_given_pos(int pos){
    struct node *info=(struct node*)malloc(sizeof(struct node)),*temp;
     char nam[10],num[11];
    printf("enter name and contact:");
    scanf("%s %s",nam,num);
    strcpy(info->name,nam);
    strcpy(info->phoneNumber,num);
    temp=head;
    int i=1;
    while(i<=pos-1){
        temp=temp->next;
        i++;
    }
     info->prev=temp;
    info->next=temp->next;
    if(temp->next != NULL){
        temp->next->prev = info;
    }
     temp->next=info;
   // temp->next->prev=info;
   
   // tail=info;
}
int main(){
    char nam[10],num[11];
    int number;
    printf("how many?");
    scanf("%d",&number);
    for(int i=0;i<number;i++){
    
    printf("enter name and contact:");
    scanf("%s %s",nam,num);
        createname(nam,num);
    }
    print();
    printf("now insert at 8th pos");
    ins_given_pos(8);
    print();
}
