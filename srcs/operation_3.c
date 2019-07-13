/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:05:23 by fshade            #+#    #+#             */
/*   Updated: 2019/07/13 21:36:41 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_min(t_clist *stack)
{
	int		min;

	min = stack->data;
	while (stack->next1 != NULL)
	{
		if (stack->next1->data < min)
			min = stack->next1->data;
		stack = stack->next1;
	}
	return (min);
}

int		ft_get_max(t_clist *stack)
{
	int		max;

	max = stack->data;
    while (stack->next1 != NULL)
	{
		if (stack->next1->data > max)
			max = stack->next1->data;
		stack = stack->next1;
	}
	return (max);
}