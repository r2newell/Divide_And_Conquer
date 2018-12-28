#include "maximaSet.h"
#include "mergeSort.h"
#include <time.h> 
#include <stdlib.h> 
#include <stdio.h> 




queue *maximaSet(const coordinate *cartesianPlane, int start, int end)
{
	if(start == end)
	{
		queue *temp = (queue *) calloc(1, sizeof(queue));
		enqueue(temp, &cartesianPlane[start]); 
		return temp;  
	}

	int middle = start + (end - start) / 2;
	queue *left = maximaSet(cartesianPlane, start, middle);
	queue *right = maximaSet(cartesianPlane, middle + 1, end);

	coordinate smallestMaxima = right->front->point; //smallest maxima point greater than the middle
	coordinate potentialMaxima;  
	while(!(isEmpty(left) || isEmpty(right)))
	{
		dequeue(left, &potentialMaxima); 
		if(!(potentialMaxima.x <= smallestMaxima.x && potentialMaxima.y <= smallestMaxima.y))
			   enqueue(right, &potentialMaxima); 
	}	   
	return right; //returns the union of maxima points in cartesian plane  
}

void generate(coordinate *cartesianPlane, int start, int end)// generates random points for testing 
{
		srand(time(NULL));
		for(int index = start ; index < end; index++)
			{
				   cartesianPlane[index].x = (rand() % (end + index)) - rand() % end; 
				   cartesianPlane[index].y = (rand() % (end+ index)) - rand() % end; 
			}
}

void displayPoints(const coordinate *cartesianPlane, int start, int end)//displays generated points
{
	for(int index = start; index < end; index++)
		   printf(" (%d, %d)",cartesianPlane[index].x, cartesianPlane[index].y);
	printf("\n");
}
