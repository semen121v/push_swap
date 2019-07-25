/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:43:29 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/25 19:55:20 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		failed_exit(t_frame *stacks)
{
	free_stacks(stacks);
	free(stacks);
	write(2, "Error\n", 6);
	exit(1);
}

t_clist		*create_clist(int data, t_frame *stacks)
{
	t_clist	*head;

	if (!(head = (t_clist*)malloc(sizeof(*head))))
		failed_exit(stacks);
	if (head)
	{
		head->prev = head;
		head->next = head;
		head->data = data;
		head->next1 = NULL;
	}
	return (head);
}

void		add_to_top(t_clist **head, int data, t_frame *stacks)
{
	t_clist *new;

	if (!(new = (t_clist*)malloc(sizeof(*new))))
		failed_exit(stacks);
	new->data = data;
	new->next = *head;
	new->next1 = *head;
	new->prev = (*head)->prev;
	(*head)->prev->next = new;
	(*head)->prev = new;
	*head = new;
}

void		pa(t_frame *stacks)
{
	if (!(stacks->b))
		return ;
	if (stacks->a)
		add_to_top(&(stacks->a), stacks->b->data, stacks);
	else
		stacks->a = create_clist(stacks->b->data, stacks);
	remove_head(&(stacks->b));
}

void		pb(t_frame *stacks)
{
	if (!(stacks->a))
		return ;
	if (stacks->b)
		add_to_top(&(stacks->b), stacks->a->data, stacks);
	else
		stacks->b = create_clist(stacks->a->data, stacks);
	remove_head(&(stacks->a));
}
