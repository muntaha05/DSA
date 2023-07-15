#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

void print(){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void Reverseprint(){
    struct node *ptr=tail;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->prev;
    }
}
void create(int data){
   
    
    struct node *ins,*temp;
    ins=(struct node*)malloc(sizeof(struct node));
    ins->data=data;
    ins->prev=ins->next=NULL;
    if(head==NULL){
        head=ins;
        tail=ins;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ins;
        ins->prev=temp;
        tail=ins;
    }

  
}
void ins_given_pos(int data,int pos){
    struct node * ins=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    ins->data=data;
    ins->next=ins->prev=NULL;
    int i=1;
    temp=head;
    while(i<pos-1){
       temp=temp->next;
       i++;
    }
    //temp->next=ins;
    ins->prev=temp;
    ins->next=temp->next;
    temp->next=ins;
    temp->next->prev=ins;



}
void del_beg(){
    struct node *temp=(struct node*)malloc(sizeof(struct node));;
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    temp=NULL;
}
int main(){
    int num,info;
    printf("how many?");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        printf("enter data ");
        scanf("%d",&info);
        create(info);
    }
    print();
    printf("\n");
    Reverseprint();
    del_beg();
    printf("\n");
    print();
    ins_given_pos(234,3);
     printf("\n");
    print();
    

}