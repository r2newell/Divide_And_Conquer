#include "utility.h" 
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
void display(const int *seq, int size)
{
	for(int index  = 0; index < size; index++)
		   printf(" %d", seq[index]);
	printf("\n"); 
}

void generate(int *seq, int size)
{
	srand(time(0)); 
	for(int index = 0; index < size; index++)
		seq[index] = index + (rand() % size); 
}
