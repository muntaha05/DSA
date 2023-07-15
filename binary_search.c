#include<stdio.h>
#include<time.h>
/*long long timeMilli(void)
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}
*/
int binary_search(int A[],int target,int min,int max)
{
    if(min>max)
    {
        return -1;
    }
    else
    {
      int mid=(min+max)/2;
      if(A[mid]<target)
      {
        return binary_search(A,target,mid+1,max);
      }
      else if(A[mid]>target)
      {
        return binary_search(A,target,min,mid-1);
      }
      else 
      {
        return mid;
      }
    }
}

int main()
{   
   // gettimeofday(&start, NULL);
    int N=50000,initial=100,arr[N];  
    int i,j,num,var;
     for(int i=0;i<N;i++)
    {
        arr[i]=initial++;
    }
    printf("enter num:between(500 to 50000)");
    scanf("%d",&num);
    var=binary_search(arr,num,100,50000);
    if(var==-1)
    {
        printf("not found");

    }
    else
    {
    printf("\nfound in index: %d",var);
    }
  /* gettimeofday(&stop, NULL);
   printf("\nexecution time %lu",(stop.tv_sec-start.tv_sec) + stop.tv_usec-start.tv_usec);
   
 
  printf("\nexcecution time %d", timeMilli());
  */
   int ticks=clock();
    printf("\nexecution time %f",(float)ticks/CLOCKS_PER_SEC);
    return 0;

}