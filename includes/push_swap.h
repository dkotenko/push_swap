/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:21:50 by clala             #+#    #+#             */
/*   Updated: 2020/02/20 20:57:19 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# define EMPTY -1

typedef struct		s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				val;
	int				sort_index;
	int				index;
	int				moves;
}					t_node;

typedef	struct		s_stack
{
	t_node			*head;
	t_node			*tail;
	t_node			*max;
	t_node			*min;
	int				size;
}					t_stack;

typedef	struct		s_push_swap
{
	t_stack			*a;
	t_stack			*b;
	int				counter;
	int				max;
	int				min;
	int				size;
	t_dlist			*instr;
	bool			debug;
}					t_push_swap;

/*
** int arr fucntions
*/

void				swap(int *a, int *b);
void				print_arr(int *arr, int size);
void				ft_qsort(int *arr, int start, int end);
void				bubble_sort(int *arr, int size);

/*
** t_stack
*/

t_stack				*t_stack_new();
t_node				*t_stack_insert_in_empty(t_stack *list, t_node *new);
t_node				*t_stack_insert_after(t_stack *list, t_node *node,
										t_node *new);
t_node				*t_stack_append(t_stack *list, t_node *new);
t_node				*t_stack_push(t_stack *list, t_node *new);
t_node				*t_stack_min(t_stack *list);
t_node				*t_stack_max(t_stack *list);
t_node				*t_stack_pop(t_stack *list, t_node *node);
void				t_stack_swap(t_stack *list);
void				t_stack_print(t_stack *list);
void				t_stack_bubble_sort(t_stack *stack);
void				t_stack_free(t_stack *stack);
t_stack				*t_stack_copy(t_stack *stack);
int					t_stack_is_sorted_ascending(t_stack *stack);
void				t_stack_get_sort_index(t_stack *stack);

/*
** t_node
*/

t_node				*t_node_new(int data);
t_node				*t_node_get_by_sort_index(t_stack *stack, int index);
t_node				*t_node_get_by_index(t_stack *stack, int index);
int					t_node_get_curr_index(t_stack *stack, t_node *node);
t_node				*t_node_get_node_next_sort_index(t_stack *stack, int index);

/*
**	t_push_swap
*/

void				t_push_swap_print(t_push_swap *ps);
t_push_swap			*t_push_swap_new(void);
void				t_push_swap_free(t_push_swap *ps);
void				split_stack(t_push_swap *ps, t_stack *a);

/*
** commands
*/

int					sa(t_push_swap *ps);
int					sb(t_push_swap *ps);
int					ss(t_push_swap *ps);
int					pa(t_push_swap *ps);
int					pb(t_push_swap *ps);
int					ra(t_push_swap *ps);
int					rb(t_push_swap *ps);
int					rr(t_push_swap *ps);
int					rra(t_push_swap *ps);
int					rrb(t_push_swap *ps);
int					rrr(t_push_swap *ps);

int					handle_error(t_push_swap *ps);
void				handle_parameters(int ac, char **av, t_push_swap *ps);
int					is_valid_parameter(t_push_swap *ps, char *s);
int					print_help(t_push_swap *ps);

#endif
