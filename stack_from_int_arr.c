#include "push_swap.h"

void		t_stack_get_sort_index(t_stack *stack)
{
	int 	i;
	t_node	*node;
	t_stack *sorted;
	t_node	*origin;

	sorted = t_stack_copy(stack);
	t_stack_bubble_sort(sorted);
	i = 0;
	node = sorted->head;
	while (i < stack->size)
	{
		origin = t_node_get_by_index(stack, node->index);
		origin->index;
		origin->sort_index = i++;
		node = node->next;
	}
	t_stack_free(sorted);
}

t_push_swap	*t_push_swap_get_stack_from_arr(int *arr, int size)
{
	int		i;
	t_push_swap *ps;

	ps = t_push_swap_new();
	i = 0;
	while (i < size)
	{
		t_stack_append(ps->a, t_node_new(arr[i]));
		ps->a->tail->index = ps->a->size - 1;
		i++;
	}
	t_stack_get_sort_index(ps->a);
	return (ps);
}

