#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# define EMPTY -1


typedef struct	g_element
{
	int			value;
	int			ind_pos;
	int			ind_val;
	int			ind_base;
}				t_element;

typedef struct	g_stack {
	t_element	*arr;
	int			size;
	int			first_ind;
	int			last_ind;	
}				t_stack;

typedef	struct g_push_swap
{
	t_stack		*a;
	t_stack		*b;
	int			counter;
}				t_push_swap;

void	swap(int *arr, int a, int b); 
#endif