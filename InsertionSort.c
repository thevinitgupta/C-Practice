#include <stdio.h>

int main(){
    int arr[50];
    int n = 0,i,j,key=0;
    printf("Enter size of array : ");
    scanf("%d",&n);
    printf("\nEnter %d elements now : \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nOriginal Array : \n",n);
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    for(i=1;i<n;i++){
        j = i-1;
        key = arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1]= arr[j];
            j = j-1;
            arr[j+1] = key;
        }
    }
    printf("\nSorted Array : \n",n);
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}