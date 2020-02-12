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

t_node	*t_node_get_max_ind_val_number(t_stack *a)
{
	int	i;

}

int			is_head_after_tail(t_stack *a, t_node *node)
{
	if (node == a->min && node->prev == a->max)
		return (1);
	if (node->sort_index = 0 && node->prev->sort_index == a->size - 1)
		return (1);
	return (0);
}

int			t_stack_index_eval(t_stack *stack)
{
	int 	i;
	int		eval;
	t_node	*node;

	node = stack->head;
	i = -1;
	eval = 0;
	while (++i < stack->size)
	{
		if (node->prev->index == node->index + 1)
			eval++;
		node = node->next;
	}
}

int			t_stack_order_eval(t_stack *stack)
{
	int	 	i;
	t_node *node;

	node = stack->head;
	i = -1;
	while (++i < stack->size)
	{
		if (node->prev->val <= node->val)
			node->eval->ord_by_val = true;
		node = node->next;
	}
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
	t_stack_get_eval(ps->a);
	return (ps);
}

