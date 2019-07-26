/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:34:01 by fshade            #+#    #+#             */
/*   Updated: 2019/07/26 15:04:36 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_pusha_all(t_frame *stacks, int size)
{
	while (size--)
		ft_push_op(stacks, 'a', stacks->print);
}

void		ft_sort_2(t_frame *stacks)
{
	int		min;
	int		max;

	min = ft_get_min(stacks->a);
	max = ft_get_max(stacks->a);
	while (!ft_is_sort_size(stacks->a, count_list(stacks->a), ASC))
	{
		if (stacks->a->data == max)
			ra(stacks);
		else if (stacks->a->next->data == max)
		{
			ft_printf("rra\n");
			rra(stacks);
		}
		else if (stacks->a->data != min && stacks->a->data != max)
		{
			ft_printf("sa\n");
			sa(stacks);
		}
	}
}

void		ft_sortl(t_frame *stacks)
{
	if (count_list(stacks->a) == 2)
	{
		if (stacks->a->data > stacks->a->next->data)
			ra(stacks);
	}
	else if (count_list(stacks->a) == 3)
		ft_sort_2(stacks);
	return ;
}

void		ft_revqsort(t_frame *stacks, int size)
{
	int		bsize;
	int		asize;
	int		pivot;
	int		is_rr;

	bsize = 0;
	asize = 0;
	pivot = get_median(stacks->b, size);
	is_rr = (size == count_list(stacks->b)) ? 0 : 1;
	if (ft_is_sort_size(stacks->b, size, DESC))
		return (ft_pusha_all(stacks, size));
	if (size <= 3)
		return (ft_revsort3(stacks, size, stacks->print));
	while (!ft_check_stack(stacks->b, pivot, size, DESC) && size--)
	{
		if (stacks->b->data > pivot && ++asize)
			ft_push_op(stacks, 'a', stacks->print);
		else if (++bsize)
			rb(stacks);
	}
	pivot = 0;
	while (is_rr && pivot++ < bsize)
		ft_revrotate_op(stacks, 'b', stacks->print);
	ft_qsort(stacks, asize);
	ft_revqsort(stacks, bsize + size);
}

void		ft_qsort(t_frame *stacks, int size)
{
	int		asize;
	int		bsize;
	int		pivot;
	int		rr;

	asize = 0;
	bsize = 0;
	pivot = get_median(stacks->a, size);
	rr = (size == count_list(stacks->a)) ? 0 : 1;
	if (ft_is_sort_size(stacks->a, size, ASC))
		return ;
	if (size <= 3)
		return (!rr ? ft_sortl(stacks) : ft_sort3(stacks, size));
	while (!ft_check_stack(stacks->a, pivot, size, ASC) && size--)
	{
		if (stacks->a->data < pivot && ++bsize)
			ft_push_op(stacks, 'b', stacks->print);
		else if (++asize)
			ra(stacks);
	}
	pivot = 0;
	while (rr && pivot++ < asize)
		ft_revrotate_op(stacks, 'a', stacks->print);
	ft_qsort(stacks, asize + size);
	ft_revqsort(stacks, bsize);
}
