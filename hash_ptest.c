#include <stdio.h>

#include "hash.h"  // Include your hash table functions

// Helper function to print the current state of the hash table
#include <stdio.h>
#include "hash.h"


void print_hashtable(HASHTABLE *ht) {
    printf("count %d ", ht->count);
    int printed_any = 0;

    for (int i = 0; i < ht->size; i++) {
        HASHNODE *node = ht->hna[i];
        if (node != NULL) {  // Only print non-empty buckets
            if (printed_any) {
                printf(" ");
            }
            printf("%d ", i);
            while (node != NULL) {
                printf("(%s %d)", node->key, node->value);
                node = node->next;
                if (node != NULL) {
                    printf(" ");
                }
            }
            printed_any = 1;
        }
    }
    printf("\n");
}
int main() {
    // Test hash function
    printf("Test for hash:\n");
    printf("hash(a): %d\n", hash("a", 5));
    printf("hash(b): %d\n", hash("b", 5));
    printf("hash(c): %d\n", hash("c", 5));
    printf("hash(d): %d\n", hash("d", 5));

    // Test new_hashtable function
    printf("\nTest for new_hashtable:\n");
    HASHTABLE *ht = new_hashtable(5);
    printf("new_hashtable(5): size %d count %d\n", ht->size, ht->count);

    // Test hashtable_insert function
    printf("\nTest for hashtable_insert:\n");
    hashtable_insert(ht, "a", 0);
    printf("hashtable_insert(a 0): ");
    print_hashtable(ht);

    hashtable_insert(ht, "b", 1);
    printf("hashtable_insert(b 1): ");
    print_hashtable(ht);

    hashtable_insert(ht, "d", 3);
    printf("hashtable_insert(d 3): ");
    print_hashtable(ht);

    // Test hashtable_search function
    printf("\nTest for hashtable_search:\n");
    HASHNODE *node = hashtable_search(ht, "a");
    printf("search(a): %s\n", node ? node->key : "NULL");
    node = hashtable_search(ht, "b");
    printf("search(b): %s\n", node ? node->key : "NULL");
    node = hashtable_search(ht, "f");
    printf("search(f): %s\n", node ? node->key : "NULL");
    node = hashtable_search(ht, "h");
    printf("search(h): %s\n", node ? node->key : "NULL");

    // Test hashtable_delete function
    printf("\nTest for hashtable_delete:\n");
    hashtable_insert(ht, "e", 4);  // Extra insertions to test delete
    hashtable_insert(ht, "f", 5);
    hashtable_insert(ht, "g", 6);
    hashtable_insert(ht, "c", 2);

    // Print before deletion
    printf("Before deletion:\n");
    print_hashtable(ht);

    hashtable_delete(ht, "a");
    printf("hashtable_delete(a): ");
    print_hashtable(ht);

    hashtable_delete(ht, "b");
    printf("hashtable_delete(b): ");
    print_hashtable(ht);

    // Clean up hash table
    hashtable_clean(&ht);
    return 0;
}