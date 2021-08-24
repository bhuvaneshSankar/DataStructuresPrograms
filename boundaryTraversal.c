#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;
struct node* createNode(int n){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insertIntoBinaryTree(int arr[], int n, int i){
    if(i<n){
        struct node* newnode = createNode(arr[i]);
        if(root == NULL){
            root = newnode;
        }
        newnode->left = insertIntoBinaryTree(arr, n, i*2+1);
        newnode->right = insertIntoBinaryTree(arr, n, i*2+2);
        return newnode;
    }
    return NULL;
}

void inorder(struct node* node){
    if(node!=NULL){
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertIntoBinaryTree(arr, n, 0);
    inorder(root);
}