#include "../implementazioni/queue.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

bool samelvl_bfs(Node *root){
    if (root == NULL) return false;
    Queue q;
    initQueue(&q);
    int lvl = 0;
    int leaf = -1;
    if (!enqueue(&q, root)) return;

    while (!isEmpty(&q)){
        int lvl_size = q.size;

        for (int i = 0; i<lvl_size; i++){
            Node *curr = dequeue(&q);
            if (curr->left == NULL && curr->right == NULL){
                if (leaf == -1) leaf = lvl;
                else if (leaf != lvl){
                    freeQueue(&q);
                    return false;
                }
            }

            if (curr->left != NULL) {
                if (!enqueue(&q, curr->left)) {
                    freeQueue(&q);
                    return false;
                }
            }
            if (curr->right != NULL) {
                if (!enqueue(&q, curr->right)) {
                    freeQueue(&q);
                    return false;
                }
            }
        }

        lvl++;
    }
    freeQueue(&q);
    return true;
}


