#ifndef QUEUE_H_
#define QUEUE_H_ 
#include "coordinate.h"
#include <stdbool.h> 

typedef struct node
{
	coordinate point; 
	struct node *next; 
}node;

typedef struct queue
{
	node *front; 
	node *tail; 
}queue;

bool isFull(void); 
bool isEmpty(const queue *); 
void enqueue(queue *, const coordinate *); 
void dequeue(queue*, coordinate*); 
void deleteQueue(queue*);
void display(const queue*); 
#endif
