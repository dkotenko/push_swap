#include "dlist.h"

t_dlist_node		*t_dlist_new(void *data)
{
	t_dlist_node	*new;

	new = (t_dlist_node *)malloc(sizeof(t_dlist_node));
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

/*
 * Add new node and set it to go given pointer
 */

t_dlist_node	*t_dlist_insert_after(t_dlist *list, t_dlist_node *node, t_dlist_node *new)
{
	new->prev = node;
	if (!node->next)
		list->tail = new;
	else
	{
		new->next = node->next;
		node->next->prev = new;
	}
	node->next = new;
	return (new);
}

t_dlist_node	*t_dlist_insert_before(t_dlist *list, t_dlist_node *node, t_dlist_node *new)
{
	new->next = node;
	if (!node->prev)	
		list->head = new;
	else
	{
		new->prev = node->prev;
		node->prev->next = new;
	}
	node->prev = new;
	return (new);
}


/*
 * add to the front of list
 */

t_dlist_node	*t_dlist_push(t_dlist *list, t_dlist_node *new)
{
	if (!list->head)
	{
		list->head = new;
		list->tail = new;		
	}
	else
	{
		t_dlist_insert_before(list, list->head, new);
	}
	return (new);	
}

t_dlist_node	*t_dlist_append(t_dlist *list, t_dlist_node *new)
{
	if (!list->tail)
		t_dlist_push(list, new);
	else
		t_dlist_insert_after(list, list->tail, new);
	return (new);
}
