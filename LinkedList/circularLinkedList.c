#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do{
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

struct Node *insertionAtBeginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while(p->next != head){
        p = p->next;
    };
    ptr -> next = p -> next;
    p -> next = ptr; 
    return ptr;
}

struct Node *insertionAtBetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->data = data;
    p->next = ptr;
    return head;
}

struct Node *insertionAtLast(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while(p->next != head){
        p = p->next;
    }
    ptr -> next = p->next;
    p ->next = ptr;

    return head;
}

struct Node *insertionAfterNode(struct Node *head, int data,struct Node *pointer)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->data != pointer ->data)
    {
        p = p->next;
    }
    ptr ->next = pointer->next;
    pointer->next = ptr;

    return head;
}

struct Node *deletionAtFirstIndex(struct Node *head)
{
    struct Node *ptr = head->next;
    struct Node *p = head;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    free(head);
    return ptr;
}

struct Node *deletionAtTheEnd(struct Node *head)
{
    struct Node *p = head->next;
    struct Node *q = head;
    while (p->next != head)
    {
        p = p->next;
        q = q->next;
    }
    q->next = p->next;
    free(p);
    return head;
}

struct Node *deletionAfterNode(struct Node *head,struct Node* pointer)
{
    struct Node *p = head->next;
    struct Node *q = head;
    while (p->data != pointer->data)
    {
        p = p->next;
        q = q->next;
    }
    q->next = p->next;
    free(p);
    return head;
}

struct Node *deletionInBetween(struct Node *head,int index)
{
    struct Node *p = head->next;
    struct Node *q = head;
    int i = 1;
    while (i != index)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    q->next = p->next;
    free(p);
    
    return head;
}


int main(int argc, char const *argv[])
{

    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 34;
    head->next = first;

    first->data = 46;
    first->next = second;

    second->data = 19;
    second->next = third;

    third->data = 29;
    third->next = head;

    linkedListTraversal(head);
    // struct Node *newHead = insertionAtBeginning(head,11);
    // struct Node *newHead = insertionAtBetween(head,11,2);
    // struct Node *newHead = insertionAtLast(head,11);
    // struct Node *newHead = insertionAfterNode(head,11,first);
    // struct Node *newHead = deletionAtFirstIndex(head);
    // struct Node *newHead = deletionAtTheEnd(head);
    // struct Node *newHead = deletionAfterNode(head,second);
    struct Node *newHead = deletionInBetween(head,2);
    linkedListTraversal(newHead);

    return 0;
}
