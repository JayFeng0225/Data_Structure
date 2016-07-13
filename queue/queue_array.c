#include<stdio.h>
#include<stdlib.h>

int rear=0 , front=0;
int main(){
    int queue[10];
    int input;
    printf("1. enqueue 2. dequeue 3.print 4.end\n");
    scanf("%d",&input);

}

void enqueue(int q[],int item){
    rear = (rear+1)%10;
    if(rear==front){
        printf("queue is full\n");
        return;
    }
    q[rear]=item;
    return;
}

int dequeue(int q[]){
    if(front == rear){
        printf("queue is empty\n");
        return;
    }
    front = (front+1)%10;
    item = q[front];
    return item;
}
