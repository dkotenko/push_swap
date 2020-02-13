#include "push_swap.h"

void	print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	printf("int arr: ");
	while (i < size)
	{
		printf("%d-", arr[i++]);
	}
	printf("\n");
}

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

void move_to_b(t_push_swap *ps, t_node *node)
{
	int	ind;

	ind = t_node_get_curr_index(ps->a, node);
	while (ps->a->head->index != node->index)
		ind * 2 >= ps->a->size + 1 ? rra(ps) : ra(ps);
	pb(ps);
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
	while (++i < a->size + 1 && a->size > 2)
	{		
		tmp->val <= median ? move_to_b(ps, tmp) : 0;
		tmp = tmp_next;
		tmp_next = tmp->next;		
	}
}
