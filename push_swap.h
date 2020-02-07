#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

# define EMPTY -1

typedef struct		g_node
{
	struct g_node	*next;
	struct g_node	*prev;	
	int				val;	
}					t_node;

typedef	struct	g_stack
{
	t_node	*head;
	t_node	*tail;
	t_node	*max;
	t_node	*min;
	int				size;
}				t_stack;


typedef	struct g_push_swap
{
	t_stack		*a;
	t_stack		*b;
	int			counter;
	int			max;
	int			min;
	int			size;
}				t_push_swap;


void	swap(int *a, int *b);
t_push_swap		*t_push_swap_new(void);
t_stack		*t_stack_new();
t_node	*t_stack_insert_in_empty(t_stack *list, t_node *new);
t_node	*t_stack_insert_after(t_stack *list, t_node *node, t_node *new);
t_node	*t_stack_append(t_stack *list, t_node *new);
t_node	*t_stack_push(t_stack *list, t_node *new);
t_node		*t_stack_min(t_stack *list);
t_node		*t_stack_max(t_stack *list);
t_node *t_stack_pop(t_stack *list, t_node *node);
void	t_stack_swap(t_stack *list);
t_node		*t_node_new(int data);
void	t_stack_print(t_stack *list);

/*
 * commands
 */

int		sa(t_push_swap *ps);
int		sb(t_push_swap *ps);
int		ss(t_push_swap *ps);
int		pa(t_push_swap *ps);
int		pb(t_push_swap *ps);
int		ra(t_push_swap *ps);
int		rb(t_push_swap *ps);
int		rr(t_push_swap *ps);
int		rra(t_push_swap *ps);
int		rrb(t_push_swap *ps);
int		rrr(t_push_swap *ps);

#endif