#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// This function should rotate list counter-clockwise
// by k and return new head (if changed)

Node *rotate(Node *head, int k)
{
    // Your code here
    Node *lastNode = NULL;
    Node *curr = head;
    int len = 0;
    while (curr->next)
    {
        ++len;
        curr = curr->next;
        if (curr->next == NULL)
        {
            lastNode = curr;
        }
    }
    len += 1;
    if (k >= len)
    {
        k = k % len;
    }
    if (k < 1)
        return head;
    Node *newHead = head;
    Node *prevNewHead = head;
    while (k > 0)
    {
        --k;
        newHead = newHead->next;
        if (k == 1)
        {
            prevNewHead = newHead;
        }
    }
    lastNode->next = head;
    prevNewHead->next = NULL;
    return newHead;
}
