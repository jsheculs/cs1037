/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * Julia Sheculski
 *
 * @version 2024-10/23
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
    // Allocate memory to the data structure
    name_set *set = malloc(sizeof *set);
    // Initialize the header fields.
    set->front = NULL;
    set->rear = NULL;
    return set;
}

int name_set_free(name_set **set) {//function that frees the memory allocated to each node of set
    if(set==NULL||*set==NULL){return 0;}//checking that set is not null
    int number_nodes_freed = 0;//declaring an integer to count the number of nodes freed

    name_set_node *current_node = (*set)->front;//sets the name set node pointer current_node to the front of set
    name_set_node *next_node = NULL;//sets next node value to null


    while (current_node!=NULL) {//while node is not null
        next_node = current_node->next;//stores pointer in next node of list
        free(current_node);//frees the current node
        current_node=next_node;//shifts the pointer
        number_nodes_freed++;//increments the number of nodes freed
    }
    return number_nodes_freed;//returns the int value of number of nodes that were freed

}


BOOLEAN name_set_append(name_set *set, const char *first_name, const char *last_name) {//function that adds names that arent already in set to set
    if (set == NULL || first_name == NULL || last_name == NULL) {//checking for null
        return FALSE; // Invalid input, returns false
    }

    name_set_node *current_node = set->front;// Initialize the current_node pointer to point to the first node of the linked list

    // Checks if the name already exists
    while (current_node != NULL) {//while loop for when current node is not null
        if (strcmp(current_node->first_name, first_name) == 0 && strcmp(current_node->last_name, last_name) == 0) {//string comparison - if first and last name at current node is duplicated returns false
            return FALSE; // Name already exists in the set
            }
        if (current_node->next == NULL) {//if next node is null, breaks while loop to append new name
            break;
        }
        current_node = current_node->next;//moves current pointer to next node
    }

    // Create a new node for the name
    name_set_node *new_node = (name_set_node *)malloc(sizeof(name_set_node));//allocating memory for new node
    if (new_node == NULL) {
        return FALSE; // returns false if memory allocation fails
    }

    // Duplicate first_name and last_name strings

    strncpy(new_node->first_name,first_name,NAME_LEN);//copies first name to first name field of new node
    new_node -> first_name[NAME_LEN-1] = '\0';//null terminates first name string

    strncpy(new_node->last_name,last_name,NAME_LEN);//copies last name to last name field of new node
    new_node -> last_name[NAME_LEN-1] = '\0';//null terminates last name string
    new_node -> next = NULL;//sets next pointer to null to separate from next node

    if (set->front == NULL) {//if list is empty
        set->front = new_node;//sets new node to the front of set
        set->rear = new_node;//sets the rear of the set to new node
    }
    else {
        set->rear -> next = new_node;//if not empty adds new node to rear
        set->rear = new_node;//updates rear to now be new node
    }

    return TRUE;//returns true to indicate successful appending
}


BOOLEAN name_set_contains(const name_set *set, const char *first_name, const char *last_name) {//function to check if first and last name already exist in set


    if (set == NULL) {//checks for invalid input
        return FALSE;
    }

    name_set_node *current_node = set->front;//sets name_set_node type node to the front of set


    while (current_node != NULL) {//while node is not null
        if (strcmp(current_node->first_name, first_name) == 0 && strcmp(current_node->last_name, last_name) == 0) {//string comparison - if first and last name at current node is duplicated returns false
            return TRUE; // Name already exists in the set, true
            }
        current_node = current_node->next;//moves pointer to next node
    }
}

void name_set_print(const name_set *set) {//function prints names formatted
    if(set==NULL){return;}//checks for invalid input
    const name_set_node *current_node = set->front;//pointer starts at front of set
    while (current_node != NULL) {//while node is not null
        printf("%s, %s\n", current_node->last_name, current_node->first_name);//prints formatted names
        current_node = current_node->next;//moves pointer to next node
    }
}
