#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
}*head = NULL;
int size = 0;
void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    if(head == NULL)
    {
       head = newNode;
       newNode -> next = head;
    }
    else
    {
       struct Node *temp = head;
       while(temp -> next != head)
          temp = temp -> next;
       newNode -> next = head;
       head = newNode;
       temp -> next = head;
    }
    printf("\nInsertion success!!!\n");
    size++;
}
void append(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   if(head == NULL)
   {
      head = newNode;
      newNode -> next = head;
   }
   else
   {
      struct Node *temp = head;
      while(temp -> next != head)
         temp = temp -> next;
      temp -> next = newNode;
      newNode -> next = head;
   }
   printf("\nInsertion success!!!\n");
   size++;   
}
void insertAfter(int value, int location)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   if(head == NULL)
   {      
      head = newNode;
      newNode -> next = head;
   }
   else
   {
      struct Node *temp = head;
      while(temp -> data != location)
      {
         if(temp -> next == head)
         {
            printf("\nGiven node is not found in the list!!!\n");
            return;
         }
         else
         {
            temp = temp -> next;
         }
      }
      newNode -> next = temp -> next;
      temp -> next = newNode;
      printf("\nInsertion success!!!\n");
      size++;
   }
}
void deleteBeginning()
{
   if(head == NULL)
      printf("\nList is Empty!!! Deletion not possible!!!\n");
   else
   {
      struct Node *temp = head,*start=head;
      while(temp->next!=head){
        temp = temp->next;
      }
      head = start->next;
      temp->next = head;
      free(start);
      printf("\nDeletion success!!!\n");
   }
   size--;
}
void deleteEnd()
{
   if(head == NULL)
      printf("\nList is Empty!!! Deletion not possible!!!\n");
   else
   {
      struct Node *temp1 = head, *temp2;
      if(temp1 -> next == head)
      {
         head = NULL;
         free(temp1);
      }
      else{
         while(temp1 -> next != head){
            temp2 = temp1;
            temp1 = temp1 -> next;
         }
         temp2 -> next = head;
         free(temp1);
      }
      printf("\nDeletion success!!!\n");
   }
   size--;
}
void deleteSpecific(int delValue)
{
   if(head == NULL)
      printf("\nList is Empty!!! Deletion not possible!!!\n");
   else
   {
      struct Node *temp1 = head, *temp2;
    while(temp1 -> data != delValue)
    {
       if(temp1 -> next == head)
       {
          printf("\nGiven node is not found in the list!!!\n");
          return;
       }
       else
       {
          temp2 = temp1;
          temp1 = temp1 -> next;
       }
    }
    if(temp1==head){
        deleteBeginning();
    }
    else if(temp1->next==head){
        deleteEnd();
    }
    else {
        temp2->next=temp1->next;
        free(temp1);
        size--;
    }
    
      printf("\nDeletion success!!!\n");
   }
}
void displayLinkedList()
{
    int i=1;
   if(head == NULL)
      printf("\nList is Empty!!!\n");
   else
   {
      struct Node *temp = head;
      printf("\nList elements are: \n");
      while(i<=size)
      {
         printf("%d ---> ",temp->data);
         temp=temp->next;
         i++;
      }
      printf("%d\n", temp->data);
   }
   return;
}

void main()
{
   int choice=1,data;
    append(5);
    append(2);
    append(7);
    append(1);
    push(0);
    displayLinkedList();
    while(choice==1){
         printf("\nEnter data \n");
        scanf("%d",&data);
        append(data);
        printf("\nEnter 0 if you want to stop\n Enter 1 if you want to add more\n");
        scanf("%d",&choice);
    }
    displayLinkedList();
    append(9);
    displayLinkedList();
    deleteSpecific(9);
    displayLinkedList();
    // displayLinkedList();
    deleteBeginning();
    displayLinkedList();
    deleteEnd();
    displayLinkedList();
    return ;
}

