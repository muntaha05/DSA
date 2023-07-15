//time com: O(nlogn) space com:O(1)

#include<stdio.h>
#define maxVer 100
int size=0,largest;
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
    if(leftChild<size && array[leftChild]>array[largest]){
       largest=leftChild; 
    }
    if(rightChild<size && array[rightChild]>array[largest]){
    largest=rightChild;
    }
    if(largest!=i){
    swap(&array[i],&array[largest]);
    heapify(array,size,largest);
    }


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
    for(int i=(size/2)-1;i>=0;i--)
    {
        heapify(array,size,i);
    }
  }
    
}
void deleteRoot(int array[],int data){
    int i;
    for(i=0;i<size;i++){
        if(data==array[i])
        break;
    }
    swap(&array[i],&array[size-1]);  //send delete item to last node and delete it
    size--;
    for(int i=size/2-1;i>=0;i--){
        heapify(array,size,i);
    }
}
int extractMax(int array[]){
    if(size<=0)
    printf("heap underflow");
    int max=array[0];
    array[0]=array[size-1];
    size--;
    heapify(array,size,0);
    return max;
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
    MaxHeapInsert(arr,27);
    MaxHeapInsert(arr,46);
    MaxHeapInsert(arr,0);
    MaxHeapInsert(arr,11);
    MaxHeapInsert(arr,72);
    printf("heap created.\n");
    printArray(arr,size);
    deleteRoot(arr,7);
    printf("after delete\n");
    printArray(arr,size);
    MaxHeapInsert(arr,23);
    printArray(arr,size);
    printf("max element is: %d",extractMax(arr));
}