/*
Print Nodes in Top View of Binary Tree
Last Updated: 22-07-2020
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Given a binary tree, print the top view of it. The output nodes can be printed in any order.

A node x is there in output if x is the topmost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6

*/
#include <bits/stdc++.h>
#include <map>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void dfs(Node *root, unordered_map<int, map<int, int>> &um, int &vmin, int &vmax, int val, int level)
{
    if (root != NULL)
    {
        vmin = min(vmin, val);
        vmax = max(vmax, val);
        um[val].insert({level, root->data});
        dfs(root->left, um, vmin, vmax, val - 1, level + 1);
        dfs(root->right, um, vmin, vmax, val + 1, level + 1);
    }
}

void topView(struct Node *root)
{
    //Your code here
    unordered_map<int, map<int, int>> um;
    int vmin = 0, vmax = 0;
    dfs(root, um, vmin, vmax, 0, 0);
    for (int i = vmin; i <= vmax; i++)
    {
        map<int, int> m = um[i];
        auto itr = m.begin();
        cout << itr->second << " ";
    }
}
