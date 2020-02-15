/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parameters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:20:33 by clala             #+#    #+#             */
/*   Updated: 2020/02/15 22:35:02 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	handle_splitted(t_push_swap *ps, char **arr)
{
	int		i;
	int		param;

	i = -1;
	while (arr[++i])
	{
		if (is_valid_parameter(ps, arr[i]))
		{
			param = ft_atoi(arr[i]);
			t_stack_append(ps->a, t_node_new(param));
			ps->a->tail->index = ps->a->size - 1;
		}
	}
	free_2dchararr_terminated(arr);
}

void		t_stack_get_sort_index(t_stack *stack)
{
	int		i;
	t_node	*node;
	t_stack *sorted;
	t_node	*origin;

	sorted = t_stack_copy(stack);
	t_stack_bubble_sort(sorted);
	i = 0;
	node = sorted->head;
	while (i < stack->size)
	{
		origin = t_node_get_by_index(stack, node->index);
		origin->sort_index = i++;
		node = node->next;
	}
	t_stack_free(sorted);
}

void		handle_parameters(int ac, char **av, t_push_swap *ps)
{
	char	**splitted;
	int		param;
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			splitted = ft_strsplit(av[i], ' ');
			handle_splitted(ps, splitted);
		}
		else if (is_valid_parameter(ps, av[i]))
		{
			param = ft_atoi(av[i]);
			t_stack_append(ps->a, t_node_new(param));
			ps->a->tail->index = ps->a->size - 1;
		}
	}
	t_stack_get_sort_index(ps->a);
}

void		handle_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
