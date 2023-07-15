#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct  Node*right;
}Node;

Node *createNode(int data){
    Node* result=malloc(sizeof(struct Node));
    if(result !=NULL){
        result->left=NULL;
        result->right=NULL;
        result->data=data;
    }
   return result;
}
void print(Node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    printf("left\n");
    print(root->left);
    printf("right\n");
    print(root->right);
}
int main(){
    Node *node1= createNode(10);
     Node *node2= createNode(18);
      Node *node3= createNode(12);
       Node *node4= createNode(9);
        Node *node5= createNode(5);
         Node *node6= createNode(2);

    node1->left=node2;
    node1->right=node3;
    node3->left=node4;
    node2->right=node5;
    node5->left=node6;

   print(node1);
         free(node1);
         free(node2);
         free(node3);
         free(node4);
         free(node5);
         free(node6);
}