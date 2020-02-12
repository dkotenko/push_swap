#include "checker.h"

void	handle_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

void 	check_parameters(int ac, char **av)
{
	int failure;

	while (ac > 0)
	{
		if (!is_integer(av[ac]) || is_duplicate(av[ac]))
			handle_error();
		ac--;
	}
}

void			handle_instructions(void)
{
	char		*s;

	t_commands	*comm;

	comm = NULL;
	while (get_next_line(0, &s))
	{
		if (!comm)
			comm = push
	}
}

int		main(int ac, char **av)
{

	if (ac > 1)
	{
		check_parameters(ac, av);
		handle_instructions();
	}
	return (0);
}