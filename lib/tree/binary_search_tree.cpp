#include <stdlib.h>
using namespace std;

int N;
struct Node {
    int key;
    Node *left, *right, *parent;
};
Node *root, *NIL;

void insert(int k) {
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while (x != NIL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NIL) {
        root = z;
    }
    else {
        if (z->key < y->key) {
            y->left = z;
        }
        else {
            y->right = z;
        }
    }
}

bool find(Node *v, int k) {
    if (v == NIL) return false;
    else if (v->key == k) return true;
    else {
        if (v->key < k) return find(v->right, k);
        else return find(v->left, k);
    }
}