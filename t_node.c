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
		temp = temp->next;
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
		if (node->sort_index == index)
			return (node);
		i++;
		node = node->next;
	}
	return (NULL);
}

t_node *t_node_get_node_next_sort_index(t_stack *stack, int index)
{
	int		i;
	t_node	*node;
	t_node	*next_node;

	next_node = NULL;
	i = -1;
	node = stack->head;
	while (++i < stack->size)
	{
		if (node->sort_index > index)
		{
			next_node = next_node ? next_node : node;
			next_node = next_node->sort_index > node->sort_index ? \
				node : next_node;
		}
		node = node->next;
	}
	return (next_node);
}