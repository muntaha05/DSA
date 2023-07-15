#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char rider[50];
    struct node *next;
};
struct node* head=NULL;
struct node* temp=NULL;
void print(){
   struct node *ptr;
   ptr=head;
   while(ptr!=NULL){
   
    printf("%s ",ptr->rider);
     ptr=ptr->next;
    
   }   
}
void insertEnd(){
    char name[50];
    printf("enter name u want to enter ");
    scanf("%s",name);
    struct node* ins=(struct node*)malloc(sizeof(struct node));
    strcpy(ins->rider,name);
    ins->next=NULL;
    if(head==NULL){
        head=ins;
        temp=ins;
    }
    else{
        temp->next=ins;
        temp=ins;
    }
    // temp=head;
    // while(temp->next!=NULL){
    //     temp=temp->next;
    // }
    // temp->next=ins;
    
}

void del_beg(){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    temp=ptr->next;
    free(ptr);
    ptr=NULL;
    head=temp;


}
int main(){
    int num;
    printf("how many?");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
    insertEnd();
    }
    print();
    printf("\nA ride has arrived\n ");
    del_beg();
    print();
}