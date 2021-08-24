#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * post order traversal
 * tc  o(n)
 * spc o(n) - considering recursion stack size
 */
int maxPath(TreeNode *currentNode, int &gmax)
{
    if (!currentNode)
        return 0;
    int l = maxPath(currentNode->left, gmax);
    int r = maxPath(currentNode->right, gmax);
    int localMax = l + r + currentNode->val;
    gmax = max(gmax, currentNode->val);
    int lmax = max(l + currentNode->val, r + currentNode->val);
    gmax = max(gmax, lmax);
    gmax = max(gmax, l + currentNode->val + r);
    return max(currentNode->val, currentNode->val + max(l, r));
}
int maxPathSum(TreeNode *root)
{
    int gmax = INT_MIN;
    maxPath(root, gmax);
    return gmax;
}