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


SOURCES = t_push_swap.c \
		t_stack1.c \
		t_stack2.c \
		t_stack3.c \
		quick_sort.c \
		bubble_sort.c \
		comm_push.c \
		comm_swap.c \
		comm_shift_up.c \
		comm_shift_down.c \
		random_number.c \
		t_node.c \
		median.c \
		handle_parameters.c \
		is_valid_parameter.c

PUSH_SWAP_C = push_swap.c
CHECKER_C = checker.c

SRCDIR = src/
OBJDIR = bin/

OBJECTS = $(SOURCES:%.c=%.o)
OBJ = $(addprefix $(OBJDIR), $(OBJECTS))
PUSH_SWAP_OBJ = $(addprefix $(OBJDIR), $(PUSH_SWAP_C:%.c=%.o))
CHECKER_OBJ = $(addprefix $(OBJDIR), $(CHECKER_C:%.c=%.o))

CC = gcc 
FLAGS = -Wall -Wextra -Werror

PUSH_SWAP = push_swap
CHECKER = checker

COMP_LIB = make -C libft/

INCLUDES = ./includes/push_swap.h ./libft/includes/libft.h

all: libft $(CHECKER) $(PUSH_SWAP)

$(PUSH_SWAP): $(PUSH_SWAP_OBJ) $(OBJ)
		$(CC) $(FLAGS) -o $(PUSH_SWAP) $(PUSH_SWAP_OBJ) $(OBJ) -L./libft -lft

$(CHECKER): $(CHECKER_OBJ) $(OBJ)
		$(CC) $(FLAGS) -o $(CHECKER) $(CHECKER_OBJ) $(OBJ) -L./libft -lft

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLUDES)
		@/bin/mkdir -p $(OBJDIR)
		gcc $(FLAGS) -I./includes -I./libft/includes -c $< -o $@

libft:
		$(COMP_LIB)

clean:	
		/bin/rm -rf $(OBJDIR)
		make clean -C libft/

fclean: clean
		make fclean -C libft/	
		/bin/rm -f $(PUSH_SWAP) $(CHECKER)

re: fclean all

.PHONY: all libft clean fclean re
