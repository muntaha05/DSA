// Online C compiler to run C program online
#include<stdio.h>
#include<time.h>
void count_sort(int A[],int n, int pos)
{
    int i,output[n],count[10]={0};
    for(i=0;i<n;i++)
    {
         count[(A[i]/pos)%10]++;
    }

    for(i=1;i<=9;i++) //cumulative freq
    {
        count[i]=count[i]+count[i-1];
    }

    for(i=n-1;i>=0;i--)
    {
        output[--count[(A[i]/pos)%10]]=A[i];
    }
    for(i=0;i<n;i++)
    {
        A[i]=output[i];
    }
}

int get_max(int A[], int n)
{
    int i,max=0;
    for(i=0;i<n;i++)
    {
        if(A[i]>max)
        {
            max=A[i];
        }
    }
    return max;
}
void radix_sort(int A[],int n)
{
    int x=get_max(A,n);
    for(int pos=1;(x/pos)>0;pos*=10)
    {
        count_sort(A,n,pos);
    }
}
int main()
{
    int A[]={23,45,34,66,23,77,88,23,66,88};
    radix_sort(A,10);
    for(int i=0;i<10;i++)
    {
      printf("%d ",A[i]);
    }

     int ticks=clock();
    printf("\nexecution time %f ms",(float)ticks/CLOCKS_PER_SEC*1000);
    return 0;
}
