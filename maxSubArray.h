#ifndef MAX_SUBARRAY_H_
#define MAX_SUBARRAY_H_ 

typedef struct max
{
	   int left; 
	   int right; 
	   int sum; 
}max;

void findMaxSubArray(const int *, int, int, int, max *); 
void maxSubArray(const int*, int, int, max *);
void display(const int*, int, int);




#endif 
