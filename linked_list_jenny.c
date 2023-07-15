#include<stdio.h>
#include<stdlib.h>
//creation of data type node
struct node{
    int data;
  
    struct node *next; 
};

// declare head pointer globally
struct node *head = NULL;   //this head pointer will store address  of next node(data type-node)
struct node *temp=NULL;     //this will act as a temporary node


void printList() {
  struct node *ptr=head;
    printf("Linked list is: ");
while(ptr!=NULL){

    printf("%d ",ptr->data);
    ptr=ptr->next;
      
   }
}

void create_list(int data){
  

struct node *newnode;    
newnode=(struct node *)malloc(sizeof(struct node));  //this will allocate space according to node data type, return add of head pointer
//a node has been created, now we want data
newnode->data=data;
newnode->next=0;
if(head==NULL)
{
    head=newnode;
    temp=newnode;
}
else{
    temp->next=newnode;   //this will put add of next node into prev one's add part
    temp=newnode;   //this will point to next node
}
}

void insert_beginning()
{  
    struct node *ins_node;
    ins_node=(struct node *)malloc(sizeof(struct node));
    printf("\nenter data you want to insert at the beginning ");
    scanf("%d",&ins_node->data);
    //first we need to store add of head into new inserted node
    ins_node->next=head;
    //then head should be updated
    head=ins_node;
    printList();

}

void insert_end()
{
    struct node *ins_end;
    ins_end=(struct node *)malloc(sizeof(struct node));
    printf("\ninsert data you want to insert at the end ");
    scanf("%d",&ins_end->data);
    ins_end->next=0;
    temp=head;
    //traverse list until end
    while(temp->next!=NULL)
    {
        temp=temp->next; //this will store node add everytime into temp pointer until last node
    }
    temp->next=ins_end;
    printList();
}

void insert_any_pos()
{   int pos,i=1;
    struct node *ins_pos;
    ins_pos=(struct node *)malloc(sizeof(struct node));
    printf("\nenter position ");
    scanf("%d",&pos);
   
    //start traversing
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;

    }
    printf("\nenter data ");
    scanf("%d",&ins_pos->data);
    ins_pos->next=temp->next;
    temp->next=ins_pos;
    printList();



}


                                         //deletion part
   void del_beginning()
   {
    temp=head;
    if(head==NULL)
    printf("empty");
    else
    {head=head->next;
    free(temp);
    }
    printf("\n");
    printList();
   }  

  void del_end()
  { struct node *prevnode;
    temp=head;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }    
        if(temp==head)
        {
            head=NULL;
           // free(temp);

        }
        else
        {prevnode->next=NULL;
       
        } free(temp);
    printf("\n");
    printList();
  }


  void del_pos()
  { struct node *nextnode;
    int pos,i=1;
    printf("\nenter position you want to delete ");
    scanf("%d",&pos);
    temp=head;
    while (i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;  //delete temp->next or nextnode
   temp->next=nextnode->next; //temp->next er khali jaygay nextnode->next
   free(nextnode);
   printf("\n");
   printList();
    

  }
int main()
{
    int data;
    int choice;
    printf("how many inputs?");
    scanf("%d",&choice);
    for(int i=0;i<choice;i++)

    {printf("enter data ");
    scanf("%d",&data);
    
    create_list(data);
    }
    
    printList();
   insert_beginning();
   insert_end();
   insert_any_pos();
   del_beginning();
   del_end();
    del_pos();

    return 0;


}