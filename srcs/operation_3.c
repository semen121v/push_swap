/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:05:23 by fshade            #+#    #+#             */
/*   Updated: 2019/07/26 16:31:55 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_op(t_frame *stacks, char op)
{
	if (op == 'a')
	{
		ft_printf("sa\n");
		sa(stacks);
	}
	else if (op == 'b')
	{
		ft_printf("sb\n");
		sb(stacks);
	}
}

void	ft_revsort3(t_frame *stacks, int bsize, int print)
{
	int		asize;

	asize = 0;
	while (bsize > 0)
	{
		if (asize == 2 && stacks->a->data > stacks->a->next->data)
			ft_swap_op(stacks, 'a');
		if (bsize > 1 && stacks->b->data < stacks->b->next->data)
			ft_swap_op(stacks, 'b');
		else
		{
			ft_push_op(stacks, 'a', print);
			bsize--;
			asize++;
		}
	}
}

void	ft_sort3(t_frame *stacks, int size)
{
	int		offsize;

	offsize = 0;
	while (!ft_is_sort_size(stacks->a, size, ASC) || offsize)
	{
		if (stacks->a->data > stacks->a->next->data)
			ft_swap_op(stacks, 'a');
		else if (offsize)
		{
			ft_push_op(stacks, 'a', stacks->print);
			offsize--;
			size++;
		}
		else
		{
			ft_push_op(stacks, 'b', stacks->print);
			offsize++;
			size--;
		}
	}
}
