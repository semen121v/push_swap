/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:08:14 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/13 14:23:33 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	remove_head(t_clist **head)
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

// static void	delete_move(t_frame *stacks, t_moves *move)
// {
// 	if ((stacks->moves))
// 	{
// 		move->prev->next = move->next;
// 		move->next->prev = move->prev;
// 		free(move);
// 		move = NULL;
// 	}
// }

// static void	free_moves(t_frame *stacks)
// {
// 	t_moves	*tmp;

// 	if (stacks->moves)
// 	{
// 		while (stacks->moves != stacks->moves->next)
// 		{
// 			tmp = stacks->moves->next;
// 			delete_move(stacks, stacks->moves);
// 			stacks->moves = tmp;
// 		}
// 		delete_move(stacks, stacks->moves);
// 	}
// 	stacks->moves = NULL;
// }

// void	add_list(t_frame *stacks, int move)
// {
// 	t_moves	*new;

// 	if (!(new = (t_moves*)malloc(sizeof(*new))))
// 		failed_exit(stacks);
// 	new->move = move;
// 	new->next = stacks->moves;
// 	new->prev = stacks->moves->prev;
// 	stacks->moves->prev->next = new;
// 	stacks->moves->prev = new;
// }

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
	//free_moves(stacks);
}
