#include<stdio.h>
#include<stdlib.h>

struct node
{
    /* data */
    int data;
    struct node * next;
    struct node * prev;
};


void append(struct node **headRef,int val){
    struct node * newNode = (struct node *) malloc(sizeof(struct node));

    struct node * temp = *headRef;

    newNode->data = val;
    newNode->next = NULL;
    if(*headRef == NULL){
        newNode->prev=NULL;
        *headRef = newNode; 
        return;
    }
    else {
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
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
int main(){
   // struct node * newNode = (struct node*) malloc(sizeof(struct node));
    struct node *head = NULL;
    int choice=1,data;
    append(&head,5);
    append(&head,2);
    append(&head,7);
    append(&head,1);
    displayLinkedList(&head);
    while(choice==1){
         printf("Enter data \n");
        scanf("%d",&data);
        append(&head,data);
        printf("Enter 0 if you want to stop\n Enter 1 if you want to add more\n");
        scanf("%d",&choice);
    }
    printf("Final Doubly Linked List :\n");
    displayLinkedList(&head);
    return 0;
}