#include <stdio.h>
#include <stdlib.h>
#include "AVL_modified.h"

// Function to get the height of a node
int height(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Utility function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node
AVLNode* createNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

// Right rotate subtree rooted with y
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get the balance factor of a node
int getBalance(AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

AVLNode* insert(AVLNode* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    //updating height
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of this ancestor node to check if it became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Utility function to print pre-order traversal of the tree
void preOrder(AVLNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//function to display inorder traversal
void inOrder(AVLNode *root) {
    if (root != NULL) {
        inOrder(root->left);//traverse left first
        printf("%d ", root->key);//print root
        inOrder(root->right);//traverse right last
    }
}

AVLNode* deleteNode(AVLNode* root, int key) {
    if (root == NULL) {return root;}//base case

    //finding the node to felete
    if (key < root->key) {
        root->left = deleteNode(root->left, key);//if key is smaller search left subtree
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);//if key is larger search right subtree
    } else {//node with key found
        if (root->left == NULL || root->right == NULL) {//case where node has one or no child
            AVLNode* temp = root->left ? root->left : root->right;
            free(root);//delete current node
            return temp;//return non null child
        } else {//two children
            AVLNode* temp = root->right;//find inorder successor
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->key = temp->key;//replace current's key with in order successor's key
            root->right = deleteNode(root->right, temp->key);//delete in order successor
        }
    }
//updating height after deletion
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);//getting balance factor

    //left left case
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    //left right case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //right right case
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    //right left case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

return root;
}

//function to search for desired key
AVLNode* search(AVLNode* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (root->key < key) {//if value at root is less than key traverse right subtree
        return search(root->right, key);
    }
    return search(root->left, key);//traverse left subtree
}

//function to count tree nodes
int countNodes(AVLNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);//returning 1 (for root) plus the left and right subtree counts
}

//helper function to compute exponential powers
int power_function(int base, int exponent) {
    int result;
    for(int i=1;i<exponent;i++) {
        result = base * result;
    }
    return result;
}
void levelOrder(AVLNode* root) {
    if (root == NULL) return;

    //creating and initializing a queue
    AVLNode **queue = (AVLNode**)malloc(sizeof(AVLNode*) * (power_function(2, root->height)+1));
    AVLNode **front = queue;
    AVLNode **rear = queue+1;

    //enqueueing
    *front = root;
    while (front != rear) {
        AVLNode *temp = *front;
        front++;
        if(temp->left != NULL) {
            *rear = temp->left;
            rear++;
        } else if(temp->right != NULL) {
            *rear = temp->right;
            rear++;
        }
        printf("%d ", temp->key);
    }
}
void tree_free(AVLNode* root) {
    if (root == NULL) return;
    tree_free(root->left);//freeing left subtree
    tree_free(root->right);//freeing right subtree
    free(root);//freeing root node
}

int main() {
    AVLNode *root = NULL;//initiating AVL root node

    //inserting each of the nodes
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 5);

    //printing tree in order
    printf("In-order traversal after insertions: ");
    inOrder(root);
    printf("\n");

    //searching if desired keys are in the tree
    printf("Is 6 in the tree?");
    if (search(root, 6) == NULL) {printf(" No\n");}
    else {printf(" Yes\n");}

    printf("Is 20 in the tree?");
    if (search(root, 20) == NULL) {printf(" No\n");}
    else {printf(" Yes\n");}

    printf("Is 10 in the tree?");
    if (search(root, 10) == NULL) {printf(" No\n");}
    else {printf(" Yes\n");}


    // Removing desired node
    root = deleteNode(root, 5);
    printf("Minimum value removed: 5\n");

    //printing in order after deletion
    printf("In-order traversal after deletion: ");
    inOrder(root);
    printf("\n");

    //removing desired node
    root = deleteNode(root, 20);

    //printing in order after deletion
    printf("In-order traversal after deleting 20: ");
    inOrder(root);

    return 0;
}

