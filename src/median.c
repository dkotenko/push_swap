/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:20:41 by clala             #+#    #+#             */
/*   Updated: 2020/02/15 22:36:34 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_arr(int *arr, int size)
{
	int		i;

	i = 0;
	ft_putstr("int arr: ");
	while (i < size)
	{
		ft_putnbr(arr[i++]);
		ft_putchar('-');
	}
	ft_putchar('\n');
}

int			get_median(t_stack *stack)
{
	int		*arr;
	int		i;
	t_node	*tmp;
	int		median;

	i = 0;
	tmp = stack->head;
	arr = (int *)malloc(sizeof(int) * stack->size);
	while (i < stack->size)
	{
		arr[i++] = tmp->val;
		tmp = tmp->next;
	}
	bubble_sort(arr, stack->size);
	median = arr[stack->size / 2];
	free(arr);
	return (median);
}

void		move_to_b(t_push_swap *ps, t_node *node)
{
	int		ind;

	ind = t_node_get_curr_index(ps->a, node);
	while (ps->a->head->index != node->index)
		ind * 2 >= ps->a->size + 1 ? rra(ps) : ra(ps);
	pb(ps);
}

void		handle_case_of_three(t_push_swap *ps)
{
	int		first;
	int		second;
	int		third;

	if (t_stack_is_sorted_ascending(ps->a))
		return ;
	first = ps->a->head->val;
	second = ps->a->head->next->val;
	third = ps->a->tail->val;
	if (first > second && first > third && ra(ps))
		second > third ? sa(ps) : 0;
	else if (first > second)
		sa(ps);
	else if (first > third)
		rra(ps);
	else
	{
		sa(ps);
		ra(ps);
	}
}

void		split_stack(t_push_swap *ps, t_stack *a)
{
	int		median;
	int		i;
	t_node	*tmp;
	t_node	*tmp_next;

	if (a->size == 3)
		return (handle_case_of_three(ps));
	median = get_median(a);
	while (a->head->val < median)
		pb(ps);
	tmp = a->head;
	tmp_next = tmp->next;
	i = 0;
	while (++i < a->size + 1 && a->size > 2)
	{
		tmp->val <= median ? move_to_b(ps, tmp) : 0;
		if (a->size == 3)
			return (handle_case_of_three(ps));
		tmp = tmp_next;
		tmp_next = tmp->next;
	}
}
