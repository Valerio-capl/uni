#include <stdio.h>
// esercizi a lezione.
#include "stack.h"
// find celebrity
// una matrice quadrata se M[C][i]==0 e M[i][C]==1 allora C è celebrita 
// si usa uno stack per arrivare ad O(n)
// prima push tutti gli elementi della matrice
// si pushano 2 indici se M[A][B] == 1 si rimuove A e si pusha B dentro come possibile celebrita

int findCelebrity(int n, int M[n][n]){
    Stack s;
    initStack(&s);
    for (int i = 0; i<n-1; i++){
        push(&s, i);
    }
    while (!isEmpty(&s)){

    }
}


typedef struct Node {
    int data;
	struct Node *next;
    struct Node *prev;
} Node;

// ruota una lista doppiamente linkata di p
void ruotaLista(Node *head, int p){
    Node *curr = head, *prev = NULL;
    int c = 0;
    while (curr != NULL && c<p){
        prev = curr;
        c++;
        curr = curr->next;
    }
    Node *tail = curr;
    while (tail != NULL){
        tail = tail->next;
    }

    tail->next = head;
    head->prev = tail;
    prev->next = NULL;
    curr->prev = NULL;
}


// rimuovi ciclo da lista single-linked
// 2 fasi, prima rilevi ciclo con fast-slow pointers poi rimuovi il ciclo
void RimuoviCiclo(Node *head){
    Node *s = head, *f = head;
    while (f != NULL && f->next != NULL){
        s = s->next;
        f = f->next->next;
        if (s == f) break;
    }
    if (f == NULL || f->next == NULL) return;
    s = head;
    // ciclo sulla testa
    if (s==f){
        while (f->next != s) f = f->next;
        f->next = NULL;
        return;
    }
    while (s->next != f->next){
        s = s->next;
        f = f->next;
    }
    f->next = NULL;
}