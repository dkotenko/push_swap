#include "push_swap.h"

int median_of_three(int a, int b, int c)
{
    if ((a > b) != (a > c)) 
        return a;
    else if ((b > a) != (b > c)) 
        return b;
    else
        return c;
}

void	ft_qsort(int *arr, int start, int end)
{  
  int	pivot;
  int	i;
  int	j;

  i = start;
  j = end;  
  
  pivot = median_of_three(arr[start], arr[end], arr[(start + end) / 2]);  
  while (i <= j)
  {
    while (arr[i] < pivot)
    	i++;
    while (arr[j] > pivot)
    	j--;
    if (i <= j)
	{        
		swap(&arr[i], &arr[j]);        
		i++;
		j++;
	}    
  }
  if (start < j)
    ft_qsort(arr, start, j);
  if (end > i)
    ft_qsort(arr, i, end);
}