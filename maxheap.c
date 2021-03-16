#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20
int maxHeap[MAX+1];

int start = 1;
int end = 1;

void insert(int data){
    int parent,temp,i;
    if(end==MAX){
        printf("Heap Full!\n");
        return;
    }
    else if(start==end){
        maxHeap[end] = data;
    }
    else {
        maxHeap[end] = data;
        i=end;
        while(i>1){
           parent = floor(i/2);
           if(maxHeap[i]>maxHeap[parent]){
               temp = maxHeap[i];
               maxHeap[i] = maxHeap[parent];
               maxHeap[parent] = temp;
               i = parent;
           }
           else {
               return;
           } 
        }
    }
    printf("Insertion successfull!\n");
    end++;
    return;
}

int delete(){
    return maxHeap[start];
}

int main(){
    int data,choice = 1,ch=0;
    maxHeap[0] = NULL;
    while(choice==1&&end!=MAX){
        printf("Enter 0 if you want to insert data\nEnter 1 if you want to delete data\n");
        scanf("%d",&ch);
        switch(ch){
            case 0 :
                printf("Enter data to insert in max-heap:\n");
                scanf("%d",&data);
                insert(data);
            break;
            case 1 :
                printf("Deleted value : %d\n",delete());
            break;
            default : 
            printf("Invalid choice!\n");
        }
        printf("Enter 0 if you want to terminate program\nEnter 1 to continue\n");
        scanf("%d",&choice);
    }

}