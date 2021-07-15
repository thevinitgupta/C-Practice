#include <stdio.h>
int arr[50];


void selection(int i, int j, int size, int flag)
{
    int temp;
 
    if (i < size - 1)
    {
        if (flag)
        {
            j = i + 1;
        }
        if (j < size)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            selection( i, j + 1, size, 0);
        }
        selection( i + 1, 0, size, 1);
    }
}
int main(){
    int n = 0,i,j,key=0,position, swap;
    printf("Enter size of array : ");
    scanf("%d",&n);
    printf("\nEnter %d elements now : \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nOriginal Array : \n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    selection(0,0,n,1);
    printf("\nSorted Array : \n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}

