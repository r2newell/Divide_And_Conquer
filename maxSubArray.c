#include "maxSubArray.h" 
#include <stdio.h> 
#include <stdlib.h> 



void findMaxSubArray(const int *seq, int start, int middle, int end, max *subArray)
{
	int leftSum = 0; 
	int rightSum = 0; 
	int left = 0 ; 
	int right = 0; 

	for(int index = middle, sum = 0; index >= start; index--)
	{
		sum += seq[index]; 
		if(sum > leftSum)
		{
			leftSum = sum; 
			left = index; 
		}
	}

	for(int index = middle + 1, sum = 0; index < end; index++)
	{
		sum += seq[index]; 
		if(sum > rightSum)
		{
			   rightSum = sum; 
			   right = index; 
		}
	}

	subArray->left = left; 
	subArray->right = right; 
	subArray->sum= leftSum + rightSum; 
}

void maxSubArray(const int*seq, int start, int end, max *sub)
{
	if(start != end)
	{
		max left = {0, 0, 0}; 
		max right = {0, 0, 0};
	     max cross = {0, 0, 0}; 	
		int middle = (start + end - 1) / 2;
		maxSubArray(seq, start, middle, &left); 
		maxSubArray(seq, middle + 1, end, &right);
		findMaxSubArray(seq, start, middle, end, &cross); 

		if(left.sum >= right.sum && left.sum >= cross.sum)
			   *sub = left; 
		else
			   if(right.sum >= left.sum && right.sum >= cross.sum)
					 *sub = right;
			   else 
					 *sub = cross; 
	} 
}

void display(const int *seq, int start, int end)
{
	for(int index = start; index <= end; index++)
		   printf(" %d", seq[index]); 
	printf("\n");

}
