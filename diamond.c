#include <stdio.h>

int main(){
    int n,i,j,k;

    printf("Enter the limit : ");
    scanf("%d",&n);
    i=0;
    while(i<n){
        j=0;
        while(j<n-i){
            printf(" ");
            j++;
        }
        k=0;
        while(k<i*2+1){
            printf("*");
            k++;
        }
        printf("\n");
        i++;
    }
    i=0;
    while(i<n-1){
        j=0;
        while(j<=i+1){
            printf(" ");
            j++;
        }
        k=i;
        while(k<=n-i){
            printf("*");
            k++;
        }
        printf("\n");
        i++;
    }
    return 0;
}

/**
 *0      @
 *1    @ @ @
 *2  @ @ @ @ @
 *3@ @ @ @ @ @ @
  0  @ @ @ @ @
 *1    @ @ @
 *2      @
 * 
 *  0123456
 *  1010101
 *   01234
 *   10101
 *    101
 *     1
 */