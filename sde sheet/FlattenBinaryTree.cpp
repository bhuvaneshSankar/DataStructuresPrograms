#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

struct TreeNode *createNode(int data)
{
    struct TreeNode *newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newnode->val = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

TreeNode *previous;
void flat(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *temp = root->right;
    previous->right = root;
    previous = root;
    flat(root->left);
    flat(temp);
}
void flatten(TreeNode *root)
{
    previous = root;
    flat(root);
    root->left = NULL;
}

void preorder(struct TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    //  preorder(root);
    flatten(root);
    cout << root->val << " " << root->right->val << " " << root->right->right->val;
}