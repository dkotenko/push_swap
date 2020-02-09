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

void split_stack(t_stack *a)
{
	int median;
	t_node *tmp;

	tmp = a->head;
	median = get_median(a);
	while (tmp->val < median)
		pb(ps);
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
	
	while (!is_sorted(ps->a))
	{		
		split_stack(ps->a);
	}	
	t_node *tmp = ps->a->head;
	
	return (0);
}



int		t_stack_is_sorted_ascending(t_stack *stack)
{
	int		i;
	t_node	*tmp;

	tmp = stack->head;
	while (i < stack->size - 1)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

