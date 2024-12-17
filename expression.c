#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include"queue.h"
#include"stack.h"
#include"expression.h"

int priority(char operator) {
    if (operator == '+' || operator == '-') {
        return 0; // Lowest precedence
    } else if (operator == '*' || operator == '/' || operator == '%') {
        return 1; // Higher precedence
    }
    return -1; // For non-operators
}
QUEUE infix_to_postfix(char *infixstr) {
    QUEUE queue = {0, NULL, NULL};//initiating a new queue
    Stack *stack = malloc(sizeof(Stack));//memory allocation
    stack -> top = NULL;
    stack -> length = 0;

    char *infix = infixstr;//pointer to traverse infix
    while (*infix != '\0') {//loop runs until end of infix
        if (isdigit(*infix)) {//check if character is a digit
            int num = 0;
            while (isdigit(*infix)) {
                num = num * 10 + (*infix - '0');//forms number
                infix++;//moves to next character
            }
            enqueue(&queue, new_node(num, 0));//enqueue node
            continue;

        } else if (*infix == '(') {
            push(stack, *infix);// Push '(' to the stack
        } else if (*infix == ')') {
            while (stack->top && stack->top->data != '(') {// Pop  the stack to the queue until '(' is found

                enqueue(&queue, new_node(pop(stack), 1));  // Pop operators and enqueue them
            }
            pop(stack);  // Pop the '(' from the stack without enqueueing it
        } else if (*infix == '+' || *infix == '-' || *infix == '*' || *infix == '/' || *infix == '%') {

            while (stack->top && priority(stack->top->data) >= priority(*infix)) {// Pop operators with higher or equal precedence and push the current operator
                enqueue(&queue, new_node(pop(stack), 1));  // Pop operator from stack and enqueue
            }
            push(stack, *infix);// push current operator to the stack
        }
        infix++;//increment to move to next
    }


    while (stack -> top) {//popping all remaining operators
        enqueue(&queue, new_node(pop(stack),1));
    }
    free(stack);//freeing stack memory
    return queue;//returning queue
}

int evaluate_postfix(QUEUE queue) {
    Stack *stack = malloc(sizeof(Stack));  // Create a stack to hold operands during evaluation
    stack->top = NULL;
    stack->length = 0;

    while (queue.length > 0) {
        NODE *np = dequeue(&queue);
        if (np->type == 0) {// node is a number, push onto stack
            push(stack, np->data);
        } else {//if operator
            int operand2 = pop(stack);  // Second operand
            int operand1 = pop(stack);  // First operand
            int result;

            switch (np->data) {//switch cases for operator evaluation
                case '+':
                    result = operand1 + operand2;
                break;
                case '-':
                    result = operand1 - operand2;
                break;
                case '*':
                    result = operand1 * operand2;
                break;
                case '/':
                    result = operand1 / operand2;
                break;
                case '%':
                    result = operand1 % operand2;
                break;
                default:
                    result = 0;//invalid
            }

            push(stack, result);  // Push result of the operation onto the stack
        }
        free(np);//free dequeued
    }

    int final_result = pop(stack);  // The final result is the only remaining item on the stack
    free(stack);  // Clean up the stack memory
    return final_result;  // Return the result of the postfix evaluation
}

int evaluate_infix(char *infixstr) {// Convert infix expression to postfix queue
    QUEUE postfix_queue = infix_to_postfix(infixstr);


    return evaluate_postfix(postfix_queue);//return evaluation of expression
}




