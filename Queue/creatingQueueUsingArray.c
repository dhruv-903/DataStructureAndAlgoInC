#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isFull(struct queue *q){
    if(q -> r == q -> size - 1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if(q -> r == q -> f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This queue is full!");
    }
    else{
        q -> r++;
        q -> arr[q->r] = val;
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This queue is empty!");
    }
    else{
        q->f++;
        a =  q->arr[q->f];

    }
    return a;
}

int main(int argc, char const *argv[])
{
    struct queue q;

    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueue(&q,34);
    enqueue(&q,32);

    if(isEmpty(&q)){
        printf("Queue is emptly!\n");
    }
    else{
        printf("Thank you for using queue\n");
    }
    
    dequeue(&q);
    dequeue(&q);
    
    if(isEmpty(&q)){
        printf("Queue is emptly!\n");
    }
    else{
        printf("Thank you for using queue\n");
    }

    return 0;
}
