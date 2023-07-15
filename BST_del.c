#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
     struct node *right;
};
struct node *head=NULL;
struct node *create(int data){
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}
struct node* insert(struct node *root,int data){
    if(root==NULL){
      return  create(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {root->right=insert(root->right,data);}
    return root;
}
 void print_preorder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    print_preorder(root->left);
    print_preorder(root->right);
 }
int main(){
    int choice,data[50];
    printf("how many?");
    scanf("%d",&choice);
   
    for(int i=0;i<choice;i++){
    printf("enter data");
    scanf("%d",&data[i]);
    }
    struct node* root = (struct node*) malloc(sizeof(struct node));
    root=create(data[0]);
     for(int i=1;i<choice;i++){
       root= insert(root,data[i]);
     }
     printf("tree created\n");
    print_preorder(root);
}