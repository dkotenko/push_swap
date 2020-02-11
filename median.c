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
	while (++i < a->size + 1 && a->size > 2)
	{
		tmp->val < median ?	move_pb(ps, tmp) : 0;
		tmp = tmp_next;
		tmp_next = tmp->next;
	}
}
