#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//creation of data type node
struct node{
    char data[50];
  
    struct node *next; 
};

// declare head pointer globally
struct node *head = NULL;   //this head pointer will store address  of next node(data type-node)
struct node *temp=NULL;     //this will act as a temporary node


void printList() {
  struct node *ptr=head;
    printf("Riders queue is: ");
while(ptr!=NULL){

    printf("%s ",ptr->data);
    ptr=ptr->next;
      
   }
}

void create_list(char data[50]){
  

struct node *newnode;    
newnode=(struct node *)malloc(sizeof(struct node));  //this will allocate space according to node data type, return add of head pointer
//a node has been created, now we want data
strcpy(newnode->data,data);
newnode->next=NULL;
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



void insert_end()
{
    struct node *ins_end;
    ins_end=(struct node *)malloc(sizeof(struct node));
    printf("\ninsert data you want to insert at the queue ");
    scanf("%s",ins_end->data);
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
    //printList();
   }  
                                       
 
  void del_pos()
  { struct node *nextnode,*find;
    int pos,i=1;
    char name[50];
    printf("\nenter name you want to delete ");
    scanf("%s",name);
    //printf("%s",name);
    temp=head;
    find=head;
    for(i=0;i<(find->next!=NULL);i++){
        find=find->next;
        if(!strcmp(name,find->data))
        {
            pos=i;
            break;
        }
    }
    
    while (i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
   temp->next=nextnode->next;
   free(nextnode);
   printf("\n");
   printf("%s has been removed",name);
   printList();
    

  }
int main()
{
    char data[50];
    int choice,ques1,ques2;
    printf("how many riders?");
    scanf("%d",&choice);
    for(int i=0;i<choice;i++)

    {printf("enter names ");
    scanf("%s",data);
    
    create_list(data);
    }
    
    printList();
  // insert_beginning();
  printf("\nDo you want to book a seat for anyone?\nPress\n1.yes  2.No\n");
  scanf("%d",&ques1);
  if(ques1==1){
   insert_end();
  }
  if(ques1==2){
    printf("thank you\n");
  }
   printf("\nDo you want to delete a seat for anyone?\nPress\n1.yes  2.No\n");
   scanf("%d",&ques2);
   if(ques2==1){

    del_pos();
   }
    if(ques2==2){
    printf("thank you\n");
  }
  printf("\nA ride has arrived.First 3 please come ahead");
  del_beginning();
  del_beginning();
  del_beginning();
  printList();
    return 0;


}