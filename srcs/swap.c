/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:42:47 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/12 18:36:07 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_frame *stacks)
{
	int		tmp;

	if (stacks->a && stacks->a != stacks->a->next)
	{
		tmp = stacks->a->data;
		stacks->a->data = stacks->a->next->data;
		stacks->a->next->data = tmp;
		// add_list(stacks, SA);
	}
}

void		sb(t_frame *stacks)
{
	int		tmp;

	if (stacks->b && stacks->b != stacks->b->next)
	{
		tmp = stacks->b->data;
		stacks->b->data = stacks->b->next->data;
		stacks->b->next->data = tmp;
		// add_list(stacks, SB);
	}
}

void		ss(t_frame *stacks)
{
	sa(stacks);
	sb(stacks);
}
