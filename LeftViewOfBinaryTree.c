#include <stdio.h>
int maxLevel = 0;
void printLeftView(Node *curr, int level)
{
    if (curr != NULL)
    {
        if (level > maxLevel)
        {
            maxLevel = level;
            printf("%d ", curr->data);
        }
        printLeftView(curr->left, level + 1);
        printLeftView(curr->right, level + 1);
    }
}
void leftView(Node *root)
{
    // Your code here
    maxLevel = 0;
    printLeftView(root, 1);
}