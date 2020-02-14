#include "../includes/push_swap.h"

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

t_node		*t_stack_insert_in_empty(t_stack *list, t_node *new)
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

t_node		*t_stack_insert_after(t_stack *list, t_node *node, t_node *new)
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
