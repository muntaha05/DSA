#include<stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int data) {
  
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
struct Node *insert(struct Node *root,int data){
    if(root==NULL)
    return create(data);
    if(data<root->data){
        root->left=insert(root->left,data);
       
    }
    else{
        root->right=insert(root->right,data);
        
    }
    return root;
    
}
//preorder: root - left - right
void Preorder(struct Node *root){
     if(root==NULL){
        return;
     }
     
     
     printf("%d ",root->data);
     Preorder(root->left);
     Preorder(root->right);
    
}

//inorder : left - root - right
void inorder(struct Node *root){
   if(root==0){
        return;
     }
    inorder(root->left);
     printf("%d ",root->data);
    inorder(root->right);
    // printf("%d ",root->data);
}
struct Node* findMinVal(struct Node *root){
    struct Node* current= root;
    while(current && current->left!=NULL){
        current=current->left;
    }
    return current;

}

struct Node* findMaxVal(struct Node *root){
    struct Node* current= root;
    while(current && current->right!=NULL){
        current=current->right;
    }
    return current;

}
void level_order(struct Node* root,int size)
{
    struct Node* queue[size];
    int front=0,rear=0,level=1;
    if(root==NULL)
    return;
    queue[rear++]=root;
    
    while(front<rear)
    {
        struct Node *temp = queue[front++];
        printf("%d ", temp->data);
        level--;
        
        if(temp->left!=NULL)
        queue[rear++]=temp->left;
        if(temp->right!=NULL)
        queue[rear++]=temp->right;
        if(level==0){
        printf("\n");
        level = rear-front;
        }
    }
}
struct Node* search(struct Node* root, int target){
  if(root==NULL || root->data==target)
  return root;
  else{
    if(target<root->data)
    {
        return search(root->left, target);
    }
    if(target>root->data)
    {
       return search(root->right, target);  
    }
    return root;
  }
}
//time com: O(height)  space com:O(1) for successor
struct Node* successor(struct Node* root){
    if(root->right!=NULL){
        return findMinVal(root->right);
    }
}
struct Node* predecessor(struct Node* root){
    if(root->left!=NULL){
        return findMaxVal(root->left);
    }
}
int main() {
    int arr[] = {15,6,18,3,7,17,20,2,4,13,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    struct Node* root = (struct Node*) malloc(sizeof(struct Node));
    root = create(arr[0]);
    for(int i=1;i<size;i++){
     //root = create(arr[i]);
     root=insert(root,arr[i]);
    }
    printf("Tree created.\n");  
    level_order(root,size);
    printf("\n");
    printf("preorder is_queue: \n");
    Preorder(root);
  
   printf("\ninorder is_queue: \n");
   inorder(root);
   printf("\nminimum value is: %d\n", findMinVal(root)->data);
   printf("maximum value is: %d", findMaxVal(root)->data);
   printf("\nsuccessor of %d is %d",(root->left)->data,successor(root->left)->data);
   printf("\npredecessor of %d is %d",(root->left)->data,predecessor(root->left)->data);
   //search(root,5);
   struct Node* targetNode = search(root, 5);
    if (targetNode != NULL)
        printf("\nTarget found.\n");
    else
        printf("\nTarget not found.\n");

    return 0;
}
