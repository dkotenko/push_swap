#include "push_swap.h"

void	handle_command(char *command, t_push_swap *ps)
{
	if (command[0] == 's')
	{
		command[1] == 'a' ? sa(ps) : 0;
		command[1] == 'b' ? sb(ps) : 0;
		command[1] == 's' ? ss(ps) : 0;
	}
	else if (command[0] == 'p')
		command[1] == 'a' ? pa(ps) : pb(ps);
	else if (command[1] == 'r')
	{
		command[2] == 'a' ? rra(ps) : 0;
		command[2] == 'b' ? rrb(ps) : 0;
		command[2] == 'r' ? rrr(ps) : 0;
		!command[2] ? rr(ps) : 0;
	}
	else
	{
		command[1] == 'a' ? ra(ps) : 0;
		command[1] == 'b' ? rb(ps) : 0;
		command[1] == 'r' ? rr(ps) : 0;
	}
}

void	handle_error()
{
	write(2, "Error\n", 6);
	exit(1);
}



int 			is_valid_instruction(char *s)
{
	int 		len;

	len = ft_strlen(s);
	if (s && s[0] && ft_strchr("spr", s[0]))
	{
		if (len == 2 && ((s[1] == 'a' || s[1] == 'b') ||
				(!ft_strcmp(s, "rr") || !ft_strcmp(s, "ss"))))
			return (1);
		if (len == 3 && s[0] == 'r' && s[1] == 'r' &&
				ft_strchr("abr", s[2]))
			return (1);
	}
	return (0);
}

void			handle_instructions(t_dlist *list)
{
	char		*s;

	while (get_next_line(0, &s))
	{
		if (!is_valid_instruction(s))
			handle_error();
		t_dlist_append(list, t_dlist_node_new(&s));
	}
}

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

	while (--ac > 0)
	{
		if (ft_strchr(av[ac], ' '))
		{
			splitted = ft_strsplit(av[ac], ' ');
			handle_splitted(ps, splitted);
		}
		else if (is_valid_parameter(av[ac], ps))
		{
			param = ft_atoi(av[ac]);
			t_stack_append(ps->a, t_node_new(param));
		}
		ac--;
	}
}

void				execute_commands(t_push_swap *ps, t_dlist *list)
{
	t_dlist_node	*node;

	node = list->head;
	while (node)
	{
		handle_command((char *)node->data, ps);
		node = node->next;
	}
}

int		main(int ac, char **av)
{
	t_dlist		*list;
	t_push_swap	*ps;

	if (ac > 1)
	{
		ps = t_push_swap_new();
		handle_parameters(ac, av, ps);
		list = t_dlist_new();
		handle_instructions(list);
		execute_commands(ps, list);
		t_stack_is_sorted_ascending(ps->a) && !ps->b->size ?
			write(2, "OK\n", 3) : write(2, "KO\n", 3);
		exit(1);
	}
	return (0);
}