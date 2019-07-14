/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:43:19 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/14 19:49:26 by fshade           ###   ########.fr       */
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
}

void		rrb(t_frame *stacks)
{
	if (stacks->b && stacks->b->prev)
	{
		stacks->b->prev->next1 = stacks->b;
		stacks->b->prev->prev->next1 = NULL;
		stacks->b = stacks->b->prev;
	}
}

void		rrr(t_frame *stacks)
{
	rra(stacks);
	rrb(stacks);
}
