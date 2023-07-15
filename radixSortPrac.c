#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

void displaycl(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void countsort(int arr[],int n,int place){
    int output[n];
    int count[10]={0};
    //now create  count array
    for(int i=0;i<n;i++){
        count[(arr[i]/place)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        int idx=count[(arr[i]/place)%10]-1;
        output[idx]=arr[i];
        count[(arr[i]/place)%10]--;
    }
    for(int i=0;i<n;i++)arr[i]=output[i];
}

int findMax(int arr[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }return max;
}

void radixSort(int arr[],int n){
    int max=findMax(arr,n);
    for(int place=1;(max/place)>0;place*=10){
        countsort(arr,n,place);
    }
}

int main(int argc,char *argv[]){

    int arr[]={678,34,56,102,347,88,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
    display(arr,n);
}