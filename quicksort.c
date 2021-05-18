#include <stdio.h>

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


int partition(int lb,int ub){
   int start,end,t,temp;
   int pivot = intArray[lb];
         start = lb;end = ub;
        while(start<end){
            while(intArray[start]<=pivot){
                start++;
            }
            while(intArray[end]>pivot){
                end--;
            }
            if(start<end){
                 temp = intArray[start];
                intArray[start] = intArray[end];
                intArray[end] = temp;
            }

        }
         t = intArray[end];
        intArray[end] = pivot;
        intArray[lb] = t;
        return end;
}

void quickSort(int lb, int ub){
   int loc;
   if(ub<=1) return;
        
        if(lb<ub){
            loc = partition(lb,ub);
            quickSort(lb,loc-1);
            quickSort(loc+1,ub);
        }
        return;
}

int main() {
    int i;
    printf("Enter elements to sort : \n");
    for(i=0;i<MAX;i++){
        scanf("%d",&intArray[i]);
    }
    printf("End of input!\n");
   printf("\n\nInput Array: ");
   display();
   quickSort(0,MAX-1);
   printf("\n\nSorted Array: ");
   display();
}