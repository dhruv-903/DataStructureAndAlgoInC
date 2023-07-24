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

struct Node *insertionAtBeginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
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

struct Node *insertionAtTheEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->data = data;
    return head;
}

struct Node *insertionAfterNode(struct Node *head,struct Node *previousNode, int data)
{
    struct Node *p = head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = previousNode->next;
    previousNode->next = ptr;
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
    struct Node* newHead = insertionAtBeginning(head,54);
    // struct Node *newHead = insertionAtBetween(head, 54, 1);
    // struct Node *newHead = insertionAtTheEnd(head, 54);
    // struct Node *newHead = insertionAfterNode(head,second, 54);
    linkedListTraversal(newHead);

    return 0;
}
