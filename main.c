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

void split_stack(t_push_swap *ps, t_stack *a, int flag)
{
	int median;
	int	i;
	t_node *tmp;
	t_node *tmp_next;

	while (a->head->val < median)
		pb(ps);
	while (!flag && a->tail->val < median)
		rb(ps);
	tmp = a->head;
	tmp_next = tmp->next;
	median = get_median(a);	
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

int		main()
{
	t_push_swap *ps = t_push_swap_new();
	int a[] = {4,5,34,64,2,5};
	int i = 0;
	while (i < 6)
	{
		t_stack_append(ps->a, t_node_new(a[i]));
		i++;
	}	
	i = 0;
	
	while (!t_stack_is_sorted_ascending(ps->a) && ps->a->size != 2)			
		split_stack(ps, ps->a, i++);
	!t_stack_is_sorted_ascending(ps->a) ? sa(ps) : 0;
	t_push_swap_print(ps);
	t_node *tmp = ps->a->head;
	
	return (0);
}




