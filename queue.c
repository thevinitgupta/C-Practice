#include<stdio.h>
#include <stdlib.h>

#define MAXQUEUE 10
int queue[MAXQUEUE];
int front = -1;
int rear = -1;

void enqueue(int val){
    if(rear==MAXQUEUE-1){
        printf("Overflow!\n");
        return;
    }
    else if(rear==-1 && front==-1){
        front =0;
        rear =0;
        queue[rear] = val;
    }
    else {
        rear++;
        queue[rear] = val;
    }
    printf("Element enqueued!\n");
    return;
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue Empty!\n");
    }
    else if(front==rear) {
        front=-1;
        rear = -1;
    }
    else {
        printf("Dequeued element is : %d\n",queue[front]);
        front++;
    }
    return;
}

void display(){
    int i;
    if(front==-1 && rear==-1){
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue elements are : \n");
        for(i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
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

int main(){
    int choice =1,data;
    // while(choice==1){
    //     printf("Enter data to enqueue : \n");
    //     scanf("%d",&data);
    //     enqueue(data);
    //     printf("Enter 0 if you want to exit,\nAnd 1 to add more elements\n");
    //     scanf("%d",&choice);
    // }
    // display();
    int i;
    for(i=0;i<MAXQUEUE;i++){
        printf("Enter data to enqueue : \n");
        scanf("%d",&data);
        enqueue(data);
    }
    display();
    for(i=0;i<MAXQUEUE;i++){
        dequeue();
        display();
    }
    // dequeue();
    // peek();
    // enqueue(6);
    // display();
    return 0;
}