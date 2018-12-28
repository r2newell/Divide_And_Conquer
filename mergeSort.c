#include "mergeSort.h" 
#include <stdlib.h>
#include <stdio.h>

void merge(coordinate *cartesianPlane, int start, int middle, int end)
{
	queue buffer1; 
	queue buffer2;
	int index; 
	buffer1.front = buffer1.tail = NULL; 
	buffer2.front = buffer2.tail = NULL; 

	for(index = start; index <= middle; index++)
		enqueue(&buffer1, &cartesianPlane[index]); 
	
	for(index = middle + 1; index <= end; index++)
		enqueue(&buffer2, &cartesianPlane[index]);
	
	index = start;

	while(!(isEmpty(&buffer1) || isEmpty(&buffer2)))
	{
		if(buffer1.front->point.x < buffer2.front->point.x)
			dequeue(&buffer1, &cartesianPlane[index]); 			   
		else 
			 if(buffer1.front->point.x == buffer2.front->point.x)
			 { 
				   if(buffer1.front->point.y <= buffer2.front->point.y)	  
					    dequeue(&buffer1, &cartesianPlane[index]); 
				   else 
					    dequeue(&buffer2, &cartesianPlane[index]);
			 }
			 else 
			       dequeue(&buffer2, &cartesianPlane[index]);
		index++; 
	}	   
	
	while(!isEmpty(&buffer1))
	{
		dequeue(&buffer1, &cartesianPlane[index]); 
		index++; 
	}

	while(!isEmpty(&buffer2))
	{
		   dequeue(&buffer2, &cartesianPlane[index]);
		   index++;
	}
}

void mergeSort(coordinate *cartesianPlane, int start, int end)
{
	if(start < end)
	{
		int middle = start + (end - start)/ 2; 
		mergeSort(cartesianPlane, start, middle); 
		mergeSort(cartesianPlane, middle + 1, end); 
		merge(cartesianPlane, start, middle, end);	
	}
}
