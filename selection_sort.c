#include<stdio.h>
void selection_sort(int list[], int N)
{
    for(int i=0;i<N;i++)
    {
        int min=i;
        for(int j=i+1;j<N;j++)
        {
            if(list[j]<list[min])
            min=j;
        }

        int temp=list[i];
        list[i]=list[min];
        list[min]=temp;
    }
}
int main()
{
    int list[]={2,5,3,6,7};
    int size=sizeof(list)/4;
    selection_sort(list,size);
    for(int i=0;i<size;i++)
    printf("%d ",list[i]);
}