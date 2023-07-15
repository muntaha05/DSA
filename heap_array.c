#include <stdio.h>
#define maxVer 100
int size = 0,largest;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* create(int data) {
   /* if (i >= size || arr[i] == -1) {
        return NULL;
    }
    */

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
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int array[],int size, int i){
    int leftChild,rightChild;
    largest=i;
    leftChild=2*i+1;
    rightChild=2*i+2;
    if(leftChild>array[largest]){
       largest=leftChild; 
    }
    if(rightChild>array[largest]){
    largest=rightChild;
    }
    swap(&array[i],&array[largest]);


}
void MaxHeapInsert(int array[],int data){
    if (size == 0)
  {
    array[0] = data;
    size += 1;
  }
  else{
    array[size]=data;
    size++;
    for(int i=(size/2)-1;i>0;i--)
    {
        heapify(array,size,i);
    }
  }
    
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

int main() {
    int arr[maxVer];
    //int size = sizeof(arr)/sizeof(arr[0]);
    MaxHeapInsert(arr,2);
    MaxHeapInsert(arr,4);
    MaxHeapInsert(arr,0);
    MaxHeapInsert(arr,1);
    MaxHeapInsert(arr,7);
    printf("heap created.\n");
    //printArray(arr,size);
       struct Node* root = (struct Node*) malloc(sizeof(struct Node));
    root = create(arr[0]);
    for(int i=1;i<size;i++){
     //root = create(arr[i]);
     root=insert(root,arr[i]);
    }
    //printf("Tree created.\n");  
    level_order(root,size);
    printf("\n");
}