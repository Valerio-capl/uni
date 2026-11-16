
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool isEmpty(Queue *q) {
    return q->front == NULL;
}

bool enqueue(Queue *q, Node *data) {
    QNode *newNode = malloc(sizeof(QNode));
    if (newNode == NULL) return false;

    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
    return true;
}

Node *dequeue(Queue *q) {
    if (isEmpty(q)) return NULL;
    QNode *temp = q->front;
    Node *data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    q->size--;
    return data;
}

void freeQueue(Queue *q) {
    while (!isEmpty(q))
        dequeue(q);
}
