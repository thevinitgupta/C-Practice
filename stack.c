#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int stack[MAX];
int top = -1;


int isEmpty(){
    if(top==-1){
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(){
    if(top==MAX-1){
        return 1;
    }
    else {
        return 0;
    }
}
void push(int val){
    if(isFull()){
        printf("Stack Overflow!\n");
    }
    else {
        top++;
        stack[top] = val;
        printf("Insertion successfull!\n");
    }
     return;
}

int pop(){
    if(isEmpty()){
        printf("Stack Underflow!\n");
        return -1;
    }
    else {
        return stack[top--];
    }
}

int peek(){
    if(isEmpty()){
        printf("Stack empty!\n");
        return -1;
    }
    else {
        return stack[top];
    }
}

void display(){
    int i;
    if(isEmpty()){
        printf("Stack Empty!\n");
        return;
    }
    printf("Stack Elements are : \n");
    for(i=0;i<=top;i++){
        printf("%d\n",stack[i]);
    }
    return;
}

int main(){
    int data,choice =1,operation,ele = -1;

    push(4);
    push(5);
    push(7);
    push(1);
    push(2);
    push(24);
    display();
    while(choice!=0){
        printf("Enter 1 to push\n2 to pop\n3 to display\n4 to peek\n");
        scanf("%d",&operation);
        switch(operation){
            case 1 :
                printf("Enter data to add :\n");
                scanf("%d",&data);
                push(data);
            break;
            case 2 :
                ele = pop();
                if(ele!=-1)
                printf("Popped element is -> %d\n",ele);
            break;
            case 3 : 
                display();
            break;
            case 4 : 
                ele = peek();
                if(ele!=-1)
                printf("Top element is -> %d\n",ele);
            break;
            default :
                printf("Invalid Entry!\n");
        }
        printf("Enter 1 if you want to continue\n0 if you want to exit\n");
        scanf("%d",&choice);
    }
    return 0;
}