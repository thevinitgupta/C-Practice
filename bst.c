#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};
struct node *root = NULL;

struct node* FindMin(struct node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

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

struct node* Delete(struct node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			free(root);
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			free(root);
		}
		else if(root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			free(root);
		}
		// case 3: 2 children
		else { 
			struct node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

struct node * Search(struct node * root,int key){
    if(root==NULL){
        return root;
    }
    else if(key == root->data){
        return root;
    }
    else if(key<root->data){
        return Search(root->left,key);
    }
    else {
        return Search(root->right,key);
    }
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
     struct node * search;
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
    Delete(root,6);
    printf("In Order after deleting 6 : \n");
    inOrder(root);
    search = Search(root,2);
    printf("Element found  left child -> %d\n",search->left->data);
    printf("Pre Order : \n");
    preOrder(root);
    printf("Post Order : \n");
    postOrder(root);

}