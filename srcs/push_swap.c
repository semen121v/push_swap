/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:09:47 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/25 19:54:33 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort_print(t_frame *stacks, int ac)
{
	int		size;

	size = count_list(stacks->a);
	if (stacks->print)
	{
		ft_printf("START\n");
		ft_print_ab(stacks);
	}
	if (ac <= 4 && count_list(stacks->a) < 4)
		ft_sortl(stacks, stacks->print);
	else
		ft_qsort(stacks, size);
	if (stacks->print)
	{
		ft_printf("END\n");
		ft_print_ab(stacks);
	}
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
	read_num(ac, av, 1, stacks);
	stacks->print = print;
	stacks->push = 1;
	ft_sort_print(stacks, ac);
	free_stacks(stacks);
	free(stacks);
	return (0);
}
