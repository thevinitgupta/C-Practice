#include<stdio.h>
#include<stdlib.h>

struct node
{
    /* data */
    int data;
    struct node * next;
    struct node * prev;
};


void append(struct node **headRef,struct node **lastRef,int val){
    struct node * newNode = (struct node *) malloc(sizeof(struct node));

    struct node * temp = *headRef;

    newNode->data = val;
    newNode->next = NULL;
    if(*headRef == NULL){
        newNode->prev=NULL;
        *headRef = newNode;
        *lastRef = newNode; 
        return;
    }
    else {
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        *lastRef = newNode;
    }
    return;
}

void push(struct node **headRef,int val){
    struct node * temp = *headRef;

    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = val;
    temp->prev = newNode;
    
    newNode->next = *headRef;
    newNode->prev = NULL;
    newNode->next = temp;  
    temp->prev=newNode;
    *headRef = newNode;
}

void insertAfter(struct node** headRef,int val,int key){
    struct node * temp = *headRef;
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = val;
    while(temp!=NULL){
        if(temp->data==key) {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
    printf("Key not present!");
    return;
}
void displayLinkedList(struct node **headRef){
    printf("\nDoubly Linked List values :\n");
    struct node * temp = *headRef;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
 void displayReverse(struct node **lastRef){
     printf("\nDoubly Linked List values in Reverse :\n");
     struct node *temp = *lastRef;
     while(temp!=NULL){
         printf("%d\n",temp->data);
        temp = temp->prev;
     }
 }
int main(){
   // struct node * newNode = (struct node*) malloc(sizeof(struct node));
    struct node *head = NULL,*last = NULL;
    int choice=1,data;
    append(&head,&last,5);
    append(&head,&last,2);
    append(&head,&last,7);
    append(&head,&last,1);
    push(&head,0);
    displayLinkedList(&head);
    while(choice==1){
         printf("Enter data \n");
        scanf("%d",&data);
        append(&head,&last,data);
        printf("Enter 0 if you want to stop\n Enter 1 if you want to add more\n");
        scanf("%d",&choice);
    }
    printf("Semi Final Doubly Linked List :\n");
    displayLinkedList(&head);
    printf("Final Doubly Linked List :\n");
    displayReverse(&last);
    insertAfter(&head,15,7);
    printf("Final Doubly Linked List :\n");
    displayLinkedList(&head);
    return 0;
}