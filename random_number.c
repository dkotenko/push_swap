#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include "libft/includes/libft.h"
#include <limits.h>
  
void	print_range(int *range, int size)
{
	int	i;

	i = 0;	
	while (i < size)
	{
		ft_putnbr(range[i++]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

int		is_duplicate(int *arr, int size, int nbr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == nbr)
			return (1);		
		i++;
	}
	return (0);
}

int		*get_random_range(int lower, int upper, int size)
{
	int	i;
	int	*range;
	int	temp;

	srand(time(0));
	range = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		temp = rand() % (upper - lower + 1) + lower;
		while (is_duplicate(range, size, temp))
			temp++;
		range[i] = temp;
		i++;
	}
	return (range);
}
  
int		main(int ac, char **av) 
{ 
    int	lower;
	int	upper;
	int	size;

	srand(time(0));  
	if (ac > 1 && ac < 5)
	{
		lower = 0;
		upper = 0x7ffff;
		size = ft_atoi(av[1]);
		if (size < 1)
		{
			ft_putstr("Size must be INT greater than 0");
			return (0);
		}
		if (ac == 4 || ac == 3)
		{
			lower = ac == 3 ? ft_atoi(av[2]) * -1 : ft_atoi(av[2]);
			upper = ac == 3 ? lower * -1 : ft_atoi(av[3]);
		}		
		print_range(get_random_range(lower, upper, size), size);
	}  
    return (0); 
}