#include "push_swap.h"

int		sa(t_push_swap *ps)
{
	if (ps->a->size > 1)
		swap(ps->a->head, ps->a->head->next);
	return (1);
}

int		sb(t_push_swap *ps)
{
	if (ps->b->size > 1)
		swap(ps->b->head, ps->b->head->next);
	return (1);
}


int		ss(t_push_swap *ps)
{
	sa(ps);
	sb(ps);
	return (1);
}

int		pa(t_push_swap *ps)
{
	t_stack_push(ps->a, t_stack_pop(ps->b, ps->b->head));
	return (1);	
}


int		pb(t_push_swap *ps)
{
	t_stack_push(ps->b, t_stack_pop(ps->a, ps->a->head));
	return (1);	
}



int		t_stack_shift_down(t_stack *stack)
{
	int	i;

	if (!stack->size)
		return (0);
	
	stack->head = stack->tail;
	stack->tail = stack->tail->prev;	
	return (1);
}

int		t_stack_shift_up(t_stack *stack)
{
	int	i;

	if (!stack->size)
		return (0);	
	stack->tail = stack->head;
	stack->head = stack->head->next;
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
