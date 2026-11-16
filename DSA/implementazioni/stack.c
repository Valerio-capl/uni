
#include <stdlib.h>
#include "stack.h"

void initStack(Stack *s) {
    s->top = NULL;
    s->size = 0;
}

bool isEmpty(Stack *s) {
    return s->top == NULL;
}

bool push(Stack *s, Node *data) {
    SNode *newNode = malloc(sizeof(SNode));
    if (newNode == NULL) return false;

    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;

    return true;
}

Node *pop(Stack *s) {
    if (isEmpty(s)) return NULL;
    SNode *temp = s->top;
    Node *data = temp->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return data;
}

Node *peek(Stack *s) {
    if (isEmpty(s)) return NULL;
    return s->top->data;
}

void freeStack(Stack *s) {
    while (!isEmpty(s))
        pop(s);
}
