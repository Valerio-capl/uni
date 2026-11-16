#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include "../implementazioni/stack.h"
// es fatti tutti con dfs. guarda es_tree_bfs.c per bfs;

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;


// dato albero binario conta quanti foglie ci sono, sia ricorsiva che iterativa;
// O(n) sia ricorsiva che iterativa, 
int conta_foglie(Node *root){
    if (root->left == NULL && root->right == NULL) return 1;
    int sx = conta_foglie(root->left);
    int dx = conta_foglie(root->right);
    return sx+dx;
}
int conta_foglie_iter(Node *root){
    if (root == NULL) return 0;
    int count = 0;
    Stack s;
    initStack(&s);
    push(&s, root);
    while (s.top != -1){
        Node *temp = pop(&s);
        if (temp->left != NULL && temp->right != NULL){
            count++;
        } else {
            if (temp->right != NULL) push(&s, temp->right);
            if (temp->left != NULL) push(&s, temp->left);
        }    
    }
    return count;
}

// altezza di un albero binario con dfs;
int profonditaMax(Node *root){
    if (root == NULL) return 0;
    int max;
    int sx = profonditaMax(root->left);
    int dx = profonditaMax(root->right);
    if (sx>dx) max = sx;
    else max = dx;
    return 1 + max;
}

// verifica che un albero è bilanciato;
// a partire dalle foglie, controlli se la distanza è piu di 1 non è bilanciato
// propaga poi dalle foglie in su se non lo è.
int balance_dfs(Node *root){
    if (root == NULL) return 0;
    int max;
    int sx = isBalanced(root->left);
    int dx = isBalanced(root->right);
    if (sx == -1 || dx == -1
        || abs(sx-dx) > 1) return -1;
    if (sx>dx) max = sx;
    else max = dx;
    return 1 + max;
}
bool isBalanced(Node *root){
    return balance_dfs(root) != -1;
}

// scambia i nodi di un albero, tranne le foglie. con dfs;
void mirrorTree(Node *root){
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    Node *temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
    
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// controlla che le foglie si trovino sullo stesso livello;
// usa leaf per capire se è la prima foglia, con dfs la prima foglia è quella che sta su lvl piu vicino a root.
// si controlla se livello della foglia attuale è uguale alla prima foglia;
bool lvl_dfs(Node *root, int lvl, int *leaf){
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL){
        if (*leaf == -1){
            *leaf = lvl;
            return true;
        }
        return lvl == *leaf;
    }
    return lvl_dfs(root->left,lvl+1, leaf) && lvl_dfs(root->right,lvl+1, leaf);
}
bool sameLvl(Node *root){
    if (root == NULL) return true;
    int leaf = -1;
    return lvl_dfs(root, 0, &leaf);
}

// ritorna tutti i nodi che hanno distanza k da root. salvati in array;
void distanzaK(Node *root, int k, int dis,  int n, Node *arr[n], int *i){
    if (root == NULL) return;
    if (dis == k) {
        arr[*i] = root;
        (*i)++;
        return;
    }
    distanzaK(root->left, k, dis+1, n, arr, i);
    distanzaK(root->right, k, dis+1, n, arr, i);
}
Node **dis(Node *root, int k){
    int n = 10; // num nodi
    Node *arr[n];
    int i = 0;
    distanzaK(root, k, 0, n, arr, &i);
    return arr;
}

// somma i valori delle foglie;
int sommaFoglie(Node *root){
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->data;
    return sommaFoglie(root->left) + sommaFoglie(root->right);
}
