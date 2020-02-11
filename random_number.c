// C program for generating a 
// random number in a given range. 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
// Generates and prints 'count' random 
// numbers in range [lower, upper]. 
int		*get_random_range(int lower, int upper, int size)
{
	int i;
	int *range;

	srand(time(0));
	range = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		range[i++] = rand() % (upper - lower + 1) + lower;
	}
	return (range);
}

  
// Driver code
/*
int main() 
{ 
    int lower = 5, upper = 7, count = 1; 
  
    // Use current time as  
    // seed for random generator 
    srand(time(0)); 
  
    printRandoms(lower, upper, count); 
  
    return 0; 
} */