#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *arb;
};
Node *createNode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->arb = NULL;
    return newnode;
}
Node *copyList(Node *head)
{
    if (head == NULL)
        return head;
    unordered_map<Node *, Node *> nodeMap;
    Node *newHead = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        struct Node *newnode = createNode(temp->data);
        nodeMap.insert({temp, newnode});
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        struct Node *matchNode = nodeMap.find(temp)->second;
        if (temp->next == NULL)
            matchNode->next = NULL;
        else
            matchNode->next = nodeMap.find(temp->next)->second;
        if (temp->arb == NULL)
            matchNode->arb = NULL;
        else
            matchNode->arb = nodeMap.find(temp->arb)->second;
        temp = temp->next;
    }
    return nodeMap.find(head)->second;
}