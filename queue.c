#include<stdio.h>
#include<stdlib.h>
#define max_size 100
int queue[max_size];
int front=-1,rear=-1;//rear inserts & increase, front delete & increases
void enqueue(int item){
    if(rear== max_size-1){
        printf("queue overflow");
    }
    if(front==-1)
    front=0;
    rear++;
    queue[rear]=item;
}
int dequeue(){
    int item;
    if(front==-1 || front>rear){
        printf("queue underflow\n ");
        return -1;
    }
    else{
    item=queue[front];
    front++;
    return item;
    }

}
void display(){
    int i;
    if(front ==-1 || front>rear)
    printf("queue is empty");
    for(i=front;i<=rear;i++){
        printf("%d ",queue[i]);
        printf("\n");
    }
}
int main(){
    enqueue(1);
    enqueue(0);
    enqueue(5);
    enqueue(6);
    display();
    printf("dequeued item is: %d\n", dequeue());
     printf("dequeued item is: %d\n", dequeue());
    printf("dequeued item is: %d\n", dequeue());
    printf("dequeued item is: %d\n", dequeue());
    printf("dequeued item is: %d\n", dequeue());
      printf("\n");
      display();
      return 0;
}


