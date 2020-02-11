#include "push_swap.h"


int		t_stack_is_sorted_ascending(t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack->head;
	while (i < stack->size - 1)
	{
		if (!tmp->next)
			break ;		
		if (tmp->val > tmp->next->val)
			return (0);		
		i++;
		tmp = tmp->next;		
	}	
	return (1);
}

t_node *count_moves(t_stack *a, t_stack *b, t_node *node)
{
	int ind;
	int next_ind;
	t_node *next_node;
	int node_moves;
	int next_node_moves;

	ind = t_node_get_curr_index(b, node);
	next_node = t_node_get_node_next_sort_index(a, node->sort_index);
	next_ind = t_node_get_curr_index(a, next_node);
	node_moves = ind * 2 >= b->size + 1 ? b->size - ind : ind;
	next_node_moves = next_ind * 2 >= a->size + 1 ? a->size - next_ind : next_ind;
	node->eval->moves = node_moves + next_node_moves;
	return (node);
}

t_node *t_node_get_min_moves(t_push_swap *ps)
{
	int 	min = 999999999;
	t_node	*temp = ps->b->head->next;
	t_node	*node_min = ps->b->head;
	int		i;
		
	count_moves(ps->a, ps->b, node_min);
	i = 0;
	while (++i < ps->b->size)
	{
		count_moves(ps->a, ps->b, temp);
		if (temp->eval->moves < node_min->eval->moves)
			node_min = temp;
		temp = temp->next;
	}
	return (node_min);
}

void		move_stack_b_to_stack_a(t_push_swap *ps)
{
	int		ind;
	int		next_ind;
	t_node	*node;
	t_node	*next_node;

	node = t_node_get_min_moves(ps);
	ind = t_node_get_curr_index(ps->b, node);
	next_node = t_node_get_node_next_sort_index(ps->a, node->sort_index);
	next_ind = t_node_get_curr_index(ps->a, next_node);
	while (ps->b->head->sort_index != node->sort_index)
	{
		ind * 2 >= ps->b->size ? rrb(ps) : rb(ps);
	}
	while (ps->a->tail->sort_index != next_node->sort_index)
	{
		next_ind * 2 >= ps->b->size ? rra(ps) : ra(ps);
	}
	pa(ps);
}



int		main()
{
	t_push_swap *ps;

	int size = 3;
	//int *a = get_random_range(-100, 5400, size);
	int i;

	int a[] = {-16, 4689, 4437};
	ps = t_push_swap_get_stack_from_arr(a, size);
	t_push_swap_print(ps);
	if (t_stack_is_sorted_ascending(ps->a))
	{
		printf("already ascending\n");
		return (0);
	}
	i = 0;
	while (!t_stack_is_sorted_ascending(ps->a) && ps->a->size != 2)
	{
		split_stack(ps, ps->a);
		t_push_swap_print(ps);
	}

	!t_stack_is_sorted_ascending(ps->a) ? sa(ps) : 0;
	t_push_swap_print(ps);


	int prev = 0;
	while (ps->b->size)
	{
		move_stack_b_to_stack_a(ps);
		prev = ps->counter;
	}
	printf("\n");
	int ind = t_node_get_curr_index(ps->a, t_node_get_by_sort_index(ps->a, 0));
	t_push_swap_print(ps);
	while (ps->a->head->sort_index)
	{
		ind * 2 >= ps->a->size ? rra(ps) : ra(ps);
	}
	t_push_swap_print(ps);
	if (!t_stack_is_sorted_ascending(ps->a))
		printf("WRONG ORDER\n");
	return (0);
}




