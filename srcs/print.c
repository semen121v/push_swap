/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:19:08 by fshade            #+#    #+#             */
/*   Updated: 2019/07/12 19:48:12 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		print_usage(void)
{
	ft_printf("Usage:\n\t./push_swap \"3 2 4\" OR ./checker \"3 2 4\"\n");
	return (0);
}

static void	ft_print_stack(t_clist *stack)
{
	if (stack)
	{
		ft_print_stack(stack->next1);
		ft_printf(" %d", stack->data);
	}
}

void	ft_print_ab(t_frame *stacks)
{
	ft_printf("a |");
	ft_print_stack(stacks->a);
	ft_printf("\nb |");
	ft_print_stack(stacks->b);
	ft_printf("\n");
}