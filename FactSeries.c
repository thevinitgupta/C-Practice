#include <stdio.h>
#include <math.h>

int fact(int n){
    int f = 1,i=2;
    while(i<=n){
        f = f * i;
        i++;
    }
    return f;
}

int main(){
    int lim, i = 0, x;
    double sum = 1,term = 0;
    printf("Enter the limit and value of x : \n");
    scanf("%d",&lim);
    scanf("%d",&x);
    for(i = 2; i<=lim; i = i+2){
        printf("Sum before : %lf\n",sum);
        term = pow(x,i)/fact(i);
        printf("Term for i=%d = %lf\n",i,term);
        if(i%4==0){
            sum = sum + term;
        }
        else {
            sum = sum - term;
        }
    }
    printf("\nSum of series : %lf",sum);
    return 0;
}