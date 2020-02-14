#include "../includes/push_swap.h"

void    bubble_sort(int *arr, int size)
{
    int i;
    int j;    

    i = -1;    
    while (++i < size)
    {        
        j = i;
        while (++j < size)
        {
            if (arr[j] < arr[i])
            {
                swap(&arr[i], &arr[j]);                
            }            
        }		
    }		
}

void		t_stack_bubble_sort(t_stack *stack)
{
	t_node	*node;
	t_node	*next_node;
	int 	i;
	int 	j;

	node = stack->head;
	i = -1;
	while (++i < stack->size)
	{
		j = i;
		next_node = node->next;
		while (++j < stack->size)
		{
			if (next_node->val < node->val)
			{
				swap(&next_node->val, &node->val);
				swap(&next_node->index, &node->index);
			}
			next_node = next_node->next;
		}
		node = node->next;
	}
}