#include<stdio.h>
void insertion_sort(int list[],int N)
{
    int temp[100];
    for(int i=1;i<N;i++)
    {  int temp=list[i];
       int j=i-1;
       while(j>=0 && list[j]>temp)
       {
        list[j+1]=list[j];
        j--;
       }
       list[j+1]=temp;
    
    
    }
}
int main()
{
    int list[]={20,5,3,6,7,4,78,33,466,46,33,4,76,345,234,464,57,6787,3446};
    int size=sizeof(list)/4;
    insertion_sort(list,size);
    for(int i=0;i<size;i++)
    printf("%d ",list[i]);
}