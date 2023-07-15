#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* addToEmpty(int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}
struct node* insert_end(struct node* tail, int data){
    struct node* newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
     newNode->next=tail->next;  //tail is the previous node (circular)
     tail->next=newNode;
     tail=tail->next;  //traverse ahead
     return tail;
}

struct node* insert_beg(struct node* tail,int data){
    struct node* ins_end=malloc(sizeof(struct node));
    //tail->next is actually the address of head or pointing to head
   ins_end->data=data;
   ins_end->next=NULL;
   ins_end->next=tail->next;
   tail->next=ins_end;
   return tail;  


}

struct node* ins_pos(struct node* tail){
    int pos;
    printf("enter position of insertion:");
    scanf("%d",&pos);
    struct node* ptr=tail->next; //head
    struct node* ins_pos=malloc(sizeof(struct node));
    printf("\nenter data: ");
    scanf("%d",&ins_pos->data);
    ins_pos->next=NULL;
    while(pos>1){  //pos=5 so 4 kombe
        ptr=ptr->next; //ptr->next=5,ptr=4
        pos--;
    }
    ins_pos->next=ptr->next; //given er add a 5 rakhlam
    ptr->next=ins_pos; //4 er add a given
   if(ptr==tail){
      
       tail=tail->next;
    }
    return tail;
   

}

struct node* del_beg(struct node* tail){
    printf("\nlist after deletion of first element:\n");
    if(tail==NULL)
    {
        return tail;  //empty list or return NULL
    }
    if(tail->next==tail){  //there is 1 element in the list
        free(tail);
        tail=NULL;
        return tail;
    }
    
    struct node* temp;
    temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp=NULL;
    return tail;
}


struct node* del_end(struct node* tail){
     printf("\nlist after deletion of last element:\n");
    if(tail==NULL)
    {
        return tail;  //empty list or return NULL
    }
    struct node* temp=tail->next;
    if(tail->next==tail){  //there is 1 element in the list
        free(tail);
        tail=NULL;
        return tail;
    }
    //traverse and go to the second last node
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
    return tail;
}


struct node* del_pos(struct node* tail){
     int pos;
     printf("\nenter position you want to delete:\n");
     scanf("%d",&pos);
     printf("\nlist after deletion of given positioned element:\n");
    if(tail==NULL)
    {
        return tail;  //empty list or return NULL
    }
    struct node* temp=tail->next;
    if(tail->next==tail){  //there is 1 element in the list
        free(tail);
        tail=NULL;
        return tail;
    }
    while(pos>2){
        temp=temp->next;
        pos--;
    }
    //6 ta node thakle temp ase head(1) a.pos 5 dile 3bar
    //agay temp=4, temp2=5 hobe  
    struct node* temp2=temp->next; //temp2 is the node we want to delete
    temp->next=temp2->next;
    if(temp2==tail)
    tail=temp;
    free(temp2);
    temp2=NULL;
    return tail;

    
}  
void print(struct node* tail){
    if(tail==NULL){
        printf("no node in the list");

    }
    else{
        struct node *ptr=tail->next;  //tail->next means address of head
        do{
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }while(ptr!=tail->next);
    }
    printf("\n");
}


int main(){
    struct node* tail=NULL;
   
     int i,n,data,data_end;
    printf("\nnumber of nodes in linked list:");
    scanf("%d",&n);
    if(n==0)  printf("empty list");
    printf("enter element 1:");
    scanf("%d",&data);
    tail=addToEmpty(data);
    for(i=1;i<n;i++){
        printf("enter element %d: ",i+1);
        scanf("%d",&data);
        tail=insert_end(tail,data);
    }
    printf("enter element to insert at end: ");
    scanf("%d",&data_end);
     tail=insert_end(tail,data_end);
    tail=insert_beg(tail,88);
    tail=ins_pos(tail);
    print(tail);
    tail=del_beg(tail);
    print(tail);
    tail=del_end(tail);
    print(tail);
    tail=del_pos(tail);
    print(tail);
    return 0;
}