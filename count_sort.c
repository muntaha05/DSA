#include<stdio.h>
#include<time.h>
int main()
{

    int i;
    
    int n=12,R=10;

    int A[12]={2,6,4,6,2,9,0,6,5,1,5,7},count[10],output[12];

    for(i=1;i<=n;i++)    //freq array
    {

        count[A[i]]++;
    }

    for(i=1;i<=R;i++) //cumulative freq
    {
        count[i]+=count[i-1];
    }

    for(i=n-1;i>=0;i--)
    {
        output[--count[A[i]]]=A[i];
    }


    for(i=0;i<n;i++)
    {
        A[i]=output[i];
    }
     for(i=0;i<n;i++)
    {
      printf("%d ",A[i]);
    }
     int ticks=clock();
    printf("\n execution time %f ms",(float)ticks/CLOCKS_PER_SEC*1000);
    return 0;
}
