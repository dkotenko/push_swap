#include "push_swap.h"

t_push_swap		*t_push_swap_new(void)
{
	t_push_swap	*ps;

	ps = (t_push_swap *)malloc(sizeof(ps));
	ps->a = t_stack_new();
	ps->b = t_stack_new();
	ps->counter = 0;
	ps->max = 0;
	ps->min = 0;
	ps->size = 0;
	return (ps);
}

