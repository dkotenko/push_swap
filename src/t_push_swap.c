/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:20:59 by clala             #+#    #+#             */
/*   Updated: 2020/02/15 22:44:42 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_push_swap		*t_push_swap_new(void)
{
	t_push_swap	*ps;

	ps = (t_push_swap *)malloc(sizeof(t_push_swap));
	ps->a = t_stack_new();
	ps->b = t_stack_new();
	ps->counter = 0;
	ps->max = 0;
	ps->min = 0;
	ps->size = 0;
	ps->instr = t_dlist_new();
	return (ps);
}

void			t_push_swap_print(t_push_swap *ps)
{
	write(1, "STACK A: ", 8);
	t_stack_print(ps->a);
	write(1, "STACK B: ", 8);
	t_stack_print(ps->b);
	write(1, "\n", 1);
	printf("MOVES NUMBER: %d\n", ps->counter);
}

void			t_push_swap_free(t_push_swap *ps)
{
	t_stack_free(ps->a);
	t_stack_free(ps->b);
	free(ps);
}
