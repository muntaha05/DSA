#include<stdio.h>
#define CAPACITY 3
int stack[CAPACITY];
int top=-1;

void push(int x){
    if(top<CAPACITY-1)
    {
        top++;
        stack[top]=x;
        printf("\nsuccessfully added item %d",x);
    }
    else{
        printf("\nexception! no spaces");
    }
}

int pop()
{
   if(top>=0){
    int val=stack[top];
    top--; //this will delete the topmost item
    return val;
   }
   printf("\nexception from pop! empty stack");
   return -1;
}

int peek()  //it will print top most value 
{
    if(top>=0){
        return stack[top];
    }
    printf("\nempty stack");
    return -1;

}

int main()
{
    printf("\nimplementing stack:\n");
    peek();
    push(10);
    push(20);
    push(30);
    push(100);
    printf("\npop item: %d",pop());
    push(40);
    printf("\ntop of stack: %d\n",peek());
    peek();
    return 0;
}