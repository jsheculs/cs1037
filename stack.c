#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_init(Stack *s) {
    s->top = NULL;//initializing top of stack to null
    s->length=0;//initializing length to zero
}

void push(Stack *s, NODE *np) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));//memory allocation
    if (new_node == NULL) {return;}
    *new_node = *np;//copying np to new_node
    new_node->next = s->top;//setting temp's next node to stack's top
    s->top = new_node;//moving top's pointer to new node
    s->length++;//incrementing length
}

NODE *pop(Stack *s) {
    if (s->top == NULL) {return NULL;}//if stack is empty return null
    NODE *pop = s->top;//pointing pop node to top of stack s
    s -> top = pop -> next;//updating top node
    pop -> next = NULL;//freeing popped node
    s->length--;//decrementing length
    return pop;//returning pointer with pop's data
}

void stack_clean(Stack *s) {
    NODE *temp = s->top;//initializing temp to top of stack
    while (temp != NULL) {
        NODE *next_node = temp->next;
        free(temp);//freeing temporary node
        temp = next_node;
    }
    s->top = NULL;//top points to null
    s->length = 0;//updates length of stack
}