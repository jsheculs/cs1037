/*
 * Convert infix expression string to postfix expression reprsented by queue data structure. 
 * @param infixstr - string of infix expression. 
 * @return - postfix expression in queue of QUEUE type. 
*/

#include "queue.h"
#include "stack.h"

QUEUE infix_to_postfix(char *infixstr);

/* 
 * Evaluate and return the value postfix expression passed by queue.
 * @parame queue - postfix expression in queue of QUEUE type.
 ^ @return - value of postfix expression
*/
int evaluate_postfix(QUEUE queue);

/* 
 * Evaluate and return the value of infix expression passed by string infixstr, 
 * using infix_to_postfix() and evaluate_postfix() functions.
 * @param infixstr - string of infix expression.  
 * @return - value of the infix expression.
*/
int evaluate_infix(char *infixstr);


/**
 * Determine and return recedence priority of simple arithmatic operators
 *
 * @param op - operator
 * @return - 0 if op is + or - 
             1 if op is * or / or %
             -1 otherwise
 */
int priority(char operator);