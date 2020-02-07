#include "dlist.h"

t_dlist		*t_dlist_new(void *data)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	new->size = 0;
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

t_dlist_node	*t_dlist_pop(t_dlist *list, t_dlist_node *node)
{
	if (!node->prev)	
		list->head = node->next;
	else
		node->prev->next = node->next;
	if (!node->next)
		list->tail = node->prev;
	else
		node->next->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_dlist		*t_dlist_remove_node(t_dlist *list, t_dlist_node *node)
{
	t_dlist_pop(list, node);
	free(node);
	return (list);	
}

