/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massive_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:36:29 by fshade            #+#    #+#             */
/*   Updated: 2019/07/25 22:31:09 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_midle(int s)
{
	int		i;

	i = s / 2;
	return (i);
}

static int	*get_mas(t_clist *list, int size)
{
	int		*mas;
	int		i;
	t_clist *tmp;

	i = 0;
	tmp = list;
	mas = (int*)malloc(sizeof(int) * size);
	while (i != size)
	{
		mas[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (mas);
}

int			count_list(t_clist *stack)
{
	t_clist	*tmp;
	int		elements;

	if (!stack)
		return (0);
	tmp = stack;
	elements = 1;
	while (tmp != stack->prev)
	{
		elements++;
		tmp = tmp->next;
	}
	return (elements);
}

int			get_median(t_clist *stacks, int size)
{
	int		*mas;
	int		j;

	mas = get_mas(stacks, size);
	quicksort(mas, 0, size - 1);
	j = check_midle(size);
	j = mas[j];
	free(mas);
	return (j);
}
