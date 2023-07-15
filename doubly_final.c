//accepted
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
//int len=0;
void print(){
    printf("Linked list is: ");
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
       // len++;
    }
    printf("\n");
}
void reverse_print(){
   struct node* ptr=tail;
     printf("Reversed linked list is: ");
   
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->prev;
    }
    printf("\n");
    }


void create(int data){
    struct node *item=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    item->data=data;
    item->prev=NULL;
    item->next=NULL;
    if(head==NULL){
        head=item;
        // temp=item;
        tail=item;
    }
    else{// h->1->2->3
        temp = head;
        while(temp->next!= NULL) 
        {temp = temp->next;}
        temp->next = item;
        item->prev = temp;
        tail = item;   //this denotes that every last item added to is tail
        // item->prev=temp;
        // temp->next=item;
        // temp=item;
    }

}
void insert_beginning(){
    struct node *item=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    printf("\nenter data you want to insert at the beginning ");
    scanf("%d",&item->data);
    item->next = item->prev = NULL;
    head->prev=item;
    item->next=head;
    head=item;
    print();
}
void insert_end(){
   struct node *item=(struct node *)malloc(sizeof(struct node));
    printf("\ninsert data you want to insert at the end ");
    scanf("%d",&item->data);
    item->next = item->prev = NULL;
    // while(temp->next!=NULL)
    // {
    //     temp=temp->next; //this will store node add everytime into temp pointer until last node
    // }
    tail->next=item;
    item->prev=tail;
    tail=item;
    print();
}

void insert_any_pos()
{   int pos,i=1;
    struct node *ins_pos;
    ins_pos=(struct node *)malloc(sizeof(struct node));
    struct node *temp;
    printf("\nenter position ");
    scanf("%d",&pos);
    ins_pos->next = ins_pos->prev = NULL;
    //start traversing
    temp=head;
    while(i<(pos-1))
    {
        temp=temp->next;
        i++;
    }
    // h->0 1 2 3 5 6 7
    printf("\nenter data ");
    scanf("%d",&ins_pos->data);
    ins_pos->next=temp->next;
    ins_pos->prev=temp;
    temp->next->prev = ins_pos;
    temp->next=ins_pos;
    print();
}

 void del_beginning()
   {// h>1 2 3 4
    struct node *temp;
    temp = head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    printf("\nAfter deleting first element:\n ");
    print();
   }

 void del_end()
  {
    tail = tail->prev;
    free(tail->next);
    tail->next= NULL;
    // temp=head;
    // while(temp->next!=NULL)
    // {
        
    //     temp=temp->next;
    // }    
    //     if(temp==head)
    //     {
    //         head=NULL;
    //        // free(temp);

    //     }
    //     temp2=temp->prev;
    //     temp2->next=NULL;
    //    free(temp);
    //    temp=NULL;
    printf("\nAfter deleting last element\n");
    print();
  }


void del_pos()
  {
    struct node *temp;
    int pos,i=1;
    printf("\nenter position you want to delete ");
    scanf("%d",&pos);
    temp=head;
    //h->1->2->3->4->t
    while (pos>=1)
    {
        temp=temp->next;
        pos--;
    }
    //temp is the node we want to delete
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
    // temp2=temp->prev;
    // temp2->next=temp->next;
    // temp->next->prev=temp2;
    // free(temp);
    // temp=NULL;
   printf("\nAfter deleting given positioned element:\n");
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
   insert_beginning();
   insert_end();
   insert_any_pos();  
   reverse_print();
   del_beginning();
   del_end();
   del_pos();
   reverse_print();
}