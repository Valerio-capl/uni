#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// implementazione queue con linked-list
// FIFO first in first out, primo elemento che entra è il primo che esce
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;
typedef struct Queue {
    QNode* front;
    QNode* tail;
} Queue;

// front->...->tail; front primo elemento, tail l'ultimo
// esempio 10->20->30; se aggiungi un num 40 si aggiunge dopo il 30, se devi fare il pop togli il 10 e il front diventa 20.

// crea una queue e inizializza a null
Queue* createQueue(){
    Queue *q = (Queue *) malloc(sizeof(Queue));
    if(q == NULL) return NULL;
    q->front = NULL;
    q->tail = NULL;
    return q;
}

// inserisci nodo alla fine;
void enqueue(Queue* q, int value){
    if(q == NULL) return;
    QNode *nodo = (QNode *) malloc(sizeof(QNode));
    if(nodo == NULL) return;
    nodo->data = value;
    nodo->next = NULL;

    if(q->front == NULL && q->tail == NULL){
        q->front = nodo;
        q->tail = nodo;
        return;
    }

    QNode *prev = q->tail;
    prev->next = nodo;
    q->tail = nodo;
}

// pop il nodo all inizio;
int dequeue(Queue* q){
    if(q == NULL || (q->front == NULL && q->tail == NULL)) return -1;
    QNode *temp = q->front;
    int data = temp->data;
    q->front = temp->next;
    if (q->front == NULL) q->tail = NULL; // perche se front è null q è vuota quindi si aggiorna anche tail
    free(temp);
    return data;
}

// peek il primo valore della q;
int first(Queue* q){
    if(q == NULL || q->front == NULL) return -1;
    return q->front->data;
}
// true or false se è vuota la q;
bool isEmpty(Queue* q){
    return (q == NULL || (q->front == NULL && q->tail == NULL));
}

// free l'intera q;
void freeQueue(Queue* q){
    if(q == NULL) return;
    while (q->front){
        QNode *temp = q->front;
        q->front = temp->next;
        free(temp);
    }
    q->tail = NULL;
    free(q);
}