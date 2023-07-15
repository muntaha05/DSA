//accepted

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int arr[], int size, int i) {
    if (i >= size || arr[i] == -1) {
        return NULL;
    }

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = arr[i];
    newNode->left = create(arr, size, 2*i+1);
    newNode->right = create(arr, size, 2*i+2);

    return newNode;
}
//preorder: root - left - right
/*void preorder(struct Node *root){
     if(root==0){
        return;
     }
     
     
     printf("%d ",root->data);
     preorder(root->left);
     preorder(root->right);
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
*/
//postorder : left - right - root
void postorder(struct Node *root){
     if(root==0){
        return;
     }
     postorder(root->left);
     postorder(root->right);
      printf("%d ",root->data);
}


void inorder(struct Node* root,int size) {
    //struct Node* stack[size];
    if (root == NULL) {
        return;
    }
    struct Node* stack[size];
    int top = -1;
    while (1) {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
        if (top == -1) {
            break;
        }
        root = stack[top--];
        printf("%d ", root->data);
        root = root->right;
    }
}

void Preorder(struct Node* root,int size){
    if(root==NULL){
        return;
    }
    struct Node* stack[size];
    int top=-1;
    stack[++top]=root;
    while(top>=0){
      root = stack[top--];  
      printf("%d ", root->data);  
      if(root->right !=NULL){
          stack[++top]=root->right;
      }
      if(root->left !=NULL){
          stack[++top]=root->left;
      }
    }
   
}
int main() {
    int arr[] = {4, 5, 10, 7, 8, -1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    struct Node* root = create(arr, size, 0);
    printf("Tree created.\n");
   
     printf("\ninorder is_queue: \n");
     inorder(root,size);
   
     printf("\npreorder is_queue: \n");
    Preorder(root,size);
    printf("\npostorder is_queue: \n");
    postorder(root);
   

    return 0;
}
