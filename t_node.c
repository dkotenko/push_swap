#include "push_swap.h"

int 	t_node_get_curr_index(t_stack *stack, t_node *node)
{
	int		i;
	t_node	*temp;

	i = -1;
	temp = stack->head;
	while (++i < stack->size)
	{
		if (temp->index == node->index)
			return (i);
	}
	return (-1);
}

int 	t_node_get_next_index(t_stack *stack, t_node *node)
{
	int		i;
	int 	next;
	t_node	*temp;

	i = -1;
	temp = stack->head;
	while (++i < stack->size)
	{
		if (temp->val > node->val)
			return (i);
	}
	return (-1);
}

t_node		*t_node_get_by_index(t_stack *stack, int index)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack->head;
	while (i < stack->size)
	{
		if (node->index == index)
			return (node);
		i++;
		node = node->next;
	}
	return (NULL);
}

t_node		*t_node_get_by_sort_index(t_stack *stack, int index)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack->head;
	while (i < stack->size)
	{
		if (node->index == index)
			return (node);
		i++;
		node = node->next;
	}
	return (NULL);
}