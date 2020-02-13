#include "push_swap.h"




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
	node->eval->moves = node_moves + next_node_moves + 1;
	return (node);
}

t_node *t_node_get_min_moves(t_push_swap *ps)
{	
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
	while (ps->a->head->sort_index != next_node->sort_index)
	{
		next_ind * 2 >= ps->a->size ? rra(ps) : ra(ps);
	}
	pa(ps);
}

int		main()
{
	t_push_swap *ps;

	int size = 100;
	int *a = get_random_range(-100, 100, size);
	//int a[] = {-6, -45, 58, 13, -69, -11, 92, -14, 92, 69, -34, -67, 94, -84, 28, -56, -40, 36, -31, -16};
	//int a[] = {63, 45, -51, -38, 48, -47, 87, 55, -88, -23, -28, -80, 57, 7, -52, 92, -92, 92, 61, 29, -49, 59, 29, -78, 70, 27, -33, -63, -3, -61, -1, -91, 34, 48, -29, -18, 52, -42, -64, 64, -15, -42, 34, -58, 65, 83, 84, 23, 24, -6, -49, 25, -48, 31, 48, -79, -43, -86, -92, 4, -97, 7, 14, 38, -95, 85, -81, 57, 93, -95, -30, -22, -37, -97, -30, 78, 86, -97, -50, -40, -3, 1, 35, 49, 82, -18, 20, -62, -53, 28, -7, -50, 85, -94, 88, 90, 91, 57, 46, 34}; 
	ps = t_push_swap_get_stack_from_arr(a, size);

	printf("START\n");
	t_push_swap_print(ps);
	if (t_stack_is_sorted_ascending(ps->a))
	{
		printf("already ascending\n");
		return (0);
	}		
	while (!t_stack_is_sorted_ascending(ps->a) && ps->a->size > 2)
	{
		split_stack(ps, ps->a);
		//t_push_swap_print(ps);		
	}
	t_push_swap_print(ps);
	//printf("after splitting\n");
	//t_push_swap_print(ps);
	
	while (ps->b->size)
	{	
		move_stack_b_to_stack_a(ps);
		//t_push_swap_print(ps);
	}
		
	printf("\n");
	int ind = t_node_get_curr_index(ps->a, t_node_get_by_sort_index(ps->a, 0));
	//t_push_swap_print(ps);
	while (ps->a->head->sort_index)
	{
		ind * 2 >= ps->a->size ? rra(ps) : ra(ps);
	}
	t_push_swap_print(ps);
	if (!t_stack_is_sorted_ascending(ps->a))
		printf("WRONG ORDER\n");
	//printf("%d %d %d\n", ps->a->head->eval->moves,
	//	   ps->a->head->eval->ord_by_ind, ps->a->head->eval->ord_by_val);
	return (0);
}




