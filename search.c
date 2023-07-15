
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    int N=50000,initial=500,list[N],i,j,num,flag=0;
   for(int i=0;i<N;i++)
    {
        list[i]=initial++;
    }
    //list[14]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
   printf("enter num:");
   scanf("%d",&num);
   for(i=0;i<N;i++)
   {
    if(list[i]==num)
    {flag=1;}
  
   }
   if(flag==1)
    { printf("found");
   
   }
    else 
    {printf("not found");
    
    }

   int ticks=clock();
    printf("\nexecution time %f",(float)ticks/CLOCKS_PER_SEC);
    return 0;
    
}