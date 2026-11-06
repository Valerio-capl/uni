#include <stdio.h>
#define STACK_SIZE 100
#define QUEUE_SIZE 100
// alberi binari

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// crea nodo di albero binario;
Node *createNode(int data){
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// numero di nodi di un albero ricorsivamente;
int num_nodi(Node *root){
    if (root == NULL) return 0;
    return 1 + num_nodi(root->left) + num_nodi(root->right);
}
// numero di figli di  nodo v;
int grado(Node *v){
    if (v == NULL) return -1;
    int count = 0;
    if (v->left != NULL) count++;
    if (v->right != NULL) count++;

    return count;
}

// inserimento per i figli, non adatta a inserimento generico.

// inserimento nodo sx
void insert_left(Node *parent, int data){
    if (parent == NULL || parent->left != NULL) return;
    Node *newNode = createNode(data);
    if (newNode == NULL) return;
    parent->left = newNode;
    newNode->parent = parent;
}
// inserimento nodo dx
void insert_right(Node *parent, int data){
    if (parent == NULL || parent->right != NULL) return;
    Node *newNode = createNode(data);
    if (newNode == NULL) return;
    parent->right = newNode;
    newNode->parent = parent;
}

// inserimento generico, link è l'indirizzo del figlio che si vuole inserire;
void insert_child(Node **link, Node *parent, int data){
    if (link == NULL || parent == NULL) return;
    if (*link != NULL) return; // esiste gia un sottoalbero dx-sx

    Node *newNode = createNode(data);
    if (newNode == NULL) return;
    *link = newNode;
}

// dfs e bfs

// prima si visita il nodo poi si analizza il sinistro e il destro;
// stampa in ordine root -> tutti figli sx -> tutti i dx
// usato soprattutto per copiare albero
void visita_preordine(Node *root){
    if (root == NULL) return;
    printf("%d", root->data);
    visita_preordine(root->left);
    visita_preordine(root->right);
}

// prima arriva all ultimo a sx poi stampa a salire;
// ultimo sx -> figli a salire sx -> root -> figli dx a salire
// usato per ricerca binaria;
void visita_simmetrica(Node *root){
    if (root == NULL) return;
    visita_simmetrica(root->left);
    printf("%d", root->data);
    visita_simmetrica(root->right);
}

// prima tutte le foglie a salire;
// usato soprattutto per eliminare l'albero.
void visita_postordine(Node *root){
    if (root == NULL) return;
    visita_postordine(root->left);
    visita_postordine(root->right);
    printf("%d", root->data);
}


void dfs_iterativa(Node *root){
    if (root == NULL) return;
    Node *s[STACK_SIZE];
    int top = -1;
    s[++top] = root; // si fa incremento preordine senno segmentation
    while (top >= 0) {
        Node *u = s[top--];
        printf("%d ", u->data);
        if (u->right != NULL && top < STACK_SIZE - 1) s[++top] = u->right;
        if (u->left != NULL && top < STACK_SIZE - 1) s[++top] = u->left;
    }
}

 
void bfs(Node *root){
    Node *q[QUEUE_SIZE];
    int tail = 0, head = 0;
    q[tail++] = root;
    while (head < tail){
        Node *u = q[head++];
        if (u != NULL){
            printf("%d", u->data);
            if (u->left != NULL && tail < QUEUE_SIZE) q[tail++] = u->left;
            if (u->right != NULL && tail < QUEUE_SIZE) q[tail++] = u->right;
        }
    }
}

// il free si fa con postordine;
void freeTree(Node *root){
    if (root == NULL) return;
    freetree(root->left);
    freetree(root->right);
    free(root);
}

int main(void){

    return 0;
}