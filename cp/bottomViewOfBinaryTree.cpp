/*
Given a Binary Tree, we need to print the bottom view from left to right. A node x is there in output if x is the bottommost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

Examples:

                      20
                    /    \
                  8       22
                /   \      \
              5      3      25
                    / \      
                  10    14

For the above tree the output should be 5, 10, 3, 14, 25.

If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottom-most nodes at horizontal distance 0, we need to print 4.

                   
                      20
                    /    \
                  8       22
                /   \    /   \
              5      3 4     25
                    / \      
                  10    14 
For the above tree the output should be 5, 10, 4, 14, 25.


*/
#include <bits/stdc++.h>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};
void dfs(Node *root, int val, unordered_map<int, map<int, int>> &um, int level, int &hdMin, int &hdMax)
{
  if (root == NULL)
    return;
  hdMin = min(val, hdMin);
  hdMax = max(val, hdMax);
  auto it = um[val].insert({level, root->data});
  if (it.second == false) //insert in map returns a pair where pair.first = inserted element if that element doesnt exists in the map previously or previous element if that element exists in the map.  pair.second = true if that element isnt present in the map already, false if the element is present already
  {                       //this level already exists as key, but we need the last node of the specified level, so overwriting the value already existing
    it.first->second = root->data;
  }
  dfs(root->left, val - 1, um, level + 1, hdMin, hdMax);
  dfs(root->right, val + 1, um, level + 1, hdMin, hdMax);
}
vector<int> bottomView(Node *root)
{
  // Your Code Here
  unordered_map<int, map<int, int>> um;
  int hdMin = 0, hdMax = 0;
  dfs(root, 0, um, 0, hdMin, hdMax);
  vector<int> result;
  for (int i = hdMin; i <= hdMax; ++i)
  {
    map<int, int> m = um[i];
    auto itr = m.end();
    itr--;
    result.push_back(itr->second);
  }
  return result;
}
