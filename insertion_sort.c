#include<stdio.h>
void insertion_sort(int list[],int N)
{
    int temp[100];
    for(int i=2;i<N;i++)
    {  int temp=list[i];
       int j=i-1;
       while(j>=1 && list[j]>temp)
       {
        list[j+1]=list[j];
        j--;
       }
       list[j+1]=temp;
    
    
    }
}
int main()
{
    int list[]={2,5,3,6,7};
    int size=sizeof(list)/4;
    insertion_sort(list,size);
    for(int i=0;i<size;i++)
    printf("%d ",list[i]);
}