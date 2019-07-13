/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:43:07 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/13 22:03:22 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_frame *stacks)
{
	if (stacks->a && stacks->a->next)
	{
		stacks->a->prev->next1 = stacks->a;
		stacks->a->next1 = NULL;
		stacks->a = stacks->a->next;
		// add_list(stacks, RA);
	}
}

void		rb(t_frame *stacks)
{
	if (stacks->b && stacks->b->next)
	{
		stacks->b->prev->next1 = stacks->b;
		stacks->b->next1 = NULL;
		stacks->b = stacks->b->next;
		// add_list(stacks, RB);
	}
}

void		rr(t_frame *stacks)
{
	ra(stacks);
	rb(stacks);
}
