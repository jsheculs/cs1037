#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

Node* new_node(char data) {
    Node *new_node = (Node *)malloc(sizeof(Node));//allocated memory to node called new_node
    if(new_node == NULL) {//returns if memory allocation fails
        return NULL;
    }
    new_node->data = data;//sets the data for the new node
    new_node->next = NULL;//next pointer is null
    new_node->prev = NULL;//previous pointer is null
    return new_node;//returns the created node

}

void dll_insert_start(Node **head, char data) {
    Node *new_node_ptr = new_node(data);//creating new node to store data
    if(new_node_ptr == NULL) {return;}//return if memory allocation is unsuccessful


    if(*head == NULL) {//if list is empty
        *head = new_node_ptr;//new node is set as the head
        (*head)->prev = NULL;//previous pointer is null
        (*head)->next = NULL;//next pointer is null

    } else {//if list is not empty
        new_node_ptr -> next = *head;//new nodes next is head of list
        (*head)->prev = new_node_ptr;//head's previous points to new node
        *head = new_node_ptr;//updates head pointer to point to new node
    }
}

void dll_insert_end(Node **head, char data) {
    Node *new_node_ptr = new_node(data);//creating a node
    if(new_node_ptr == NULL) {return;}//returns if memory allocation fails


    if(*head == NULL) {//if list is empty
        *head = new_node_ptr;//sets new node as head
        (*head)->prev = NULL;//previous pointer is null
        (*head)->next = NULL;//next pointer is null

    } else {//if list is not empty
        Node *temp = *head;//temporary pointer to head
        while(temp->next != NULL) {//traverses to end of list
            temp = temp->next;
        }
        temp->next = new_node_ptr;//last's next node is new node
        new_node_ptr -> prev = temp;//new nodes previous is last node
    }

}

void dll_delete_start(Node **head) {
    if (*head == NULL) { return; }//Return if the list is empty
    Node *temp = *head;//Temporary pointer to head

    if ((*head)->next == NULL) {//If there is only one node
        *head = NULL;//Set head to NULL
    } else {
        *head = (*head)->next;//Moves head to the next node
        (*head)->prev = NULL;//Setting the new head's previous pointer to NULL
    }
    free(temp);//frees old head
}

void dll_delete_end(Node **head) {
    if (*head == NULL) { return; }// Return if the list is empty
    Node *temp = *head;// Temporary pointer

    if ((*head)->next == NULL) {// If there is only one node
        *head = NULL;// Set head to NULL
    } else {
        while (temp->next != NULL) {//traverse to the end of the list
            temp = temp->next;
        }
        temp->prev->next = NULL;//second last node's next to NULL
    }
    free(temp);//frees old tail
}

