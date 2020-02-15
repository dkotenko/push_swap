/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_shift_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:20:21 by clala             #+#    #+#             */
/*   Updated: 2020/02/15 23:24:09 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			t_stack_shift_down(t_stack *stack)
{
	if (!stack->size)
		return (0);
	stack->head = stack->tail;
	stack->tail = stack->tail->prev;
	return (1);
}

/*
** Shift down a
*/

int			rra(t_push_swap *ps)
{
	char	*s;

	s = ft_strdup("rra");
	t_dlist_append(ps->instr, t_dlist_node_new(s));
	ps->counter++;
	t_stack_shift_down(ps->a);
	return (1);
}

/*
** Shift down b
*/

int			rrb(t_push_swap *ps)
{
	char	*s;

	s = ft_strdup("rrb");
	t_dlist_append(ps->instr, t_dlist_node_new(s));
	ps->counter++;
	t_stack_shift_down(ps->b);
	return (1);
}

/*
** Shift down both stacks
*/

int			rrr(t_push_swap *ps)
{
	rra(ps);
	rrb(ps);
	return (1);
}
