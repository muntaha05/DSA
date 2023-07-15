#include<stdio.h>
#include<time.h>
void swap(int *i,int *j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
int partition (int A[],int p,int r)
{
    int x=A[r];  //x=pivot
    int i=p-1;  //i=low
    for(int j=p;j<r;j++)
    {
        if(A[j]<=x)
        {
            i++;
            swap(&A[i],&A[j]);
        }
        

    }
    swap(&A[i+1],&A[r]);
    return i+1;
}
void quicksort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=partition(A,p,r);  //q=pivot_index
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}
int main()
{
   // int N=5000,initial=0; 
  /* int N=500; 
    int arr[N];
   
    
    for(int i=0;i<N;i++)
    {
        arr[i]=rand()%N;
    }

    */
   int arr[]={2,5,7,1,9,0,5,7,3,7};
   int N=10;
    quicksort(arr,0,N);
    for(int i=0;i<N;i++)
   {printf("%d ",arr[i]);}

   int ticks=clock();
    printf("\nexecution time %f",(float)ticks/CLOCKS_PER_SEC);
    return 0;

}