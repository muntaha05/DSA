#include<stdio.h>
void selectionSortRecursive(int arr[], int n) {
    // base case
    if (n <= 1) {
        return;
    }
    
    // find the minimum element in the unsorted part of the array
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    
    // swap the minimum element with the first element of the unsorted part
    int temp = arr[0];
    arr[0] = arr[minIndex];
    arr[minIndex] = temp;
    
    // call selectionSortRecursive() for the remaining unsorted part of the array
    selectionSortRecursive(arr+1, n-1);
}
int main()
{
    int list[]={2,5,3,6,7};
    int size=sizeof(list)/4;
    selectionSortRecursive(list,size);
    for(int i=0;i<size;i++)
    printf("%d ",list[i]);
}