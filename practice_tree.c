#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[50];
    struct node *left;
    struct node *right;
};

struct node *head=NULL;
void findParents(struct node* root, char* person);
void findChildren(struct node* root, char* person);
struct node* create(char names[][50],int size,int i){
   struct node* root=(struct node*)malloc(sizeof(struct node));
   if(i>=size )
   return NULL;
  
   
    strcpy(root->name,names[i]);
    // strcpy(names[2*i+1][50],root->left);
    // strcpy(names[2*1+2][50],root->right);
    root->left=create(names,size,2*i+1);
    root->right=create(names,size,2*i+2);


    //printf("else");
   return root;
}
void findParents(struct node *root, char *person ){
    if(root==NULL)
    return;
  
    if(root->left && strcmp(root->left->name,person)==0)
   {printf("\nParent of %s: %s",person,root->name);
   return;}



    if(root->right && strcmp(root->right->name,person)==0)
   {printf("\nParent of %s: %s",person,root->name);
   return;}
   
   findParents(root->left,person);
   findParents(root->right,person);
}


void findChildren(struct node *root, char *person){
    if(root==NULL)
    return;
  
    if( strcmp(root->name,person)==0)
   { if(root->left !=NULL)
    {printf("\nLeft children of %s: %s",person,root->left->name);}
   if(root->right!=NULL)
   {printf("\nRight children of %s: %s",person,root->right->name);}
   return;}

   findChildren(root->left,person);
   findChildren(root->right,person); 
}
int main(){
    char names[10][50];
    int choice,i=0;
    printf("how many members?");
    scanf("%d",&choice);
    for(i=0;i<choice;i++){
        printf("enter name ");
        scanf("%s",names[i]);
    }
    printf("input done");
    int size=(sizeof(names)/sizeof(names[0]));
   
    struct node *root=create(names,size,0);
    printf("\ntree created\n");
    //printf("%s",root->left);
    findParents(root,root->left->left);
    findChildren(root,root->left);
    
}