/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:20:29 by clala             #+#    #+#             */
/*   Updated: 2020/02/15 22:33:39 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		t_node_swap(t_node *a, t_node *b)
{
	swap(&a->val, &b->val);
	swap(&a->index, &b->index);
	swap(&a->sort_index, &b->sort_index);
}

int			sa(t_push_swap *ps)
{
	char	*s;

	ps->counter++;
	if (ps->a->size > 1)
	{
		t_node_swap(ps->a->head, ps->a->head->next);
		s = ft_strdup("sa");
		t_dlist_append(ps->instr, t_dlist_node_new(s));
		if (ps->debug)
			t_push_swap_print(ps);
		return (1);
	}
	return (0);
}

int			sb(t_push_swap *ps)
{
	char	*s;

	ps->counter++;
	if (ps->b->size > 1)
	{
		s = ft_strdup("sb");
		t_dlist_append(ps->instr, t_dlist_node_new(s));
		t_node_swap(ps->b->head, ps->b->head->next);
		if (ps->debug)
			t_push_swap_print(ps);
		return (1);
	}
	return (0);
}

int			ss(t_push_swap *ps)
{
	if (sa(ps) || sb(ps))
		return (1);
	return (0);
}
