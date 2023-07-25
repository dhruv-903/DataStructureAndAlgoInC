#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node *insertAtFirstIndex(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    return ptr;
}

struct Node *insertAtTheEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;
    return head;
}

struct Node *insertInBetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    int i = 1;
    struct Node *p = head;
    struct Node *q = head->next;
    while (i != index)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = q;
    q->prev = ptr;
    return head;
}

struct Node *insertAfterNode(struct Node *head, int data, struct Node *pointer)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    struct Node *q = head->next;
    while (p != pointer)
    {
        p = p->next;
        q = q->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = q;
    q->prev = ptr;
    return head;
}

struct Node *deleteAtFirstIndex(struct Node *head)
{
    struct Node *q = head;
    struct Node *p = head->next;

    head = p;
    head->prev = NULL;
    free(q);
    return head;
}

struct Node *deleteAtLastIndex(struct Node *head)
{
    struct Node *p = head->next;
    struct Node *q = head;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    q->next = p->next;
    free(p);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    int i = 1;
    struct Node *p = head->next;
    struct Node *q = head;
    while(i != index){
        p = p->next;
        q = q->next;
        i++;
    }
    struct Node *r = p->next;

    q->next = r;
    r->prev = q;
    free(p);
    
    return head;
}

struct Node *deleteAfterNode(struct Node *head, struct Node *pointer)
{
    struct Node *p = head->next;
    struct Node *q = head;

    while(p->data != pointer->data){
        p = p->next;
        q = q->next;
    }
    struct Node *r = p->next;
    q->next = r;
    r->prev = q;
    free(p);

    return head;
}

int main(int argc, char const *argv[])
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 34;
    head->next = first;

    first->prev = head;
    first->data = 46;
    first->next = second;

    second->prev = first;
    second->data = 19;
    second->next = third;

    third->next = second;
    third->data = 29;
    third->next = fourth;

    fourth->next = third;
    fourth->data = 54;
    fourth->next = NULL;

    linkedListTraversal(head);
    // struct Node *newHead = insertAtFirstIndex(head,77);
    // struct Node *newHead = insertAtTheEnd(head,64);
    // struct Node *newHead = insertInBetween(head,42,3);
    // struct Node *newHead = insertAfterNode(head,84,second);
    // struct Node *newHead = deleteAtFirstIndex(head);
    // struct Node *newHead = deleteAtLastIndex(head);
    // struct Node *newHead = deleteAtIndex(head, 2);
    struct Node *newHead = deleteAfterNode(head, third);
    linkedListTraversal(newHead);

    return 0;
}
