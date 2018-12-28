#include "queue.h"
#include <stdio.h> 
#include <stdlib.h> 

bool isEmpty(const queue *buffer)
{
	if(buffer->front)
		  return false; 
	else
		  return true;	   
}

bool isFull(void)
{
	node *coordinatePoint = (node *) malloc(sizeof(coordinate));

     if(coordinatePoint == NULL)
	   return true; 
	 else
	 {
		free(coordinatePoint); 
		return false; 
	 }	   
}

void enqueue(queue *cartesianPlane, const coordinate *location)
{
	if(isFull())
	{
		printf("Queue is full");
		return;
	}

	node *temp = (node *) calloc(1,sizeof(node));
	temp->point = *location; 
	if(isEmpty(cartesianPlane))
		cartesianPlane->front = cartesianPlane->tail = temp; 
	else
	{
		cartesianPlane->tail->next = temp; 
		cartesianPlane->tail = temp; 
	}

}

void dequeue(queue *cartesianPlane, coordinate*temp)
{
	if(isEmpty(cartesianPlane))
		   return;

	*temp = cartesianPlane->front->point; 	   
	
	if(cartesianPlane->front == cartesianPlane->tail)
	{
		free(cartesianPlane->front); 
		cartesianPlane->front = cartesianPlane->tail = NULL; 
	}
	else
	{
		node *tempFront = cartesianPlane->front; 
		cartesianPlane->front = cartesianPlane->front->next; 
		free(tempFront); 
	}
}

void display(const queue *cartesianPlane)
{
	node *tempFront = cartesianPlane->front; 
	while(tempFront)
	{
		printf(" (%d, %d)", tempFront->point.x, tempFront->point.y); 
		tempFront = tempFront->next;
	}
	printf("\n");
}
