#include <stdio.h>

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

// dfs e bfs
void visita_preordine(Node *root);
void visita_simmetrica(Node *root);
void visita_postordine(Node *root);
void dfs_iterativa(Node *root);
void bfs(Node *root);



int main(void){

    return 0;
}