/**
 * RECORD structure
 * name  - char array for person's name
 * score - float score of record
 */
typedef struct {
  char name[40];
  float score;
} RECORD;

/**
 * NODE structure
 * data  - RECORD data
 * next  - pointer pointing to the next node of singly linked list
 */
typedef struct node {
  RECORD data;
  struct node *next;
} NODE;

/**
 * Singly linked list structure
 * int length  - the number of nodes of the linked list
 * NODE *start - pointer pointing to the first node of the linked list
 */
typedef struct sllist {
  int length;
  NODE *start;
} SLL;


/**
 * Search singly linked list by name key.
 * @param SLL *sllp provides the address of a singly linked list structure.
 * @param name Key to search
 * @return Pointer to found node if found; otherwise NULL
 */
NODE *sll_search(SLL *sllp, char *name);

/**
 * Insert new record to linked list at the position sorted by record name field.
 * @param @param SLL *sllp provides the address of a singly linked list structure.
 * @param name The name data of new record.
 * @param score The score data of new record
 */
void sll_insert(SLL *sllp, char *name, float score);

/**
 * Delete a node of record matched by the name key from linked list.
 * @param @param SLL *sllp provides the address of a singly linked list structure.
 * @param name  The key used to find the node for deletion. 
 * @return 1 if deleted a matched node, 0 otherwise. 
 */
int sll_delete(SLL *sllp, char *name);

/**
 * Clean singly linked list, delete all nodes. 
 * @param @param SLL *sllp provides the address of a singly linked list structure.
 */
void sll_clean(SLL *sllp);

// Imports records from a specified file into the linked list.
// Parameters:
//    filename - The path to the file containing record data.
//    sllp - Pointer to the linked list structure where data will be imported.

void import_data(const char *filename, SLL *sllp);
// Description: Imports records from a specified file into the linked list.
// Each record from the file is added to the list in a sorted order or as per the required structure.
// Parameters:
//    filename - The path to the file containing record data.
//    sllp - Pointer to the linked list structure where data will be imported.

void process_data(SLL *sllp);
// Description: Processes the data in the linked list, calculating and displaying
// statistics such as count, mean, standard deviation, and median.
// This function iterates over the list to collect and compute these metrics,
// providing a summary of the records in the linked list.
// Parameters:
//    sllp - Pointer to the linked list structure containing the records.

void sll_clean(SLL *sllp);
