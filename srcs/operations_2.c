/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:45:21 by fshade            #+#    #+#             */
/*   Updated: 2019/07/13 21:37:51 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sort_size(t_clist *stack, int size, int direct)
{
	if (size == 0)
		return (1);
	while (--size)
	{
		if (direct == ASC && stack->data > stack->next->data)
			return (0);
		else if (direct == DESC && stack->data < stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		ft_check_stack(t_clist *stack, int pivot, int size)
{
	while (size--)
	{
		if (stack->data > pivot)
			return (0);
		// else if (direct == DESC && stack->data > pivot)
		// 	return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_push_op(t_frame *stacks, char op, int print)
{

	if (op == 'a')
	{
		pa (stacks);
		if (print)
			ft_print_ab(stacks);
	}
	else if (op == 'b')
	{
		pb (stacks);
		if (print)
			ft_print_ab(stacks);
	}
}

void	ft_revrotate_op(t_frame *stacks, char op, int print)
{
	if (print >= 0)
		ft_printf("rr%c\n", op);
	if (op == 'a')
	{
		ft_printf("rra\n");
		rra(stacks);
		if (print)
			ft_print_ab(stacks);
	}
	else if (op == 'b')
	{
		ft_printf("rrb\n");
		rrb(stacks);
		if (print)
			ft_print_ab(stacks);
	}
}