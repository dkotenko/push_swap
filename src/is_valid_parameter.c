/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_parameter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:20:37 by clala             #+#    #+#             */
/*   Updated: 2020/02/20 20:57:22 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_duplicate(t_push_swap *ps, int param)
{
	int		i;
	t_node	*node;

	i = -1;
	if (!ps->a->size)
		return (0);
	node = ps->a->head;
	while (++i < ps->a->size)
	{
		if (node->val == param)
			return (1);
		node = node->next;
	}
	return (0);
}

static int	is_integer(char *s, int n)
{
	size_t	len;

	len = ft_strlen(s);
	if ((s[0] != '-' && !ft_isdigit(s[0])) || (int)len != ft_ilen(n))
		return (0);
	return (1);
}

int			is_valid_parameter(t_push_swap *ps, char *s)
{
	int		param;

	param = ft_atoi(s);
	if (!is_integer(s, param))
		handle_error(ps);
	if (is_duplicate(ps, param))
		handle_error(ps);
	return (1);
}
