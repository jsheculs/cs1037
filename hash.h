#ifndef HASH_H
#define HASH_H
#define KEY_LENGTH 20

typedef struct hashdata {
    char key[KEY_LENGTH];//key string of up to 20 characters
    int value;//integer value associated with key
} HASHDATA;

typedef struct hashnode {
    char key[KEY_LENGTH];//key string of up to 20 characters
    int value;//integer value associated with key
    struct hashnode *next;//pointer to next node in the list
} HASHNODE;

typedef struct hashtable {
    HASHNODE **hna;//array of pointers to linked list (buckets)
    int size;//size of hash table
    int count;//number of elements in hash table
} HASHTABLE;

// Function prototypes
int hash(const char *key, int size);
HASHTABLE *new_hashtable(int size);
int hashtable_insert(HASHTABLE *ht, const char *key, int value);
HASHNODE *hashtable_search(HASHTABLE *ht, const char *key);
int hashtable_delete(HASHTABLE *ht, const char *key);
void hashtable_clean(HASHTABLE **ht);

#endif