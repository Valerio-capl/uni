#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;


// inverti lista single-link.       1->2->3->4->5->null  null<-1<-2<-3<-4<-5
// idea prendi un prev = none e salvi il next del nodo, il next dell curr diventa il prev e aggiorni prev e next
void reverse(Node** head){
    if (head == NULL || *head == NULL) {
        return;
    }

    Node *prev = NULL, *curr = *head;
    Node *temp = curr;
    while (!curr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
}

// metti in una lista gia ordinata il nuovo nodo nel posto giusto
// 1->2->3->4->6->null  nuovo: 5  1->2->3->4->5->6->null
void insertOrdered(Node **head, Node *newNode){
    Node *prev, *curr;
    while (curr->next != NULL){
        if (curr->data < newNode->data && curr->next > newNode->data){
            newNode->next = curr->next;
            curr->next = newNode;
        }
        curr = curr->next;

    if (newNode->next == NULL) curr->next = newNode;
    }
}


// Scrivi una funzione in linguaggio C che riceva in input la testa (head) di una lista semplicemente collegata 
// e stampi l'elemento che si trova esattamente a metà della lista.
// fast pointers uno scorre 1 volta avanti l'altro 2 e quando fast arriva alla fine l'altro sta a meta
int mid(Node **head){
    Node *s = *head, *f = *head;
    while (s != NULL && f != NULL){
        s = s->next;
        f = f->next->next;
    }
    return s->data;
}

// Scrivi una funzione in linguaggio C per rimuovere tutti i nodi duplicati da una lista semplicemente collegata non ordinata. 
// La funzione deve mantenere soltanto la prima occorrenza di ciascun valore e liberare correttamente la memoria 
Node *delete(Node **prec){
    if (prec == NULL || *prec == NULL) return NULL;
    Node *target = *prec;
    *prec = target->next;
    target->next = NULL;
    return target;
}
bool is_seen(int val, int *arr, int n){
    for (int i=0; i<n; i++){
        if(arr[i] == val) return true;
    }
    return false;
}  
// si puo fare senza arr, con due cicli
// il primo prende un nodo e il secondo controlla se ci sono altri nodi con lo stesso valore. 
// ora O(n^2) caso peggiore e O(n) caso medio ma O(n) spazio con cicli tempi uguali ma O(1) spazio.
// senno con set O(n) tempo e O(n) spazio, ma ancora non fatti (04-11)
void removeDuplicates(Node **head, int n){
    if (head == NULL || *head == NULL) return;

    Node *curr = *head, *prev = NULL;
    int seen[n]; // con array perche ancora non fatti set, n è lunghezza lista
    int i = 0;
    while (curr != NULL){
        if (is_seen(curr->data, seen, i)){
            Node *deleted;
            if (prev == NULL){
                deleted = delete(head);
                curr = *head;
            } else {
                deleted = delete(&(prev->next));
                curr = prev->next;
            }
            free(deleted);
        } else {
            seen[i] = curr->data;
            i++;
            prev = curr;
            curr = curr->next;
        }
    }
}
void removeDup_cicli(Node **head){
    if (head == NULL || *head == NULL) return;
    Node *curr = *head;
    while (curr != NULL) {
        Node *temp = curr;
        while (temp->next != NULL) {
            if (temp->next->data == curr->data) {
                Node *deleted = delete(&(temp->next));
                free(deleted);
            } else temp = temp->next;
        }
        curr = curr->next;
    }
}

// removeDuplicates con lista gia ordinata O(n)
void removeDuplicates_ord(Node **head){
    if (head == NULL || *head == NULL) return;
    Node *curr = *head;
    while (curr != NULL){
        while((curr->next != NULL) && (curr->next->data == curr->data)){
            Node *temp = curr->next;
            curr->next = temp->next;
            temp->next = NULL;
            free(temp);
        }
        curr = curr->next;
    }
}

int main(void) {

    return 0;
}