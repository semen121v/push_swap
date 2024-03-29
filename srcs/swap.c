/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:42:47 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/26 15:05:39 by fshade           ###   ########.fr       */
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
	}
	if (stacks->print)
		ft_print_ab(stacks);
}

void		sb(t_frame *stacks)
{
	int		tmp;

	if (stacks->b && stacks->b != stacks->b->next)
	{
		tmp = stacks->b->data;
		stacks->b->data = stacks->b->next->data;
		stacks->b->next->data = tmp;
	}
	if (stacks->print)
		ft_print_ab(stacks);
}

void		ss(t_frame *stacks)
{
	sa(stacks);
	sb(stacks);
}
