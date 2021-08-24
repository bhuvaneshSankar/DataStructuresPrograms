#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void printLL(struct node *curr)
{
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}
void reverseLinkedList(struct node *prev, struct node *curr, struct node **newHead)
{
    if (!curr)
        return;
    reverseLinkedList(curr, curr->next, newHead);
    if (*newHead == NULL)
    {
        *newHead = curr;
        cout << curr->data << " cd \n";
    }
    curr->next = prev;
}
struct node *reverseKGroup(struct node *head, int k)
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next = curr->next;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;

        curr = next;
        ++count;
    }
    if (next != NULL)
        head->next = reverseKGroup(next, k);
    return prev;
}
int main()
{
    struct node *head = createNode(5);
    head->next = createNode(1);
    head->next->next = createNode(10);
    head->next->next->next = createNode(7);

    struct node *temp = head;
    printLL(temp);

    cout << "reverse ll --- \n";
    struct node *newHead = NULL;
    reverseLinkedList(NULL, head, &newHead); //passing address of newHead
    head = newHead;
    printLL(newHead);
}