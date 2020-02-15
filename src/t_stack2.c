/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:21:06 by clala             #+#    #+#             */
/*   Updated: 2020/02/15 22:21:06 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node		*t_stack_append(t_stack *list, t_node *new)
{
	if (list->size)
		t_stack_insert_after(list, list->tail, new);
	else
		t_stack_insert_in_empty(list, new);
	list->tail = new;
	return (new);
}

t_node		*t_stack_push(t_stack *list, t_node *new)
{
	if (list->size)
		t_stack_insert_after(list, list->tail, new);
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
		if (!tmp)
			break ;
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
		if (!tmp)
			break ;
		if (min < tmp->val)
		{
			min = tmp->val;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

t_node		*t_stack_pop(t_stack *list, t_node *node)
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
