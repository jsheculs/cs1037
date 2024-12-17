#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_sllist.h"

void print_sll(SLL *sllp) {//function to print formatting of singly linked lsit
    NODE *current = sllp -> start;
    while (current != NULL) {
        printf("%s %.1f ", current -> data.name, current -> data.score);
        current = current -> next;
    }
}

SLL *sll_init() {//function to initialize singly linked list
    SLL *sllp = malloc(sizeof(SLL));
    sllp->length = 0;
    sllp->start = NULL;
    return sllp;
}

void test_sll_insert() {//function to test sll_insert function
    printf("\n------------------\n");
    printf("Test: sll_insert\n");
    SLL sll = {0, NULL};
    printf("given linked list: length %d\n", sll.length);

    sll_insert(&sll, "A9", 90.0);
    printf("sll_insert(A9 90.0): length %d ", sll.length);
    print_sll(&sll);

    sll_insert(&sll, "A8", 80.0);
    printf("\nsll_insert(A8 80.0): length %d ", sll.length);
    print_sll(&sll);

    sll_insert(&sll, "A7", 70.0);
    printf("\nsll_insert(A7 70.0): length %d ", sll.length);
    print_sll(&sll);

    sll_insert(&sll, "A6", 60.0);
    printf("\nsll_insert(A6 60.0): length %d ", sll.length);
    print_sll(&sll);

}

void test_sll_search() {//function to test sll_search function
    printf("\n\n------------------\n");
    printf("Test: sll_search\n");
    SLL sll = {0, NULL};

    sll_insert(&sll, "A0", 100.0);
    for(int i = 1; i < 10; i++) {
        char name[3];
        sprintf(name, "A%d", i);
        sll_insert(&sll, name, (i) * 10.0);
    }

    printf("given linked list: length %d", sll.length);
    print_sll(&sll);
    NODE *search;

    search = sll_search(&sll, "A1");
    if(search) {
        printf("\nsll_search(A1): %s %.1f\n", search -> data.name, search -> data.score);
    } else {
        printf("sll_search(A1): not found\n");
    }

    search = sll_search(&sll, "A3");
    if(search) {
        printf("sll_search(A3): %s %.1f\n", search -> data.name, search -> data.score);
    } else {
        printf("sll_search(A3): not found\n");
    }

    search = sll_search(&sll, "A5");
    if(search) {
        printf("sll_search(A5): %s %.1f\n", search -> data.name, search -> data.score);
    } else {
        printf("sll_search(A5): not found\n");
    }

    search = sll_search(&sll, "A10");
    if(search) {
        printf("sll_search(A10): %s %.1f\n", search -> data.name, search -> data.score);
    } else {
        printf("sll_search(A10): not found\n");
    }
}

void test_sll_delete(){//function to test sll_delete function
    printf("\n------------------\n");
    printf("Test: sll_delete\n");

    // Create a linked list with 10 records
    SLL sll = {0, NULL};
    sll_insert(&sll, "A0", 100.0);

    for (int i = 1; i < 10; i++) {
        char name[3];
        sprintf(name, "A%d", i);
        sll_insert(&sll, name, i * 10.0);
    }

    printf("given linked list: length %d ", sll.length);
    print_sll(&sll);

    // Delete specific records
    sll_delete(&sll, "A2");
    printf("\nsll_delete(A2): length %d ", sll.length);
    print_sll(&sll);

    sll_delete(&sll, "A4");
    printf("\nsll_delete(A4): length %d ", sll.length);
    print_sll(&sll);

    sll_delete(&sll, "A6");
    printf("\nsll_delete(A6): length %d ", sll.length);
    print_sll(&sll);

    sll_delete(&sll, "A8");
    printf("\nsll_delete(A8): length %d ", sll.length);
    print_sll(&sll);
}


void test_import_data(const char *filename) {//function to test import_data function
    printf("\n------------------\n");
    printf("Test: import_data\n");

    SLL *sll = sll_init();
    import_data(filename, sll);

    printf("Import data from file\n");
    printf("length: %d\n", sll->length);
    print_sll(sll);
}

void test_process_data(SLL *sllp) {//function to test process_data function
    printf("\n------------------\n");
    printf("Test: process_data\n");

    process_data(sllp); // Calculate statistics and print them

    printf("Sort records by scores\n");
    NODE *current = sllp->start;
    while (current != NULL) {
        printf("%s,%.1f\n", current->data.name, current->data.score);
        current = current->next;
    }
}

int main() {
        test_sll_insert();
        test_sll_search();
        test_sll_delete();

        // Test with data import from file
       SLL sll = {0, NULL};
        test_import_data("marks.txt");
        test_process_data(&sll);

    return 0;
}