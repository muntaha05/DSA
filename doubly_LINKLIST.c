
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *temp=NULL;  //for traverse
struct node *temp2=NULL;
int len=0;
void print(){
    printf("Linked list is: ");
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
        len++;
    }
    printf("\n");
}
void reverse_print(){
   struct node* last=temp;
     printf("Reversed linked list is: ");
   
    while(last !=NULL){
        printf("%d ",last->data);
        last=last->prev;
    }
    printf("\n");
    }


void create(int data){
    struct node *item=(struct node*)malloc(sizeof(struct node));
    item->data=data;
    item->prev=NULL;
    item->next=NULL;

    if(head==NULL){
        head=item;
        temp=item;
    }
    else{
        item->prev=temp;
        temp->next=item;
        temp=item;
    }

}
void insert_beginning(){
     struct node *item=(struct node*)malloc(sizeof(struct node));
     printf("\nenter data you want to insert at the beginning ");
    scanf("%d",&item->data);
     head->prev=item;
     item->next=head;
     head=item;
     print();
}
void insert_end(){
   struct node *item=(struct node*)malloc(sizeof(struct node));
 printf("\ninsert data you want to insert at the end ");
    scanf("%d",&item->data);
   item->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next; //this will store node add everytime into temp pointer until last node
    }
   temp->next=item;
   item->prev=temp;
   temp=item;
   print();
}

void insert_any_pos()
{   int pos,i=1;
    struct node *ins_pos;
    ins_pos=(struct node *)malloc(sizeof(struct node));
    printf("\nenter position ");
    scanf("%d",&pos);
   
    //start traversing
    temp=head;
    while(i<(pos-1))
    {
        temp=temp->next;
        i++;

    }
    printf("\nenter data ");
    scanf("%d",&ins_pos->data);
    ins_pos->prev=temp;
    ins_pos->next=temp->next;
    temp->next=ins_pos;
    ins_pos->next->prev=ins_pos;
    print();



}

 void del_beginning()
   {
   
    head=head->next;
  
    free(head->prev);
    
    head->prev=NULL;
    
    printf("\nAfter deleting first element:\n ");
    print();
   }

 void del_end()
  {
    temp=head;
    while(temp->next!=NULL)
    {
        
        temp=temp->next;
    }    
        if(temp==head)
        {
            head=NULL;
           // free(temp);

        }
        temp2=temp->prev;
        temp2->next=NULL;
       free(temp);
       temp=NULL;
    printf("\nAfter deleting last element\n");
    print();
  }


void del_pos()
  {
    int pos,i=1;
    printf("\nenter position you want to delete ");
    scanf("%d",&pos);
    temp=head;
    while (pos>1)
    {
        temp=temp->next;
        pos--;
    }
    //temp is the node we want to delete
    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    temp=NULL;
   printf("\nAfter deleting inserted positioned element:\n");
   print();
    

  }



int main(){
     int data;
    int choice;
    printf("how many inputs?");
    scanf("%d",&choice);
    for(int i=0;i<choice;i++)

    {printf("enter data ");
    scanf("%d",&data);
    
    create(data);
    }
     print();
   //insert_beginning();
   //insert_end();
   insert_any_pos();  
 
   reverse_print();
   del_beginning();
   del_end();
   del_pos();
   reverse_print();
}