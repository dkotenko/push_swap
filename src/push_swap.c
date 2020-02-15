#include "../includes/push_swap.h"

t_node				*count_moves(t_stack *a, t_stack *b, t_node *node)
{
	int				ind;
	int				next_ind;
	t_node			*next_node;
	int				node_moves;
	int				next_node_moves;

	ind = t_node_get_curr_index(b, node);
	next_node = t_node_get_node_next_sort_index(a, node->sort_index);
	next_ind = t_node_get_curr_index(a, next_node);
	node_moves = ind * 2 >= b->size + 1 ? b->size - ind : ind;
	next_node_moves = next_ind * 2 >= a->size + 1 ? a->size - next_ind : next_ind;
	node->moves = node_moves + next_node_moves + 1;
	return (node);
}

t_node				*t_node_get_min_moves(t_push_swap *ps)
{	
	t_node	*temp = ps->b->head->next;
	t_node	*node_min = ps->b->head;
	int		i;
		
	count_moves(ps->a, ps->b, node_min);
	i = 0;
	while (++i < ps->b->size)
	{
		count_moves(ps->a, ps->b, temp);
		if (temp->moves < node_min->moves)
			node_min = temp;
		temp = temp->next;
	}
	return (node_min);
}

void				move_stack_b_to_stack_a(t_push_swap *ps)
{
	int				ind;
	int				next_ind;
	t_node			*node;
	t_node			*next_node;

	node = t_node_get_min_moves(ps);
	ind = t_node_get_curr_index(ps->b, node);
	next_node = t_node_get_node_next_sort_index(ps->a, node->sort_index);
	next_ind = t_node_get_curr_index(ps->a, next_node);
	while (ps->b->head->sort_index != node->sort_index)
	{
		ind * 2 >= ps->b->size ? rrb(ps) : rb(ps);
	}
	while (ps->a->head->sort_index != next_node->sort_index)
	{
		next_ind * 2 >= ps->a->size ? rra(ps) : ra(ps);
	}
	pa(ps);
}

void				print_insructions_list(t_dlist *list)
{
	t_dlist_node	*node;

	node = list->head;
	while (node)
	{
		ft_putstr((const char *)(node->data));
		ft_putchar('\n');
		node = node->next;
	}
}


int					main(int ac, char **av)
{
	t_push_swap		*ps;
	int				ind;
    
	if (ac > 1)
	{
		ps = t_push_swap_new();		
		handle_parameters(ac, av, ps);
		if (t_stack_is_sorted_ascending(ps->a))
			exit(0);
		while (!t_stack_is_sorted_ascending(ps->a) && ps->a->size > 2)
		{
			split_stack(ps, ps->a);
		}
		while (ps->b->size)
		{
			move_stack_b_to_stack_a(ps);
		}
		ind = t_node_get_curr_index(ps->a, t_node_get_by_sort_index(ps->a, 0));
		while (ps->a->head->sort_index)
			ind * 2 >= ps->a->size ? rra(ps) : ra(ps);
		print_insructions_list(ps->instr);
		exit(0);
	}
	return (0);
}
