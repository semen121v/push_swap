/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:09:39 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/25 22:55:43 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void		gnl(t_frame *stack, char *line)
{
	if (!ft_strcmp(line, "pb"))
		pb(stack);
	else if (!ft_strcmp(line, "pa"))
		pa(stack);
	else if (!ft_strcmp(line, "sb"))
		sb(stack);
	else if (!ft_strcmp(line, "sa"))
		sa(stack);
	else if (!ft_strcmp(line, "ss"))
		ss(stack);
	else if (!ft_strcmp(line, "ra"))
		ra(stack);
	else if (!ft_strcmp(line, "rb"))
		rb(stack);
	else if (!ft_strcmp(line, "rrb"))
		rrb(stack);
	else if (!ft_strcmp(line, "rra"))
		rra(stack);
	else if (!ft_strcmp(line, "rrr"))
		rrr(stack);
	else if (!ft_strcmp(line, "rr"))
		rr(stack);
	else
		failed_exit(stack);
}

static void	parse_instructions(t_frame *stacks)
{
	char	*line;

	if (stacks->print)
	{
		ft_printf("START\n");
		ft_print_ab(stacks);
	}
	while (get_next_line(0, &line) == 1)
	{
		gnl(stacks, line);
		if (stacks->print)
			ft_print_ab(stacks);
		free(line);
	}
	if (stacks->print)
	{
		ft_printf("END\n");
		ft_print_ab(stacks);
	}
	ft_printf((is_sorted(stacks) == 1) ? "OK\n" : "KO\n");
	free_stacks(stacks);
	free(stacks);
}

static int	ft_check_option(char *option)
{
	if (ft_strnstr(option, "-v", 3))
		return (1);
	return (0);
}

int			main(int ac, char **av)
{
	t_frame	*stacks;
	int		print;

	if (ac < 2)
		return (0);
	if ((print = ft_check_option(av[1])))
	{
		av++;
		ac--;
	}
	if (valid_item(ac, av) == 1)
		return (print_usage());
	if (!(stacks = (t_frame*)malloc(sizeof(*stacks))))
		return (0);
	stacks->b = NULL;
	stacks->print = print;
	read_num(ac, av, 1, stacks);
	parse_instructions(stacks);
	return (0);
}
