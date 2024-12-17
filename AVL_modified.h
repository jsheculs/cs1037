#ifndef AVL_MODIFIED_H
#define AVL_MODIFIED_H

#include <stdio.h>
#include <stdlib.h>

// Define the AVLNode structure
typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

// Function prototypes
AVLNode* createNode(int key);
AVLNode* insert(AVLNode* node, int key);
AVLNode* deleteNode(AVLNode* root, int key);
AVLNode* search(AVLNode* root, int key);
void preOrder(AVLNode* root);
void inOrder(AVLNode* root);
int height(AVLNode* node);
int getBalance(AVLNode* node);
int countNodes(AVLNode* root);
void levelOrder(AVLNode* root);
void tree_free(AVLNode* root); // Function to free the AVL tree

#endif // AVL_MODIFIED_H