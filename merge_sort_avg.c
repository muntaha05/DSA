#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void Mergesort(int list[],int templist[],int N); 
void Msort(int list[],int templist[],int left,int right);
void Merge(int list[],int templist[],int Lpos, int Rpos, int RightEnd);



int main()
{   /*time_t start,end;
    start= time(NULL);*/
   
    int list[5000];
    int templist[5000],i,j;
    int N=5000;
    for(int i=0;i<N;i++)
    {
        list[i]=rand()%N;
    }
    Mergesort(list,templist,N);
    /*end=time(NULL);
    printf("\ntime taken %f seconds",difftime(end,start));*/

     int ticks=clock();
    printf("\nexecution time %f",(float)ticks/CLOCKS_PER_SEC);
    return 0;

}

void Mergesort(int list[],int templist[],int N)    //create f1
{
   Msort(list,templist,0,N-1);
    for(int i=0;i<N;i++)
    printf("%d ",list[i]);
}

void Msort(int list[],int templist[],int left,int right)   //create f2
{
    if(left<right)
    {
        int center=(left+right)/2;
        Msort(list,templist,left,center);  //recursion
        Msort(list,templist,center+1,right);
        Merge(list,templist,left,center+1,right);
    }
}

void Merge(int list[],int templist[],int Lpos, int Rpos, int RightEnd)
{
    int LeftEnd=Rpos-1;
    int tmppos=Lpos;
    int NumElement=RightEnd-Lpos+1;
    while(Lpos<=LeftEnd && Rpos<=RightEnd)
    {
        if(list[Lpos]<=list[Rpos])
        {
            templist[tmppos++]=list[Lpos++];
        }
        else
        {
            templist[tmppos++]=list[Rpos++];
        }
    }
        while(Lpos<=LeftEnd)
        {
            templist[tmppos++]=list[Lpos++];
        }
        while(Rpos<=RightEnd)
        {
            templist[tmppos++]=list[Rpos++];
        }
        for(int i=0;i<NumElement;i++)
        {
            list[RightEnd]=templist[RightEnd];
            RightEnd--;
        }
    
}
