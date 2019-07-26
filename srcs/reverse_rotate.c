/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:43:19 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/26 15:05:21 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra(t_frame *stacks)
{
	if (stacks->a && stacks->a->prev)
	{
		stacks->a->prev->next1 = stacks->a;
		stacks->a->prev->prev->next1 = NULL;
		stacks->a = stacks->a->prev;
	}
	if (stacks->print)
		ft_print_ab(stacks);
}

void		rrb(t_frame *stacks)
{
	if (stacks->b && stacks->b->prev)
	{
		stacks->b->prev->next1 = stacks->b;
		stacks->b->prev->prev->next1 = NULL;
		stacks->b = stacks->b->prev;
	}
	if (stacks->print)
		ft_print_ab(stacks);
}

void		rrr(t_frame *stacks)
{
	rra(stacks);
	rrb(stacks);
}
