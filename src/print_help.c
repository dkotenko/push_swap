/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:21:10 by clala             #+#    #+#             */
/*   Updated: 2020/02/20 21:03:25 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		print_help(t_push_swap *ps)
{
	ft_printf("%sUSAGE%s:\t./push_swap [debug] [filename | arguments]\n",
		C_GRN, C_NRM);
	ft_printf("\t./checker   [debug] [filename | arguments]\n");
	ft_printf("\t        -v  debug mode, must be first argument\n");
	ft_printf("\t[filename]  read numbers from file. ");
	ft_printf("All arguments after \"filename\" will be omitted\n");
	ft_printf("\t    --help  this information\n");
	free(ps->a);
	free(ps->b);
	free(ps->instr);
	exit(0);
	return (1);
}
