#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "common.h"

void queue_init(QUEUE *q){
  q->front = NULL;//pointing front to null since no nodes in the queue
  q->rear = NULL;//pointing rear to node since no nodes in queue
  q->length = 0;//length is 0 (empty)
}

void enqueue(QUEUE *q, NODE *np) {
  NODE *new_node = malloc(sizeof(NODE));//allocating memory for new node
  if(new_node == NULL){return;}//return if memory allocation fails
  *new_node = *np;////copying node np to new node
  new_node->next = NULL;//new node's next to null


  if(q->length == 0) {//if queue is empty
    q->front = new_node;//front and rear point to new node
    q->rear = new_node;
  } else {//not empty
    q->rear->next = new_node;//new node linked to end of queue
    q->rear = new_node;//rear is updated
    q->rear->next = NULL;//node after rear is null
  }
  q->length++;}//incrementing length

NODE *dequeue(QUEUE *q) {
  if(q->length == 0){return NULL;}//if queue is empty return nothing
  NODE *temp = q->front;//temporary node to store front

  q->front = temp->next;//moves front pointer to next node
  if (q->front == NULL) {//if queue is empty after dequeue
    q->rear = NULL;//set rear to null
  }
  q->length--;//decrement length
  temp->next = NULL;
  return temp;//return the dequeued front node
}

void queue_clean(QUEUE *q) {
  if(q->front == NULL){return;}//return if empty
  NODE *temp = q->front;//temportary node to hold front
  while(temp != NULL) {//freeing all nodes in queue
    NODE *next = temp->next;//storing next pointer after temp
    free(temp);//freeing temp
    temp = next;//moving enxt to temp
  }
  q->front = NULL;//front is now null
  q->rear = NULL;//rear is now null
  q->length = 0;//length is now zero
}