#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 8
int maxHeap[MAX+1];

int end = 0;

void displayHeap(){
    if(end==1){
        printf("Empty!\n");
        return;
    }
    int i =1,lc,rc;
    for(i=1;i<=end;i++){
        // printf("Parent : %d\n",maxHeap[i]);
        // printf("Children : ");
        // if(i*2<=end) 
        // printf("Left : %d",maxHeap[i*2]);
        // if((i*2)+1 <=end)
        // printf("Right : %d",maxHeap[(i*2)+1]);

        // printf("\n\n");
        printf("%d\n",maxHeap[i]);
    }
    return;
}
void heapify(int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    int temp;
 
    // If left child is larger than root
    if (l < n && maxHeap[l] > maxHeap[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && maxHeap[r] > maxHeap[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        //swap(maxHeap[i], maxHeap[largest]);
        temp = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = temp;
 
        // Recursively heapify the affected sub-tree
        heapify(n, largest);
    }
}


void insert(int data){
    int parent,temp,i;
    if(end==MAX){
        printf("Heap Full!\n");
        return;
    }
    else {
        end = end+1;
        i=end;
        maxHeap[end]=data;
        while(i>1){
            parent=i/2;
            if(maxHeap[parent]>=maxHeap[i]) i=0;
            else {
                temp = maxHeap[i];
                maxHeap[i] = maxHeap[parent];
                maxHeap[parent] = temp;
                i = parent;
            }
        }
    }
    printf("Insertion successfull!\n");
    return;
}


//giving problem for right swapping when only 3 elements are left in the heap
//*[null,30,20,7,9,15] ->30
int delete(){
    int deleted = maxHeap[1];
    int i=1;
    int leftChild=2,rightChild=3,temp;
    maxHeap[1] = maxHeap[end];
    end = end - 1;
    while(maxHeap[leftChild]>=maxHeap[i]||maxHeap[rightChild]>=maxHeap[i]){
        temp = 0 + maxHeap[i];
        if(maxHeap[leftChild]>maxHeap[rightChild]){
            printf("Temp value : %d",temp);
            maxHeap[i] = maxHeap[leftChild];
            maxHeap[leftChild] = temp;
            i=i*2;
        }
        else {
            printf("Temp value : %d",temp);
            maxHeap[i] = maxHeap[rightChild];
            maxHeap[rightChild] = temp;
            i = i*2 + 1;
        }
        rightChild = (i* 2) + 1;
        leftChild = i*2;
        if(leftChild>MAX || rightChild>MAX){
            break;
        }
    }


    // while(i<end){
    //     if(maxHeap[i]>=maxHeap[leftChild] && maxHeap[i]>=maxHeap[rightChild]){
    //         return deleted;
    //     }
    //     else {
    //         if(maxHeap[leftChild]>maxHeap[rightChild]){
    //             temp = maxHeap[i];
    //             maxHeap[i] = maxHeap[leftChild];
    //             maxHeap[leftChild] = temp;
    //             i = leftChild;
    //             leftChild = 2*i;     
    //             rightChild = (2*i)+1;
    //         }
    //         else if(maxHeap[leftChild]<maxHeap[rightChild]) {
    //             temp = maxHeap[i];
    //             maxHeap[i] = maxHeap[rightChild];
    //             maxHeap[rightChild] = temp;
    //             i = rightChild;
    //             leftChild = 2*i;     
    //             rightChild = (2*i)+1;
    //         }
    //         else {
    //             return deleted;
    //         }
    //     }
    // }
    return deleted;
}




int main(){
    int data,choice = 1,ch=0,arr[5];
    maxHeap[0] = -1;
    // while(choice==1&&end-1!=MAX){
    //     printf("Enter 0 if you want to insert data\nEnter 1 if you want to delete data\nEnter 2 if you want to print the heap\n");
    //     scanf("%d",&ch);
    //     switch(ch){
    //         case 0 :
    //             printf("Enter data to insert in max-heap:\n");
    //             scanf("%d",&data);
    //             insert(data);
    //         break;
    //         case 1 :
    //             printf("Deleted value : %d\n",delete());
    //         break;
    //         case 2 :
    //             printf("The Max heap :\n");
    //             displayHeap();
    //         break;
    //         default : 
    //         printf("Invalid choice!\n");
    //     }
    //     printf("Enter 0 if you want to terminate program\nEnter 1 to continue\n");
    //     scanf("%d",&choice);
    // }
    insert(54);
    insert(45);
    insert(36);
    insert(27);
    insert(29);
    insert(18);
    insert(21);
    insert(11);
    printf("Final heap \n");
    displayHeap();
    // printf("Deleted : %d\n", delete());
    // displayHeap();
    ch=0;
    printf("Descending sorted order :\n");
        while(end>0){
        printf("%d\n", delete());
        printf("After deletion : \n");
        displayHeap();
        printf("\n");
        }
    
    // for(ch=0;ch<MAX;ch++){
    //     printf("%d\n",arr[ch]);
    // }

    return 0;
}