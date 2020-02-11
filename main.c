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

void move_stack_b_to_stack_a(t_push_swap *ps)
{
	int ind;
	t_node *next_node;

	next_node = t_node_get_node_next_sort_index(ps->a, ps->b->head->sort_index);
	ind = t_node_get_curr_index(ps->a, next_node);
	ps->a->head->val;
	while (ps->a->head->sort_index != next_node->sort_index)
	{
		ind * 2 >= ps->a->size ? rra(ps) : ra(ps);
	}
	if (ps->b->size)
		pa(ps);
}



int		main()
{
	t_push_swap *ps;

	int size = 500;
	int *a = get_random_range(-100, 5400, size);
	int i;

	ps = t_push_swap_get_stack_from_arr(a, size);
	i = 0;
	while (!t_stack_is_sorted_ascending(ps->a) && ps->a->size != 2)
	{
		split_stack(ps, ps->a);
	}
	!t_stack_is_sorted_ascending(ps->a) ? sa(ps) : 0;
	while (ps->b->size)
	{
		move_stack_b_to_stack_a(ps);
	}
	int ind = t_node_get_curr_index(ps->a, t_node_get_by_sort_index(ps->a, 0));
	while (ps->a->head->sort_index)
	{
		ind * 2 >= ps->a->size ? rra(ps) : ra(ps);
	}
	if (t_stack_is_sorted_ascending(ps->a))
		t_push_swap_print(ps);
	else
		printf("WRONG ORDER\n");
	return (0);
}




