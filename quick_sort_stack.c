#include<stdio.h>
void quicksort_stack(int arr[],int N, int low, int up){
int top=0;
while (top>0)
{if(N>1)
{
    top++;
    
}
low[top]=1;
up[top]=N;
}
int beg=low[top];
int end=up[top];
top--;
int loc=pivot(arr,beg,end);
if(beg<loc-1)
{
    top++;
    low[top]=beg;
    up[top]=loc-1;
}
if(loc+1<end)
{
   top++;
   low[top]=loc+1;
   up[top]=end;
}

}
int pivot(int arr[], int beg, int end){
int left=beg;
int right=end;
int loc=beg;
while(arr[loc]<=arr[right])
{
    if(loc!=right)
    {
        right=right-1;
    }
    if(loc==right)
    {
        return loc;
    }
}
while(arr[loc]>=arr[left])
{
    if(loc!=left)
    {
        left=left=1;

    }
    if(loc==left)
    {
        return loc;
    }
}
if(arr[loc]<arr[left])
{
    int temp=arr[loc];
    arr[loc]=arr[left];
    arr[left]=temp;
    loc=left;

     if(loc!=right)
    {
        right=right-1;
    }
    if(loc==right)
    {
        return loc;
    }
}
}
int main()
{
    int arr[]={2,6,1,8,5,8,4,8,4,2};
    quicksort_stack(arr,10,0,9);
}