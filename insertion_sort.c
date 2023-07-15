#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
    int N=500;  
    int list[N];

    
    for(int i=0;i<N;i++)
    {
        list[i]=rand()%N;
    }
    insertion_sort(list,N);
    for(int i=0;i<N;i++)
    printf("%d ",list[i]);
     int ticks=clock();
    printf("\nexecution time %f",(float)ticks/CLOCKS_PER_SEC);
    return 0;
}