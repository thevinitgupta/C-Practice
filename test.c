#include<stdio.h>

int main(){
    int a=2,b=3;
    a = a^b;
    b = a^b;
    a = a^b;
    printf("%d\n",a);
    printf("%d\n",b);

    return 0;
}