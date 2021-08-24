#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    int size;
    int height;
};
struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    newnode->size = 1;
    return newnode;
}
int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
int getHeight(struct node* node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}
int getSize(struct node* node){
    if(node==NULL){
        return 0;
    }
    return node->size;
}
int getBalanceFactor(struct node* node){
    if(node==NULL){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}
struct node* leftRotate(struct node* x){
    struct node* y = x->right;
    struct node* z = y->left;
    y->left = x;
    x->right = z;
    x->height = max(getHeight(x->left), getHeight(x->right))+1;
    x->size = getSize(x->left) + getSize(x->right) +1;
    
    y->height = max(getHeight(y->left), getHeight(y->right))+1;
    y->size = getSize(y->left) + getSize(y->right)+1;
    
    return y;
}
struct node* rightRotate(struct node* y){
    struct node* x = y->left;
    struct node* z = x->right;
    x->right = y;
    y->left = z;
    
    x->height = max(getHeight(x->left), getHeight(x->right))+1;
    x->size = getSize(x->left) + getSize(x->right)+1;
    
    y->height = max(getHeight(y->left), getHeight(y->right))+1;
    y->size = getSize(y->left) + getSize(y->right)+1;
    
    return x;
}
struct node* insert(struct node* root, int data, int* lowPtr){
    if(root==NULL){
        return createNode(data);
    }
    else if(data < root->data){
        root->left = insert(root->left, data, lowPtr);
    }
    else{
        root->right = insert(root->right, data, lowPtr);
        *lowPtr = *lowPtr + getSize(root->left)+1;
    }
    root->height = max(getHeight(root->left), getHeight(root->right))+1;
    root->size = getSize(root->left) + getSize(root->right)+1;
    int balanceFactor = getBalanceFactor(root);
    if(balanceFactor>1 && data<root->left->data){
        return rightRotate(root);
    }
    else if(balanceFactor<-1 && data>root->right->data){
        return leftRotate(root);
    }
    else if(balanceFactor>1 && data>root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if(balanceFactor<-1 && data<root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    } 
    return root;
}
struct node* root = NULL;
int* solve (int* S,int n) {
   int i;
   int* flag = (int *)malloc(sizeof(int)*n);
   for(i=0; i<n; i++){
       flag[i]=0;
   }
   for(i=n-1; i>=0; i--){
      root = insert(root, S[i], &flag[i]);
   }
   return flag;
}

int main() {
    int out_n;
    int T;
    scanf("%d", &T);
    for(int t_i=0; t_i<T; t_i++)
    {   int n;
        scanf("%d", &n);
        int i_S;
        int *S = (int *)malloc(n*sizeof(int));
        for(i_S=0; i_S<n; i_S++) 
           scanf("%d", &S[i_S]);
        int* out_ = solve(S,n);
        printf("%d", out_[0]);
        for(int i_out_=1; i_out_<n; i_out_++)
        	printf(" %d", out_[i_out_]);
        printf("\n");
    }
}

/**
42
468 335 1 170 225 479 359 463 465 206 146 282 328 462 492 496 443 328 437 392 105 403 154 293 383 422 217 219 396 448 227 272 39 370 413 168 300 36 395 204 312 323
output 38 22 0 6 10 34 19 31 31 7 3 10 14 26 26 26 24 14 22 16 2 17 2 8 12 15 4 4 11 12 4 4 1 6 7 1 2 0 3 0 0 0