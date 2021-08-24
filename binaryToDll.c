#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;
struct node* head = NULL;
struct node* createnode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node* insert(struct node* current, int val){
    if(current == NULL){
        struct node* newnode = createnode(val);
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
bool flag = false;
struct node *before = NULL;
void bToDLL(struct node *root, struct node **head_ref)
{
    convertbToDLL(root, head_ref);
    before = NULL;
    flag = false;
}
void convertbToDLL(struct node *root, struct node **head_ref)
{
    if(root!=NULL){
        convertbToDLL(root->left, head_ref);
        if(root->left==NULL && flag==false){
            *head_ref = root;
            flag = true;
        }
        else{
            root->left = before;
            before->right = root;
        }
        before = root;
        convertbToDLL(root->right, head_ref);
    }
}
void printList(struct node* headDll){
    printf("print\n");
    while(headDll != NULL){
        printf("%d ", headDll->data);
        headDll = headDll->right;
    }
}
int main(){
root =    insert(root, 20);
root =    insert(root, 10);
root =     insert(root, 15);
root =    insert(root, 12);
root =    insert(root, 25);
struct node* headDll = NULL;
bToDLL(root, &headDll);
printList(headDll);
}
