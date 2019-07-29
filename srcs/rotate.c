/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:43:07 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/27 22:44:04 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_frame *stacks)
{
	if (stacks->a && stacks->a->next && stacks->a->data \
		!= stacks->a->next->data)
	{
		stacks->a->prev->next1 = stacks->a;
		stacks->a->next1 = NULL;
		stacks->a = stacks->a->next;
	}
	if (stacks->push == 1)
		ft_printf("ra\n");
	if (stacks->print)
		ft_print_ab(stacks);
}

void		rb(t_frame *stacks)
{
	if (stacks->b && stacks->b->next && stacks->b->data \
		!= stacks->b->next->data)
	{
		stacks->b->prev->next1 = stacks->b;
		stacks->b->next1 = NULL;
		stacks->b = stacks->b->next;
	}
	if (stacks->push == 1)
		ft_printf("rb\n");
	if (stacks->print)
		ft_print_ab(stacks);
}

void		rr(t_frame *stacks)
{
	ra(stacks);
	rb(stacks);
}
