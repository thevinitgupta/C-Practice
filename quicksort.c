#include <stdio.h>
#include <stdbool.h>

#define MAX 7

int intArray[MAX];

void display() {
   int i;
   printf("[");
	
   // navigate through all items 
   for(i = 0;i < MAX;i++) {
      printf("%d ",intArray[i]);
   }
	
   printf("]\n");
}

void swap(int num1, int num2) {
   int temp = intArray[num1];
   intArray[num1] = intArray[num2];
   intArray[num2] = temp;
}

int partition(int left, int right, int pivot) {
   int leftPointer = left -1;
   int rightPointer = right;

   while(true) {
      while(intArray[++leftPointer] < pivot) {
         //do nothing
      }
		
      while(rightPointer > 0 && intArray[--rightPointer] > pivot) {
         //do nothing
      }

      if(leftPointer >= rightPointer) {
         break;
      } else {
         swap(leftPointer,rightPointer);
      }
   }
	
   swap(leftPointer,right);
   return leftPointer;
}

void quickSort(int left, int right) {
   if(right-left <= 0) {
      return;   
   } else {
      int pivot = intArray[right];
      int partitionPoint = partition(left, right, pivot);
      quickSort(left,partitionPoint-1);
      quickSort(partitionPoint+1,right);
   }        
}

int main() {
    int i;
    printf("Enter elements to sort : \n");
    for(i=0;i<MAX;i++){
        scanf("%d",&intArray[i]);
    }
   printf("\n\nInput Array: ");
   display();
   quickSort(0,MAX-1);
   printf("\n\nSorted Array: ");
   display();
}