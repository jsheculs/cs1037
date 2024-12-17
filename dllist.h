
typedef struct Node {//node to hold char data values
 char data;
 struct Node* prev;
 struct Node* next;
}Node;

typedef struct {//structure to hold length, start and end node pointers
 Node *head;
 Node *tail;
 int length;
}DLL;

/*
 * Create and return a new node using malloc() with passed data value and returns pointer of the node.
*/
Node* new_node(char data);

/*
 * Insert a given node at the beginning the of a doubly linked list. 
 * @param DLL *dllp -  reference to input DLL variable 
 * @param NODE *np  -  reference of a NODE node to be inserted
*/
void dll_insert_start(Node **head, char data);

/*
 * Insert a node at the end of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable 
 * @param NODE *np  -  reference of a NODE node to be inserted
*/
void dll_insert_end(Node **head, char data);

/*
 * This deletes the first node of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable 
*/
void dll_delete_start(Node **head);

/*
 * Delete the end node of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable  
*/
void dll_delete_end(Node **head);

/*
 * Clean and free the nodes of a doubly linked list and reset start and length.
 * @param DLL *dllp -  reference to input DLL variable 
*/
void dll_clean(DLL *dllp);