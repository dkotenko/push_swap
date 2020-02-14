#include "../includes/push_swap.h"

int 	t_node_get_curr_index(t_stack *stack, t_node *node)
{
	int		i;
	t_node	*temp;

	if (!node)
		return (-1);	
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
			if (!next_node || node->sort_index < next_node->sort_index)
				next_node = node;
		}
		node = node->next;
	}
	next_node = next_node ? next_node : node;
	return (next_node);
}

t_eval		*t_eval_new(void)
{
	t_eval	*eval;

	eval = (t_eval *)malloc(sizeof(t_eval));
	eval->moves = 0;
	eval->ord_by_ind = false;
	eval->ord_by_val = false;
	return (eval);
}

t_node		*t_node_new(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = data;
	new->prev = NULL;
	new->next = NULL;
	new->index = -1;
	new->sort_index = -1;
	new->eval = t_eval_new();	
	return (new);
}

void		t_node_free(t_node *node)
{
	free(node->eval);
	free(node);
}