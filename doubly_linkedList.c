

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
 //this will produce new nodes
 struct node* createNode(int data){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    return new;
 }

 void ins_beginning(struct node** head,int data){
    struct node* newNode=createNode(data);
    newNode->next=*head;   //0<-newNode->head || newNode<-head->...
    if(*head !=NULL){
        (*head)->prev=newNode;
    }
    (*head)=newNode;  //then head will point to the newNode
 }

 void ins_end(struct node** head,int data){
     struct node* newNode=createNode(data);
     struct node* temp=(*head); //for traversing
     //if node is already created -*(nodeName)
     //if we create then - node* (nodeName)
     if(*head==NULL){
        *head=newNode;
     }
     while(temp->next !=NULL){
        temp=temp->next;
     }
     temp->next=newNode;
     newNode->prev=temp;
 }

 void delete(struct node** head,int data){
    struct node* temp=(*head);
    if(temp !=NULL && temp==data){
        *head=temp->next;
        if((*head) !=NULL){
            (*head) -> prev = NULL;
        }
        free(temp);
        return;
    }
    while(temp != NULL && temp->data !=data){
        temp=temp->next;
    }
    if(temp== NULL){
        return;
    }
    //temp is the node that will be deleted
    if(temp->next !=NULL){  //temp->next is the next node
        temp->next->prev=temp->prev;  //prev of temp->next
    }
    if(temp->prev != NULL){   //temp->prev is the prev node
        temp->prev->next=temp->next;  //next of temp->prev
    }
    free(temp);
 }

 void print(struct node* head){
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
 }
 void printReverse(struct node* head){
    struct node* last=NULL;
     printf("Reversed linked list is:");
    while(head != NULL){
        last=head;
        head=head->next;
    }
    while(last !=NULL){
        printf("%d ",last->data);
        last=last->prev;
    }
    printf("\n");
   
 }
 int main(){
    struct node* head= NULL;
    ins_beginning(&head,22);
    ins_end(&head,23);
    ins_beginning(&head,56);
    ins_end(&head,99);
    printf("Linked list is: ");
    print(head);
    printReverse(head);
    delete(&head,23);
    printf("list after deleting : ");
    print(head);
    delete(&head,56); // delete the first node
    printf("List after deleting the first node: ");
    print(head);
 }