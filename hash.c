#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int hash(const char *key, int size) {
    int sum = 0;//initiating a sum variable to 0
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];//add the ASCII value of each character in the key
    }
    return sum % size;//return index value
}

HASHTABLE* new_hashtable(int size) {
    HASHTABLE *ht = (HASHTABLE*)malloc(sizeof(HASHTABLE));//allocating memory for the hash table
    if(ht == NULL) {return NULL;}
    ht->hna=(HASHNODE**)calloc(size, sizeof (HASHNODE*));//initialising array of hash buckets to null
    ht->size = size;//setting hash table size
    ht->count = 0;//initializing count to zero

    return ht;//return new hash table
}

// Inserts a key-value pair into the hash table
int hashtable_insert(HASHTABLE *ht, const char *key, int value) {
    int index = hash(key, ht->size);//getting hash index for the key
    HASHNODE *current = ht->hna[index];//pointer to start of linked list at the bucket
    HASHNODE *prev = NULL;

    //traversing the linked list at the hash index to check for the key
    while (current != NULL && strcmp(current->key, key) < 0) {
        prev = current;
        current = current->next;//moving to next node
    }

    if (current != NULL && strcmp(current->key, key) == 0) {//if key already exists
        current->value = value;//updating existing keys value
        return 0;//return 0 to indicate key already existed
    }

    HASHNODE *new_node = (HASHNODE*)malloc(sizeof(HASHNODE));//memory allocation
    if (new_node == NULL) {return 0;}
    strcpy(new_node->key, key);//copying key into new node
    new_node->value = value;//initiating the value of the new node
    new_node->next = current;  //insert node in the correct position

    if (prev == NULL) {//if key is first node insert at head of linked list
        ht->hna[index] = new_node;
    } else {//key is not first node
        prev->next = new_node;//insert between previous and current
    }

    ht->count++;//increment number of elements
    return 1;//return 1 upon successful insertion
}

HASHNODE* hashtable_search(HASHTABLE *ht, const char *key) {
    int index = hash(key, ht->size);//getting hash index for key
    HASHNODE *current = ht->hna[index];//pointer to start of linked list

    //traversing linked list to find key
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current;//return current node if key is found
        }
        current = current->next;//move to next node
    }
    return NULL;//return null if key is not found
}

int hashtable_delete(HASHTABLE *ht, const char *key) {
    int index = hash(key, ht->size);//getting hash index for key
    HASHNODE *current = ht->hna[index];//pointer to start of linked list
    HASHNODE *prev = NULL;

    //traverse the linked list to find the key
    while (current != NULL && strcmp(current->key, key) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return 0;//if key is not found return 0
    }

    //Delete the node
    if (prev == NULL) {
        ht->hna[index] = current->next;//deleting from head
    } else {
        prev->next = current->next;//deleting from middle
    }

    free(current);//freeing deleted node
    ht->count--;//decrementing count
    return 1;//return 1 to indicate successful deletion
}

void hashtable_clean(HASHTABLE **ht) {
    for (int i = 0; i < (*ht)->size; i++) {
        HASHNODE *current = (*ht)->hna[i];
        while (current != NULL) {
            HASHNODE *temp = current;
            current = current->next;
            free(temp);//freeing each node
        }
    }

    free((*ht)->hna);//free array of pointers
    free(*ht);//free hash table
    *ht = NULL;//hash table pointer to null
}