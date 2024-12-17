#ifndef BT_H
#define BT_H

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
}Node;

typedef Node *Tree;

int tree_member(int x, Tree *tree);
void tree_free(Tree *tree);
Tree *tree_insert(int x, Tree *tree);
void pop_minimum(Tree *tree, int *min, Tree **new_tree);

#endif