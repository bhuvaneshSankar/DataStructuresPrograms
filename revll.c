#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* head = NULL;

struct node* createNode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}
void insert(int val){
    if(head == NULL){
        struct node* newnode = createNode(val);
        head = newnode;
    }
    else{
        struct node* newnode = createNode(val);
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void printLinkedList() {
    struct node* temp=head;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp=temp->next;
    }
  //  printf("%d ", temp->data);
}
void revInGroupsUtil(struct node* head, int k){
    struct node* curr = head;
    struct node* prev = NULL;
    int temp=0, attempt=0;
    struct node* nextCurr = curr;
    struct node* ptrArr[25];
    int len = 0;
    for(int i=1;  ;i++){
        if(curr->next == NULL)
            break;        
        curr = curr->next;
        if(i%k==0){
            ptrArr[len] = curr;
            len++;
        }
    }
    revInGroups(head, head, prev, k, 1, attempt);
    attempt++;    
      for(int i=0; i<len; i++){
        // printf("%d ", ptrArr[i]->data);
         revInGroups(ptrArr[i], ptrArr[i], prev, k, 1, attempt);
         attempt++;
     }
}

int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
}