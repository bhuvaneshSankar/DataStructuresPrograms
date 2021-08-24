#include <bits/stdc++.h>
using namespace std;
/*
    Floyd's algorithm for loop detection and removal in linked list
*/
struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

struct Node *findHeadOfCycle(struct Node *head, struct Node *ptr2)
{
    struct Node *ptr1 = head;
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}
void removeLoop(Node *head)
{
    //detect cycle in a ll
    //find the head of the cycle
    //remove the loop
    Node *slow = head;
    Node *fast = head;
    bool isCycle = false;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            //loop detected
            //find the head
            isCycle = true;
            break;
        }
    }
    if (isCycle)
    {
        Node *loopHead = findHeadOfCycle(head, fast);
        Node *loopPrevious = loopHead->next;
        while (loopPrevious->next != loopHead)
        {
            loopPrevious = loopPrevious->next;
        }
        loopPrevious->next = NULL; //point the next to NULL so that the loop formation doesnt occur
    }
}