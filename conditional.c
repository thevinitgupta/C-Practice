#include <stdio.h>

int main(){
    int x=2,y=5,z=0;
    printf("x==2 ->");
    if(x==2){
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    printf("x!=5 ->");
    if(x!=5){
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    printf("x!=5 && y>=5 -> ");
    if(x!=5 && y>=5){
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    printf("z!=0 || x==2 -> ");
    if(z!=0 || x==2){
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    printf("!(y<10) ->");
    if(!(y<10)){
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    return 0;
}