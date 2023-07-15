// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
int partition(int arr[],int low,int high);
void quicksort(int arr[],int low, int high){
    if(low<high)
    {
       int pivot_ind= partition(arr,low,high);
       quicksort(arr,low,pivot_ind-1);
       quicksort(arr,pivot_ind+1,high);
    }
}
int partition(int arr[],int low,int high){
    int i=low-1;
    int pivot=arr[high];
    //j loop var
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
        
   
    int temp=pivot;
    pivot=arr[i];
    arr[i]=temp;
    return i;
    
}
int main() {
   int arr[]={2,7,4,7,1,9,0,4,6};
   //int size=(sizeof(arr))/4;
   int size=9;
   quicksort(arr,0,(size-1));
   for(int i=0;i<size;i++)
   {
       printf("%d ",arr[i]);
   }
    return 0;
}