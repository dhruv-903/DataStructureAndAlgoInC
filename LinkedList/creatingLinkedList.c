#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr){

    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } 
}

int main(int argc, char const *argv[])
{
    
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head = (struct Node*) malloc(sizeof(struct Node));
    first = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    head->data = 34;
    head->next = first;
    
    first->data = 46;
    first->next = second;

    second->data = 19;
    second->next = third;

    third->data = 29;
    third->next = NULL;

    linkedListTraversal(head);
    
    return 0;
}
