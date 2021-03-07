#include<stdio.h>
#include <stdlib.h>

#define MAXQUEUE 3
int queue[MAXQUEUE];
int front = -1;
int rear = -1;
int size = 0;

void enqueue(int val){
    if(front == (rear+1)%MAXQUEUE){
        printf("Overflow!\n");
        return;
    }
    else if(rear==-1&&front==-1){
       rear = 0;
       front=0;
       queue[rear] = val; 
    }
    else {
        rear = (rear+1)%MAXQUEUE;
        queue[rear]=val;
    }
    size++;
    printf("Insertion successfull!\n");
    return;
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue empty! Cannot dequeue!\n");
        return;
    }
    else if(front==rear){
        printf("Dequeued element : %d",queue[front]);
        front =-1;
        rear =-1;
    }
    else {
        printf("Dequeued element : %d",queue[front]);
        front = (front+1)%MAXQUEUE;
    }
    size--;
    printf("Dequeue successfull!");
    return;
}

void peek(){
    if(front==-1 && rear==-1){
        printf("Queue is empty!\n");
    }
    else {
        printf("Front element -> %d\n",queue[front]);
    }
    return;
}


void display(){
    int i = front;
    if(front==-1 && rear==-1){
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue elements are : \n");
        if(front<=rear){
            for(i=front;i<=rear;i++){
                printf("%d\n",queue[i]);
            }
        }
        else {
            for(i=front;i<=MAXQUEUE-1;i++)
            printf("%d\n",queue[i]);
            for(i=0;i<=rear;i++){
                printf("%d\n",queue[i]);
            }
        }
    }
    return;
}

int main(){
    int i,data,choice=1;
    while(choice==1){
        printf("Enter value to enqueue : \n");
        scanf("%d",&data);
        enqueue(data);
        printf("Enter 0 to stop,\nAnd 1 to continue\n");
        scanf("%d",&choice);
    }
    display();
    dequeue();
    enqueue(100);
    display();
    peek();
}