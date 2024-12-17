/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author name, ID, email
 *
 * @version 2024-10-22
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"

// Functions

queue_linked* queue_initialize() {
    queue_linked* q = (queue_linked*)malloc(sizeof(queue_linked));//allocating memory to new queue linked structure
    if(q == NULL) {return NULL;}//checking if memory allocation is successful
    q->front = NULL;//initialize queue to empty
    q->rear = NULL;//initialize queue to empty
    return q;//return pointer to new queue

}

void queue_free(queue_linked **source) {

    if(source == NULL || *source == NULL) {return;}//checking if source pointer is null
    queue_linked *q = *source;//assigning source pointer to linked queue q
    queue_node* current = q->front;//pointer to current node at front of q
    while (current != NULL) {//while current node is not null
        queue_node* next = current->next;//stores pointer to next node
        free(current);//frees current node
        current = next;//moves current node to next node
    }

}

BOOLEAN queue_empty(const queue_linked *source) {

    if(source->front == NULL && source->rear == NULL ) {//checks if queue is empty if front and rear are null
        return TRUE;//returns true
    } else {
        return FALSE;//false if not empty
    }

}

int queue_count(const queue_linked *source) {
    if(source == NULL || source -> front ==NULL) {//if source is null and front of queue is null
        return 0;
    }
    int counter = 0;//initializing a counter to track queue count
    queue_node* current = source->front;//current pointer is set to front of source
    while (current != NULL) {//while current pointer is not null
        counter++;//increments counter
        current = current->next;//moves current to next node
    }
    return counter;//returns count
}

void queue_insert(queue_linked *source, data_ptr item) {
    if(source == NULL) {return;}//checks if source is null
    queue_node* new_node = (queue_node*)malloc(sizeof(queue_node));//allocates memory to new node
    if(new_node == NULL) {return;}//checks if node is null therefore memory allocation failed

    new_node -> item = item;//stores item in new node
    new_node -> next = NULL;//points last node to null

    if(source->rear == NULL) {//if source rear is null (queue is empty)
        source -> front = new_node;//assigns new node to front and rear pointers
        source -> rear = new_node;//assigns null to node after rear
    }
    else{//if queue is not empty
        source->rear -> next = new_node;//adds new node to node after rear
        source->rear = new_node;//updates rear pointer to point to new node
    }
}

BOOLEAN queue_peek(const queue_linked *source, data_ptr item) {

    if(source != NULL && source -> front != NULL) {//checks if source and front is not null
        item = source-> front -> item;
        return TRUE;//true if retrieved
    }

    return FALSE;//false if empty
}

BOOLEAN queue_remove(queue_linked *source, data_ptr *item) {
    if(source == NULL || source -> front == NULL){return FALSE;}//checks that source and front of queue are not null or empty
    queue_node *temp = source->front;//assigns temporary pointer to front of source queue
    *item = temp -> item;//assigns data from front node to item pointer
    source->front = source->front->next;//updates front pointer to point to next node

    if(source->front == NULL) {//if front is null updates the rear pointer to also be null
        source -> rear = NULL;
    }

    free(temp);//frees temporary pointer
    return TRUE;//returns true if successfully removed


}

void queue_print(const queue_linked *source) {
    char string[DATA_STRING_SIZE];
    queue_node *current = source->front;

    while(current != NULL) {
        printf("%s\n", data_string(string, sizeof string, current->item));
        current = current->next;
    }
}
