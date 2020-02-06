#include "push_swap.h"

void	swap(int *arr, int a, int b)
{
	int	t;

	t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;	
}