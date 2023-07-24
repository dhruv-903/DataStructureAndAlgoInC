#include <stdio.h>
#include <stdlib.h>

struct Node
{
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

struct Node *deletionAtFirstIndex(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deletionInBetween(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deletionAtTheEnd(struct Node *head)
{
    struct Node *p = head->next;
    struct Node *q = head;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    q->next = NULL;
    free(p);
    return head;
}

struct Node *deletionAfterNode(struct Node *head,struct Node*pointer)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != pointer->data)
    {
        q = q->next;
        p = p->next;
    }
    p->next = q->next;
    free(q);
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
    third->next = NULL;

    linkedListTraversal(head);
    // struct Node *newHead = deletionAtFirstIndex(head);
    // struct Node *newHead = deletionInBetween(head,1);
    // struct Node *newHead = deletionAtTheEnd(head);
    struct Node *newHead = deletionAfterNode(head,first);
    linkedListTraversal(newHead);

    return 0;
}
