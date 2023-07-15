#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void print(struct node* tail){
    struct node *ptr;
    ptr=tail->next;//head
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=tail->next);
}
struct node* addToempty(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}
struct node *insertEnd(struct node*tail,int data){
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->next=tail->next;
    tail->next=newNode;
    tail=tail->next;
    return tail;
}

struct node* insert_beg(struct node* tail,int data){
    struct node* ins=(struct node*)malloc(sizeof(struct node));
    ins->data=data;
    ins->next=tail->next;
    tail->next=ins;
    return tail;

}

struct node* ins_pos(struct node* tail,int pos,int data){
    struct node* ptr,*ins=(struct node*)malloc(sizeof(struct node));
    ptr=tail->next; //head
    ins->data=data;
    ins->next=NULL;
    while(pos>1){
        ptr=ptr->next;
        pos--;
    }
    ins->next=ptr->next;
    ptr->next=ins;
    if(ptr==tail){
      
       tail=tail->next;
    }
    return tail;
   
    
}

struct node *del_beg(struct node* tail){
    if(tail==NULL){
        return tail;
    }
    if(tail->next==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    struct node *temp;
    temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp=NULL;
    return tail;
}

struct node* del_end(struct node *tail){
     if(tail==NULL){
        return tail;
    }
    if(tail->next==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    struct node *temp;
    temp=tail->next;
    while(temp->next!=tail){
        temp=temp->next;

    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
    return tail;
}

struct node* del_pos(struct node* tail, int pos){
     struct node *temp,*temp2;
    temp=tail->next;
      if(tail==NULL){
        return tail;
    }
    if(tail->next==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    
    while(pos>2){
        temp=temp->next;
        pos--;
    }
    temp2=temp->next;
    temp->next=temp2->next;
    if(temp2==tail)
        tail=temp;
    
    free(temp2);
    temp2=NULL;
    return tail;
}
    
int main(){
    struct node* tail=NULL;
    tail=addToempty(5);
    tail=insertEnd(tail,6);
    tail=insertEnd(tail,67);
     tail=insertEnd(tail,22);
      tail=insertEnd(tail,47);
    tail=ins_pos(tail,2,65);
    print(tail);
    printf("\nafter delewting\n");
    tail=del_end(tail);
    tail=del_beg(tail);
    print(tail);
    printf("\n");
    tail=del_pos(tail,3);
    print(tail);

    
    
}