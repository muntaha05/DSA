#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(struct Node* root, int data) {
    if (root->data == -1) {
        return NULL;
    }

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = create(ro, size);
    newNode->right = create(data, size);

    return newNode;
}

/*void Preorder(struct Node* root,int size){
    struct Node* stack[size],*ptr;
    //stack[0]=NULL;
    int top=0;
    
    ptr=root; 
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
void inorder(struct Node* root,int size){
    

     struct Node* stack[1000]; // initialize stack with a fixed size
    int top = 0;
    struct Node* ptr = root;

    while (ptr != NULL || top > 0) {
        while (ptr != NULL) {
            stack[++top] = ptr; // push node to stack
            ptr = ptr->left;
        }

        ptr = stack[top--]; // pop node from stack
        printf("%d ", ptr->data);

        ptr = ptr->right;
    }
}
*/
/*int find_min(int arr[],int size,int root){  //root=7
     int num=-1;
    for(int i=0;i<size;i++){
      
        if(arr[i]>num && arr[i]<7)
        {num=arr[i];}

    }
    return num;

}

int find_max(int arr[],int size,int root){  
     int num=10000;
    for(int i=0;i<size;i++){
      
        if(arr[i]<num && arr[i]>7)
        num=arr[i];

    }
    return num;

}
*/
void postorder(struct Node *root){
     if(root==0){
        return;
     }
     postorder(root->left);
     postorder(root->right);
      printf("%d ",root->data);
}
int main() {
    int arr[] = {1,2,3,5,6,8,9};
    int mid=arr[(0+6)/2];
    



    //int size = sizeof(arr)/sizeof(arr[0]);
    int size=7;
     struct Node* root= (struct Node*) malloc(sizeof(struct Node));
    root->data = mid;
    for(int i=mid-1;i>=0;i--){
     
    //root->left = create(find_min(arr[i],size,root->data), size);
    root->left = create(arr[i], size);
    }
     for(int i=mid;i<=6;i++){
    //root->right = create(find_max(arr[i],size,root->data), size);
    root->right = create(arr[i], size);

    }
    
    printf("Tree created.\n");
    postorder(root);
   
   //  printf("\ninorder is_queue: \n");
    // inorder(root,size);
   
  /*   printf("\npreorder is_queue: \n");
    Preorder(root,size);
     printf("\ninorder is_queue: \n");
    inorder(root,size);
   */
    
   

    return 0;
}