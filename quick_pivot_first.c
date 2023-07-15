
#include<stdio.h>
void swap(int *i,int *j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
int partition (int A[],int p,int r)
{
    int x=A[p];
    int i=p,j=r;
    while(i<j)
  {  while(A[i]<=x)
    {
        i++;
    }
    while(A[j]>x)
    {
        j--;
    }
   if(i<j)
   { swap(&A[i],&A[j]);}

  }
  swap(&A[p],&A[j]);
    return j;
}
void quicksort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}
int main()
{
    int arr[10]={2,6,3,5,7,2,7,9,5,24};
    quicksort(arr,0,9);
    for(int i=0;i<10;i++)
   {printf("%d ",arr[i]);}

}
