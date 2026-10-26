#include <stdio.h>
#include <stdlib.h>
// linked list
// altre funzioni su liste linkate negli esercizi.

typedef struct Node {
	int data;
	struct Node *next;
} Node;


// crea nodo della lista
Node *createNode(int data){
    Node *nodo = (Node *) malloc(sizeof(Node));
    if (!nodo) {
        printf("Errore di allocazione memoria.\n");
        exit(1);
    }
    nodo->data = data;
    nodo->next = NULL;
    return nodo;
}

// inserisci nuova testa, se lista vuota primo nodo.
void insertHead(Node** head, int data){
    Node *newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

// inserisci nodo in mezzo a altri nodi
void insertAfter(Node **head, int data, Node *prev){
    Node *newNode = createNode(data);
    if (prev == NULL){ // lista vuota
        newNode->next = *head;
        *head = newNode;
    } else {
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

// inserisci nodo all'ultimo posto, se non vuoto aggiorna lista.
void insertTail(Node **head, int data){
    Node *newNode = createNode(data);
    if (*head == NULL){ // lista vuota
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// del nodo in base al valore
void deleteValue(Node **head, int key){
    Node *temp = *head, *prev = NULL;
    // se testa è il nodo con key.
    if (temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }
    // ciclo finche non trovo la chiave e il prev punta a quello prima quindi scollega il temp e collega il next
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;    // val non trovato
    prev->next = temp->next;
    free(temp);
}

/*  inserimento generico
    prec puo essere sia head che head.next, quindi puo essere sia inserimento in testa che in mezzo alla lista  */
void insert(Node **prec, Node *newNode){
    newNode->next = *prec;
    *prec = newNode;
}

// del generico, ritorna il nodo da rimuovere completamente scollegato dalla lista
Node *delete(Node **prec){
    Node *target = *prec;
    *prec = target->next;
    target->next = NULL; // per motivi di sicurezza cosi non ho problemi è completamente scollegato
    return target;  // il free è a carico del uso non fatto all interno.
}


// cerca se un valore c è nella lista o meno 1==TRUE 0==FALSE
int search(Node* head, int v) {
    Node* current = head;    
    while (current != NULL) {
        if (current->data == v) return 1;
        current = current->next;
    }

    return 0;
}

// restituisce il numero di nodi presenti nella lista
int length(Node* head) {
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main(void){
    Node *head = NULL;
    return 0;
}