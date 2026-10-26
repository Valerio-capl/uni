#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// implementazione stack con linked-list
// LIFO last in first out, l'ultimo elemento aggiunto è il primo a uscire
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// stack: top->..->inizio->null;

// push nodo al top dello stack
void push(StackNode** top, int data){
    if (top == NULL) return;
    StackNode *temp = createStackNode(data);
    temp->next = *top;
    *top = temp;
}

// pop elimina l'elemento piu in alto e ritorna il suo valore
int pop(StackNode** top){
    if (top == NULL) return -1; // err
    StackNode *temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
} 

// guarda il valore dell'elemento piu in alto
int peek(StackNode* top){
    if (top == NULL) return -1; // err
    return top->data;
}

// vero o falso se è vuota lo stack
bool isEmpty(StackNode* top){
    return (top == NULL);
}

// crea nodo dello stack
StackNode* createStackNode(int data){
    StackNode *nodo = malloc(sizeof(StackNode));
    if (nodo == NULL) return NULL;
    nodo->data = data;
    nodo->next = NULL;
    return nodo;
}

// free su ogni elemento dello stack
void freeStack(StackNode** top){
    if (top == NULL) return; 
    while (*top != NULL) {
        StackNode* temp = *top;
        *top = temp->next;
        free(temp);
    }
}
