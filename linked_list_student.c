#include<stdio.h>
#include<stdlib.h>

//creation of data type node
struct node{
    int roll;
    int marks;
  
    struct node *next; 
}stu[5];

// declare head pointer globally
struct node *head = NULL;   //this head pointer will store address  of next node(data type-node)
struct node *temp=NULL;  

void create_list(int roll, int marks){
  

struct node *newnode;    
//head=NULL;
newnode=(struct node *)malloc(sizeof(struct node));  //this will allocate space according to node data type, return add of head pointer
//a node has been created, now we want data
newnode->roll=roll;
newnode->marks=marks;
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

void printList() {
  struct node *ptr=head;
    printf("Linked list is: \n");
while(ptr!=NULL){

    printf("Roll:%d ",ptr->roll);
    printf("Marks:%d",ptr->marks);
    printf("\n");
    ptr=ptr->next;
      
   }
}

void insert_beginning()
{  
    struct node *ins_node;
    ins_node=(struct node *)malloc(sizeof(struct node));
    printf("\nenter data you want to insert at the beginning ");
    scanf("%d %d",&ins_node->roll,&ins_node->marks);
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
    scanf("%d %d",&ins_end->roll,&ins_end->marks);
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
    scanf("%d %d",&ins_pos->roll,&ins_pos->marks);
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
    printf("\nAfter deleting from the beginning:\n");
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
    printf("\nAfter deleting from the end:\n");
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
    nextnode=temp->next;
   temp->next=nextnode->next;
   free(nextnode);
    printf("\nAfter deleting from the current position:\n");
   printList();
    

  }


int main()
{
    int roll[5],marks[5],i,tempo;
    printf("enter roll and marks");
    for(i=0;i<5;i++)
    {    
        scanf("%d %d",&stu[i].roll,&stu[i].marks);
    }
     for(i=0;i<5;i++)
     {
    //    roll[i]=stu[i].roll;
        marks[i]=stu[i].marks;
    }
   for(int i=0;i<5;i++)
   {
    for(int j=0;j<5;j++)
    {
      if(marks[i]<marks[j])
      {
        tempo=marks[i];
        marks[i]=marks[j];
        marks[j]=tempo;

        
      }
    }
   }
   //marks[i] contains sorted array of marks
   for(int i=0;i<5;i++)
   {
    for(int j=0;j<5;j++)
    {
       if(marks[i]==stu[j].marks)
       {
        create_list(stu[j].roll,stu[j].marks);
       }


    }

   }



  // for(int i=0;i<5;i++)
   //{create_list(roll[i],marks[i]);}
   printList();
   insert_beginning();
   insert_end();
   insert_any_pos();
   del_beginning();
   del_end();
    del_pos();
    
}