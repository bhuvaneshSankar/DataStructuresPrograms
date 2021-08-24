#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct node *reverse(struct node *head, int k)
{
    struct node *t1;
    struct node *t2;
    struct node *t3;

    t1 = head;
    t2 = head->next;
    if (t2 == NULL)
    {
        return t1;
    }
    t3 = t2->next;
    int count = 1;
    while (count < k && t3)
    {
        t3 = t2->next;
        t2->next = t1;
        t1 = t2;
        t2 = t3;
        count++;
    }
    if (count < k && t3 == NULL && t2)
    {
        t3 = t2->next;
        t2->next = t1;
        t1 = t2;
        t2 = t3;
        count++;
    }
    if (t2)
    {
        head->next = reverse(t2, k);
    }
    else
    {
        head->next = NULL;
    }
    return t1;
}
