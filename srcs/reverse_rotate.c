/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:43:19 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/13 22:03:47 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra(t_frame *stacks)
{
	if (stacks->a && stacks->a->prev)
	{
		stacks->a->prev->next1 = stacks->a;
		stacks->a->next1->next1 = NULL;
		stacks->a = stacks->a->prev;
		// add_list(stacks, RRA);
	}
}

void		rrb(t_frame *stacks)
{
	if (stacks->b && stacks->b->prev)
	{
		stacks->b->prev->next1 = stacks->b;
		stacks->b->next1->next1 = NULL;
		stacks->b = stacks->b->prev;
		// add_list(stacks, RRB);
	}
}

void		rrr(t_frame *stacks)
{
	rra(stacks);
	rrb(stacks);
}
