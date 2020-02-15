/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:20:17 by clala             #+#    #+#             */
/*   Updated: 2020/02/15 22:20:17 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			pa(t_push_swap *ps)
{
	char	*s;

	s = ft_strdup("pa");
	t_dlist_append(ps->instr, t_dlist_node_new(s));
	t_stack_push(ps->a, t_stack_pop(ps->b, ps->b->head));
	ps->counter++;
	return (1);
}

int			pb(t_push_swap *ps)
{
	char	*s;

	s = ft_strdup("pb");
	t_dlist_append(ps->instr, t_dlist_node_new(s));
	t_stack_push(ps->b, t_stack_pop(ps->a, ps->a->head));
	ps->counter++;
	return (1);
}
