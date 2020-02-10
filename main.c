#include "push_swap.h"

int		get_median(t_stack *stack)
{
	int *arr;
	int	i;
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

void move_pb(t_push_swap *ps, t_node *node)
{	
	while (ps->a->head->val != node->val)
		ra(ps);
	pb(ps);
}

void move_rb(t_push_swap *ps, t_node *node)
{
	while (ps->a->tail->val != node->val)
	{		
		rra(ps);
	}
	rb(ps);
}

void split_stack(t_push_swap *ps, t_stack *a)
{
	int median;
	int	i;
	t_node *tmp;
	t_node *tmp_next;

	median = get_median(a);
	while (a->head->val < median)
		pb(ps);
	tmp = a->head;
	tmp_next = tmp->next;
	i = 0;	
	while (++i < a->size + 1)
	{
		tmp->val < median ?	move_pb(ps, tmp) : 0;		
		tmp = tmp_next;
		tmp_next = tmp->next;		
	}
}

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

t_stack		*t_stack_copy(t_stack *stack)
{
	t_stack	*new;
	int 	i;
	t_node 	*node;

	i = 0;
	new = t_stack_new();
	node = stack->head;
	while (i < stack->size)
	{
		t_stack_append(new, t_node_new(node->val));
		new->tail->index = node->index;
		node = node->next;
		i++;
	}
	return (new);
}

void		t_stack_get_sort_index(t_stack *stack)
{
	int 	i;
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
		origin->index;
		origin->sort_index = i++;
		node = node->next;
	}
	t_stack_free(sorted);
}

t_push_swap	*t_push_swap_get_stack_from_arr(int *arr, int size)
{
	int		i;
	t_push_swap *ps;

	ps = t_push_swap_new();
	i = 0;
	while (i < size)
	{
		t_stack_append(ps->a, t_node_new(arr[i]));
		ps->a->tail->index = ps->a->size - 1;
		i++;
	}
	t_stack_get_sort_index(ps->a);
	return (ps);
}

void move_stack_b_to_stack_a(t_push_swap *ps)
{
	int ind;
	t_node *next_node;

	next_node = t_node_get_by_sort_index(ps->a, ps->b->head->sort_index + 1);
	ind = t_node_get_curr_index(ps->a, next_node);
	while (ps->a->head->sort_index != next_node->sort_index)
	{
		ind * 2 >= ps->a->size ? rra(ps) : ra(ps);
	}
	pa(ps);
}



int		main()
{
	t_push_swap *ps;
	int a[] = {34,64,17,11,2,5};
	int i;

	ps = t_push_swap_get_stack_from_arr(a, 6);
	i = 0;
	while (!t_stack_is_sorted_ascending(ps->a) && ps->a->size != 2)			
		split_stack(ps, ps->a);
	!t_stack_is_sorted_ascending(ps->a) ? sa(ps) : 0;
	while (!t_stack_is_sorted_ascending || ps->b->size)
		move_stack_b_to_stack_a(ps);
	//while (ps->a->head->sort_index)

	t_push_swap_print(ps);
	return (0);
}




