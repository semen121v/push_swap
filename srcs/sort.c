/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:08:16 by fshade            #+#    #+#             */
/*   Updated: 2019/07/25 23:31:30 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sorted(t_frame *stacks)
{
	t_clist		*tmp;

	if (!stacks->a || (stacks->b))
		return (0);
	tmp = stacks->a;
	while (tmp != stacks->a->prev)
	{
		if (tmp->data >= tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	change_values(int *numbers, int pivot, int new, int *hold)
{
	numbers[new] = pivot;
	pivot = new;
	if (hold[0] < pivot)
		quicksort(numbers, hold[0], pivot - 1);
	if (hold[1] > pivot)
		quicksort(numbers, pivot + 1, hold[1]);
	return ;
}

void		quicksort(int *numbers, int left, int right)
{
	int		pivot;
	int		mas[2];

	mas[0] = left;
	mas[1] = right;
	pivot = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--;
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++;
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	change_values(numbers, pivot, left, mas);
}
