#include <stdio.h>
#include "dllist.h"

int dll_length(Node* head) {//function to find length of head
    int length = 0;//initiating length variable
    Node* current = head;//setting current node to start of list
    while (current != NULL) {
        length++;//increments for each traversal
        current = current->next;//moves current to next node
    }
    return length;//returns length integer
}

void test_new_node() {
    printf("\n--------------------\n");
    printf("Test: new_node\n\n");

    //printing new_node data to test new node function
    printf("new_node(A): %c\n", new_node('A')->data);
    printf("new_node(B): %c\n", new_node('B')->data);
    printf("new_node(C): %c\n", new_node('C')->data);
    printf("new_node(D): %c\n", new_node('D')->data);
}

void dll_print(Node* head) {//function to print list output
    if (head == NULL) {
        return;
    }
    Node* node = head;//points node to head of list
    while (node != NULL) {//while the node is not null
        printf("%c ", node->data);//prints data at node
        node = node->next;//moves node pointer to next node
    }
    printf("\n");
}

void dll_print_backward(Node* head) {
    if (head == NULL) {
        return;
    }
    Node *node = head;//points node to head of list
    while (node->next != NULL) {//traverses list until end
        node = node->next;
    }
    while (node != NULL) {//while node is not null
        printf("%c ", node->data);//prints data at node
        node = node->prev;//moves node pointer back a node
    }
    printf("\n");
}

void test_dll_insert_start(Node **head) {//function to test insert at start
    printf("\n--------------------\n");//prints formatting to match desired output
    printf("Test: dll_insert_start\n\n");
    printf("given dll: length %d forward", dll_length(*head));//prints list length
    dll_print(*head);//calling dll_print(head) function to print list

    dll_insert_start(head,'A');//creating new node for character and inserting at start of list
    printf("dll_insert_start(A) : length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//calling dll_print(list) function to print list

    dll_insert_start(head,'B');//creating new node for character and inserting at start of list
    printf("dll_insert_start(B) : length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//calling dll_print(list) function to print list

    dll_insert_start(head,'C');//creating new node for character and inserting at start of list
    printf("dll_insert_start(C) : length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//calling dll_print(list) function to print list

    dll_insert_start(head,'D');//creating new node for character and inserting at start of list
    printf("dll_insert_start(D) : length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//calling dll_print(list) function to print list
}

void test_dll_insert_end(Node **head) {
    printf("\n--------------------\n");
    printf("Test: dll_insert_end\n\n");
    printf("given dll: length %d forward", dll_length(*head));//prints list length
    dll_print(*head);//prints list

    //testing insert at end function, printing list length, then printing list for each character
    dll_insert_end(head,'A');
    printf("dll_insert_end(A) : length %d forward ", dll_length(*head));
    dll_print(*head);

    dll_insert_end(head,'B');
    printf("dll_insert_end(B) : length %d forward ", dll_length(*head));
    dll_print(*head);

    dll_insert_end(head,'C');
    printf("dll_insert_end(C) : length %d forward ", dll_length(*head));
    dll_print(*head);

    dll_insert_end(head,'D');
    printf("dll_insert_end(D) : length %d forward ", dll_length(*head));
    dll_print(*head);

    printf("resulted dll: length %d backwards ", dll_length(*head));
    dll_print_backward(*head);
}

void test_dll_delete_start(Node **head) {
    printf("\n\n--------------------\n");
    printf("Test: dll_delete_start\n\n");

    printf("given dll: length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//prints list

    dll_delete_start(head);//deleting start node
    printf("dll_delete_start(A): length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//prints list

    dll_delete_start(head);//deleting start node
    printf("dll_delete_start(B): length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//prints list

    dll_delete_start(head);//deleting start node
    printf("dll_delete_start(C): length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//prints list

    dll_delete_start(head);//deleting start node
    printf("dll_delete_start(D): length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//prints list
}

void test_dll_delete_end(Node **head) {
    printf("\n--------------------\n");
    printf("Test: dll_delete_end\n\n");

    printf("given dll: length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//prints list

    dll_delete_end(head);//deletes end node
    printf("dll_delete_end(A): length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//prints list

    dll_delete_end(head);//deletes end node
    printf("dll_delete_end(B): length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//prints list

    dll_delete_end(head);//deletes end node
    printf("dll_delete_end(C): length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//prints list

    dll_delete_end(head);//deletes end node
    printf("dll_delete_end(D): length %d forward ", dll_length(*head));//prints list length
    dll_print(*head);//prints list

}

int main() {
    Node* head1 = NULL;//creating list for start tests
    Node* head2 = NULL;//creating list for end tests

    test_new_node();

    test_dll_insert_start(&head1);//calling test_dll_insert_start
    test_dll_insert_end(&head2);//calling test_dll_insert_end

    test_dll_delete_start(&head1);//calling test_dll_delete_start

    head2 = NULL;//clearing list for next test
    //populating list for next test
    dll_insert_end(&head2,'D');
    dll_insert_end(&head2,'C');
    dll_insert_end(&head2,'B');
    dll_insert_end(&head2,'A');
    test_dll_delete_end(&head2);//testing deletion from end

    return 0;
}