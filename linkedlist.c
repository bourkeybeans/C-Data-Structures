#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int val;
    struct node* next;
    struct node* prev;

} node;

node* buildlist(int *numbers, int len);
node* findtail(node *head);
void insert_at_end(int val);
void insert_at_start(int val);
void insert_at_interval(int pos, int val);

node* head;
node* tail;

int main(int agrc, char** argv)
{
    node* curr;
  
    int numbers[] = {1,2,3,4,5};
    int length;
    length = 5;

    head = buildlist(numbers, length);
    curr = head;
    tail = findtail(curr);
    while (curr != NULL)
    {
        printf("%i", curr->val);
        curr = curr->next;
    }
    printf("\n");
    printf("Reversed:\n");
    curr = tail;
    printf("%i\n", tail->val);
    while (curr != NULL)
    {
        printf("%i", curr->val);
        curr = curr->prev;
    }
    insert_at_end(5);
    insert_at_start(3);
    curr = head;
    printf("insert test\n");
    while (curr != NULL)
    {
        printf("%i", curr->val);
        curr = curr->next;
    }
    
}

node* buildlist(int *numbers, int len)
{
    int i;
    node* NewNode;
    head = NULL;
    tail = NULL;
    for (i = 0; i < len; i++)
    {
       NewNode = malloc(sizeof(node));
       NewNode->val = numbers[i];
       NewNode->next = NULL;
       NewNode->prev = tail;
       if (tail) {
            tail->next = NewNode; /*Link previous tail to new node*/ 
        } else {
            head = NewNode; /* If it's the first node, set head */
        }
        
        tail = NewNode; /*Update tail to new node*/ 
    }

    return head;
}

node* findtail(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    while(head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

void insert_at_start(int val)
{
    node* NewNode;
    node* temp;
    NewNode = malloc(sizeof(sizeof(node)));
    NewNode->val = val;
    NewNode->prev = NULL;
    NewNode->next = head;
    
    head = NewNode;

}

void insert_at_end(int val)
{
    
    node* NewNode = malloc(sizeof(sizeof(node)));
    NewNode->val = val;
    NewNode->prev = tail;
    NewNode->next = NULL;
    
    tail = NewNode;
}


void insert_at_interval(int pos, int val)
{

}