#include <stdio.h>
#include <stdlib.h>
#include "mway_tree.h"

TNODE *create_node() {
    TNODE *new_node = (TNODE *)malloc(sizeof(TNODE));//allocating memory for a new m-way tree node
    new_node->count = 0;//initializing number of keys in node to zero
    for (int i = 0; i < M; i++) {
        new_node->child[i] = NULL;//child pointers initialized to NULL
    }
    return new_node;//function returns the new TNODE
}

void insert_key(TNODE **root, int key) {
    if (!*root) {//if the tree is empty create a new node
        *root = create_node();//create node and assign it to the root
        (*root)->key[0] = key;//insert key into first position
        (*root)->count = 1;//update the count of keys
    return;
}
//case when tree is not empty fild correct position to insert new key
    int i = (*root)->count - 1;//initialize i to start at the last key
    while (i >= 0 && (*root)->key[i] > key) {//traverse until reach the first key or until the key at position i is greater than input key
        (*root)->key[i + 1] = (*root)->key[i];//shifting keys
        i--;//move to previous key
    }
    (*root)->key[i + 1] = key;//insert key
    (*root)->count++;//increment key count

}

int search_key(TNODE *root, int key) {
    if (!root) return 0;//node is null, return
    for (int i = 0; i < root->count; i++) {//loop for keys in current node
        if (root->key[i] == key) return 1;//if key found, return 1 to indicate success
        if (root->key[i] > key && root->child[i]) {//if current key is greater than search key search left child
            return search_key(root->child[i], key);
        }
    }

    return (root->child[root->count]) ? search_key(root->child[root->count], key) : 0;//if key is not found search right child, return 0 to indicate not found
}

void print_inorder(TNODE *root) {
    if (!root) return;//if node is null return
    for (int i = 0; i < root->count; i++) {
        print_inorder(root->child[i]);//print left subtree
        printf("%d ", root->key[i]);//print current subtree
    }
    print_inorder(root->child[root->count]);//print right subtree
}

void display_tree(TNODE *root) {
    if (!root) return;//if node is null return
    //print keys in current node
    printf("Node keys: [");
    for (int i = 0; i < root->count; i++) {
        printf("%d%s", root->key[i], (i == root->count - 1) ? "" : ", ");
    }
    printf("]\n");

    //print if child pointer is null or not null
    printf("Child pointers: [");
    for (int i = 0; i <= root->count; i++) {
        printf("%s", root->child[i] ? "Child" : "NULL");
        if (i < root->count) printf(", ");
    }
    printf("]\n");

    //recursively display child nodes
    for (int i = 0; i <= root->count; i++) {
        display_tree(root->child[i]);
    }
}
int find_max_key(TNODE *node) {
    //find the maximum key in the subtree of the current node
    while (node->child[node->count] != NULL) {
        node = node->child[node->count];//move to the right-most child
    }
    return node->key[node->count - 1];//Return the right-most key
}

int delete_key(TNODE **root, int key) {
    if (*root == NULL) {
        return 0;//tree is empty
    }

    //Search for the key to delete in the current node
    int i;
    for (i = 0; i < (*root)->count; i++) {
        if ((*root)->key[i] == key) {
            break;//break if key found in current node
        }
    }

    //if key is found in the current node
    if (i < (*root)->count) {
        //if the node is a leaf, remove the key
        if ((*root)->child[0] == NULL) {
            for (int j = i; j < (*root)->count - 1; j++) {
                (*root)->key[j] = (*root)->key[j + 1];//shift keys left
            }
            (*root)->count--;//decrement key count
            return 1;//return 1 to inidicate success
        }

        //if node is an internal node, replace with max key in the left subtree
        if ((*root)->child[i] != NULL) {
            int predecessor = find_max_key((*root)->child[i]);//finding predecessor key
            (*root)->key[i] = predecessor;//replacing key with predecessor
            return delete_key(&(*root)->child[i], predecessor);//delete predecessor recursively
        }
    }

    //if the key is not found, search child
    if (i == (*root)->count || key < (*root)->key[i]) {
        return delete_key(&(*root)->child[i], key);  //recurse into the correct child
    }

    return 0;//key not found
}