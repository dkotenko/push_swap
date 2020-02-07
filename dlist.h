#ifndef DLIST_H
# define DLIST_H

# include <string.h>
# include <stdlib.h>

typedef struct		g_dlist_node
{
	t_dlist_node	*next;
	t_dlist_node	*prev;	
	void			*data;	
}					t_dlist_node;

typedef struct		g_dlist
{
	t_dlist			*head;
	t_dlist			*tail;
	int				size;
}					t_dlist;

#endif