/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:08:14 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/26 20:20:07 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			mas_len(char **av)
{
	int		i;

	i = 0;
	while (av[i] != NULL)
		i++;
	return (i);
}

int			ft_get_min(t_clist *stack)
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

int			ft_get_max(t_clist *stack)
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

void		remove_head(t_clist **head)
{
	t_clist	*tmp;

	if (!(*head))
		return ;
	tmp = (*head)->next;
	if ((*head)->next == *head)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		(*head)->prev->next = (*head)->next;
		(*head)->next->prev = (*head)->prev;
		free(*head);
		*head = tmp;
	}
}

void		free_stacks(t_frame *stacks)
{
	t_clist	*tmp;

	if (stacks->a)
	{
		while (stacks->a != stacks->a->next)
		{
			tmp = stacks->a->next;
			remove_head(&(stacks->a));
			stacks->a = tmp;
		}
		remove_head(&(stacks->a));
		stacks->a = NULL;
	}
	if (stacks->b)
	{
		while (stacks->b != stacks->b->next)
		{
			tmp = stacks->b->next;
			remove_head(&(stacks->b));
			stacks->b = tmp;
		}
		remove_head(&(stacks->b));
		stacks->b = NULL;
	}
}
