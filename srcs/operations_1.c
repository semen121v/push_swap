/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:34:01 by fshade            #+#    #+#             */
/*   Updated: 2019/07/13 22:15:56 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pusha_all(t_frame *stacks, int size)
{
	while (size--)
		ft_push_op(stacks, 'a', stacks->print);
}

void		ft_sort_2(t_frame *stacks, int print)
{
	int		min;
	int		max;

	min = ft_get_min(stacks->a);
	max = ft_get_max(stacks->a);
	while (!ft_is_sort_size(stacks->a, count_list(stacks->a), ASC))
	{
		if (stacks->a->data == max)
		{
			ra(stacks);
			ft_printf("ra\n");
		}
		else if (stacks->a->next->data == max)
		{
			rra(stacks);
			ft_printf("rra\n");
		}
		else if (stacks->a->data != min && stacks->a->data != max)
		{
			sa(stacks);
			ft_printf("sa\n");
		}
		if (print)
			ft_print_ab(stacks);
	} 
}

void		ft_sortl(t_frame *stacks, int print)
{
	if (count_list(stacks->a) == 2) 
	{
		if (stacks->a->data > stacks->a->next->data)
		{
			ra(stacks);
			ft_printf("ra\n");
			if (print)
				ft_print_ab(stacks);
		}
	}
	else if (count_list(stacks->a) == 3)
		ft_sort_2(stacks, stacks->print);
	return ;
}

// void	ft_revqsort(t_frame *stacks, int size)
// {
// 	int		bsize;
// 	int		asize;
// 	int		pivot;
// 	int		is_rr;

// 	bsize = 0;
// 	asize = 0;
// 	pivot = get_median(stacks->b);
// 	is_rr = (size == count_list(stacks->b)) ? 0 : 1;
// 	if (ft_is_sort_size(stacks->b, size, DESC))
// 		return (ft_pusha_all(b, a, print, size));
// 	if (size <= 3)
// 		return (ft_revsort3(b, a, size, print));
// 	while (!ft_check_stack(*b, pivot, size, DESC) && size--)
// 	{
// 		if ((*b)->value > pivot && ++asize)
// 			ft_push_op(b, a, 'a', print);
// 		else if (++bsize)
// 			ft_rotate_op(b, a, 'b', print);
// 	}
// 	pivot = 0;
// 	while (is_rr && pivot++ < bsize)
// 		ft_revrotate_op(b, a, 'b', print);
// 	ft_qsort(a, b, asize, print);
// 	ft_revqsort(b, a, bsize + size, print);
// }

void		ft_qsort(t_frame *stacks, int size)
{
	int		asize;
	int		bsize;
	int		pivot;
	int		rr;

	asize = 0;
	bsize = 0;
	pivot = get_median(stacks->a);
	rr = (size == count_list(stacks->a)) ? 0 : 1;
	if (ft_is_sort_size(stacks->a, size, ASC))
		return ;
	while (!ft_check_stack(stacks->a, pivot, size) && size--)
	{
		if (stacks->a->data < pivot && ++bsize)
			ft_push_op(stacks, 'b', stacks->print);
		else if (++asize)
		{
			ft_printf("ra\n");
			ra(stacks);
			if (stacks->print)
				ft_print_ab(stacks);
		}
	}
	pivot = 0;
	ft_printf("%d\n", asize + size);
	while (rr && pivot++ < asize)
		ft_revrotate_op(stacks, 'a', stacks->print);
	ft_qsort(stacks, asize + size);
	// ft_revqsort(stacks, bsize);
 }