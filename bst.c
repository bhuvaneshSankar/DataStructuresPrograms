#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;

struct node* createNode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node* insert(struct node* current, int val){
    if(current == NULL){
        struct node* newnode = createNode(val);
        return newnode;
    }
    if(val < current->data){
      current->left  = insert(current->left, val);  
    }
    else if(val > current->data){
        current->right = insert(current->right, val);
    }
    return current;
}
void inorder(struct node* current){
    if(current!=NULL){
    inorder(current->left);
    printf("%d ", current->data);
    inorder(current->right);
    }
}
bool startCount=false, targetAttained=false;
void findKthElement(struct node* current, int target, int *k){
    if(current!=NULL && targetAttained==false){
        findKthElement(current->left, target, k);
        *k+=1;
        if(*k==target){
            targetAttained=true;
            printf("target %d ", current->data);
        }
        printf("\n%d %d", current->data, *k);
        findKthElement(current->right, target, k);
    }
}
int main(){
root =    insert(root, 20);
root =    insert(root, 10);
root =     insert(root, 15);
root =    insert(root, 12);
root =    insert(root, 25);
root = insert(root, 30);
//inorder(root);
int k=0;
findKthElement(root, 6, &k);
}
