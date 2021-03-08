#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};
struct node *root = NULL;

void insert(int val){
    
    struct node *prev = root, *ptr = root;
    while(ptr!=NULL){
        if(val==ptr->data){
            printf("Already present!\n");
            return;
        }
        else if(val<ptr->data){
            prev = ptr;
            ptr = ptr->left;
        }
        else {
            prev = ptr;
            ptr = ptr->right;
        }
    }
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    
    newNode->data = val;
    newNode->left =NULL;
    newNode->right =NULL;
    if(prev==NULL){
        root = newNode;
    }
    else {
        if(val<prev->data){
            prev->left = newNode;
        }
        else {
            prev->right = newNode;
        }
    }
   
    printf("Insertion SuccessFull!\n");
    return;
}
void inOrder(struct node* rootCurr)
{
    if (rootCurr != NULL) {
        inOrder(rootCurr->left);
        printf("%d \n", rootCurr->data);
        inOrder(rootCurr->right);
    }
}
void preOrder(struct node* rootCurr)
{
    if (rootCurr != NULL) {
        printf("%d \n", rootCurr->data);
        preOrder(rootCurr->left);
        preOrder(rootCurr->right);
    }
}

void postOrder(struct node* rootCurr)
{
    if (rootCurr != NULL) {
        postOrder(rootCurr->left);
        postOrder(rootCurr->right);
        printf("%d \n", rootCurr->data);
    }
}

int main(){
    int i = 0;
    int arr[8] = {2,1,14,3,16,22,11,6};
    
    printf("Insertion started!\n");
    for(i=0;i<8;i++){
        insert(arr[i]);
    }
   
    insert(4);
    insert(11);
    insert(3);
    insert(7);
    insert(5);
    printf("In Order : \n");
    inOrder(root);
    printf("Pre Order : \n");
    preOrder(root);
    printf("Post Order : \n");
    postOrder(root);

}