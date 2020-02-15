/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_shift_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:20:25 by clala             #+#    #+#             */
/*   Updated: 2020/02/15 22:33:20 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			t_stack_shift_up(t_stack *stack)
{
	if (!stack->size)
		return (0);
	stack->tail = stack->head;
	stack->head = stack->head->next;
	return (1);
}

/*
** Shift up a
*/

int			ra(t_push_swap *ps)
{
	char	*s;

	s = ft_strdup("ra");
	t_dlist_append(ps->instr, t_dlist_node_new(s));
	ps->counter++;
	t_stack_shift_up(ps->a);
	return (1);
}

/*
** Shift up b
*/

int			rb(t_push_swap *ps)
{
	char	*s;

	s = ft_strdup("rb");
	t_dlist_append(ps->instr, t_dlist_node_new(s));
	ps->counter++;
	t_stack_shift_up(ps->b);
	return (1);
}

/*
** Shift up both stacks
*/

int			rr(t_push_swap *ps)
{
	ra(ps);
	rb(ps);
	return (1);
}
