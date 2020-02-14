#include "../includes/push_swap.h"

void		t_stack_swap(t_stack *list)
{
	swap(&list->head->val, &list->head->next->val);
}

void		t_stack_print(t_stack *list)
{
	int		i;
	t_node	*tmp;

	if (!list->size)
		return ;
	i = -1;
	tmp = list->head;
	while (++i < list->size)
	{
		printf("%d, ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}

void		t_stack_free(t_stack *stack)
{
	int		i;
	t_node	*node;
	t_node	*node_next;

	i = 0;
	node = stack->head;
	node_next = node->next;
	while (i < stack->size)
	{
		free(node);
		if (i < stack->size - 1)
		{
			node = node_next;
			node_next = node->next;			
		}
		i++;
	}
}

t_stack		*t_stack_copy(t_stack *stack)
{
	t_stack	*new;
	int 	i;
	t_node 	*node;

	i = 0;
	new = t_stack_new();
	node = stack->head;
	while (i < stack->size)
	{
		t_stack_append(new, t_node_new(node->val));
		new->tail->index = node->index;
		node = node->next;
		i++;
	}
	return (new);
}

int		t_stack_is_sorted_ascending(t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack->head;	
	while (i < stack->size - 1)
	{
		if (!tmp->next)
			break ;
		if (tmp->val > tmp->next->val)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}
