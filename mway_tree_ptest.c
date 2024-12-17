#include <stdio.h>
#include <stdlib.h>
#include "mway_tree.h"  // Assume this contains your function declarations and structure definition

void tester() {
    TNODE *root = create_node();  // Create the root of the m-way tree

    // Test: Insert and Display
    printf("Test: Insert and Display\n");
    insert_key(&root, 22);
    printf("insert_key(root, 22)\n");
    insert_key(&root, 5);
    printf("insert_key(root, 5)\n");
    insert_key(&root, 10);
    printf("insert_key(root, 10)\n");

    printf("display_tree(root):\n");
    display_tree(root);

    // Test: In-Order Traversal
    printf("\nTest: In-Order Traversal\n");
    printf("print_inorder(root): ");
    print_inorder(root);
    printf("\n");

    // Test: Search Key
    printf("\nTest: Search Key\n");
    if (search_key(root,10)) {
        printf("search_key(root, 10): Found\n");
    } else {
        printf("search_key(root, 10): Not Found\n");
    }

    if (search_key(root,15)) {
        printf("search_key(root, 15): Found\n");
    } else {
        printf("search_key(root, 15): Not Found\n");
    }

    // Test: Delete Key
    printf("\nTest: Delete Key\n");
    delete_key(&root, 10);
    printf("delete_key(root, 10)\n");

    printf("display_tree(root):\n");
    display_tree(root);
}

int main() {
    tester();  // Call the test function
    return 0;
}