#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Node Node;

typedef struct SNode {
    Node *data;
    struct SNode *next;
} SNode;

typedef struct Stack {
    SNode *top;
    int size;
} Stack;

// Stack operations
void initStack(Stack *s);
bool isEmpty(Stack *s);
bool push(Stack *s, Node *data);
Node *pop(Stack *s);
Node *peek(Stack *s);
void freeStack(Stack *s);

#endif