#include <stdio.h> 
#include <stdlib.h> 
#include "kadanes.h" 


void findMax(const int*seq, int size)
{
	int left = 0; 
	int right = 0; 
	int currentMax; 
	int max; 

	currentMax = max = seq[0]; 

	for(int index = 1; index < size; index++)
	{
		currentMax += seq[index]; 
		if(currentMax < seq[index])
		{
			left = index; 
			right = index; 
			currentMax = max = seq[index]; 
		}
		else 
			   if(currentMax > max)
			   {
				max = currentMax; 
				right = index; 
			   }
	}
	printf("\nThe max subarray found is seq[%d...%d] and the sum is  %d", left, right, max); 
	printf("\nThe max subarray:");
	display(seq, left, right); 

}

void display(const int*seq, int start, int end)
{
	for(int index = start; index <= end; index++)
		printf(" %d",seq[index]);
	printf("\n");	

}
