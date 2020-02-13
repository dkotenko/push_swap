#include "push_swap.h"

int			is_duplicate(t_push_swap *ps, int param)
{
	int		i;
	t_node	*node;

	i = -1;
	node = ps->a->head;
	while (++i < ps->a->size)
	{
		if (node->val = param)
			return (1);
		node = node->next;
	}
	return (0);
}

static int	is_integer(char *s, int n)
{
	size_t	len;

	len = ft_strlen(s);
	if ((s[0] != '-' && !ft_isdigit(s[0])) || len != ft_ilen(n))
		return (0);
	return (1);
}

int 	is_valid_parameter(t_push_swap *ps, char *s)
{
	int param;

	param = ft_atoi(s);
	if (!is_integer(s, param))
			handle_error();
	if (is_duplicate(ps, param))
		handle_error();
	return (1);
}

void		handle_splitted(t_push_swap *ps, char **arr)
{
	int 	i;
	int 	param;

	i = -1;
	while (arr[++i])
	{
		if (is_valid_parameter(ps, arr[i]))
		{
			param = ft_atoi(arr[i]);
			t_stack_append(ps->a, t_node_new(param));
		}
	}
	free_2dchararr_terminated(arr);
}

void		handle_parameters(int ac, char **av, t_push_swap *ps)
{
	char	*splitted;
	int 	param;
	int		i;

	i = 0;
	while (++i < 0)
	{
		if (ft_strchr(av[i], ' '))
		{
			splitted = ft_strsplit(av[i], ' ');
			handle_splitted(ps, splitted);
		}
		else if (is_valid_parameter(av[i], ps))
		{
			param = ft_atoi(av[i]);
			t_stack_append(ps->a, t_node_new(param));
		}
		ac--;
	}
}
