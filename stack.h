#ifndef STACK_H
#define STACK_H
#include "common.h"
/*
 * Define a structure STACK containing the length and pointer of the top node.  
 * int length - maintains the length of stack.
 * NODE *top - pointer to the top node of linked list stack
*/
typedef struct stack {
  int length;  
  NODE *top;
} Stack;

/* 
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack 
 * @param NODE *np - pointer to the node.
*/ 
void push(Stack *s, NODE *np);

/* 
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack
 * @return - the reference of the removed node and set it's next to NULL  
*/ 
NODE *pop(Stack *s);

/*
 * clean the linked list stack
 * @param *sp - pointer to the stack 
 */ 
void stack_clean(Stack *sp);
void stack_init(Stack *sp);
#endif