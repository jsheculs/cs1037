// BST.c
#include "BST.h"
Node* addNode(Node* root, int value) {
//if root node is null create a new node
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            return NULL;
        }
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

//if value we want to add is less than data at the root add node to the left subtree
    if (value < root->data) {
        root->left = addNode(root->left, value);

//if value we want to add is less than data at the root add node to the left subtree
    } else if (value > root->data) {
        root->right = addNode(root->right, value);
    }
    return root;
}


Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;//if root is null return

//recursively searching for the node to delete
    if (value < root->data) {//if value to delete is smaller than the root's value, recurse left subtree
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {//if value to delete is greater than root's value, recurse right subtree
        root->right = deleteNode(root->right, value);

    //if the node to delete is found
    } else {
        // Node with one or no child
        if (root->left == NULL) {//left child is null, replace node with its right child
            Node* temp = root->right;
            free(root);//free memory
            return temp;//return the new root

        } else if (root->right == NULL) {//if right child is null replace node with left child
            Node* temp = root->left;
            free(root);//free memory
            return temp;//return new root
        }
        // Node with two children, we want to find in order successor
        Node* temp = findSmallestValue(root->right);//temporary node to hold smallest value (in order successor)
        root->data = temp->data;//replace data of current node with in order successor
        root->right = deleteNode(root->right, temp->data);//delete in order successor
    }
    return root;
}

Node* searchNode(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;//if found or empty return root
    }
    if (value < root->data) {
        return searchNode(root->left, value);//searching left subtree
    }
    return searchNode(root->right, value);//searching right subtree

}

int computeSize(Node* root) {
    if (root == NULL) {//if tree is empty return 0
        return 0;
    }
    return 1 + computeSize(root->left) + computeSize(root->right);//count nodes in left and right subtrees plus 1 for current node
}


void inOrderTraversal(Node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);//traverse left subtree
    visit(root);//visit the root
    inOrderTraversal(root->right);//traverse right subtree
}
void postOrderTraversal(Node* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);//traverse left subtree
    postOrderTraversal(root->right);//traverse right subtree
    visit(root);//visit the root
}
void preOrderTraversal(Node* root) {
    if (root == NULL) return;
    visit(root);//visit root
    preOrderTraversal(root->left);//traverse left subtree
    preOrderTraversal(root->right);//traverse right subtree

}
void visit(Node* node) {
    if (node != NULL)
        printf("%d ", node->data);
    }
Node* findSmallestValue(Node* root) {
    Node* current = root;
    while (current && current->left != NULL)
    current = current->left;
    return current;
}
int isEmpty(Node* root) {
    return root == NULL;
}
