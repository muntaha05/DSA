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
//pre order = root - left - right
void Preorder(struct Node* root,int size){
    struct Node* stack[size],*ptr;
    //stack[0]=NULL;
    int top=0;
    //stack[top]=root;
    ptr=root; //top=0
    
    
     //ptr->data=root->data;
     while(ptr!=NULL){      
           printf("%d ",ptr->data);
            // top--;//top=-1
            if(ptr->right !=NULL){
         
         stack[top++]=ptr->right;
        //  top++;
     }
    
          if(ptr->left !=NULL){
         ptr=ptr->left;
         //stack[top]=ptr;
         //top++;
     }
     else{
         if(top>0)
         {ptr=stack[--top];//popping right sub tree 
        
         }  
        else ptr=NULL;
     }
    
}
}

//left - root - right 
void inorder(struct Node* root,int size){
   
     struct Node* stack[1000]; // initialize stack with a fixed size
    int top = 0;
    struct Node* ptr = root;

    while (ptr != NULL || top > 0) {
        while (ptr != NULL) {
            stack[top++] = ptr; // push node to stack
            ptr = ptr->left;
        }

        ptr = stack[--top]; // pop node from stack
        printf("%d ", ptr->data);

        ptr = ptr->right;
    }
}

//post order= left - right - root
void postorder(struct Node* root, int size){
    struct Node *stk1[1000]={NULL},*stk2[1000]={NULL},*ptr;
    ptr=root;
    int top1=0,top2=0;
    while(ptr->left!=NULL && ptr->right!=NULL){
    stk1[top1++]=ptr;
    while(top1>0){
    
    ptr=stk1[--top1];//pop
    

    stk2[top2++]=ptr;//push to stack 2
    if(ptr->left !=NULL)
    {stk1[top1++]=ptr->left;}
    if(ptr->right !=NULL){
    stk1[top1++]=ptr->right;
    }
   
    //ptr=ptr->left;
    }
    }
  
     while (top2 > 0) {
        struct Node *node = stk2[--top2];
        printf("%d ", node->data);
    }


}

void level_wise_printing(struct Node *root,int size){
    struct Node *queue[size];
    int front=0,rear=0,level=1;
    if(root==NULL)
    return;
    queue[rear++]=root;
    while(front<rear){
        struct Node *temp=queue[front++];
        printf("%d  ",temp->data);
        level--;
        //queue= FIFO
        if(temp->left!=NULL)
         queue[rear++]=temp->left;
        if(temp->right!=NULL)
         queue[rear++]=temp->right; 
         if(level==0)
         {printf("\n");
         level=rear-front;
         }
    }

}

int main() {
    int arr[] = {4, 5, 10, 7, 8, -1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    struct Node* root = create(arr, size, 0);
    printf("Tree created.");
    printf("\npreorder is_queue: \n");
    Preorder(root,size);
    printf("\ninorder is_queue: \n");
    inorder(root,size);
    printf("\npostorder is_queue: \n");
    postorder(root,size);
    printf("\nlevelwise printing\n");
    level_wise_printing(root,size);

    return 0;
}





 