#include "bt.h"
#include <stdio.h>
#include <stdlib.h>

int tree_member(int x, Tree *tree) {
    Node *current = *tree;//starting at root node

    while (current != NULL) {//tree traversal
        if (x > current->value) {//check if value is greater than the current node
            current = current->right;//move to right subtree
        }else if (x < current->value) {//if value is less than current node
            current = current->left;//move to left subtree
        } else if (x == current->value) {//if value is found
            return 1;//return 1
            // if value is less, then value is to the left
        }
    }
    return 0;//value not found, return 0
}

void tree_free(Tree *tree) {
    if (*tree == NULL) {return;}//if tree is empty do nothing
    tree_free(&(*tree)->left);//recursively free left subtree
    tree_free(&(*tree)->right);//recursively free right subtree
    free(*tree);//free current node

}

Tree* tree_insert(int x, Tree *tree) {
    if (tree == NULL) {//checking if tree is null
        tree = malloc(sizeof(Tree));//allocating memory to new tree
        *tree = NULL;//set tree to initially be empty
    }

    if (*tree == NULL) {//if tree is empty
        Node *new_node = malloc(sizeof(Node)); // Allocate memory for new node
        new_node->value = x;//setting value to be x integer
        new_node->left = NULL;//no left child initially
        new_node->right = NULL;//no right child initially

        *tree = new_node;//assign new node to tree
        return tree;//return updated tree
    }

    Node *current = *tree; // begin traversal with current node
    while (current->value != x) {//while current value is not same as x value
        if (x > current->value) {//if x is greater insert new node to the right
            if (current->right == NULL) {//right tree empty
                Node *new_node = malloc(sizeof(Node));//allocate memory
                new_node->value = x;//setting value to be x
                new_node->left = NULL;//no child initially
                new_node->right = NULL;//no child initially

                current->right = new_node;//linking new node to right
                return tree;//returning updated tree
            } else {//if right tree is not empty
                current = current->right;//move to right subtree
            }
        } else if (x < current->value) {//value to insert is less than current
            if (current->left == NULL) {//if left tree is null
                Node *new_node = malloc(sizeof(Node));//allocate memory
                new_node->value = x;//setting value to be x
                new_node->left = NULL;//no child initially
                new_node->right = NULL;//no child initially

                current->left = new_node;//linking new node to left
                return tree;//returning updated tree
            } else {
                current = current->left;//move to left subtree
            }
        }
    }
    return NULL;// value is already in tree so do nothing
}
