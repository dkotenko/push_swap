# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clala <clala@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/15 16:58:10 by clala             #+#    #+#              #
#    Updated: 2020/01/30 23:32:38 by clala            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = main.c \
		swap.c \
		t_push_swap.c \
		t_stack.c \
		quick_sort.c \
		bubble_sort.c \
		commands.c \
		random_number.c

HEAD = ./src/filler.h
OBJECTS = $(SOURCES:%.c=%.o)
CC = gcc 
FLAGS = -Wall -Wextra -Werror
LEMIN = push_swap
COMP_LIB = make -C libft/
INCLUDES = ./push_swap.h
LIB = libft/libft.a

all: $(LEMIN)

$(LEMIN): $(OBJECTS)
	$(CC) $(FLAGS) -o $@  $(OBJECTS)

%.o: %.c $(INCLUDES) $(LIB)
	$(CC) $(FLAGS) -I./ -I./libft/ -c $< -o $@

libft:
	$(COMP_LIB)

clean:	
		/bin/rm -f $(OBJECTS)

fclean: clean		
		/bin/rm -f $(LEMIN)

re: fclean all

.PHONY: all libft clean fclean re
