#include<stdio.h>
void devide(int arr[],int left,int right);
void conquer(int arr[],int left,int mid,int right);
int main()
{
    int arr[10]={2,4,1,6,3,8,6,9,0,5};
   devide(arr,0,9);
   for(int i=0;i<10;i++)
   printf("%d ",arr[i]);

}

void devide(int arr[],int left,int right)
{
    if(left>=right)
    return;
    int mid=(left+right)/2;
    devide(arr,left,mid);
    devide(arr,mid+1,right);
    conquer(arr,left,mid,right);
}

void conquer(int arr[],int left,int mid,int right)
{   int k=0,i,j;
    int temp[right-left+1];
    int index1=left;
    int index2=mid+1;
    while(index1<=mid && index2<=right)
    {
        if(arr[index1]<arr[index2])
        temp[k++]=arr[index1++];
        else temp[k++]=arr[index2++];

    }
    while(index1<=mid)
    {temp[k++]=arr[index1++];}
    while(index2<=right)
    {temp[k++]=arr[index2++];}
    for(i=0,j=left;i<(right-left+1);i++,j++)
    arr[j]=temp[i];
}