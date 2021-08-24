#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct node
{
    bool isLock;
    int numberOfDescendantsLocked;
    struct node *parent;
};

struct node *createNode(struct node *parent)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->isLock = false;
    newnode->numberOfDescendantsLocked = 0;
    newnode->parent = parent;
}

bool isLock(struct node *currentNode)
{
    return currentNode->isLock;
}

/**
 * time complexity - o(logn+logn) => o(logn) (considering height of the nary tree is o(logn))
 * one logn for checking ancestors arent lockable
 * another logn for updating count in ancestors
 */
void lock(struct node *currentNode)
{
    if (currentNode->isLock || currentNode->numberOfDescendantsLocked > 0)
    {
        //cant lock this element as its been already locked or its descendants are been locked
        return;
    }
    //check ancestors
    struct node *tempNode = currentNode->parent;
    bool isLockableCurrentNode = true;
    while (tempNode != NULL)
    {
        if (tempNode->isLock)
        {
            isLockableCurrentNode = false;
            break;
        }
        tempNode = tempNode->parent;
    }
    if (!isLockableCurrentNode)
    {
        //one of the ancestor nodes has been locked
        return;
    }
    //lock the current node and update parent's count
    currentNode->isLock = true;
    tempNode = currentNode->parent;
    while (tempNode != NULL)
    {
        tempNode->numberOfDescendantsLocked += 1;
        tempNode = tempNode->parent;
    }
}

/**
 * tc - o(logn) (considering height of the n-ary tree is o(logn))
 * updates all the ancestors upto the top
 */
void unlock(struct node *currentNode)
{
    if (currentNode->isLock)
    {
        currentNode->isLock = false;
        struct node *tempNode = currentNode->parent;
        while (tempNode != NULL)
        {
            tempNode->numberOfDescendantsLocked -= 1;
            tempNode = tempNode->parent;
        }
    }
}

int main()
{
    struct node *newnode = createNode(NULL); //root
    struct node *n1 = createNode(newnode);
    struct node *n2 = createNode(newnode);
    struct node *n11 = createNode(n1);
    struct node *n12 = createNode(n1);
    struct node *n13 = createNode(n1);
    struct node *n111 = createNode(n11);
    struct node *n21 = createNode(n2);
}