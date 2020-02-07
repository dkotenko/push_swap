#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "dlist.h"

# define EMPTY -1

typedef struct	g_stack {
	t_element	*arr;
	int			size;
	int			first_ind;
	int			last_ind;	
}				t_stack;

typedef	struct g_push_swap
{
	t_dlist		*a;
	t_dlist		*b;
	int			counter;
}				t_push_swap;

void	swap(int *arr, int a, int b); 
#endif