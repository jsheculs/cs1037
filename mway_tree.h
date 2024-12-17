#ifndef MWAY_TREE_H
#define MWAY_TREE_H

#define M 4//defining the order of the tree

typedef struct node {
    int count;//number of keys in the ndoe
    int key[M-1];//array to hold up to m-1 keys
    struct node *child[M];//array of pointers to child nodes
} TNODE;

// Function prototypes
TNODE *create_node();
void insert_key(TNODE **root, int key);
int search_key(TNODE *root, int key);
void print_inorder(TNODE *root);
void display_tree(TNODE *root);
int delete_key(TNODE **root, int key);

#endif