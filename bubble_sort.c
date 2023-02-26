#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void bubble_sort(int list[], int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-i-1;j++)
        {
            if(list[j]>list[j+1])
            {
                int temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
}
int main()
{
    int N=5000,initial=500;  
    int list[N];
    int templist[N],i,j;
    
    for(int i=0;i<N;i++)
    {
        list[i]=initial--;
    }
    int size=sizeof(list)/4;
    printf("%d\n",size);
    bubble_sort(list,size);
    for(int i =0;i<size;i++)
    printf("%d ",list[i]);
     int ticks=clock();
    printf("\nexecution time %f",(float)ticks/CLOCKS_PER_SEC);
}