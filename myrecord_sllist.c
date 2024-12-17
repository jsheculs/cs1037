//
// Created by jshec on 2024-10-29.
//
#include "myrecord_sllist.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sll_insert(SLL *sllp, char *name, float score) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (new_node == NULL) {return;}

    strncpy(new_node -> data.name, name, sizeof(new_node->data.name)-1);
    new_node->data.name[sizeof(new_node->data.name) - 1] = '\0';
    new_node -> data.score = score;
    new_node ->next = NULL;

    if (sllp -> start == NULL || strcmp(new_node -> data.name, sllp -> start -> data.name) < 0){
        new_node -> next = sllp -> start;
        sllp -> start = new_node;

    }else {
        NODE *current = sllp -> start;
        while (current -> next != NULL && strcmp(new_node -> data.name, current -> next -> data.name) >0) {
            current = current -> next;
        }
        new_node -> next = current -> next;
        current -> next = new_node;
    }
    sllp->length++;
}

NODE *sll_search(SLL *sllp, char *name) {
    NODE *current = sllp -> start;
    if(current == NULL){return NULL;}
    while(current!= NULL) {
        if (strcmp(current -> data.name, name) == 0) {
            return current;
        }
        current = current -> next;//moves current to next node
    }
    return NULL;
}

int sll_delete(SLL *sllp, char *name) {
    NODE *current = sllp -> start;//current node is set to start of singly linked list
    NODE *previous = NULL;//previous is null

    if(current == NULL){return 0;}//return 0 if current node is a null pointer
    while(current!= NULL) {//while current node is not null
        if (strcmp(current -> data.name, name) == 0) {//if name is found in data -> name area of current
            if (previous == NULL) {//if current is at the start
                sllp -> start = current -> next;//start node is current's next node (delete initial start node)
            }
            else{//if current is not at the start
                previous -> next = current -> next;//links node after previous to node after current
            }
            free(current);//frees current node
            sllp->length--;//decrements length

            return 1;//return 1 if current is deleted
        }
        previous = current;//sets previous node to current node
        current = current -> next;//sets current to next node

    }
    return 0;//returns 0 is node with matching name is not found
}


void import_data(const char *filename, SLL *sllp) {
    sll_clean(sllp);//clearing sllp
    FILE *file = fopen(filename, "r");//opening file in read mode
    if (file == NULL) {return;}


    char name[40];
    float score;

    while(fscanf(file, "%5[^,], %f", name, &score)==2) {//if fscanf is successfully able to read 2 items (name and score)
        sll_insert(sllp, name, score);//inserts name and score into sllp
    }
    fclose(file);//closing file
}

void process_data(SLL *sllp) {
    if (sllp == NULL || sllp -> start == NULL){return;}
    int count = sllp -> length;
    if (count == 0) {return;}

    float sum = 0, sum_squared = 0;
    float *scores = (float *)malloc(count * sizeof(float));

    if (scores == NULL) {return;}

    NODE *current = sllp -> start;
    int i = 0;
    if(current == NULL){return;}
    while (current != NULL) {
        scores[i] = current -> data.score;
        sum += scores[i];
        sum_squared += scores[i] * scores[i];
        current = current -> next;
        i++;
    }
    float average = sum / count;
    float stdev = sqrt(sum_squared / count - (average*average));

    for(i=0; i < count - 1; i++) {
        for(int j = i + 1; j < count; j++) {
            if(scores[i] > scores[j]) {
                float temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }
    float median;
    if(count % 2 == 0) {//checking for even number of nodes
        median = (scores[count / 2 - 1] + scores[count / 2]) / 2;
    }
    else {
        median = scores[count / 2];
    }
    current = sllp -> start;
    for(i=0; i < count; i++) {
        current -> data.score = scores[i];
        current = current -> next;
    }

    free(scores);//free dynamic memory allocation
    printf("count %.2f\nmean %.2f\nstddev %.2f\nmedian %.2f\n", (double)count, average, stdev, median);
}

void sll_clean(SLL *sllp) {
    if (sllp == NULL) {return;}//no nodes to delete
    NODE *current = sllp -> start;//pointer to first node
    NODE *next=NULL;
    while (current != NULL) {
        next = current -> next;
        free(current);//frees current node
        current = next;//moves next to current
    }
    sllp -> length = 0;//length is now 0
    sllp -> start = NULL;//pointer to start is now null
}
