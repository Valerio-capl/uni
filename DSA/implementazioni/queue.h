
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Node Node;

typedef struct QNode {
    Node *data;
    struct QNode *next;
} QNode;

typedef struct Queue {
    QNode *front;
    QNode *rear;
    int size;
} Queue;

// Queue operations
void initQueue(Queue *q);
bool isEmpty(Queue *q);
bool enqueue(Queue *q, Node *data);
Node *dequeue(Queue *q);
void freeQueue(Queue *q);

#endif
