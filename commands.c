#include "push_swap.h"

void	t_stack_swap(t_stack *stack, int index_a, int index_b)
{
	int	t;	

	t = stack->arr[index_a].value;
	stack->arr[index_a].value = stack->arr[index_b].value;
	stack->arr[index_b].value = t;	
}

int		sa(t_push_swap *ps)
{
	if (ps->a->size > 1)
		swap(ps->a, 0, 1);
	return (1);
}

int		sb(t_push_swap *ps)
{
	if (ps->b->size > 1)
		swap(ps->b, 0, 1);
	return (1);
}


int		ss(t_push_swap *ps)
{
	sa(ps);
	sb(ps);
	return (1);
}

int		t_stack_push(t_stack *s1, t_stack *s2)
{
	if (s1->first_ind == 0)
	{
		t_stack_shift_down(s1);
		s1->arr[s1->last_ind + 1] = s1->arr[s1->first_ind];
		s1->last_ind++;
		s1->first_ind++;
	}
	s1->arr[s1->first_ind - 1] = s2->arr[s2->first_ind];
	s1->first_ind--;
	s2->first_ind++;
	return (0);
}

int		pa(t_push_swap *ps)
{
	t_stack_push(ps->a, ps-> b);
	return (1);	
}


int		pb(t_push_swap *ps)
{
	t_stack_push(ps->b, ps-> a);
	return (1);	
}



int		t_stack_shift_down(t_stack *stack)
{
	int	i;

	if (stack->size < 2)
		return (1);
	i = stack->first_ind + 1;
	while (i < stack->size)
	{
		t_stack_swap(stack, stack->first_ind, i);
		i++;
	}
	return (1);
}

int		t_stack_shift_up(t_stack *stack)
{
	int	i;

	if (stack->size < 2)
		return (1);
	i = stack->last_ind;
	while (i > stack->first_ind)
	{
		t_stack_swap(stack, stack->first_ind, i);
		i--;
	}
	return (1);
}
	


int		ra(t_push_swap *ps)
{
	t_stack_shift_up(ps->a);
	return (1);
}

int		rb(t_push_swap *ps)
{
	t_stack_shift_up(ps->b);
	return (1);
}

int		rr(t_push_swap *ps)
{
	ra(ps);
	rb(ps);
	return (1);
}

int		rra(t_push_swap *ps)
{
	t_stack_shift_down(ps->a);
	return (1);
}

int		rrb(t_push_swap *ps)
{
	t_stack_shift_down(ps->b);
	return (1);
}

int		rrr(t_push_swap *ps)
{
	rra(ps);
	rrb(ps);
}
