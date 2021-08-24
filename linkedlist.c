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
void reversePrint(struct node* current){
    if(current==NULL){
        return;
    }
    else{
        reversePrint(current->next);
        printf("%d ", current->data);
    }
}
void findMid(){
    struct node* temp1 = head;
    struct node* temp2 = head;
    while(temp1!=NULL && temp1->next!=NULL){
        temp1 = temp1->next->next;
        temp2 = temp2->next;
    }
    printf("%d ", temp2->data);
}

void deleteNode(struct node *temp)         // del without head pointer - left shift the data of the nodes and make n-1th node's next as null
{
   // Your code here
   struct node* curr = temp;
   while(curr!= NULL){
       curr->data = curr->next->data;
       if(curr->next->next == NULL){
            struct node* lastNode = curr->next;
            curr->next = NULL;
            free(lastNode);
       }
       curr= curr->next;
   }
}
struct node* end;
struct node* nxt;
void revInGroups(struct node* currRoot, struct node* curr, struct node* prev, int k, int count, int attempt){
    if(count==k-1){
        end = curr->next;
        nxt = end->next;
        end->next = curr;
        curr->next = prev;
        if(attempt==0){
            head = end;
        }
     //   printf("%d ", end->data);
    }
    else{
        revInGroups(currRoot, curr->next, curr, k, count+1, attempt);
        if(curr==currRoot){
            struct node* temp = end;
            int flag=0;
        /*    while(temp!=NULL && flag<k){
                temp = temp->next;
                flag++;
            }
            if(temp==NULL){
                curr->next = temp;
            }
            else{
                curr->next = temp->next;
            }  */
            curr->next = nxt;
        }
        else{
            curr->next = prev;
        }   
    }
}
void revInGroupsUtil(struct node* head, int k){
    struct node* curr = head;
    struct node* prev = NULL;
    int temp=0, attempt=0;
    struct node* nextCurr = curr;
    struct node* ptrArr[25];
    int len = 0;
    for(int i=1;  ;i++){
    //    printf("%d ", curr->data);
        if(curr->next == NULL)
            break;        
        curr = curr->next;
            
        if(i%k==0){
        //    printf("%d %d\n", i, curr->data);
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
  /*   revInGroups(curr, curr, prev, k, 1, attempt);
    attempt++;
 //   printLinkedList();
     for(int i=0; ;i++){
        curr = curr->next;
        if(curr==NULL){
            break;
        }
        if(i%k==0){
            printf("%d ", curr->data);
            revInGroups(curr, curr, prev, k, 1);
            attempt++;
        }
     }  */ 
 /*    while(1){
        revInGroups(curr, curr, prev, k, 1);
        temp=0;
        while(temp<k){
            ++temp;
            curr = curr->next;
        }
        if(curr==NULL){
            break;
        }
    }  */
}
void reverse(struct node* curr, struct node* prev){
    if(curr->next == NULL){
        head = curr;
        curr->next = prev;
    }
    else{
        reverse(curr->next, curr);
        curr->next = prev;
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
  //  reversePrint(head);
  //  printf("\n");
  //  findMid(head);
   revInGroupsUtil(head, 4);
 //   reverse(head, NULL);
    printLinkedList();
}