#include "push_swap.h"

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
		origin->sort_index = i++;
		node = node->next;
	}	
	t_stack_free(sorted);	
}

int 		get_ord_ind_number(t_push_swap *ps, t_stack *a, t_node *node)
{
	int 	i;
	int 	ind_counter;
	int 	ind_next;

	ind_counter = 1;
	i = -1;
	ind_next = node->sort_index + 1;
	while (++i < a->size)
	{
		if (node->next->sort_index == ind_next)
		{
			ind_counter++;
			ind_next++;
		}
		else if (node->sort_index == ps->size - 1 && node->next->sort_index == 0)
		{
			ind_counter++;
			ind_next = 1;
		}
		node = node->next;
	}
	return (ind_counter);
}

t_node	*t_node_get_node_max_ord_number(t_push_swap *ps, t_stack *a,
		int (*get_ord)(t_push_swap *, t_stack *, t_node *))
{
	int	i;
	t_node *node;
	t_node *max_node;
	int max_eval;
	int temp_eval;

	max_node = a->head;
	i = -1;
	max_eval = 0;
	node = a->head;
	while (++i < a->size)
	{
		temp_eval = get_ord(ps, a, node);
		if (temp_eval > max_eval)
		{
			max_node = node;
			max_eval = temp_eval;
		}
		else if (temp_eval == max_eval)
		{
			max_node = max_node->sort_index < node->sort_index ? max_node : node;
			max_eval = max_node == node ? temp_eval : max_eval;
		}
		node = node->next;
	}
	return (max_node);
}


void		t_eval_set_ord_by_ind(t_push_swap *ps)
{
	int	 	i;
	t_node *node;

	node = t_node_get_node_max_ord_number(ps, ps->a, get_ord_ind_number);
	i = -1;
	while (++i < ps->a->size)
	{
		if (node->next->sort_index == node->sort_index + 1)
			node->eval->ord_by_val = true;
		else if (node->sort_index == ps->size - 1 && node->next->sort_index == 0)
			node->eval->ord_by_val = true;
		else
			node->eval->ord_by_val = false;
		node = node->next;
	}
}

int 		get_ord_val_number(t_push_swap *ps, t_stack *a, t_node *node)
{
	int 	i;
	int 	val_counter;

	val_counter = 1;
	i = -1;
	while (++i < a->size)
	{
		if (node->next->val >= node->val)
			val_counter++;
		else if (node->val == ps->max && node->next->val == ps->min)
			val_counter++;
		node = node->next;
	}
	return (val_counter);
}

void		t_eval_set_ord_by_val(t_push_swap *ps)
{
	int		i;
	t_node	*node;
	int 	flag;

	flag = 0;
	node = t_node_get_node_max_ord_number(ps, ps->a, get_ord_val_number);
	i = -1;
	while (++i < ps->a->size)
	{
		if (!flag && (node->next->val >= node->val ||
		(node->sort_index == ps->size - 1 && node->next->sort_index == 0)))
			node->eval->ord_by_val = true;
		else
		{
			node->eval->ord_by_val = false;
			if (!flag)
				flag = 1;
		}
		node = node->next;
	}
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
	t_eval_set_ord_by_ind(ps);
	t_eval_set_ord_by_val(ps);
	return (ps);
}

