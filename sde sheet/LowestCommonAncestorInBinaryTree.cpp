#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *lca(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    Node *node1 = lca(root->left, n1, n2);
    Node *node2 = lca(root->right, n1, n2);
    if (!node1)
        return node2;
    if (!node2)
        return node1;
    if (node1 && node2)
        return root;
    if (!node1 && !node2)
        return NULL;
}