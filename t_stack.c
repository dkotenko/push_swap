#include "push_swap.h"

t_stack		*t_stack_new(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->head = NULL;
	new->tail = NULL;
	new->max = NULL;
	new->min = NULL;
	new->size = 0;
	return (new);
}

t_node	*t_stack_insert_in_empty(t_stack *list, t_node *new)
{	
	list->head = new;
	list->tail = new;
	list->max = new;
	list->min = new;	
	new->next = new;
	new->prev = new;
	list->size++;
	return (new);
}

t_node	*t_stack_insert_after(t_stack *list, t_node *node, t_node *new)
{
	new->next = node->next;
	new->prev = node;
	node->next->prev = new;
	node->next = new;	
	if (new->val > list->max->val)
		list->max = new;
	else if (new->val < list->min->val)
		list->min = new;
	list->size++;
	return (new);
}

t_node	*t_stack_append(t_stack *list, t_node *new)
{
	if (list->size)
		t_stack_insert_after(list, list->tail, new);
	else
		t_stack_insert_in_empty(list, new);
	list->tail = new;
	return (new);
}

t_node	*t_stack_push(t_stack *list, t_node *new)
{
	if (list->size)
		t_stack_insert_after(list, list->tail->next, new);
	else
		t_stack_insert_in_empty(list, new);
	list->head = new;
	return (new);
}

t_node		*t_stack_max(t_stack *list)
{
	t_node	*tmp;
	int		max;
	t_node	*max_node;

	tmp = list->head->next;
	max = list->head->val;
	max_node = list->head;
	while (tmp != list->head)
	{
		if (max < tmp->val)
		{
			max = tmp->val;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

t_node		*t_stack_min(t_stack *list)
{
	t_node	*tmp;
	int		min;
	t_node	*min_node;

	tmp = list->head->next;
	min = list->head->val;
	min_node = list->head;
	while (tmp != list->head)
	{
		if (min < tmp->val)
		{
			min = tmp->val;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

t_node *t_stack_pop(t_stack *list, t_node *node)
{
	if (node == list->head)
		list->head = node->next;
	else if (node == list->tail)
		list->tail = node->prev;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->prev = NULL;
	node->next = NULL;
	list->size--;
	if (node == list->max)
		list->max = t_stack_max(list);
	if (node == list->min)
		list->min = t_stack_min(list);
	return (node);
}

void	t_stack_swap(t_stack *list)
{
	swap(&list->head->val, &list->head->next->val);
}

t_node	*t_stack_pop_tail(t_stack *list)
{
	t_node *node;	
}

t_node	*t_stack_pop_head(t_stack *list)
{
	t_node *node;
	return (node);
}

t_node		*t_node_new(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	t_stack_print(t_stack *list)
{
	int	i;
	t_node *tmp;

	i = -1;
	tmp = list->head;
	while (++i < list->size)
	{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");	
}



