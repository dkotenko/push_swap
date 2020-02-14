PS_C = push_swap.c
CH_C = checker.c
ALL_C =     case_of_error.c add_to_stack.c check_for_duplicates.c get_nbr.c                 \
            new_elem.c func_sa.c func_sb.c func_ss.c func_pa.c func_pb.c push_from_to.c     \
            func_ra.c func_rb.c func_rr.c rotate_lst.c func_rra.c func_rrb.c func_rrr.c     \
            fill_stack.c find_solution.c swap_elems.c ft_is_sort.c ft_sort.c                \
            fill_stack_vars.c init_struct.c array_asc_sort.c func_arr.c command_end_other.c \
            get_cur_offset.c get_cur_tab.c init_stack_vars.c command_end_pb.c               \
            count_of_ops_for_input.c remove_commands.c define_rev_command.c insert_elem.c   \
            find_command_by_name.c rev_ro_lst.c remove_elem.c pre_sort_a.c func_free.c      \


SRCDIR = srcs/
OBJDIR = objs/

ALL_OBJ = $(ALL_C:%.c=%.o)

OBJS = $(addprefix $(OBJDIR), $(ALL_OBJ))
PS_OBJS = $(addprefix $(OBJDIR), $(PS_C:%.c=%.o))
CH_OBJS = $(addprefix $(OBJDIR), $(CH_C:%.c=%.o))

NAME_PS = push_swap
NAME_CH = checker

INCLUDES = ./includes/push_swap.h ./libft/includes/libft.h

COMP_LIB = make -C libft/

FLAGS = -Wall -Wextra -Werror

all: lib $(NAME_CH) $(NAME_PS)

$(NAME_PS): lib $(PS_OBJS) $(OBJS)
		@gcc $(FLAGS) -o $(NAME_PS) $(PS_OBJS) $(OBJS) -L./libft -lft

$(NAME_CH): lib $(CH_OBJS) $(OBJS)
		@gcc $(FLAGS) -o $(NAME_CH) $(CH_OBJS) $(OBJS) -L./libft -lft

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLUDES)
		@/bin/mkdir -p $(OBJDIR)
		@gcc $(FLAGS) -I./includes -I./libft/includes -c $< -o $@

lib:
		@$(COMP_LIB)

clean:
	    @/bin/rm -rf $(OBJDIR)
		@$(COMP_LIB) clean

fclean: clean
		@/bin/rm -rf $(NAME_CH) $(NAME_PS)
		@$(COMP_LIB) fclean

re: fclean all

.PHONY: lib clean fclean all re
