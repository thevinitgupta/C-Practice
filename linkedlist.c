#include<stdio.h>
#include<stdlib.h>

 struct node
    {
        int data;
        struct node *next;
    };

    void push(struct node **headRef,int val){
    struct node* newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = val;
    
    /* Make next of new node as head */
    newNode->next = *headRef;

    /* move the head to point to the new node  */
    *headRef = newNode;
}

void insertAfter(struct node* prevNode, int val){

     if (prevNode == NULL) 
    { 
      printf("the given previous node cannot be NULL"); 
      return; 
    } 
    struct node * newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
void insertAt(struct node** headRef,int val,int pos) {
    int i;
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    struct node* temp = *headRef;
    for(i=2;i<pos;i++){
        temp = temp->next;
        if(temp==NULL){
            break;
        }
    }
    newNode->next = temp->next;
    temp->next =newNode;
}
void append(struct node** headRef,int val) {
    struct node* last = *headRef;
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = newNode;
}

void deleteFirst(struct node** headRef){
    struct node* temp = *headRef;
    if(temp->next==NULL){
        printf("List Empty!");
        return;
    }
    temp = temp->next;
    *headRef = temp;
}
void deleteNode(struct node** headRef,int key){
    struct node *temp = *headRef,*prev = NULL;
    if(temp->next==NULL){
        printf("List Empty!");
        return;
    }
    while(temp!=NULL){
        if(temp->data==key){
           if(prev==NULL) {
               deleteFirst(&temp);
           } 
           else {
               prev->next = temp->next;
           }
           return;
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    printf("Key not found!");
}
void printLinkedList(struct node** headRef){
    printf("\nLinked List values :\n");
    struct node * temp = *headRef;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

int main(){
    struct node *head = NULL,*newnode,*temp=NULL;
    int choice=1;
    while(choice==1){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data \n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter 0 if you want to stop\n Enter 1 if you want to add more");
        scanf("%d",&choice);
    }
    printLinkedList(&head);

    push(&head,5);
    printf("After inserting new node at head:\n");
    printLinkedList(&head);
    insertAt(&head,12,3);
    printf("After inserting new node at 3rd node:\n");
    printLinkedList(&head);
    append(&head,24);
    printf("After inserting new node at last node:\n");
    printLinkedList(&head);
    deleteFirst(&head);
    printf("After deleting first node :");
    printLinkedList(&head);
    deleteNode(&head,12);
    printf("After deleting some node :");
    printLinkedList(&head);
    return 0;
}

