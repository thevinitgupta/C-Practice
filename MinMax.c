#include <stdio.h>
int min,max;
int arr[100];

void minMax(int low,int high){
	int mid,max1,min1;
	if(low==high){
		max=min=arr[low];
	}
	else if(low==high-1){
		if(arr[low]>=arr[high]){
			max=arr[low];
			min=arr[high];
		}
		else{
			min=arr[low];
			max=arr[high];
		}
	}
	else{
		mid=(low+high)/2;
		minMax(low,mid);
		max1=max;
		min1=min;
		minMax(mid+1,high);
		if(max<max1)
			max=max1;
		if(min>min1)
			min=min1;
	}
}
void main(){
    int lim = 0;
    printf("Enter no. of elements : ");
    scanf("%d",&lim);
    printf("Enter array elements:\n");
    for(int i=0;i<lim;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array elements :\n");
    for(int i=0;i<lim;i++){
        printf("%d\n",arr[i]);
    }
    minMax(0,lim-1);
    printf("\nMin -> %d\n",min);
    printf("Max -> %d",max);
}