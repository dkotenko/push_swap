#include "push_swap.h"

void	t_node_swap(t_node *a, t_node *b)
{
	swap(&a->val, &b->val);
	swap(&a->index, &b->index);
	swap(&a->sort_index, &b->sort_index);
}

int		sa(t_push_swap *ps)
{
	ps->counter++;
	if (ps->a->size > 1)
	{
		t_node_swap(ps->a->head, ps->a->head->next);
		return (1);
	}
	return (0);
}

int		sb(t_push_swap *ps)
{
	ps->counter++;
	if (ps->b->size > 1)
	{
		t_node_swap(ps->b->head, ps->b->head->next);
		return (1);
	}
	return (0);
}


int		ss(t_push_swap *ps)
{
	if (sa(ps) || sb(ps))
		return (1);
	return (0);
}

int		pa(t_push_swap *ps)
{
	t_stack_push(ps->a, t_stack_pop(ps->b, ps->b->head));
	ps->counter++;
	return (1);	
}


int		pb(t_push_swap *ps)
{
	t_stack_push(ps->b, t_stack_pop(ps->a, ps->a->head));
	ps->counter++;
	return (1);	
}



int		t_stack_shift_down(t_stack *stack)
{
	if (!stack->size)
		return (0);	
	stack->head = stack->tail;
	stack->tail = stack->tail->prev;	
	return (1);
}

int		t_stack_shift_up(t_stack *stack)
{
	if (!stack->size)
		return (0);	
	stack->tail = stack->head;
	stack->head = stack->head->next;
	return (1);
}
	

/*
 * Shift up a
 */

int		ra(t_push_swap *ps)
{
	ps->counter++;
	t_stack_shift_up(ps->a);
	return (1);
}

/*
 * Shift up b
 */
int		rb(t_push_swap *ps)
{
	ps->counter++;
	t_stack_shift_up(ps->b);
	return (1);
}

/*
 * Shift up both stacks
 */
int		rr(t_push_swap *ps)
{
	ra(ps);
	rb(ps);
	return (1);
}

/*
 * Shift down a
 */
int		rra(t_push_swap *ps)
{
	ps->counter++;
	t_stack_shift_down(ps->a);
	return (1);
}

/*
 * Shift down b
 */
int		rrb(t_push_swap *ps)
{
	ps->counter++;
	t_stack_shift_down(ps->b);
	return (1);
}

/*
 * Shift down both stacks
 */
int		rrr(t_push_swap *ps)
{
	rra(ps);
	rrb(ps);
	return (1);
}
